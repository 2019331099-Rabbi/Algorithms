#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 10000010
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int nodes;
vector <int> adj[sz], cost[sz];
int minCost[sz], parent[sz];

void init()
{
    for (int i = 0; i <= nodes; i++) parent[i] = -1, minCost[i] = inf;
}

void dijkstra(int strt)
{
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    int c, u, v, alt;
    
    init();
    pq.push({0, strt});
    minCost[strt] = 0;

    while (!pq.empty()) {
        c = pq.top().first;
        u = pq.top().second;
        pq.pop();
        if (c > minCost[u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];
            alt = c + cost[u][i];
            if (alt >= minCost[v]) continue;
            pq.push({alt, v});
            minCost[v] = alt;
            parent[v] = u;
        }
    }
    stack <int> path;
    for (int i=1; i<=nodes; i++) {
        int dest=i;
        cout << "Minimum cost from " << strt << " to " << dest << " = " << minCost[dest] << endl;
        cout << "path =";

        while (~dest) {
            path.push(dest);
            dest=parent[dest];
        }
        while (!path.empty()) {
            cout << ' ' << path.top();
            path.pop();
        }
        cout << endl << endl;
    }
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
    cin >> u;
    dijkstra(u);
    return 0;
}
