#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool adj[sz][sz];
int deg[sz];

void addEdge(int u, int v)
{
    adj[u][v] = adj[v][u] = true;
}

void deleteEdge(int u, int v)
{
    adj[u][v] = adj[v][u] = false;
}

bool isPossible(int nodes)
{
    int cnt = 0;
    for (int i = 0; i < nodes; i++) if (deg[i] & 1) cnt++;
    return cnt == 0 || cnt == 2;
}

int findSource(int nodes)
{
    for (int i = 0; i < nodes; i++) if (deg[i] & 1) return i;
    return 0;
}

int bfs(int strt, int nodes)
{
    bool vis[nodes + 1] = {false};
    queue <int> q;

    q.push(strt);
    vis[strt] = true;

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        cnt++;
        q.pop();
        for (int i = 0; i < nodes; i++) {
            if (vis[i] || !adj[u][i]) continue;
            q.push(i);
            vis[i] = true;
        }
    }
    return cnt;
}

bool isBridge(int u, int v, int nodes)
{
    int cnt1 = bfs(u, nodes);
    deleteEdge(u, v);
    int cntt2 = bfs(u, nodes);
    addEdge(u, v);

    return cnt1 != cntt2;
}

void fleury(int nodes)
{
    vector <pair <int, int>> path;
    int u, v1, v2;

    u = findSource(nodes);
    
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
            deleteEdge(u, v1);
            u = v1;
        }
        else {
            path.push_back({u, v2});
            deleteEdge(u, v2);
            u = v2;
        }
        
    }
    for (auto xx: path) cout << xx.first << "->" << xx.second << endl;
    cout << endl;

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v;

    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        addEdge(u, v);
        deg[u]++, deg[v]++;
    }
    if (isPossible(nodes)) fleury(nodes);
    else cout << "Euler cicuit or path not possible" << endl;
    return 0;
}
/**
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

Output:
0->1
1->2
2->3
3->4
4->6
6->3
3->8
8->6
6->7
7->4
4->2
2->5
5->1

5 5
4 3
0 1
1 2
4 0
2 3

Output:
0->1
1->2
2->3
3->4
4->0
*/