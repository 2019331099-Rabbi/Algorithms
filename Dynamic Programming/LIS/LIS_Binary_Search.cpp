#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
--------------Longest Increasing tailsequence-------------------
You are given an numsay of integers. Find the longest increasing tailsequence of the given numsay.
Test Cases
7
3 4 -1 0 6 2 3
output: 4
*/

/*
What is tail?
In this approach, the tail array doesn't actually store the subsequences themselves. Instead, it stores the smallest possible ending values of increasing subsequences of various lengths.
The key idea is that each element in the tail array represents the smallest possible end element of an increasing subsequence of a particular length.
*/

int LIS(vector <int> &nums)
{
    vector <int> tail;
    for (auto &num: nums) {
        if (tail.empty() || tail[tail.size() - 1] < num) tail.push_back(num);
        else {
            int pos = lower_bound(tail.begin(), tail.end(), num) - tail.begin(); // Find the index of the first element >= num
            tail[pos] = num; // Replace that number with num
        }
    }
    return tail.size();
}

void LIS_sequence(vector <int> &nums)
{
    int n = nums.size();
    vector<int> tail; // Stores the smallest end values of LIS for different lengths
    vector<int> indices; // Stores indices of elements in in tail
    vector<int> prev(n, -1); // Tracks the previous index of each element in LIS

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(tail.begin(), tail.end(), nums[i]) - tail.begin();
        
        // If nums[i] extends the LIS
        if (pos == tail.size()) {
            tail.push_back(nums[i]);
            indices.push_back(i); // Track the index of this element in 'tail'
        }
        else {
            tail[pos] = nums[i]; // Replace to maintain the smallest possible value
            indices[pos] = i;   // Update the index of this element in 'tail'
        }
        // Update the 'prev' array for reconstruction
        if (pos > 0) prev[i] = indices[pos - 1];
    }

    // Reconstruct the LIS
    stack <int> lis;
    for (int i = indices.back(); i != -1; i = prev[i]) {
        lis.push(nums[i]);
    }
    while (!lis.empty()) {
        cout << lis.top() << ' ';
        lis.pop();
    }
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    cin >> n;
    // vector <int> nums = {10, 22, 9, 33, 21, 50, 41, 45};
    vector <int> nums = {3, 4, -1, 0, 6, 2, 3};
    
    cout << "Length of LIS: " << LIS(nums) << endl;
    cout << "LIS sequence: ";
    LIS_sequence(nums);

    return 0;
}