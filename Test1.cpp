#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> primes;
bool siv[sz + 1];

void genp()
{
    int lim = sqrt(sz + 1) + 1;
    for (int i = 3; i < lim; i += 2) {
        if (!siv[i]) {
            for (int j = i * i; j < sz; j += i + i) siv[j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 3; i < sz; i += 2) if (!siv[i]) primes.push_back(i);
}

void factors(int n)
{
    vector <pair <int, int>> pr;
    int totDiv = 1;
    for (int i = 0; primes[i] * primes[i] <= n; i++) {
        int p = primes[i];
        int cnt = 0;

        while (n % p == 0) n /= p, cnt++;
        pr.push_back({p, cnt});
        totDiv *= (cnt + 1);
    }
    if (n > 1) pr.push_back({n, 1}), totDiv *= 2;
    for (auto xx: pr) cout << xx.first << ' ' << xx.second << endl;
    cout << "Total divisors = " << totDiv << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    genp();

    int T, n;
    
    cin >> T;
    while (T--) {
        cin >> n;
        cout << "Factorization of " << n << endl;
        factors(n);
    }
    return 0;
}