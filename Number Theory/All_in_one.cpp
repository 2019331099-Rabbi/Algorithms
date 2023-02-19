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
#define PI acos(-1)
#define RUN_FAST ios::sync_with_stdio(false);
#define sz 1000000
using namespace std;

bool siv[sz+1];
vector <int> primes;

void gen_p()
{
    int i, j, limit=sqrt(sz+1);
    for (i=3; i<=limit; i+=2) {
        if (!siv[i]) {
            for (j=i*i; j<=sz; j+=i+i)
                siv[j]=true;
        }
    }
    primes.push_back(2);
    for (i=3; i<=sz; i+=2)
        if (!siv[i]) primes.push_back(i);
}

void sum_d(vector <pair <int , int> > facts)
{
    int i, l, sum=1, val, pw, tmp;
    l=facts.size();
    for (i=0; i<l; i++) {
        val=facts[i].first;
        pw=facts[i].second;
        tmp=pow(val, pw+1)+0.5;
        sum*=(tmp-1)/(val-1);
    }
    cout << "Sum of all divisors: " << sum << endl;
}

void facotrs(int n)
{
    int i, j, limit=sqrt(n+1), tmp, cnt, tot_div=1, res=n;
    vector < pair <int, int> > facts;
    for (i=0; primes[i]<=limit; i++) {
        tmp=primes[i];
        cnt=0;
        while (n%tmp==0) {
            n/=tmp;
            cnt++;
        }
        tot_div*=(cnt+1);
        facts.push_back({tmp, cnt});
        if (n==1) break;
    }
    if (n>1) facts.push_back({n, 1}), tot_div*=(2);
    for (i=0; i<facts.size(); i++)
        cout << facts[i].first << ' ' << facts[i].second  << endl;
    cout << "Total divisors: " <<tot_div << endl;
    sum_d(facts);
    facts.clear();
}

void segsiv(int l, int r)
{
    int i, j, limit=sqrt(r+1), tmp1, tmp2, tmp=r-l+1;
    bool seg[tmp]={false};
    for (i=0; primes[i]<=limit; i++) {
        tmp1=primes[i];
        tmp2=(l/tmp1)*tmp1;
        if (tmp2<l) tmp2+=tmp1;
        for (j=tmp2; j<=r; j+=tmp1) {
            seg[j-l]=true;
        }
        if (tmp1==tmp2) seg[tmp1-l]=false;
    }
    if (l==1) seg[0]=true;
    for (i=0; i<tmp; i++) {
        if (!seg[i]) cout << i+l << ' ';
    }
    cout << endl;
}

int main()
{
    RUN_FAST;
    gen_p();

    int n, T, l, r;
    ///sieve, prime factorization, Total divisors, Sum of all divisors part
    cin >> T;
    while (T--) {
        cin >> n;
        facotrs(n);
    }

    ///Segmented sieve part
//    cin >> T;
//    while (T--) {
//        cin >> l >> r;
//        segsiv(l, r);
//    }
//    return 0;
}
