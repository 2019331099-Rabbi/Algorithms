#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
********** Problem 8 ************
You have given a string. Find the longest substring that is a palindrome.

Test Case:
abaab
Output: 3

abbaeae
Output: 4
*/


int memo[sz][sz];
string s;

void init()
{
    memset(memo, -1, sizeof(memo));
}

int isPalindrome(int l, int r)
{
    if (l >= r) return 1;
    if (memo[l][r] != -1) return memo[l][r];

    if (s[l] == s[r]) return memo[l][r] = isPalindrome(l + 1, r - 1);
    else return memo[l][r] = 0;
}

int TotalPalindromicSubstring()
{
    int len = s.size(), ans = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) if (isPalindrome(i, j)) ans++;
    }
    return ans;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> s;
    int ans = TotalPalindromicSubstring();
    cout << "Total palindromic substring = " << ans << endl;

    return 0;
}