#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/*
********** Problem ************
You have given a string. Find the longest substring that is a palindrome.
Test Case:
abccbcca
Output: 5
*/

int memo[sz][sz];
/*
memo[i][j] = 1, if the substring [i, j] is a palindrome
memo[i][j] = 0, if the substring [i, j] is not a palindrome
*/
string s;

void init()
{
    memset(memo, -1, sizeof(memo));
}

int isPalindrome(int l, int r)
{
    if (l >= r) return 1;
    if (memo[l][r] != -1) return memo[l][r];
    return memo[l][r] = (s[l] == s[r])?isPalindrome(l + 1, r - 1):0;
}

pair <int, int> longestPalindromicSubstring()
{
    int len = s.size(), ans = -1, l, r;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) if (isPalindrome(i, j) && (j - i + 1) > ans) ans = j - i + 1, l = i, r = j;
    }
    return {l, r};
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> s;
    pair <int, int> ans = longestPalindromicSubstring();
    cout << "Longest palindrome = " << ans.first << " to " << ans.second << endl;
    cout << "Longest palindrome length = " << ans.second - ans.first + 1 << endl;

    return 0;
}