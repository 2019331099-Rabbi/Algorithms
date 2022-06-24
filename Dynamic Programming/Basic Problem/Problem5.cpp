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
1 * Ab1 + 2 * Ab2 + 3 * Ab3 + .............

NB: Can take two consequtive numbers.

Test Case
5
3 1 -1 100 2
Output = 412
*/
int arr[sz], memo[sz][sz];
int n;

int maxSum(int cur, int cnt)
{
    if (cur >= n) return 0;
    if (memo[cur][cnt] != -1) return memo[cur][cnt];
    return memo[cur][cnt] = max(cnt * arr[cur] + maxSum(cur + 1, cnt + 1), maxSum(cur + 1, cnt));
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