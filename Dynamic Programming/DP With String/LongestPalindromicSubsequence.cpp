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
/*
memo[i][j] = maximum palindromic subsequence length in the substring [i, j] 
Here memo[i][j] contains the actual answer.
*/
pair <int, int> nxt[sz][sz];
string s;

int longestPS(int l, int r)
{
    if (l == r) return 1;
    if (l > r) return 0;
    if (memo[l][r] != -1) return memo[l][r];

    if (s[l] == s[r]) {
        nxt[l][r] = {l + 1, r - 1};
        return memo[l][r] = 2 + longestPS(l + 1, r - 1);
    }
    else {
        int val1 = longestPS(l + 1, r);
        int val2 = longestPS(l, r - 1);
        nxt[l][r] = (val1 > val2)?make_pair(l + 1, r):make_pair(l, r - 1);
        return max(val1, val2);
    }
}

string lonngestPSgenerator()
{
    int i = 0, j = s.size() - 1;
    string left = "", right = "";

    while (true) {
        if (i == j) {
            if (i || (!left.size() && !right.size())) left += s[i];
            break;
        }
        int x = nxt[i][j].first;
        int y = nxt[i][j].second;
        if (x == i + 1 && y == j - 1) left += s[i], right += s[j];
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
    cout << "Longest subsequence len = " << longestPS(0, s.size() - 1) << endl;
    cout << "Longest subsequence = " << lonngestPSgenerator() << endl;
    return 0;
}