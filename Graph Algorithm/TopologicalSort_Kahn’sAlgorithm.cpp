#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**

*** Condition for Topological Sort: The graph must be a DAG.
This program finds a valid topological ordering.
If there is no valid order it print -1. Otherwise print a valid order.

Test Case

9 10
1 2
1 8
2 5
2 9
3 4
4 5
4 8
5 7
5 9
6 7


*/

int nodes, indeg[sz];
vector <int> adj[sz];
bool vis[sz];

void toposort()
{
    vector <int> topo;
    queue <int> q;
    int i, u;

    for (i=1; i<=nodes; i++) if (!indeg[i]) q.push(i), vis[i]=true;
    while (!q.empty()) {
        u=q.front();
        q.pop();
        topo.push_back(u);

        for (auto xx: adj[u]) {
            if (vis[xx]) continue;
            indeg[xx]--;
            if (!indeg[xx]) q.push(xx), vis[xx]=true;
        }
    }
    if (topo.size()==nodes) for (auto xx: topo) cout << xx << ' ';
    else cout << -1;
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int edges, u, v, strt;

    cin >> nodes >> edges;

    while (edges--) {
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    toposort();
    return 0;
}
