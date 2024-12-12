#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/*
Problem link: https://cses.fi/problemset/task/1651/
*/

void computeLogs(vector <int> &logs)
{
    int n = logs.size();
    logs[0] = logs[1] = 0;
    for (int i = 2; i < n; i++) logs[i] = logs[i/2]+1;
}

void buildTable(vector <int> &nums, vector <int> &logs, vector <vector <int>> &sptable)
{
    int n = nums.size();
    for (int i = 0; i < n; i++) sptable[i][0] = nums[i];
    for (int j = 1; j <= logs[n]; j++) {
        for (int i = 0; i+(1<<j) <= n; i++) {
            sptable[i][j] = min(sptable[i][j-1], sptable[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq(int left, int right, vector <int> &logs, vector <vector <int>> &sptable)
{
    int p = logs[right - left + 1];
    return min(sptable[left][p], sptable[right - (1<<p) + 1][p]);
}

void sparseTable(vector <int> &nums, vector <vector <int>> &queries)
{
    int n = nums.size();
    vector <int> logs(n+1);
    computeLogs(logs);

    vector <vector <int>> sptable(n, vector <int>(logs[n] + 1));
    buildTable(nums, logs, sptable);

    for (auto &query: queries) {
        int left = query[0] - 1;
        int right = query[1] - 1;
        cout << left << ' ' << right << ' ' << rmq(left, right, logs, sptable) << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    vector <int> nums = {3, 2, 4, 5, 1, 1, 5, 3};
    vector <vector <int>> queries = {
        {2, 4},
        {5, 6},
        {1, 8},
        {3, 3}
    };
    sparseTable(nums, queries);
    return 0;
}