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
This Program find the lexicographically smallest topological ordering.
If topological sort is not possible for the given graph it print -1.
Otherwise it print the smallest topological ordering.

Test Case

9 10
9 2
9 8
2 5
2 1
3 4
4 5
4 8
5 7
5 1
6 7


*/

int nodes, indeg[sz];
vector <int> adj[sz];
bool vis[sz];

void LS_Toposort()
{
    vector <int> topo;
    priority_queue <int, vector <int>, greater <int>> pq;
    int i, u;

    for (i=1; i<=nodes; i++) if (!indeg[i]) pq.push(i), vis[i]=true;
    while (!pq.empty()) {
        u=pq.top();
        pq.pop();
        topo.push_back(u);

        for (auto xx: adj[u]) {
            if (vis[xx]) continue;
            indeg[xx]--;
            if (!indeg[xx]) pq.push(xx), vis[xx]=true;
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
    LS_Toposort();
    return 0;
}
