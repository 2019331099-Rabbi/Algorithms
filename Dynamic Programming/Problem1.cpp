#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
********** Problem 1 ************
Given a 2 x N grid. How many way you can cover the whole grid using 2 x 1 and 2 x 2 tiles?
NB: Rotation of tiles isn't allowed here.

Recurrence relation: f(n) = f(n - 1) + f(n - 2);
base case: f(1) = 1, f(2) = 2;
*/

int memo[sz];

int tiling(int n)
{
    if (n <= 2) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = tiling(n - 1) + tiling(n - 2);
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    int n;
    cin >> n;
    cout << tiling(n) << endl;

    return 0;
}