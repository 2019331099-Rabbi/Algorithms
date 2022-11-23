#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n;

    cin >> n;
    vector <int64_t> v(n);
    for (auto &xx: v) cin >> xx;

    int64_t meh = 0, msf = INT64_MIN;
    for (auto xx: v) {
        meh += xx;
        if (xx > meh) meh = xx;
        if (meh > msf) msf = meh;
    }
    cout << msf << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}