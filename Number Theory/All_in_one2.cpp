#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

bool siv[sz + 1];
vector <int> primes;

void gen_p()
{
    for (int i = 3; i * i <= sz; i += 2) {
        if (!siv[i]) {
            for (int j = i * i; j <= sz; j += i + i) siv[j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= sz; i += 2) if (!siv[i]) primes.push_back(i);
}

vector <pair <int, int>> pFactors(int n)
{
    vector <pair <int, int>> factors;

    int tmpn = n;
    for (int i = 0; primes[i] * primes[i] <= n; i++) {
        int p = primes[i], cnt = 0;
        while (tmpn % p == 0) {
            tmpn /= p;
            cnt++;
        }
        if (cnt > 0) factors.push_back({p, cnt});
    }
    if (tmpn > 1) factors.push_back({tmpn, 1});
    return factors;
}

int totalDiv(int n)
{
    vector <pair <int, int>> factors = pFactors(n);

    int tot = 1;
    for (auto xx: factors) tot *= (xx.second + 1);
    return tot;
}



int Pow(int b, int p)
{
    if (!p) return 1;
    if (p & 1) return b * Pow(b, p - 1);
    int tmp = Pow(b, p / 2);
    return tmp * tmp;
}

int sumDiv(int n)
{
    vector <pair <int, int>> factors = pFactors(n);

    int sum = 1;

    for (auto xx: factors) {
        int b = xx.first;
        int p = xx.second;
        int tmp = Pow(b, p + 1);

        sum *= (tmp - 1) / (b - 1);
    }
    return sum;
}

void solve(int T)
{
    int n;
    cin >> n;

    vector <pair <int, int>> factors = pFactors(n);
    cout << "Prime factorization of " << n << endl;
    for (auto xx: factors) cout << xx.first << ' ' << xx.second << endl;

    cout << "Total divisors of " << n << " = " << totalDiv(n) << endl;
    cout << "Sum of divisors of " << n << " = " << sumDiv(n) << endl;

    cout << endl;

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    gen_p();

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}