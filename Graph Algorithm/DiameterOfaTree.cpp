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
This program finds the diameter of a tree.
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.

Test Case 1
6
1 2
2 4
2 5
1 3
3 6

Test Case 2
9
7 8
1 2
9 7
6 7
1 3
1 9
4 9
5 9


*/

int nodes;
vector <int> adj[sz];

pair <int, int> find_diameter(int strt)
{
    queue <int> q;
    int dis[nodes+1]={0};
    int u, diameter=1, fnode=strt;

    q.push(strt);
    dis[strt]=1;

    while (!q.empty()) {
        u=q.front();
        q.pop();
        if (dis[u]>diameter) diameter=dis[u], fnode=u;
        for (auto xx: adj[u]) {
            if (dis[xx]) continue;
            dis[xx]=dis[u]+1;
            q.push(xx);
        }
    }
    return {fnode, diameter};
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int u, v, i;
    pair <int, int> pr1, pr2;

    cin >> nodes;
    for (i=1; i<nodes; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pr1=find_diameter(1);
    pr2=find_diameter(pr1.first);
    cout << pr1.first << ' ' << pr2.first << ' ' << pr2.second << endl;

    return 0;
}
