#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz];
int dt[sz], low[sz], parent[sz], timer;
vector <pair <int, int>> bridges;

void init(int nodes)
{
    for (int i = 0; i <= nodes; i++) dt[i] = low[i] = parent[i] = -1;
}

void dfs(int strt)
{
    dt[strt] = low[strt] = ++timer;

    for (auto xx: adj[strt]) {
        if (dt[xx] == -1) {
            parent[xx] = strt;
            dfs(xx);
            low[strt] = min(low[strt], low[xx]);
            if (low[xx] > dt[strt]) bridges.push_back({strt, xx});
        }
        else if (xx != parent[strt]) low[strt] = min(low[strt], dt[xx]);
    }
}

int bridgeTarjan(int nodes)
{
    init(nodes);
    for (int i = 0; i < nodes; i++) {
        if (dt[i] == -1) dfs(i);
    }
    cout<<"Bridges are:" << endl;
	for(auto it: bridges) cout << it.first << "-->" << it.second << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v;

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bridgeTarjan(nodes);
    return 0;
}
/**
5 5
0 2
0 3
1 0
2 1
3 4
 */