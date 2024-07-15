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
in O(N) time.

Tutorial
https://www.youtube.com/watch?v=nbTSfrEfo6M
*/

class Solution {
public:
    string preprocess(const string& s) {
        if (s.empty()) return "$@";
        string tmps = "$";
        for (auto ch: s) tmps += '#', tmps += ch;
        tmps += "#@";
        return tmps;
    }
    string longestPalindrome(string s) {
        string T = preprocess(s);
        vector <int> P(T.size(), 0);

        int C = 0, R = 0;
        for (int i = 1; i < T.size() - 1; i++) {
            int iMirror = 2*C - i; // c - (i - c)
            if (i < R) {
                P[i] = min(R - i, P[iMirror]);
            }
            else P[i] = 0;

            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;
            if (i + P[i] > R) R = i + P[i], C = i;
        }
        int cnt = 0;
        for (int i = 1; i < T.size() - 1; i++) {
            if (P[i] > cnt) cnt = P[i], C = i;
        }
        int start = (C - 1 - cnt) / 2;
        return s.substr(start, cnt);
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