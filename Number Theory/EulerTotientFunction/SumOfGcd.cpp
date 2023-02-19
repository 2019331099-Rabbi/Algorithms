#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10000010
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

int phi[sz+1];

void phi_1toN()
{
    int i, j;
    for (i=1; i<sz; i++) phi[i]=i;

    for (i=2; i<sz; i++) {
        if (phi[i]==i) {
            for (j=i; j<sz; j+=i) {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}



int gcd_sum(int n)
{
    int i, d1, d2, res=0;
    for (i=1; i*i<=n; i++) {
        if (n%i==0) {
            d1=i;
            d2=n/i;
            res+=d1*phi[n/d1];
            if (d1!=d2) res+=d2*phi[n/d2];
        }
    }
    return res;
}

int main()
{
    RUN_FAST; //cin.tie(nullptr);
    phi_1toN();

    int T, n;

    cin >> T;
    while (T--) {
        cin >> n;
        cout << "sum of all GCD for " << n << " is " << gcd_sum(n) << endl;
    }
    return 0;
}
