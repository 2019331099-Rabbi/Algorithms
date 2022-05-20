#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e18
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
This program finds the Strongly Connected Components in a directed graph using Kosaraju's algorithm.

Test case

7 8
1 2
2 3
3 1
3 4
4 5
5 7
7 6
6 5


*/

vector <int> adj[sz], radj[sz];
stack <int> stk;
bool vis[sz];

void dfs1(int u)
{
    vis[u]=true;
    for (auto xx: adj[u]) {
        if (vis[xx]) continue;
        dfs1(xx);
    }
    stk.push(u);
}

void dfs2(int u)
{
    vis[u]=true;
    for (auto xx: radj[u]) {
        if (vis[xx]) continue;
        dfs2(xx);
    }
}

int Kosaraju(int nodes)
{
    int scc=0;
    for (int i=1; i<=nodes; i++) {
        if (vis[i]) continue;
        dfs1(i);
    }
    memset(vis, false, sizeof(vis));

    while (!stk.empty()) {
        if (!vis[stk.top()]) scc++, dfs2(stk.top());
        stk.pop();
    }
    return scc;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v;

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    cout << "Total SCC = " << Kosaraju(nodes) << endl;
    return 0;
}
