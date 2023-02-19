#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 2e9
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row4[]={0, 0, -1, 1};
//int col4[]={1, -1, 0, 0};

//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};

//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int phi(int n)
{
    int i, cnt=0;
    for (i=1; i<=n; i++) {
        if (__gcd(n, i)==1) cnt++;
    }
    return cnt;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    int n;
    cin >> n;
    cout << "Totient of " << n << " is " << phi(n) << endl;

    return 0;
}
