#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ALL(v) v.begin(),v.end()
#define endl "\n"
 
#define MAX 2000
#define MOD 1000000007
#define EPS 1e-9
#define PI acos(-1.0)
 
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void prntVec(vector<int> &a){
    for(auto i: a)
        cout<<i<<' ';
    cout<<endl;
}

int sign(double a){
	return a<0?-1:a==0?0:1;
}

struct PT{
	double x,y;
	PT(){}
	PT(double x_,double y_) {x = x_; y = y_;}

	PT operator + (const PT &p){
		return PT(x+p.x , y+p.y);
	}
	PT operator - (const PT &p){
		return PT(x-p.x , y-p.y);
	}
	PT operator * (double c){
		return PT(c*x , c*y);
	}
	PT operator / (double c){
		return PT(x/c , y/c);
	}
	bool operator == (const PT &p){
		return (x==p.x && y==p.y);
	}
	//didn't understand
	bool operator < (const PT &p){
		return x<p.x || (x==p.x && y<p.y);
	}
	void out(){
		cout << fixed << setprecision(6) << x << ' ' << y << endl;
	}
};


struct Line{
	double a,b,c;
	Line (){a=0.0; b=0.0; c=0.0;}
	Line (double a_, double b_, double c_) {a =a_;b=b_;c=c_;}

	void out(){
		cout<<fixed<<setprecision(6)<<a<<' '<<b<<' '<<c<<endl;
	}
};

void pointsToLines(PT p1,PT p2, Line &l){
	if(fabs(p1.x-p2.x) < EPS){
		l.a =1.0; l.b = 0.0; l.c = -p1.x;
	}else{
		l.a = -(p1.y-p2.y)/(p1.x-p2.x);
		l.b = 1.0;
		l.c = -(l.a*p1.x)-p1.y; 
	}
}

bool areParallel(Line &l1, Line &l2){
	return (fabs(l1.a-l2.a)<EPS && fabs(l1.b-l2.b)<EPS);
}

bool areIntersect(Line l1,Line l2,PT &p){
	if(areParallel(l1,l2)){ return false;}
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// if (fabs(l1.b) > EPS) {p.y = -(l1.a * p.x + l1.c); cout<<"you dog"<<endl;}
	// else {p.y = -(l2.a * p.x + l2.c); cout<<"you bitch"<<endl;}
	p.y = -(l2.a * l1.c - l1.a * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// cout<<p.y<<endl;
	return true;	

}

void verticalLine(Line l,PT p,Line &l1){
	l1.a = -l.b;
	l1.b = l.a;
	l1.c = (l.b*p.x - l.a*p.y);
}

// void sortPoints(vector<PT> &p){
// 	for(int i=0;i<p.size();i++){

// 	}
// }

PT translate(PT v, PT p){
	return v+p;
}

PT scale(PT c, double factor, PT p) {
	return c + (p-c)*factor;
}

PT rot(PT p, double a) {
return PT(p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a));
}

double mag(const PT &p){
	return sqrt(p.x*p.x + p.y*p.y);
}
double dot(PT a, PT b){
	return a.x*b.x + a.y*b.y;
}
double cross(PT a,PT b){
	return a.x*b.y - a.y*b.x;
}
double angle(PT a,PT b){
	return acos(dot(a,b)/(mag(a)*mag(b)));
}

int orientation(PT a,PT b,PT c){
	if(cross(a-b,a-c)<0) return -1;
	else if(cross(a-b,a-c)>0) return 1;
	else return 0;
}

bool inDisk(PT a, PT b, PT p) {
	return dot(a-p, b-p) <= 0;
}

bool onSegment(PT a, PT b, PT p) {
	return orientation(a,b,p) == 0 && inDisk(a,b,p);
}

double computeSignArea(const vector<PT> &p){
	double area=0;
	for(int i=0;i<p.size();i++){
		int j = (i+1)%p.size();
		area += p[i].x*p[j].y - p[i].y*p[j].x;
	}
	return area/2.0;
}

double computeArea(const vector<PT> &p){
	return fabs(computeSignArea(p));
}

bool isLineIntersect(PT a, PT b, PT c, PT d){
	PT e,f,g;
	e = a-b;
	f = a-c;
	g = a-d;

	if(cross(e,f)*cross(e,g)>0) return false;
	else{
		if(cross(c-d,c-a)*cross(c-d,c-b)>0) return false;
		return true;
	}
}



double distPointPoint(PT a,PT b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double areaTriangle(pii &a, pii &b, pii &c){
	return fabs(.5 * (a.first*(b.second-c.second) - a.second*(b.first-c.first) + (b.first*c.second - c.first*b.second)));
}

double areaTriangle(PT &a, PT &b, PT &c){
	return fabs(.5 * (a.x*(b.y-c.y) - a.y*(b.x-c.x) + (b.x*c.y - c.x*b.y)));
}

vector<PT> grahamScan(vector<PT> &points){
	sort(ALL(points));
	for (auto xx: points) cout << xx.x << ' ' << xx.y << endl;
	vector<PT> hull;
	for(int i=0;i<points.size();i++){
		while(hull.size()>=2 && orientation(hull[hull.size()-2], hull[hull.size()-1], points[i])<=0){
			hull.pop_back();
		}
		hull.pb(points[i]);
	}
	for(int i=points.size()-2;i>=0;i--){
		while(hull.size()>=2 && orientation(hull[hull.size()-2], hull[hull.size()-1], points[i])<=0){
			hull.pop_back();
		}
		hull.pb(points[i]);
	}
	return hull;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<PT> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    vector<PT> hull = grahamScan(points);
    for(int i=0;i<hull.size();i++) hull[i].out();              
    // PT a,b;
    // double x1,y1,r1,x2,y2,r2;
    // while(cin>>x1>>y1>>r1>>x2>>y2>>r2){
    // 	a = PT(x1,y1);
    // 	b = PT(x2,y2); 

    // 	if(distPointPoint(a,b)>r1+r2){
    // 		cout<<"NO INTERSECTION"<<endl;
    // 	}
    // 	else if(r1==r2 && a==b){
    // 		cout<<"THE CIRCLES ARE THE SAME"<<endl;
    // 	}
    // 	else{

    // 	}

    // int n,k;
    // cin>>n>>k;
    // vector<PT> arr(n);
    // for(int i=0;i<n;i++){
    // 	cin>>arr[i].x>>[i].y;
    // }
    // int go_away =n-k;
    // while(go_away--){
    // 	arr.pop_back();
    // }

    // cout<<fixed<<setprecision(6)<<computeArea(arr)<<endl;



	



    return 0;
}

