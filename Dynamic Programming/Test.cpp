#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------0/1 knapsack-------------------
Given weights and profits of n items, put these items in a knapsack of capacity W to get
the maximum total profit in the knapsack.

3 50
10 20 30
60 100 120

Expalanation
W = 50
item weight profit
1      10    60
2      20    100
3      30    120
*/

int memo[sz][sz];

int maxProfit(int pos, int w, vector <int> &weights, vector <int> &profits)
{
    if (w < 0) return -inf;
    if (pos == weights.size()) return 0;
    
    int profit1 = maxProfit(pos + 1, w, weights, profits);
    int profit2 = profits[pos] + maxProfit(pos + 1, w - weights[pos], weights, profits);
    return max(profit1, profit2);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    
    int n, w;
    cin >> n >> w;
    
    vector <int> weights(n), profits(n);
    for (auto &weight: weights) cin >> weight;
    for (auto &profit: profits) cin >> profit;

    memset(memo, -1, sizeof(memo));
    cout << maxProfit(0, w, weights, profits) << endl;
    return 0;
}