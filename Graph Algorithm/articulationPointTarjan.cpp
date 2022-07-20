#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> adj[sz];
int low[sz], dt[sz], parent[sz], timer;
bool isAP[sz];

void init()
{
    for (int i = 0; i < sz; i++) low[i] = dt[i] = parent[i] = -1;
}

void dfs(int strt)
{
    dt[strt] = low[strt] = ++timer;
    int child = 0;

    for (int xx: adj[strt]) {
        if (dt[xx] == -1) {
            child++;
            parent[xx] = strt;
            dfs(xx);
            low[strt] = min(low[strt], low[xx]);
            if (parent[xx] == -1 && child > 1) isAP[strt] = true;
            else if (parent[xx] != -1 && low[xx] >= dt[strt]) isAP[strt] = true;
        }
        else if (xx != parent[strt]) low[strt] = min(low[strt], dt[xx]);
    }
}

void ArticulationPointTarjan(int nodes)
{
    init();
    for (int i = 0; i < nodes; i++) {
        if (dt[i] == -1) dfs(i);
    }
    for (int i = 0; i < nodes; i++) {
        if (isAP[i]) cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges;

    cin >> nodes >> edges;
    while (edges--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ArticulationPointTarjan(nodes);
    return 0;
}
/**
5 5
0 2
0 3
1 0
2 1
3 4
 */