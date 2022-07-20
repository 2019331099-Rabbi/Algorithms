#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1e18
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int deg[sz];
bool adj[sz][sz];
int nodes, edges, before, after;
vector <pair <int, int>> dir;

void addEdge(int u, int v)
{
    adj[u][v]=adj[v][u]=true;
    deg[u]++, deg[v]++;
}

void deleteEdge(int u, int v)
{
    adj[u][v]=adj[v][u]=false;
    deg[u]--, deg[v]--;
}

bool isPossible()
{
    int i, odd=0;
    for (i=0; i<nodes; i++) if (deg[i]&1) odd++;
    return (odd==2 || odd==0);
}

int find_src()
{
    if (!isPossible()) return -1;
    int i, src=0;

    for (i=0; i<nodes; i++) if (deg[i]&1) return i;
    return src;
}

bool vis[sz];
int cnt;

void init()
{
    memset(vis, false, sizeof(vis));
}

void dfs(int u)
{
    vis[u]=true;
    cnt++;
    for (int i=0; i<nodes; i++) {
        if (!adj[u][i] || vis[i]) continue;
        dfs(i);
    }
}

bool isBridge(int u, int v)
{
    init();
    cnt=0;
    dfs(u);
    before=cnt;

    deleteEdge(u, v);

    init();
    cnt=0;
    dfs(u);
    after=cnt;

    addEdge(u, v);

    return before>after;
}

void fleury(int u)
{
    int i;
    vector <int> bridge;

    for (i=0; i<nodes; i++) {
        if (!adj[u][i]) continue;
        if (isBridge(u, i)){
            bridge.push_back(i);
            continue;
        }
        deleteEdge(u, i);
        dir.push_back({u, i});
        fleury(i);
        return;
    }
    if (bridge.size()) {
        deleteEdge(u, bridge[0]);
        dir.push_back({u, bridge[0]});
        fleury(bridge[0]);
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int i, u, v, src;

    cin >> nodes >> edges;
    for (i=0; i<edges; i++) {
        cin >> u >> v;
        addEdge(u, v);
    }
    src=find_src();
    if (src==-1) cout << "Euler Path not possible" << endl;
    else {
        fleury(src);
        cout << endl;
        for (auto xx: dir) cout << xx.first << " -> " << xx.second << endl;
        dir.clear();
    }
    return 0;
}
/**
5 5
4 3
3 0
0 1
1 2
4 0

9 13
0 1
1 2
1 5
5 2
3 2
2 4
3 4
3 8
3 6
4 6
4 7
8 6
6 7

*/
