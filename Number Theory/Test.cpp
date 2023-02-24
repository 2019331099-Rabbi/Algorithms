#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int phi[sz + 1];

void phi1ton()
{
    for (int i = 1; i < sz; i++) phi[i] = i;
    
    for (int i = 2; i < sz; i++) {
        if (phi[i] == i) {
            for (int j = i; j < sz; j += i) phi[j] /= i, phi[j] *= (i - 1);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            int d1 = i;
            int d2 = n / i;
            sum += d1 * phi[n / d1];
            if (d1 != d2) sum += d2 * phi[n / d2];
        }
    }
    cout << sum << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    phi1ton();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}