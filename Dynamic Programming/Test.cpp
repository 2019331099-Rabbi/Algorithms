#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 12
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Given A and B. If we write from A to B, how many zeroes will be write down?
1 <= A <= B <= 1000000000
*/

int dp2(int pos, int isSmall, string &str)
{
    if (pos == str.size()) return 1;
    
    int ans = 0;
    int lim = (isSmall)?(9):(str[pos] - '0');
    for (int i = 0; i <= lim; i++) ans += dp2(pos + 1, isSmall | (i < lim), str);
    return ans;
}

int dp1(int pos, int hasStarted, int isSmall, string &str)
{
    if (pos == str.size()) return 0;
    
    int lim = (isSmall)?(9):(str[pos] - '0');
    int ans = 0;
    for (int i = 0; i <= lim; i++) {
        ans += dp1(pos + 1, hasStarted | (i != 0), isSmall | (i < lim), str);
        if (hasStarted && !i) ans += dp2(pos + 1, isSmall | (i < lim), str);
    }
    return ans;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string a, b;
    cin >> a >> b;

    cout << dp1(0, 0, 0, b) << endl;
    a = to_string(stoi(a) - 1);
    cout << dp1(0, 0, 0, a) << endl;
    return 0;


}