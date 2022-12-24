#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 104
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <pair <pair <int, int>, int>> task;
int n;

int upperBound(int val)
{
    int low = 0, high = n, ans = n;

    while (low <= high) {
        int mid = (low + high) >> 1;
        if (task[mid].first.first <= val) low = mid + 1;
        else ans = mid, high = mid - 1;
    }
    return ans;
}

int maxProfit(int cur)
{
    if (cur >= n) return 0;

    int p1 = maxProfit(cur + 1);
    int p2 = task[cur].second + maxProfit(upperBound(task[cur].first.second));
    return max(p1, p2);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, f, p;
        cin >> s >> f >> p;
        task.push_back({{s, f}, p});
    }
    sort(task.begin(), task.end());
    for (auto xx: task) cout << xx.first.first << ' ' << xx.first.second << ' ' << xx.second << endl;

    cout << "Max Profit = " << maxProfit(0) << endl;
    return 0;
}