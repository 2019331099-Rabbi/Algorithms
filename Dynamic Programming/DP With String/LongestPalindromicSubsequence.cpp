#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
********** Longest Palindromic Subsequence ************
You have given a string. Find the longest subsequence that is a palindrome.

Test Case:
abcabcb
Output: 5 bcacb

abcaabbav
Output: 6 abaaba

a
Output: 1 a  

abc
Output: 1 a
*/


int memo[sz][sz];
pair <int, int> nxt[sz][sz];
string s;

int isPalindrome(int l, int r)
{
    if (l == r) return memo[l][r] = 1;
    if (l > r) return 0;
    if (memo[l][r] != -1) return memo[l][r];

    if (s[l] == s[r]) {
        nxt[l][r] = {l + 1, r - 1};
        return memo[l][r] = 2 + isPalindrome(l + 1, r - 1);
    }
    else {
        int val1 = isPalindrome(l + 1, r);
        int val2 = isPalindrome(l, r - 1);
        if (val1 > val2) nxt[l][r] = {l + 1, r};
        else nxt[l][r] = {l, r - 1};
        return memo[l][r] = max(val1, val2);
    }
}

int longestPalindromicSubsequence()
{
    int len = s.size(), ans = -1;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) if (isPalindrome(i, j)) ans = max(ans, memo[i][j]);
    }
    return ans;
}

string subsequenceGenerator()
{
    int i = 0, j = s.size() - 1, x, y;
    string left = "", right = "";
    
    while (true) {
        if (i == j) {

            if (i || (!left.size() && !right.size())) left += s[i];
            break;
        }
        x = nxt[i][j].first, y = nxt[i][j].second;
        if (x == i + 1 && y == j - 1) {
            left += s[i];
            if (i != j) right += s[j];
        }
        i = x, j = y;
    }
    reverse(right.begin(), right.end());
    return left + right;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> s;
    cout << longestPalindromicSubsequence();
    cout << ' ' << subsequenceGenerator() << endl;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) cout << '(' << nxt[i][j].first << ',' << nxt[i][j].second << ") ";
        cout << endl;
    }
    return 0;
}