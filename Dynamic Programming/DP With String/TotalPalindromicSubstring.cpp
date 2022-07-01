#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 61
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
You are given a string. Find how many palindromic subsequence can be formed from the given string.
For example
s = PASTA
8 palindromic subsequence can be formed
P, A, S, T, A, AA, ASA, ATA

SALADS
15

For more details visit https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/
*/

int64_t memo[sz][sz];
int len;
string s;

int64_t dp(int left, int right)
{
    if (left == right) return 1;
    if (left > right) return 0;
    if (memo[left][right] != -1) return memo[left][right];

    int64_t val;
    if (s[left] == s[right]) val = 1 + dp(left + 1, right) + dp(left, right - 1);
    //Checking the rest once respect to left and once respect to right
    else val = dp(left + 1, right) + dp(left, right - 1) - dp(left + 1, right - 1);
    //Checking the rest and removing the common parts.
    return memo[left][right] = val;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    cin >> s;
    len = s.size();
    init();
    cout <<  dp(0, len - 1) << endl;

    return 0;
}