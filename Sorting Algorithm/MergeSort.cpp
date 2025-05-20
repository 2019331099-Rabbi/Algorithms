#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10000
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;
using namespace std::chrono;

//int row4[]={0, 0, -1, 1};
//int col4[]={1, -1, 0, 0};

//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};

//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void merge(int left, int right, int mid, vector <int> &nums)
{
    int llen = mid - left + 1, rlen = right - mid;
    vector <int> lnums, rnums;
    for (int i = left; i <= mid; i++) lnums.push_back(nums[i]);
    for (int i = mid + 1; i <= right; i++) rnums.push_back(nums[i]);

    int lpos = 0, rpos = 0;
    while (lpos < llen && rpos < rlen) {
        if (lnums[lpos] <= rnums[rpos]) nums[left++] = lnums[lpos++];
        else nums[left++] = rnums[rpos++];
    }
    while (lpos < llen) nums[left++] = lnums[lpos++];
    while (rpos < rlen) nums[left++] = rnums[rpos++];
}

void mergeSort(int left, int right, vector <int> &nums)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(left, mid, nums);
    mergeSort(mid + 1, right, nums);
    merge(left, right, mid, nums);
} 

int main()
{
    RUN_FAST; cin.tie(nullptr);
    vector <int> nums = {-1, 5, 3, 4, 0};
    mergeSort(0, nums.size() - 1, nums);

    for (auto xx: nums) cout << xx << ' ';
    cout << endl;
}
