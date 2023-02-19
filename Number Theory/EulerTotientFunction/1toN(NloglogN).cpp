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

int main()
{
    RUN_FAST; //cin.tie(nullptr);
    phi_1toN();

    int T, n;

    cin >> T;
    while (T--) {
        cin >> n;
        cout << "Totient of " << n << " is " << phi[n] << endl;
    }
    return 0;
}
