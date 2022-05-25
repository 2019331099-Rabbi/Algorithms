#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row4[]={0, 0, -1, 1};
//int col4[]={1, -1, 0, 0};

//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};

//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int nodes, dt[sz], ft[sz], cnt;
vector <int> adj[sz];
bool vis[sz];

void dfs(int strt)
{
    vis[strt]=true;
    dt[strt]=++cnt;
    for (auto xx: adj[strt]) {
        if (vis[xx]) continue;
        dfs(xx);
    }
    ft[strt]=++cnt;
}

void dfsvis()
{
    for (int i=1; i<=nodes; i++) {
        if (vis[i]) continue;
        dfs(i);
    }
}

/**
9 8
7 8
1 2
9 7
6 7
1 3
1 9
4 9
5 9
*/

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int edges, u, v, strt;

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsvis();
    for (int i=1; i<=nodes; i++) cout << i << ' ' << dt[i] << ' ' << ft[i] << endl;
    return 0;
}
