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
This program finds the minimum spanning tree(MST) of a given graph using Prims Algorithm.
Test Cases

6 9
1 2 2
1 5 1
1 4 1
2 3 3
2 5 2
3 5 1
3 6 5
4 6 2
5 6 3

ans:
1 1 4
1 1 5
1 5 3
2 1 2
2 4 6

8 11
1 2 4
1 4 10
1 5 2
2 3 18
2 4 8
3 4 11
4 5 5
4 8 9
4 7 11
6 7 1
6 8 2

*/

int nodes;
vector <int> adj[sz], cost[sz];
vector <pair <int, pair <int, int>>> ans;
bool vis[sz];

void mst_prims()
{
    priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, greater <pair <int, pair <int, int>>>> pq;
    int i, u, v, w;

    for (i=0; i<adj[1].size(); i++) pq.push({cost[1][i], {1, adj[1][i]}});
    vis[1]=true;

    while (!pq.empty()) {
        w=pq.top().first;
        u=pq.top().second.first;
        v=pq.top().second.second;
        pq.pop();

        if (vis[v]) continue;
        ans.push_back({w, {u, v}});
        vis[v]=true;

        for (i=0; i<adj[v].size(); i++) {
            if (vis[adj[v][i]]) continue;
            pq.push({cost[v][i], {v, adj[v][i]}});
        }
    }
    cout << "Edge list int MST(Prims):" << endl;
    for (auto xx: ans) cout << xx.first << " (" << xx.second.first << ',' << xx.second.second << ")" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int edges, u, v, w;

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    mst_prims();
    return 0;
}
