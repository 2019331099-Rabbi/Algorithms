#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
********** Problem 4 ************
Given an array of n integers. Find a subsequence of this array(Ab1, Ab2, Ab3, ......) to maximize the
following expression.
Ab1 - Ab2 + Ab3 - Ab4 + .............

NB: Can take two consequtive numbers.

Test Case
5
3 1 -1 100 2
Output = 104
*/
int arr[sz], memo[sz][2];
int n;

int maxSum(int cur, int flag)
{
    if (cur >= n) return 0;
    if (memo[cur][flag] != -1) return memo[cur][flag];
    return memo[cur][flag] = max(maxSum(cur + 2, !flag) + ((flag)?1:(-1)) * arr[cur], maxSum(cur + 1, flag));
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
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << maxSum(0, 1) << endl;

    return 0;
}