#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 3001
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool adj[sz][sz];
int deg[sz];

bool isPossible(int nodes)
{
    int cnt = 0;
    for (int i = 0; i < nodes; i++) if (deg[i] & 1) cnt++;
    return cnt == 2 || cnt == 0;
}

int findSource(int nodes)
{
    for (int i = 0; i < nodes; i++) if (deg[i] & 1) return i;
    return 0;
}

int bfs(int strt, int nodes)
{
    bool vis[nodes] = {false};
    queue <int> q;
    
    q.push(strt);
    vis[strt] = true;
    int cnt = 0;

    while (!q.empty()) {
        int u = q.front();
        cnt++;
        q.pop();
        for (int i = 0; i < nodes; i++) {
            if (!adj[u][i] || vis[i]) continue;
            q.push(i);
            vis[i] = true;
        }
    }
    return cnt;
}

bool isBridge(int u, int v, int nodes)
{
    int cnt1 = bfs(u, nodes);
    adj[u][v] = adj[v][u] = false;
    int cnt2 = bfs(u, nodes);

    adj[u][v] = adj[v][u] = true;
    return cnt1 != cnt2;
}

void fleury(int nodes, int edges)
{
    vector <pair <int, int>> path;
    int u, v1, v2, cnt = 0;

    u = findSource(nodes);
    cout << bfs(u, nodes) << endl;
    while (true) {
        v1 = v2 = -1;
        for (int i = 0; i < nodes; i++) {
            if (!adj[u][i]) continue;
            if (isBridge(u, i, nodes)) v1 = i;
            else {
                v2 = i;
                break;
            }
        }
        if (v1 < 0 && v2 < 0) break;

        if (v2 < 0) {
            path.push_back({u, v1});
            adj[u][v1] = adj[v1][u] = false;
            u = v1;
        }
        else {
            path.push_back({u, v2});
            adj[u][v2] = adj[v2][u] = false;
            u = v2;
        }
    }
    for (auto xx: path) cout << xx.first << "->" << xx.second << endl;
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges;

    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
        deg[u]++, deg[v]++;
    }
    if (isPossible(nodes)) fleury(nodes, edges);
    else cout << "Eular path not possible" << endl;
    return 0;
}