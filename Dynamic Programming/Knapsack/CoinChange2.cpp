#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------Coin Change Variation 2-------------------
Suppose you have n coins. The value of the coins can be expressed by
C0, C1, C2......Cn - 1. You are given an amount W. Now figure out the minimum
number of coins you need to make the total amout equal to W.
NB: Every coin can be used any number of times.

5 30
2 5 9 13 15
*/

int n, w, arr[sz], memo[sz][sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int coinChange(int pos, int amount)
{
    if (amount < 0) return inf;
    if (pos == n) {
        if (amount == 0) return 0;
        else return inf;
    }
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int val1 = 1 + coinChange(pos, amount - arr[pos]);
    int val2 = coinChange(pos + 1, amount);
    return memo[pos][amount] = min(val1, val2);
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