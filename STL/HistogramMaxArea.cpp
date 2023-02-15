#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    int n;

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    stack <int> stk;

    stk.push(0);
    int nextsmaller[n];
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[stk.top()]) {
            stk.push(i);
            continue;
        }
        while (stk.size() && arr[i] < arr[stk.top()]) {
            nextsmaller[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (stk.size()) {
        nextsmaller[stk.top()] = n;
        stk.pop();
    }
    int prevsmaller[n];
    stk.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= arr[stk.top()]) {
            stk.push(i);
            continue;
        }
        while (stk.size() && arr[i] < arr[stk.top()]) {
            prevsmaller[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (stk.size()) {
        prevsmaller[stk.top()] = -1;
        stk.pop();
    }
    int mxarea = -inf;
    for (int i = 0; i < n; i++) mxarea = max(mxarea, (nextsmaller[i] - prevsmaller[i] - 1) * arr[i]);
    cout << "Case " << T << ": " << mxarea << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}