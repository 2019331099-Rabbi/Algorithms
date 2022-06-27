#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Given A and B. If we write from A to B, how many zeroes will be write down?
1 <= A <= B <= 1000000000
*/

string A, B;
int memo1[10][2][2], memo2[10][2];

int dp2(int pos, int isSmall, string &str)
{
    if (pos == str.size()) return 1;
    if (memo2[pos][isSmall]) return memo2[pos][isSmall];

    int ans = 0, lim = str[pos] - '0';
    if (isSmall) lim = 9;
    for (int i = 0; i <= lim; i++) ans += dp2(pos + 1, isSmall | (i < lim), str);
    return memo2[pos][isSmall] = ans;
}

int dp1(int pos, int isSmall, int hasStarted, string &str)
{
    if (pos == str.size()) return 0;
    if (memo1[pos][isSmall][hasStarted] != -1) return memo1[pos][isSmall][hasStarted];

    int ans = 0, lim = str[pos] - '0';
    if (isSmall) lim = 9;
    for (int i = 0; i <= lim; i++) {
        int val = dp1(pos + 1, isSmall | (i < lim), hasStarted | (i != 0), str);
        if (hasStarted && i == 0) val += dp2(pos + 1, isSmall | (i < lim), str);
        ans += val;
    }
    return memo1[pos][isSmall][hasStarted] = ans;
}

void init()
{
    memset(memo1, -1, sizeof(memo1));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> A >> B;
    cout << dp1(0, 0, 0, B) << endl;
    A = to_string(stoi(A) - 1);

    init();
    cout << dp1(0, 0, 0, A) << endl;
    return 0;

}