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
Given an array of n integers. Find a subsequence of this array to maximize the
sum of the subsequence.
NB: Can't take two consequtive numbers.

Test Case
5
7 10 1 -2 3
Output = 13
*/
int arr[sz], memo[sz];
int n;

int maxSum(int cur)
{
    if (cur >= n) return 0;
    if (memo[cur] != -1) return memo[cur];
    return  memo[cur] = max(arr[cur] + maxSum(cur + 2), maxSum(cur + 1));
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
    cout << maxSum(0) << endl;

    return 0;
}