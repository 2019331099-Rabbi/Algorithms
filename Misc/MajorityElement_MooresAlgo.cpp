#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

problem link: https://leetcode.com/problems/majority-element/description/

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;
        for (auto xx: nums) {
            if (count == 0) element = xx;
            if (element == xx) count++;
            else count--;
        }
        return element;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {2,2,1,1,1,2,2};
    cout << soln->majorityElement(nums) << endl;


}