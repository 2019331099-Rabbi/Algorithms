#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define RUN_FAST ios::sync_with_stdio(false);
#define sz 500010
using namespace std;

int bigmod(int b, int p, int mod)
{
    int tmp1, tmp2;
    cout << p << endl;
    if (p==0) return 1;
    if (p%2==0) {
        tmp1=bigmod(b, p/2, mod)%mod;
        return (tmp1*tmp1)%mod;
    }
    else {
        tmp1=b%mod;
        tmp2=bigmod(b, p-1, mod)%mod;
        return (tmp1*tmp2)%mod;
    }
}

int main()
{
    RUN_FAST;
    int b, p, mod, tmp;
    cin >> b >> p >> mod;
    tmp=bigmod(b, p, mod);
    cout << tmp << endl;
}
///2563122
///9220942
