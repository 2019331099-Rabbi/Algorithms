#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz], cost[sz];
int dis[sz], parent[sz];

void init(int nodes)
{
    for (int i = 0; i <= nodes; i++) dis[i] = inf, parent[i] = -1;
}

bool bellmanford(int strt, int dst, int nodes)
{
    int u;
    init(nodes);
    dis[strt] = 0;

    for (int k = 1; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                u = adj[i][j];
                if (dis[u] > dis[i] + cost[i][j]) dis[u] = dis[i] + cost[i][j], parent[u] = i;
            }
        }
    }
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            u = adj[i][j];
            if (dis[u] > dis[i] + cost[i][j]) return true;
        }
    }
    return false;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v, w;

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        cost[u].push_back(w);
    }
    cin >> u >> v;
    if (bellmanford(u, v, nodes)) cout << "Negative cycle detected" << endl;
    else {
        cout << "Minimum path cost = " << dis[v] << endl;
        stack <int> stk;
        while (~v) {
            stk.push(v);
            v = parent[v];
        }
        while(!stk.empty()) {
            cout << stk.top() << ' ';
            stk.pop();
        }
    }
    return 0;
}
/**
6 10
0 1 3
0 2 -2
0 4 8
2 3 6
1 2 1
1 5 4
1 4 6
4 5 -5
3 5 -5
3 1 9
0 5
 */