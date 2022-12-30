#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 12
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Given an valid arithmetic expession which consists of only digits, '+' or '*'.
You can insert brackets to maximize the expression. Print the maximum score
you can get.

Example: 2+3*4+7*1
*/

string s;
int memo[sz][sz][2];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int do_op(char op, int a, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    }
}

int dp(int left, int right, bool isMax)
{
    if (left == right) return s[left] - '0';
    if (memo[left][right][isMax] != -1) return memo[left][right][isMax];

    int ans = (isMax)?INT_MIN:INT_MAX;

    for (int i = left; i <= right; i++) {
        if (s[i] >= '0' && s[i] <= '9') continue;

        int val, val1, val2;
        if (s[i] == '+' || s[i] == '*') {
            val1 = dp(left, i - 1, isMax);
            val2 = dp(i + 1, right, isMax);
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
        }
        val = do_op(s[i], val1, val2);
        ans = (isMax)?max(ans, val):min(ans, val);
    }
    return memo[left][right][isMax] = ans;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    cin >> s;
    init();
    cout << dp(0, s.size() - 1, true) << endl;
    return 0;
}