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
        vector <vector <bool>> memo(len + 1, vector <bool>(len + 1, false));
        /*
        What does every element in memo mean here?
        memo[i][j] = true or false
        A substring starts at index i and ends at index j. If this substring is a palindrome then
                  memo[i][j] is true;
        otherwise memo[i][j] = false;

        Here the substring will be a palindrome, if the following two condition meet.
        1. s[i] = s[j] and
        2. The substring s[i+1 : j-1] is a palindrome.
        For example, let s = "abba"
        now "abba" is palindrome, because s[0] = s[3] = a and "bb" is palindrome. For checking the second condition we
        use DP. We save the results in memo.
        */

        int left = 0, right = 0;
        int lps = 1;
        for (int i = 0; i < len; i++) {
            memo[i][i] = true;
            if (s[i] == s[i + 1]) memo[i][i + 1] = true, left = i, right = i + 1;
        }
        /*
        Here we initialize the memo as
        1. All the one length string is palindrome.
        2. We check all the two length substring manually, it is palindrome or not.
        */
        lps = right - left + 1;

        for (int step = 2; step < len; step++) {
            for (int i = 0; i + step < len; i++) {
                int xi = i, yi = i + step;
                if (memo[xi + 1][yi - 1] && s[xi] == s[yi]) {
                    memo[xi][yi] = true;
                    if ((yi - xi + 1) > lps) lps = yi - xi + 1, left = xi, right = yi;
                }
            }
        }
        return s.substr(left, right - left + 1);
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