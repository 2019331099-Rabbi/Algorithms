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
    int m = (l + r) >> 1;

    init(a, l, m);
    init(b, m + 1, r);
    tree[node].sum = tree[a].sum + tree[b].sum;
}

void push(int node, int l, int r)
{
    if (tree[node].prop == 0) return;

    tree[node].sum += (r - l + 1) * tree[node].prop;
    if (l != r) {
        tree[node * 2].prop += tree[node].prop;
        tree[node * 2 + 1].prop += tree[node].prop;
    }
    tree[node].prop = 0;
}

void pull(int node)
{
    int a = node << 1;//Left child: node * 2
    int b = (node << 1) | 1;//Right child: (node * 2) + 1
    tree[node].sum = tree[a].sum + tree[b].sum;
}

void update(int node, int l, int r, int x, int y, int64_t val)
{
    /*
    [l, r] -> Currently where we are
    [x, y] -> The range we want to update
    val -> The value we want to add with everyone in [x, y] range

    */
    push(node, l, r);//Update the propagation value
    if (r < x || l > y) return;
    if (l >= x && r <= y) {
        tree[node].prop += val;
        push(node, l, r);
        return;
    }

    int a = node << 1;//Left child: node * 2
    int b = (node << 1) | 1;//Right child: (node * 2) + 1
    int m = (l + r) >> 1;

    update(a, l, m, x, y, val);
    update(b, m + 1, r, x, y, val);
    pull(node);//Update the node with it's left child and right child
    
}

int64_t combine(int64_t lcResult, int64_t rcResult)
{
    return lcResult + rcResult;
}

int64_t query(int node, int l, int r, int x, int y)
{
    push(node, l, r);
    if (r < x || l > y) return 0;
    if (l >= x && r <= y) return tree[node].sum;

    int a = node * 2;
    int b = a + 1;
    int m = (l + r) >> 1;
    return combine(query(a, l, m, x, y), query(b, m + 1, r, x, y));
    //Combine the left child and right child result
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, q;
 
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
 
    while (q--) {
        int c;
        cin >> c;
        if (c == 2) {
            int k;
            cin >> k;
            cout << query(1, 1, n, k, k) << endl;
        }
        else {
            int a, b;
            int64_t val;
            cin >> a >> b >> val;
            update(1, 1, n, a, b, val);
        }
    }
    return 0;
}