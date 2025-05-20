#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

double W, H;
double degree = 0.0;

struct Point {
    double x;
    double y;
    Point(double a, double b)
    {
        x = a;
        y = b;
    }

    Point()
    {
        x = 0;
        y = 0;
    }
};

vector <Point> v;

void init()
{
    W = 30, H = 30;
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-W/2, W/2, -H/2, H/2, -10, 10);
}

void drawAxis()
{
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);

    // Draw x axis
    glVertex2f(-W/2, 0);
    glVertex2f(W/2, 0);

    // Draw y axis
    glVertex2f(0, -H/2);
    glVertex2f(0, H/2);

    glEnd();
    glFlush();

}

Point translate(Point p, Point t)
{
    p.x += t.x;
    p.y += t.y;
    return p;
}

Point rotate(Point p, double angle)
{
    angle = angle * (3.1416/180);
    double x_new = p.x * cos(angle) - p.y * sin(angle);
    double y_new = p.x * sin(angle) + p.y * cos(angle);
    return Point(x_new, y_new);
}

Point scale(Point p, Point factor)
{
//    double factorMatrix[2][2] = {{factor.x,0},{0,factor.y}};
//    double pointVector[2] = {p.x,p.y};
//    double result[2] = {0,0};
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<2;j++)
//        {
//            result[i] += pointVector[j] * factorMatrix[i][j];
//        }
//    }
//    return Point(result[0],result[1]);
    p.x *= factor.x;
    p.y *= factor.y;
    return p;
}

void printShape()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);

    for (auto point: v) {
        glVertex2f(point.x, point.y);
    }
    glEnd();
    glFlush();
}

void populatePoint(double degree)
{
    v.clear();
    v.push_back(Point(4, 10));
    v.push_back(Point(1, 7));
    v.push_back(Point(7, 7));

    Point t = Point(4, 10);
    for (auto &p: v)
    {
        p = translate(p, Point(-t.x, -t.y));
        double factor = (degree+360.0)/360.0;
        p = scale(p, Point(factor, factor));
        p = rotate(p, degree);
        p = translate(p, t);
    }
}

void sp_keyboard(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            degree += 1;
            break;
        case GLUT_KEY_DOWN:
            degree -= 1;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    populatePoint(degree);
    printShape();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Triangle Movement");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(sp_keyboard);
    glutMainLoop();

    return EXIT_SUCCESS;

}

