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

vector <int> segSiv(int l, int r)
{
    int len = r - l + 1;
    int seg[len] = {false};

    for (int i = 0; primes[i] * primes[i] <= r; i++) {
        int p = primes[i];
        int strt = (l / p) * p;
        if (strt < l) strt += p;
        for (int j = strt; j <= r; j += p) seg[j - l] = true;
        if (strt == p) seg[p - l] = false;
    }
    if (l == 1) seg[0] = true;
    vector <int> v;
    for (int i = 0; i < len; i++) if (!seg[i]) v.push_back(i + l);
    return v;
}

void solve(int T)
{
    int l, r;

    cin >> l >> r;
    vector <int> segP = segSiv(l, r);
    for (auto xx: segP) cout << xx << ' ';
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
