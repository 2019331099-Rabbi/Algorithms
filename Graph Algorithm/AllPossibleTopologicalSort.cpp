#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
You are given a DAG. Find all possible topological sort of the given DAG.
Test Case
6 6
2 1
2 3
4 3
4 5
1 6
6 5
*/

vector <int> adj[sz];
int nodes;

void allPossibleTopoSort(vector <int> res, int indeg[], bool vis[])
{
    if (res.size() == nodes) {
        for (auto xx: res) cout << xx << ' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= nodes; i++) {
        if (!indeg[i] and !vis[i]) {
            for (auto xx: adj[i]) indeg[xx]--;
            res.push_back(i);
            vis[i] = true;

            allPossibleTopoSort(res, indeg, vis);
            
            for (auto xx: adj[i]) indeg[xx]++;
            res.pop_back();
            vis[i] = false;
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int edges, u, v;
    int indeg[sz] = {0};
    bool vis[sz] = {false};

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    vector <int> res;
    allPossibleTopoSort(res, indeg, vis);
    return 0;
}