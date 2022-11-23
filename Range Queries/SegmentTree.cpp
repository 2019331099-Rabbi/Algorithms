#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t tree[3 * sz], arr[sz];

void init(int node, int l, int r)
{
	if (l == r) {
		tree[node] = arr[l];
		return;
	}
	int a = node * 2;
	int b = a + 1;
	int m = (l + r) / 2;

	init(a, l, m);
	init(b, m + 1, r);
	tree[node] = tree[a] + tree[b];
}

void update(int node, int l, int r, int x, int64_t val)
{
	//x = which index we have to update
	//val = updated value
	if (r < x || l > x) return;
	if (l == r && l == x) {
		tree[node] = val;
		return;
	}
	int a = node * 2;
	int b = a + 1;
	int m = (l + r) / 2;

	update(a, l, m, x, val);
    update(b, m + 1, r, x, val);
	tree[node] = tree[a] + tree[b];
}

int64_t query(int node, int l, int r, int x, int y)
{
	/*
	x y -> sum of range [x, y]
	l r -> currenty where are we. if [l, r] contains completly inside [x, y] we return the entire value of [l, r].
	Othewise it means [l, r] and [x, y] overlap. So we go down again to get into [x, y].
	*/
	if (r < x || l > y) return 0;
	if (l >= x && r <= y) return tree[node];
	
	int a = node * 2;
	int b = a + 1;
	int m = (l + r) / 2;
	return query(a, l, m, x, y) + query(b, m + 1, r, x, y);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
	int n, q;

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);

	while (q--) {
		int c, a, b;
		cin >> c >> a >> b;
        if (c == 1) update(1, 1, n, a, b);
        else cout << query(1, 1, n, a, b) << endl;
	}
	return 0;
}