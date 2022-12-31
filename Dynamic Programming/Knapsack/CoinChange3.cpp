#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------Coin Change Variation 3-------------------
Suppose you have n coins. The value of the coins can be expressed by
C0, C1, C2......Cn - 1. You are given an amount W. Now calculate how
many ways you can make W by using each coin at most once.
NB: Every coin can be used only once.

6 22
2 5 9 13 15 7
*/

int n, w, arr[sz], memo[sz][sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int coinChange(int pos, int amount)
{
    if (amount < 0) return 0;
    if (pos == n) return amount == 0;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int val = 0;
    val += coinChange(pos + 1, amount);
    if (amount - arr[pos] >= 0) val += coinChange(pos + 1, amount - arr[pos]);
    return memo[pos][amount] = val;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << coinChange(0, w) << endl;
    return 0;
}