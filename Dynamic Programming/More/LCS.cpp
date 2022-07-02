#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------Longest Common Subsequence-------------------
You are given two string. Find out the longest common subsequence between them.

Test Case:
abcdefghij
cdgi
Output: 4

abcdefghij
ecdgi
Output: 4
*/

string s1, s2;
int memo[sz][sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int LCS(int pos1, int pos2)
{
    if (pos1 == s1.size() || pos2 == s2.size()) return 0;
    if (memo[pos1][pos2] != -1) return memo[pos1][pos2];

    if (s1[pos1] == s2[pos2]) return memo[pos1][pos2] = 1 + LCS(pos1 + 1, pos2 + 1);
    else return memo[pos1][pos2] = max(LCS(pos1, pos2 + 1), LCS(pos1 + 1, pos2));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> s1 >> s2;
    cout << LCS(0, 0) << endl;
    return 0;
}