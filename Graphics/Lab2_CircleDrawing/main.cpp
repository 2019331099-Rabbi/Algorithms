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

void findPoints(Point p, vector <Point> &points)
{
    int x = p.x, y = p.y;
    points.push_back(Point(x, y));
    points.push_back(Point(-x, y));
    points.push_back(Point(-x, -y));
    points.push_back(Point(x, -y));
    points.push_back(Point(y, x));
    points.push_back(Point(-y, x));
    points.push_back(Point(-y, -x));
    points.push_back(Point(y, -x));
}

void bresenhamCircleDrawing(Point center, int radius)
{
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    cout << center.x << ' ' << center.y << ' ' << radius << endl;

    vector <Point> points;
    while (x <= y) {
        findPoints(Point(x, y), points);
        if (d < 0) d = d + 4*x + 6;
        else {
            d = d + 4*(x-y) + 10;
            y--;
        }
        x++;
    }

    // Translate back
    for (auto &p: points) {
        p.x = p.x + center.x;
        p.y = p.y + center.y;
    }

    // Draw the points
    for (auto point: points) setPixel(point);
}

void midPointCircleDrawing(Point center, int radius)
{
    int x = 0, y = radius;
    int p = 1 - radius;

    vector <Point> points;
    while (x <= y) {
        findPoints(Point(x, y), points);
        if (p < 0) p = p + 2*x + 3;
        else {
            p = p + 2*(x-y) + 5;
            y--;
        }
        x++;
    }

    // Translate back
    for (auto &p: points) {
        p.x = p.x + center.x;
        p.y = p.y + center.y;
    }

    // Draw the points
    for (auto point: points) setPixel(point);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glColor3f(1.0, 1.0, 1.0);  // White

    glBegin(GL_POINTS);

    Point center = Point(20, 30);
    int radius = 10;
    bresenhamCircleDrawing(center, radius);
    radius = 5;
    midPointCircleDrawing(center, radius);

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
