#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Given n matrix with their dimension.
3
2 3 4 2
2
2 3 4
3
1 2 3 4

Explanation: There is 3 matrix. Their dimesions are:
M1: 2 x 3
M2: 3 x 4
M3: 4 x 2
Find out the minimum number of operation needed to multiply them.
*/

int n, memo[sz][sz], dim[sz + 2];

int mcm(int left, int right)
{
    if (left == right) return 0;
    if (memo[left][right] != -1) return memo[left][right];

    int ans = inf;
    for (int i = left; i < right; i++) {
        int val = mcm(left, i) + mcm(i + 1, right) + dim[left - 1] * dim[i] * dim[right];
        ans = min(ans, val);
    }
    return memo[left][right] = ans;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> n;
    for (int i = 0; i <= n; i++) cin >> dim[i];
    cout << mcm(1, n) << endl;

    return 0;
}