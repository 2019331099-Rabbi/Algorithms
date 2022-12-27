#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Given a string S(Only digits) and an integer D. How many permutation of S is divisible by D?
Assum that, |S| <= 10 and 1 <= D <= 1000.All digits of S are unique.
*/

int d, memo[1 << 10][sz];
string s;

int dp(int mask, int remainder)
{
    int pos = __builtin_popcount(mask);
    if (pos == s.size()) return remainder == 0;
    if (memo[mask][remainder] != -1) return memo[mask][remainder];

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((1 << i) & mask) continue;
        ans += dp(mask | (1 << i), (remainder * 10 + s[i] - '0') % d);
    }
    return memo[mask][remainder] = ans;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> s >> d;
    cout << dp(0, 0) << endl;

    return 0;
}