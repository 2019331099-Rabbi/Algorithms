#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct point
{
    int x, y;
    bool operator<(point other)
    {
        if(x == other.x)
            return y < other.y;
        return x < other.x;
    }
};


int orientation(point p1, point p2, point p3)
{
    int val = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if (val < 0) return -1;
    else if (val > 0) return 1;
    return 0;
}

void graphamScan(int n, vector <point> points)
{
    sort(points.begin(), points.end());
    vector<point> hull;
    
	for(int i=0;i<points.size();i++){
		while(hull.size()>=2 && orientation(hull[hull.size()-2], hull[hull.size()-1], points[i])<=0){
			hull.pop_back();
		}
		hull.push_back(points[i]);
	}
	for(int i=points.size()-2;i>=0;i--){
		while(hull.size()>=2 && orientation(hull[hull.size()-2], hull[hull.size()-1], points[i])<=0){
			hull.pop_back();
		}
		hull.push_back(points[i]);
	}
 
    
    cout << "Points of Convex Hull in anticlockwise:" << endl;
    for (auto xx: hull) cout << xx.x << ' ' << xx.y << endl;
    

    // point p1 = {4, 4};
    // point p2 = {3, 3};
    // point p3 = {3, 1};
    // cout << orientation(p1, p2, p3) << endl;;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    

    
    cin >> n;vector <point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    graphamScan(n, points);
    return 0;
    
}