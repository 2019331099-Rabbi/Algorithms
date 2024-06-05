#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t memo[sz], arr[sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int64_t maxSum(int n)
{
    if (n < 0) return 0;
    if (memo[n] != -1) return memo[n];
    int64_t val1 = maxSum(n - 1);
    int64_t val2 = arr[n] + maxSum(n - 2);
    return memo[n] = max(val1, val2);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << maxSum(n - 1) << endl;

    return 0;

}