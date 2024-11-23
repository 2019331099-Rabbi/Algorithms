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
You are given an numsay of integers. Find the longest increasing subsequence of the given numsay.
Test Cases
7
3 4 -1 0 6 2 3
output: 4
*/

int LIS(vector <int> &nums)
{
    int n = nums.size();
    vector <int> lis(n, 1);
    // Each element in the numsay represents the length of the LIS ending at that index
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    return *max_element(lis.begin(), lis.end());
}

void LIS_sequence(vector <int> &nums)
{
    int n = nums.size();
    vector <int> lis(n, 1);
    vector <int> prev(n, -1);

    int endIdx = 0, mxLen = -1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
        if (lis[i] > mxLen) {
            mxLen = lis[i];
            endIdx = i;
        }
    }

    stack <int> seq;
    while (endIdx != -1) {
        seq.push(nums[endIdx]);
        endIdx = prev[endIdx];
    }
    while (!seq.empty()) {
        cout << seq.top() << ' ';
        seq.pop();
    }
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    cin >> n;
    vector <int> nums = {10, 22, 9, 33, 21, 50, 41, 45};
    
    cout << "Length of LIS: " << LIS(nums) << endl;
    cout << "LIS sequence: ";
    LIS_sequence(nums);

    return 0;
}