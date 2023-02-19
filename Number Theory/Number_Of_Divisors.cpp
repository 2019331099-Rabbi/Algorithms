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

void find_d(int n)
{
    int limit, i;
    limit=sqrt(n+1);
    int cnt=0;
    cout << "Limit: " << limit << endl;
    for (i=2; i<=limit; i++) {
        if (n%i==0) cnt+=2;
    }
    if (limit*limit==n) cnt--;
    cout << "Number of divisors: " << cnt+2 << endl;
}

int main()
{
    RUN_FAST;
    int n;
    while (cin >> n) {
        find_d(n);
    }
}
