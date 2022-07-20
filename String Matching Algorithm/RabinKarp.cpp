#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;
const int c = 26;
const int p = inf;

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

int power[sz];

void generatePower()
{
    power[0] = 1;
    for (int i = 1; i < sz; i++) power[i] = (power[i - 1] * c) % p;
}

void RabinCarp(string& text, string& pattern)
{
    int tlen, pLen, pHash;
    vector <int> indxPos;

    tlen = text.size(), pLen = pattern.size(), pHash = 0;

    for (int i = 0; i < pLen; i++) {
        int hVal = pattern[i] - 'a' + 1;
        pHash = (pHash + hVal * power[pLen - i - 1]) % p;
    }

    int curHash = 0;
    for (int i = 0; i < pLen; i++) {
        int hVal = text[i] - 'a' + 1;
        curHash = (curHash + hVal * power[pLen - i - 1]) % p;
    }

    for (int i = 0; i <= tlen - pLen; i++) {
        cout << curHash << ' ' << pHash << endl;

        if (curHash == pHash) indxPos.push_back(i);

        int hVal = text[i] - 'a' + 1;
        curHash = curHash - (hVal * power[pLen - 1]) % p;
        curHash = (curHash * c) % p;
        
        hVal = text[i + pLen] - 'a' + 1;
        curHash = (curHash + (hVal * power[0]) % p) % p;
        if (curHash < 0) curHash += p;
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

    generatePower();
    RabinCarp(text, pattern);

    return 0;
}