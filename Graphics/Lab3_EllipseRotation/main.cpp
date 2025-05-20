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

void drawAxis();

void setPixel(float x, float y, float xc, float yc){
    double mul = 1.0/ sqrt(2);
    float xx = x * mul - y * mul + xc;
    float yy = x * mul + y * mul + yc;

    glVertex3f(xx, yy, 0.0);
    cout<<"("<<xx <<","<<yy<<")";
}

void midPointEllipseDrawing(float xc, float yc, float a, float b)
{
    float x = 0, y = b;
    float fx = 0;
    float fy = 2*a*a*b;
    float p = b*b + 0.25*a*a - a*a*b;

    while(fx<fy){
        setPixel(x, y, xc, yc);
        setPixel(-x, y, xc, yc);
        setPixel(x, -y, xc, yc);
        setPixel(-x, -y, xc, yc);

        //cout<<"("<<x+xc <<","<<y+yc<<")"<<endl;

        x++;
        fx += 2*b*b;
        if(p < 0)
            p += (fx + b*b);
        else{
            y--;
            fy -= (2*a*a);
            p += (fx-fy+b*b);
       }

    }
    setPixel(x, y, xc, yc);
    setPixel(-x, y, xc, yc);
    setPixel(x, -y, xc, yc);
    setPixel(-x, -y, xc, yc);
    //cout<<"("<<x+xc <<","<<y+yc<<")"<<endl;

    p = b*b*(x + 0.5)*(x + 0.5) + a*a*(y - 1)*(y - 1) - a*a*b*b;
    while(y>0){

        y--;
        fy -= 2*a*a;
        if(p >= 0)
            p += (a*a - fy);
        else{
            x++;
            fx += 2*b*b;
            p += (fx-fy+a*a);
       }

        setPixel(x, y, xc, yc);
        setPixel(-x, y, xc, yc);
        setPixel(x, -y, xc, yc);
        setPixel(-x, -y, xc, yc);
        //cout<<"("<<x+xc <<","<<y+yc<<")"<<endl;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glColor3f(1.0, 1.0, 1.0);  // White

    glBegin(GL_POINTS);

    float a = 10, b = 5;
    float xc = -9, yc = 9;
    midPointEllipseDrawing(xc, yc, a, b);

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
