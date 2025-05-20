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

struct Point {
    float x, y;
    Point(float _x = 0, float _y = 0) : x(_x), y(_y) {}
};

struct Line {
    Point p1, p2;
    Line(Point _p1, Point _p2) : p1(_p1), p2(_p2) {}
};

vector<Line> inputLines;
vector<Line> clippedLines;

// Window bounds
float wx_min = -30, wy_min = -30, wx_max = 30, wy_max = 30;
float degree = 0;

// Region codes for Cohen-Sutherland
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

int computeCode(Point p) {
    int code = INSIDE;
    if (p.x < wx_min) code |= LEFT;
    else if (p.x > wx_max) code |= RIGHT;
    if (p.y < wy_min) code |= BOTTOM;
    else if (p.y > wy_max) code |= TOP;
    return code;
}

bool cohenSutherlandClip(Point& p1, Point& p2) {
    int code1 = computeCode(p1);
    int code2 = computeCode(p2);

    while (true) {
        if ((code1 | code2) == 0) return true; // trivially accepted
        else if ((code1 & code2) != 0) return false; // trivially rejected
        else {
            int codeOut = code1 ? code1 : code2;
            float x, y;

            float dx = p2.x - p1.x;
            float dy = p2.y - p1.y;

            if (codeOut & TOP) {
                x = p1.x + dx * (wy_max - p1.y) / dy;
                y = wy_max;
            } else if (codeOut & BOTTOM) {
                x = p1.x + dx * (wy_min - p1.y) / dy;
                y = wy_min;
            } else if (codeOut & RIGHT) {
                y = p1.y + dy * (wx_max - p1.x) / dx;
                x = wx_max;
            } else if (codeOut & LEFT) {
                y = p1.y + dy * (wx_min - p1.x) / dx;
                x = wx_min;
            }

            if (codeOut == code1) {
                p1.x = x; p1.y = y;
                code1 = computeCode(p1);
            } else {
                p2.x = x; p2.y = y;
                code2 = computeCode(p2);
            }
        }
    }
}

// Transformation
Point rotate(Point p, float angle_deg) {
    float rad = angle_deg * M_PI / 180.0;
    return Point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

Point translate(Point p, Point t) {
    return Point(p.x + t.x, p.y + t.y);
}

Point inv_translate(Point p, Point t) {
    return Point(p.x - t.x, p.y - t.y);
}

void processClipping() {
    clippedLines.clear();
    Point center((wx_min + wx_max) / 2, (wy_min + wy_max) / 2);

    for (auto line : inputLines) {
        Point p1 = inv_translate(line.p1, center);
        Point p2 = inv_translate(line.p2, center);
        p1 = rotate(p1, -degree);
        p2 = rotate(p2, -degree);

        if (cohenSutherlandClip(p1, p2)) {
            p1 = rotate(p1, degree);
            p2 = rotate(p2, degree);
            p1 = translate(p1, center);
            p2 = translate(p2, center);
            clippedLines.push_back(Line(p1, p2));
        }
    }
}

// Viewport drawing
void drawRotatedWindow() {
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_LINE_LOOP);
    vector<Point> corners = {
        Point(wx_min, wy_min),
        Point(wx_max, wy_min),
        Point(wx_max, wy_max),
        Point(wx_min, wy_max)
    };

    Point center((wx_min + wx_max) / 2, (wy_min + wy_max) / 2);

    for (auto p : corners) {
        p = inv_translate(p, center);
        p = rotate(p, degree);
        p = translate(p, center);
        glVertex2f(p.x, p.y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    processClipping();

    drawRotatedWindow();

    // Draw original lines
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    for (auto line : inputLines) {
        glVertex2f(line.p1.x, line.p1.y);
        glVertex2f(line.p2.x, line.p2.y);
    }
    glEnd();

    // Draw clipped lines
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    for (auto line : clippedLines) {
        glVertex2f(line.p1.x, line.p1.y);
        glVertex2f(line.p2.x, line.p2.y);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -1, 1);
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) degree -= 5;
    if (key == GLUT_KEY_RIGHT) degree += 5;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    inputLines.push_back(Line(Point(-80, -20), Point(80, 60)));
    inputLines.push_back(Line(Point(-40, -70), Point(90, 80)));
    inputLines.push_back(Line(Point(-60, -40), Point(-10, 10)));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rotated Cohen-Sutherland Clipping");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
