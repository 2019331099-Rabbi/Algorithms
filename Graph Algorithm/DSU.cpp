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
This program finds the total number of components in a given undirected graph
using DSU.

Test cases
7 6
1 2
6 1
5 4
3 7
5 1
6 5
*/

int nodes, par[sz];

void make_set()
{
    for (int i=1; i<=nodes; i++) par[i]=i;
}

int find_set(int u)
{
    return (par[u]==u)?u:par[u]=find_set(par[u]);
}

void union_set(int u, int v)
{
    u=find_set(u);
    v=find_set(v);
    if (u==v) return;
    par[v]=u;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int edges, u, v, i, T, cnt;

    cin >> nodes >> edges;
    make_set();

    while (edges--) {
        cin >> u >> v;
        union_set(u, v);
    }
    bool vis[sz]={false};
    cnt=0;
    for (i=1; i<=nodes; i++) {
        u=find_set(i);
        if (vis[u]) continue;
        vis[u]=true;
        cnt++;
    }
    cout << "Total number of components = " << cnt << endl;
    return 0;
}
