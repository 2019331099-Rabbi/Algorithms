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
This program finds the minimum spanning tree(MST) of a given graph using Kruskal's Algorithm.
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
priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, greater <pair <int, pair <int, int>>>> pq;
int par[sz];
vector <pair <int, pair <int, int>>> ans;

void make_set(int nodes)
{
    for (int i=1; i<=nodes; i++) par[i]=i;
}

int find_set(int u)
{
    return (par[u]==u)?u:par[u]=find_set(par[u]);
}

void union_set(int u, int v)
{
    par[v]=u;
}

void mst_kruskal()
{
    int u, v, w;
    while (!pq.empty()) {
        w=pq.top().first;
        u=pq.top().second.first;
        v=pq.top().second.second;
        pq.pop();

        int p=find_set(u);
        int q=find_set(v);
        if (p==q) continue;
        union_set(p, q);
        ans.push_back({w, {u, v}});
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v, w;

    cin >> nodes >> edges;
    make_set(nodes);
    while (edges--) {
        cin >> u >> v >> w;
        pq.push({w, {u, v}});
    }
    mst_kruskal();
    cout << "Edge list int MST(Kruskal):" << endl;
    for (auto xx: ans) cout << xx.first << " (" << xx.second.first << ',' << xx.second.second << ")" << endl;

    return 0;
}
