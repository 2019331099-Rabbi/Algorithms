#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
********** Problem 2 ************
Given a 2 x N grid. How many way you can cover the whole grid using 2 x 1 and 2 x 2 tiles?
NB: Rotation of tiles is allowed here.

Recurrence relation: f(n) = f(n - 1) + 2 * f(n - 2);
base case: f(1) = 1, f(2) = 3;
*/

int64_t memo[sz];

int64_t tiling(int cur)
{
    if (cur == 1) return 1;
    if (cur == 2) return 3;
    if (memo[cur] != -1) return memo[cur];
    return memo[cur] = tiling(cur - 1) + 2 * tiling(cur - 2);
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