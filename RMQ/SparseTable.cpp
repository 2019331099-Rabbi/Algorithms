#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 1000000009
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
 * Sparse table. Solves static RMQ problem (without element changes).
 * O(NlogN) on precomputation, O(1) on minimum query.
 *
 * Based on the problem RMQSQ from SPOJ.com:
 * https://cses.fi/problemset/task/1647/
 */


int logs[sz];
int sptable[18][sz];

void computeLogs(int n)
{
    logs[1] = 0;
    for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
}

void buildTable(int n)
{
    for (int i = 1; i <= logs[n]; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            sptable[i][j] = min(sptable[i - 1][j], sptable[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int rmq(int l, int r)
{
    int p = logs[r - l + 1];
    return min(sptable[p][l], sptable[p][r - (1 << p) + 1]);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, q;

    cin >> n >> q;
    computeLogs(n);
    for (int i = 0; i < n; i++) cin >> sptable[0][i];
    buildTable(n);

    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << rmq(l - 1, r - 1) << endl;
    }
    return 0;
}