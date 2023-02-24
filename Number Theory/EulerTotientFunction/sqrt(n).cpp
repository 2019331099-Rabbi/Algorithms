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
    int res=n, i;

    for (i=2; i*i<=n; i++) {
        if (n%i==0) {
            while (n%i==0) n/=i;
            res/=i;
            res*=(i-1);
            /**
            instead of line 27 and 28 we can use res-=res/i;
            */
        }
    }
    if (n>1) res/=n, res*=(n-1);
    return res;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    // int n;
    // cin >> n;
    for (int i = 2; i <= 10; i++) cout << "Totient of " << i << " is " << phi(i) << endl;

    return 0;
}
