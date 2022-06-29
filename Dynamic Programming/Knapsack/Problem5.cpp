#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
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

int n, w, weight[sz], profit[sz], memo[sz][sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int maxProfit(int pos, int amount)
{
    if (pos == n) return 0;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int val1, val2 = 0;
    val1 = maxProfit(pos + 1, amount);
    if (amount - weight[pos] >= 0) val2 = profit[pos] + maxProfit(pos + 1, amount - weight[pos]);
    return memo[pos][amount] = max(val1, val2);
}



int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> profit[i];
    cout << maxProfit(0, w) << endl;
    
    return 0;
}