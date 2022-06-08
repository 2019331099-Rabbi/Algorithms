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
You are given a DAG. Find the lexicographically smallest topological sort.
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

void smallestTopoSort()
{
    vector <int> topo;
    priority_queue <int, vector <int>, greater <int>> pq;

    for (int i=1; i<=nodes; i++) if (!indeg[i]) pq.push(i);
    while (!pq.empty()) {
        int u = pq.top();
        topo.push_back(u);
        pq.pop();

        for (auto xx: adj[u]) {
            indeg[xx]--;
            if (!indeg[xx]) pq.push(xx);
        }
    }
    for (auto xx: topo) cout << xx << ' ';
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
    smallestTopoSort();
    return 0;
}
