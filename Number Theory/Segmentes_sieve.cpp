#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define endl '\n'
#define ll long long
#define pb push_back
#define pi 3.14159265358979323846264338327950288419716939937510
#define RUN_FAST ios::sync_with_stdio(false);
#define sz 32000
using namespace std;

bool siv[sz];
vector <int> primes;

//bool isprime(int n)
//{
//    bool flag=siv[n];
//    if (n<2) return true;
//    if (n==2) return false;
//    if (n%2==0) return true;
//    return flag;
//}

void chk()
{
    int i, j, limit=sqrt(sz+1);
    for (i=3; i<=limit; i+=2) {
        if (!siv[i]) {
            for (j=i*i; j<=sz; j+=i+i)
                siv[j]=true;
        }
    }
    primes.push_back(2);
    for (i=3; i<sz; i+=2) {
        if (!siv[i]) primes.push_back(i);
    }
}

void segsiv(ll l, ll r)
{
    ll tmp, tmp1=r-l+1, limit, i, j, tmp2;
    bool seg[tmp1]={false};
    limit=sqrt(r+1);
    for (i=0; primes[i]<=limit; i++) {
        tmp=primes[i];
        tmp2=(l/tmp)*tmp;
        if (tmp2<l) tmp2+=tmp;
        //cout << tmp2 << ' ' << tmp << endl;
        //cout << tmp << ' ' << tmp2 << endl;
        for (j=tmp2; j<=r; j+=tmp) {
            seg[j-l]=true;
//            cout << j << ' ' << j-l << ' ';
        }
//        cout << endl;
//        for (int k=0; k<tmp1; k++) cout << seg[k] << ' ';
//        cout << endl;
        if (tmp2==tmp) seg[tmp-l]=false;
    }
    if (l==1) seg[0]=true;
//    for (int k=0; k<tmp1; k++) cout << seg[k] << ' ';
//        cout << endl;

    for (i=0; i<tmp1; i++) {
        if (!seg[i]) cout << l+i << endl;
    }
    cout << endl;
}

int main()
{
    RUN_FAST;
    chk();
    int T;
    ll l, r;
    cin >> T;
    while (T--) {
        cin >> l >> r;
        segsiv(l, r);
    }
    return 0;
}
