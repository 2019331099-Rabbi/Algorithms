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

int memo[sz][sz], dim[sz + 2];

int mcm(int i, int j)
{
    if (i == j) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    int mn = INT_MAX;
    for (int k = i; k < j; k++) {
        int val = mcm(i, k) + mcm(k + 1, j) + dim[i - 1] * dim[k] * dim[j];
        mn = min(mn, val);
    }
    return memo[i][j] = mn;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;

    cin >> n;
    for (int i = 0; i <= n; i++) cin >> dim[i];

    init();
    cout << "Minimum calculation needed = " << mcm(1, n) << endl;
    return 0;
}