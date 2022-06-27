#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
How many N length numbers are there which has every pos at least once?
NB: No leading zeroes are allowed.
*/

int64_t n,  memo[sz][1 << 10];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int64_t check(int mask)
{
    if (mask == ((1 << 10) - 1)) return 1;
    return 0;
}

int64_t dp(int pos, int mask)
{
    if (pos >= n) return check(mask);
    if (memo[pos][mask] != -1) return memo[pos][mask];

    int ans = 0;
    for (int i = (pos)?0:1; i < 10; i++) ans += dp(pos + 1, mask | (1 << i));
    return memo[pos][mask] = ans;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> n;
    cout << dp(0, 0) << endl;

    return 0;
}