#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 51
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------Coin Change Variation 4-------------------
Suppose you have n coins. The value of the coins can be expressed by
A0, A1, A2......An - 1. C0, C1, ... Cn - 1 denote the number of coins
of value A0, A1 ... An - 1 respectively. You are given an amount W. Now calculate how
many ways you can make W by using the coins.

3 5
1 2 5 -> Coin
3 2 1 -> Number of corresponding coin you have. It means you can't use Ai coins more than Ci times

3 5
1 2 5
3 2 1
Output: 3

4 20
1 2 3 4
8 4 2 1
Output: 9
*/

int n, w, coin[sz], freq[sz];
int64_t memo[sz][1001];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int64_t coinChange(int pos, int amount)
{
    if (pos == n) return amount == 0;
    if (amount == 0) return 1;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int64_t val = 0;
    val = (val + coinChange(pos + 1, amount)) % mod;
    int sum = 0;
    for (int i = 0; i < freq[pos]; i++) {
        sum += coin[pos];
        if (amount - sum >= 0) val = (val + coinChange(pos + 1, amount - sum)) % mod;
    }
    return memo[pos][amount] = val;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> coin[i];
    for (int i = 0; i < n; i++) cin >> freq[i];

    init();
    cout << coinChange(0, w) << endl;
    return 0;
}