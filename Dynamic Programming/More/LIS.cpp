#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------Longest Increasing Subsequence-------------------
You are given an array of integers. Find the longest increasing subsequence of the given array.
Test Cases
7
3 4 -1 0 6 2 3
output: 4
*/

int LIS(int n, vector <int> &arr)
{
    vector <int> lis(n, 1);
    // Each element in the array represents the length of the LIS ending at that index
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    return *max_element(lis.begin(), lis.end());
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    cin >> n;
    vector <int> arr(n);
    for (auto &xx: arr) cin >> xx;
    cout << LIS(n, arr) << endl;

    return 0;
}