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

vector <Point> findPoints_takingX(Point p1, Point p2) {
    vector <Point> points;
    long double m = slope(p1, p2);
    int x = p1.x;
    long double y = (long double)p1.y;

    while (x <= p2.x) {
        points.push_back(Point(x, (int)(y + 0.5)));
        y = y + m;
        x++;
    }
    return points;
}

vector <Point> findPoints_takingY(Point p1, Point p2) {
    vector <Point> points;
    long double m_inv = 1.0 / slope(p1, p2);
    long double x = p1.x;
    int y = p1.y;
    while (y <= p2.y) {
        points.push_back(Point((int)(x + 0.5), y));
        y++;
        x = x + m_inv;
    }
    return points;
}

void ddaLineDrawing(Point p1, Point p2)
{
    long double m = slope(p1, p2);
    vector <Point> points;

    if (0 <= m && m <= 1) points = findPoints_takingX(p1, p2);
    else if (m > 1) points = findPoints_takingY(p1, p2);
    else if (-1 < m && m < 0) {
        p1.y = -p1.y;
        p2.y = -p2.y;
        points = findPoints_takingX(p1, p2);
        for (auto &p: points) p.y = -p.y;
    }
    else {
        swap(p1.x, p1.y);
        swap(p2.x, p2.y);
        p1.y = -p1.y;
        p2.y = -p2.y;
        points = findPoints_takingX(p1, p2);
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

//    Point p1 = Point(2, 6);
//    Point p2 = Point(6, 13);

    Point p1 = Point(-2, 2);
    Point p2 = Point(-10, 10);

    ddaLineDrawing(p1, p2);

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
