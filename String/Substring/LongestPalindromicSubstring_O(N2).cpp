#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

/*
You are given a string s. This algorithm find the longest palindromic substring
in O(N Sq) time.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        bool memo[len][len];
        int left = 0, right = 0, mxLen = 1;

        for (int i = 0; i < len; i++) memo[i][i] = 1;
        for (int i = 1; i < len; i++) {
            memo[i - 1][i] = s[i] == s[i - 1];
            if (left == right && memo[i - 1][i]) left = i - 1, right = i;
        }
        for (int i = 2; i < len; i++) {
            for (int j = i; j < len; j++) {
                memo[j - i][j] = (s[j - i] == s[j]) && memo[j - i + 1][j - 1];
                if (memo[j - i][j] && (i + 1) > mxLen) mxLen = i + 1, left = j - i, right = j; 
            }
        }

        string res = "";
        while (left <= right) res += s[left], left++;
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();
    string s = "iaiadaiadak";
    cout << soln->longestPalindrome(s) << endl;
    return 0;
}