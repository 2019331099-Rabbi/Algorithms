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
This is the standard code for vanilla BFS. We traverse the graph using
Breadth First Search.

Test Case
7 7
1 2
2 3
3 1
1 4
5 6
6 7
7 5
2
*/

int nodes;
vector <int> adj[sz];
bool vis[sz];

void bfs(int strt)
{
    int u;
    queue <int> q;

    q.push(strt);
    vis[strt]=true;

    while (!q.empty()) {
        u=q.front();
        cout << u << ' ';
        q.pop();
        for (auto xx: adj[u]) {
            if (vis[xx]) continue;
            q.push(xx);
            vis[xx]=true;
        }
    }
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
        adj[v].push_back(u);
    }
    cin >> strt;
    bfs(strt);

    return 0;
}
