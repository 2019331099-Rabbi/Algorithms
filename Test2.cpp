#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct point
{
    int x, y;
}points[sz];

bool orientation(point p1, point p2, point p3)
{
    int val = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return val < 0;
}

void jarvisMarch(int n)
{
    int strt = 0;
    for (int i = 1; i < n; i++) if (points[i].y < points[strt].y) strt = i;

    int p = strt, q;
    vector <int> hull;

    do
    {
        hull.push_back(p);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (i == p || i == q) continue;
            if (orientation(points[p], points[q], points[i])) q = i;
        }
        p = q;
    } while (p != strt);
    for (auto xx: hull) cout << points[xx].x << ' ' << points[xx].y << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
    jarvisMarch(n);
    return 0;
}