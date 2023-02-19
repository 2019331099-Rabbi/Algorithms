#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define endl '\n'
#define ll long long
#define pb push_back
#define ppb pop_back
#define pi 3.14159265358979323846264338327950288419716939937510
#define RUN_FAST ios::sync_with_stdio(false);
#define sz 32000
using namespace std;

bool siv[sz+1];
vector <int> primes;

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
    for (i=3; i<=sz; i+=2)
        if (!siv[i]) primes.push_back(i);
}

void factors(int n)
{
    vector < pair<int, int> > fact;
    int cnt, i, j, tmp, limit=sqrt(n+1);
    for (i=0; primes[i]<=limit; i++) {
        tmp=primes[i];
        cnt=0;
        while (n%tmp==0) {
            n/=tmp;
            cnt++;
        }
        fact.push_back({tmp, cnt});
        if (n==1) break;
    }
    if (n>1) fact.push_back({n, 1});
    for (i=0; i<fact.size(); i++)
        cout << fact[i].first << ' ' << fact[i].second << endl;
}

int main()
{
    chk();
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        factors(n);
    }
    return 0;
}
