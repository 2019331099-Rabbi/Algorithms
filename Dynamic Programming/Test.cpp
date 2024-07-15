#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n, w, arr[sz];

int coinChange(int pos, int amount)
{
    if (amount < 0) return inf;
    if (pos == n) {
        if (amount == 0) return 0;
        else return inf;
    }
    int cnt1 = 1 + coinChange(pos + 1, amount - arr[pos]);
    int cnt2 = coinChange(pos + 1, amount);
    return min(cnt1, cnt2);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << coinChange(0, w) << endl;

}