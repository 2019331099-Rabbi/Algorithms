#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct point
{
    int x, y;
}points[sz];

bool clockOrAntiClock(point p, point q, point r)
{
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y - q.y);
    return val < 0;
}

void printResult(vector <point> result)
{
    for (auto xx: result) cout << xx.x << ' ' << xx.y << endl;
}

void jarvisMarch(int n)
{
    int strt = 0;
    for (int i = 1; i < n; i++) if (points[i].x < points[strt].x) strt = i;
    vector <point> result;

    int current = strt, q;

    do
    {
        result.push_back(points[current]);
        q = (current + 1) % n;
        for (int i = 0; i < n; i++) {
            if (i == current || i == q) continue;
            if (clockOrAntiClock(points[current], points[q], points[i])) q = i;
        }
        current = q;
    } while (current != strt);

    printResult(result);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, x, y;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
    }
    jarvisMarch(n);
    return 0;
}
/**

 */