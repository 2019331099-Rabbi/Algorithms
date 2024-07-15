#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e18
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
You are given a text and pattern. You have to find out weather the given pattern
is a substring of the text or not. If yes, print the index.

Test Case 1
abdxabddabdabddabddabcy
abddabcy

Test Case 2
abcabcd
abcd

shahedshahedshahedshAhed
shahed

*/

vector <int> generateLPS(string pattern)
{
    int len = pattern.size(), i = 0, j = 1;
    vector <int> lps(len);

    lps[0] = 0;
    while (j < len) {
        if (pattern[i] == pattern[j]) {
            lps[j] = i + 1;
            i++, j++;
        }
        else {
            if (!i) lps[j] = 0, j++;
            else i = lps[i - 1];
        }
    }
    return lps;
}

void KMP(string text, string pattern)
{
    vector <int> lps = generateLPS(pattern);
    
    int i = 0, j = 0, tlen = text.size(), pLen = pattern.size();
    vector <int> indxPos;

    while (i < tlen) {
        if (text[i] == pattern[j]) i++, j++;
        else {
            if (!j) i++;
            else j = lps[j - 1];
        }
        if (j == pLen) {
            indxPos.push_back(i - pLen);
            j = lps[j - 1];
        }
    }
    cout << "pattern position(s) in text:" << endl;
    for (auto xx: indxPos) cout << xx << ' ';
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string text, pattern;

    cin >> text >> pattern;
    KMP(text, pattern);

    return 0;
}