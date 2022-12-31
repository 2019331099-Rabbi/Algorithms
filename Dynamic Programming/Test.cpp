#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------Coin Change Variation 1-------------------
Suppose you have n coins. The value of the coins can be expressed by
C0, C1, C2......Cn - 1. You are given an amount W. Now figure out the minimum
number of coins you need to make the total amout equal to W.
NB: Every coin can be used only once.

5 22
2 5 9 13 15

5 30
2 5 9 13 15
*/

int n, w, weight[sz], profit[sz], memo[sz][sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int knapsack(int pos, int capacity)
{
    if (capacity < 0) return -inf;
    if (pos == n) return 0;

    int val1 = knapsack(pos + 1, capacity);
    int val2 = profit[pos] + knapsack(pos + 1, capacity - weight[pos]);
    return max(val1, val2);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> profit[i];

    cout << knapsack(0, w) << endl;
    return 0;
}