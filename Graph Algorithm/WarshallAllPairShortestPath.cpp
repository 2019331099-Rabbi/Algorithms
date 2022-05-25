#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e18
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int cost[sz][sz];

void printG(int nodes)
{
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) cout << cost[i][j] << ' ';
        cout << endl;
    }
}

void warshall(int nodes)
{
    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (cost[i][k] && cost[k][j])
                    cost[i][j] = (cost[i][j])?min(cost[i][j], cost[i][k] + cost[k][j]):cost[i][k] + cost[k][j];
            }
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes, edges, u, v, w;

    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v >> w;
        cost[u][v] = cost[v][u] = w;
    }
    cout << "Before Warshall's" << endl;
    printG(nodes);
    warshall(nodes);
    cout << "After warshall's" << endl;
    printG(nodes);
    return 0;
}
/**
6 8
5 2 6
1 3 2
4 0 1
3 4 8
0 2 9
5 0 1
0 1 5
0 3 2

Before Warshall's
0 5 9 2 1 1 
5 0 0 2 0 0 
9 0 0 0 0 6 
2 2 0 0 8 0 
1 0 0 8 0 0 
1 0 6 0 0 0 
After warshall's
2 4 7 2 1 1 
4 4 11 2 5 5 
7 11 12 9 8 6 
2 2 9 4 3 3 
1 5 8 3 2 2 
1 5 6 3 2 2
 */