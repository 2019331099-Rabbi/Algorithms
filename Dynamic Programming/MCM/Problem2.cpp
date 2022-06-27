#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Given an valid rthmetic expession which consists of only digits, '+' or '*'.
You can insert brackets to maximize the expression. Print the maximum score
you can get.

Ex
5-8+7*4-8+9 = 200
*/

string s;
int memo[sz][sz][2];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int dp(int left, int right, int isMax)
{
    if (left == right) return s[left] - '0';
    if (memo[left][right][isMax] != -1) return memo[left][right][isMax];

    int ans;

    if (isMax) ans = -100000000;
    else ans = 10000000;

    for (int i = left; i <= right; i++) {
        if (s[i] >= '0' && s[i] <= '9') continue;

        int val1, val2, val;
        if (s[i] == '+' || s[i] == '*') {
            val1 = dp(left, i - 1, isMax);
            val2 = dp(i + 1, right, isMax);
            if (s[i] == '+') val = val1 + val2;
            else val = val1 * val2;
        }
        else {
            if (isMax) {
                val1 = dp(left, i - 1, 1);
                val2 = dp(i + 1, right, 0);
            }
            else {
                val1 = dp(left, i - 1, 0);
                val2 = dp(i + 1, right, 1);
            }
            val = val1 - val2;
        }
        if (isMax) ans = max(ans, val);
        else ans = min(ans, val);
    }
    return memo[left][right][isMax] = ans;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> s;
    cout << dp(0, s.size() - 1, 1) << endl;

    return 0;
}