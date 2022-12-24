#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
********** Problem 3 ************
Given a 3 x N grid. How many way you can cover the whole grid using 3 x 1 and 3 x 2 tiles?
NB: Rotation of tiles is allowed here.

Recurrence relation: f(n) = f(n - 1) + f(n - 2) + 3 * f(n - 3)
base case: f(1) = 1, f(2) = 2, f(3) = 6
*/

int64_t memo[sz];

int64_t tiling(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 6;
    if (memo[n] != -1) return memo[n];
    return memo[n] = tiling(n - 1) + tiling(n - 2) + 3 * tiling(n - 3);
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    for (int i = 1; i <= 10; i++) cout << i << ' ' << tiling(i) << endl;
    return 0;
}