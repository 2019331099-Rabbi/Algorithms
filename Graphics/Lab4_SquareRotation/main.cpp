#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
#define ld long double
#define f first
#define s second
#define limit 1e-6
using namespace std;

long double wx_mn, wx_mx, wy_mn, wy_mx;
long double vx_mn, vx_mx, vy_mn, vy_mx;

struct Point {
    long double x;
    long double y;
    Point() : x(0), y(0) {}
    Point(long double _x, long double _y) : x(_x), y(_y) {}
};

struct LineSegment {
    long double xi, yi;
    long double xf, yf;
    LineSegment(ld _xi, ld _yi, ld _xf, ld _yf) : xi(_xi), yi(_yi), xf(_xf), yf(_yf) {}
};

vector <LineSegment> clippedSegments;

void setPixel(float x, float y){
    glVertex3f(x, y, 0.0);
}

int get_mask(Point p)
{
    int tmp = 0;
    if(p.x < wx_mn) tmp |= 1;
    if(p.x > wx_mx) tmp |= 2;
    if(p.y < wy_mn) tmp |= 4;
    if(p.y > wy_mx) tmp |= 8;
    return tmp;
}

void viewportTransformation(vector<LineSegment> &v)
{
    long double kx = (vx_mx - vx_mn) / (wx_mx - wx_mn);
    long double ky = (vy_mx - vy_mn) / (wy_mx - wy_mn);

    for (int i = 0; i < v.size(); i++) {
        v[i].xi = kx * (v[i].xi - wx_mn) + vx_mn;
        v[i].yi = ky * (v[i].yi - wy_mn) + vy_mn;

        v[i].xf = kx * (v[i].xf - wx_mn) + vx_mn;
        v[i].yf = ky * (v[i].yf - wy_mn) + vy_mn;
    }
}

void drawViewport(long double x_mn, long double y_mn, long double x_mx, long double y_mx)
{
    glBegin(GL_POLYGON);
    glColor3f(.8, .8, .8);
    setPixel(x_mn, y_mn);
    setPixel(x_mx, y_mn);
    setPixel(x_mx, y_mx);
    setPixel(x_mn, y_mx);
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawViewport(vx_mn, vy_mn, vx_mx, vy_mx);

    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    setPixel(-20, 0);
    setPixel(20, 0);
    setPixel(0, -20);
    setPixel(0, 20);
    glEnd();

    viewportTransformation(clippedSegments);

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i < clippedSegments.size(); i++) {
        LineSegment &segment = clippedSegments[i];
        setPixel(segment.xi, segment.yi);
        setPixel(segment.xf, segment.yf);
    }
    glEnd();

    glFlush();
}

Point clip(Point p, long double m)
{
    int cnt = 10;
    int mask = get_mask(p);
    long double im = 1.0 / m;
    while (mask && cnt) {
        if (mask & 1) {
            Point tmp;
            tmp.x = wx_mn;
            tmp.y = p.y + m * (tmp.x - p.x);
            p = tmp;
            mask = get_mask(p);
        }
        if(mask & 2) {
            Point tmp;
            tmp.x = wx_mx;
            tmp.y = p.y + m * (tmp.x - p.x);
            p = tmp;
            mask = get_mask(p);
        }
        if(mask & 4) {
            Point tmp(0.0, 0.0);
            tmp.y = wy_mn;
            tmp.x = p.x + im * (tmp.y - p.y);
            p = tmp;
            mask = get_mask(p);
        }
        if(mask & 8) {
            Point tmp(0.0, 0.0);
            tmp.y = wy_mx;
            tmp.x = p.x + im * (tmp.y - p.y);
            p = tmp;
            mask = get_mask(p);
        }
        cnt--;
    }
    return p;
}

void input()
{
    cin >> wx_mn >> wy_mn >> wx_mx >> wy_mx;
    cin >> vx_mn >> vy_mn >> vx_mx >> vy_mx;
    int n;
    cin >> n;
    while (n--) {
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        int mask1 = get_mask(p1);
        int mask2 = get_mask(p2);
        if (mask1 == 0 && mask2 == 0) {
            // Completely Inside
            clippedSegments.push_back(LineSegment(p1.x, p1.y, p2.x, p2.y));
        }
        else if ((mask1 & mask2) != 0) {
            // Completely Outside
            // Ignore
        }
        else {
            // Clipping Candidate
            long double m = (p2.y - p1.y) / (p2.x - p1.x);
            p1 = clip(p1, m);
            p2 = clip(p2, m);
            mask1 = get_mask(p1);
            mask2 = get_mask(p2);
            if (mask1 == 0 && mask2 == 0) clippedSegments.push_back(LineSegment(p1.x, p1.y, p2.x, p2.y));
        }
    }
}

void init(){
    input();
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20.0, 20.0, -20.0, 20.0, -2000.0, 2000.0);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024,1024);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Demo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
