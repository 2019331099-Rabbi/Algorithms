#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int xmin = -50, xmax = 50;
int ymin = -50, ymax = 50;

struct Point {
    int x;
    int y;
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

long double slope(Point p1, Point p2);
void setPixel(Point p);
void drawAxis();

vector <Point> findPoints(Point p1, Point p2) {
    vector <Point> points;
    int x = p1.x, y = p1.y;
    int dx = p2.x - p1.x, dy = p2.y - p1.y;
    int ds = 2 * dy, dt = 2 * (dy - dx);
    int d = 2 * dy - dx;

    while (x <= p2.x) {
        points.push_back(Point(x, y));
        if (d < 0) d = d + ds;
        else d = d + dt, y++;
        x++;
    }
    return points;
}

void brasenhamsLineDrawing(Point p1, Point p2)
{
    long double m = slope(p1, p2);
    vector <Point> points;

    cout << m << endl;

    if (0 <= m && m <= 1) {
        points = findPoints(p1, p2);
    }
    else if (m > 1) {
        swap(p1.x, p1.y);
        swap(p2.x, p2.y);
        points = findPoints(p1, p2);
        for (auto &p: points) swap(p.x, p.y);
    }
    else if (-1 < m && m < 0) {
        p1.y = -p1.y;
        p2.y = -p2.y;
        points = findPoints(p1, p2);
        for (auto &p: points) p.y = -p.y;
    }
    else {
        swap(p1.x, p1.y);
        swap(p2.x, p2.y);
        p1.y = -p1.y;
        p2.y = -p2.y;
        points = findPoints(p1, p2);
        for (auto &p: points) {
            p.y = -p.y;
            swap(p.x, p.y);
        }
    }

    for (auto point: points) setPixel(point);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glColor3f(1.0, 1.0, 1.0);  // White

    glBegin(GL_POINTS);

    Point p1 = Point(-2, 2);
    Point p2 = Point(-10, 10);

    brasenhamsLineDrawing(p1, p2);


    glEnd();
    glFlush();
}



void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xmin, xmax, ymin, ymax, -10, 10);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Demo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}


long double slope(Point p1, Point p2)
{
    return (long double)(p2.y - p1.y) / (long double)(p2.x - p1.x);
}

void setPixel(Point p)
{

    glVertex3f(p.x, p.y, 0.0);
}

void drawAxis()
{
    glColor3f(0.0, 1.0, 0.0);  // White color for axes
    glBegin(GL_LINES);

    // X-axis
    glVertex2f(xmin, 0);
    glVertex2f(xmax, 0);

    // Y-axis
    glVertex2f(0, ymin);
    glVertex2f(0, ymax);

    glEnd();
}
