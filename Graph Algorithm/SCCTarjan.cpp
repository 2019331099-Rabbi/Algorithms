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
bool inStack[sz];
int dt[sz], low[sz], timer;
stack <int> stk;

void init(int nodes)
{
    for (int i = 0; i <= nodes; i++) dt[i] = low[i] = -1;
}

void dfs(int strt)
{
    dt[strt] = low[strt] = ++timer;
    stk.push(strt);
    inStack[strt] = true;

    for (auto xx: adj[strt]) {
        if (dt[xx] == -1) {
            dfs(xx);
            low[strt] = min(low[strt], low[xx]);
        }
        else if (inStack[xx]) low[strt] = min(low[strt], dt[xx]);
    }

    if (low[strt] == dt[strt]) {
        cout << "SCC: ";
        while (stk.top() != strt) {
            cout << stk.top() << ' ';
            inStack[stk.top()] = false;
            stk.pop();
        }
        cout << stk.top() << endl;
        inStack[stk.top()] = false;
        stk.pop();
    }
}

int tarjan(int nodes)
{
    init(nodes);
    for (int i = 0; i < nodes; i++) {
        if (dt[i] == -1) dfs(i);
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v;

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    tarjan(nodes);
    return 0;
}
/**
7 9
0 1
1 2
1 3
3 4
4 0
4 5
4 6
5 6
6 5
 */