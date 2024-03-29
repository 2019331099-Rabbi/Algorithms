#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Given A, B and X. How many integers between A and B have a digit sum equal to X.
1 <= A <= B <= 1000000000, 1 <= x <= 90
*/

int x, memo[15][2][90];

int dp(int pos, int isSmall, int digitSum, string &str)
{
    if (pos == str.size()) return digitSum == x;
    if (memo[pos][isSmall][digitSum] != -1) return memo[pos][isSmall][digitSum];

    int ans = 0, lim = str[pos] - '0';
    if (isSmall) lim = 9;

    for (int i = 0; i <= lim; i++) {
        int newIsSmall = isSmall | (i < lim);
        ans += dp(pos + 1, newIsSmall, digitSum + i, str);
    }
    return memo[pos][isSmall][digitSum] = ans;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string A, B;
    cin >> A >> B >> x;
    
    init();
    int r = dp(0, 0, 0, B);

    A = to_string(stoi(A) - 1);
    init();
    int l = dp(0, 0, 0, A);

    cout << r << ' ' << l << endl;
    cout << r - l << endl;
    return 0;
}