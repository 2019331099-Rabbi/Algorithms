#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100
#define inf 1e18
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
This program finds all possible permutation of n(1 to n) numbers.
How many permutations are possible if we take r things from n things? (n p r)
*/

bool vis[sz];
int n, r, cnt;

void backtracking(vector <int> order)
{
    if (order.size()==r) {
        for (auto xx: order) cout << xx << ' ';
        cout << endl;
        cnt++;
        return;
    }
    for (int i=1; i<=n; i++) {
        if (vis[i]) continue;
        order.push_back(i);
        vis[i]=true;
        backtracking(order);

        vis[i]=false;
        order.pop_back();
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    vector <int> order;

    cin >> n >> r;
    backtracking(order);
    cout << "Total possible permutation = " << cnt << endl;
    return 0;
}
