#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int lr[sz][sz], rl[sz][sz];

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, q;

    cin >> n >> q;
    vector <string> v(n);
    for (auto &xx: v) cin >> xx;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i - 1][j - 1] == '*') lr[i][j] = rl[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            lr[i][j] += lr[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n - 1; j >= 1; j--) {
            rl[i][j] += rl[i][j + 1];
        }
    }
    //print(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            lr[j][i] += lr[j - 1][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n - 1; j >= 1; j--) {
            rl[j][i] += rl[j + 1][i];
        }
    }

    //print(n);

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = lr[n][n];
        
        ans -= lr[n][y1 - 1];
        ans -= rl[1][y2 + 1];
        ans -= lr[x1 - 1][y2];
        ans -= rl[x2 + 1][y1];
        ans += lr[x1 - 1][y1 - 1];
        ans += rl[x2 + 1][y2 + 1];
        cout << ans << endl;
    }
    return 0;
}