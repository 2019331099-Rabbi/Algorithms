#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
********** Problem 8 ************
You are given N tasks. Each task has a starting time, finishing time ans profit. You can
do any number of non-overlapping tasks and get the profit associated with them. Your goal
is to maximize total profit.

Test Case
5
1 5 10
4 12 20
13 15 8
7 14 15
8 10 11
Output: 29
*/


int n, memo[sz];
vector <pair <pair <int, int>, int>> tasks;

int upperBound(int cur)
{
    int left = cur + 1, right = n - 1, mid, ans, x = tasks[cur].first.second;

    if (x >= tasks[n - 1].first.first) return n;
    if (x < tasks[0].first.first) return 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (tasks[mid].first.first > x) {
            ans = mid, right = mid - 1;
        }
        else left = mid + 1;
    }
    return ans;
}

int maxProfit(int cur)
{
    if (cur >= n) return 0;
    if (memo[cur] != -1) return memo[cur];

    int next = upperBound(cur);

    int val1 = maxProfit(cur + 1);
    int val2 = maxProfit(next) + tasks[cur].second;
    return memo[cur] = max(val1, val2);
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
    for (int i = 0; i < n; i++) {
        int s, f, p;
        cin >> s >> f >> p;
        tasks.push_back({{s, f}, p});
    }
    sort(tasks.begin(), tasks.end());    
    cout << maxProfit(0) << endl;
    return 0;

}