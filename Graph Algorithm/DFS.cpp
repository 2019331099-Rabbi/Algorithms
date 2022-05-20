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

int nodes;
vector <int> adj[sz];
bool vis[sz];

void dfs(int strt)
{
    vis[strt]=true;
    cout << strt << ' ';
    for (auto xx: adj[strt]) {
        if (vis[xx]) continue;
        dfs(xx);
    }
}

/**
7 8
1 2
2 3
3 1
1 4
5 6
6 7
7 5
2 6
2

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
    cin >> strt;
    dfs(strt);

    return 0;
}
