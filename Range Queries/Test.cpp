#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct info
{
    int64_t sum, prop;
}tree[sz * 3];

int64_t arr[sz];

void init(int node, int l, int r)
{
    if (l == r) {
        tree[node].sum = arr[l];
        return;
    }
    int a = node * 2;
    int b = a + 1;
    int m = (l + r) / 2;

    init(a, l, m);
    init(b, m + 1, r);
    tree[node].sum = tree[a].sum + tree[b].sum;
}

void update(int node, int l, int r, int x, int y, int val)
{
    if (r < x || l > y) return;
    if (l >= x && r <= y) {
        tree[node].sum += (r - l + 1) * val;
        tree[node].prop += val;
        return;
    }
    int a = node * 2;
    int b = a + 1;
    int m = (l + r) / 2;

    update(a, l, m, x, y, val);
    update(b, m + 1, r, x, y, val);
    tree[node].sum = tree[a].sum + tree[b].sum + (r - l + 1) * tree[node].prop;
}

int64_t query(int node, int l, int r, int x, int y, int64_t carry = 0)
{
    if (r < x || l > y) return 0;
    if (l >= x && r <= y) return tree[node].sum + (r - l + 1) * carry;

    int a = node * 2;
    int b = a + 1;
    int m = (l + r) / 2;
    return query(a, l, m, x, y, carry + tree[node].prop) + query(b, m + 1, r, x, y, carry + tree[node].prop);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, q;
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];

}