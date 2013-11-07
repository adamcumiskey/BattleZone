//
//  main.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/6/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  Main file for the battlezone program. All OpenGL main loop logic should go here.

#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define TABLE_WIDTH 4000
#define TABLE_HEIGHT 2000
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // Angles to rotate scene.

void setup()
{
    // Set the clear color to black and enable depth testing
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void drawGround()
{
    float origin[4] = {0, 0, 0, 1};
    float one[4] = {1, 0, 0, 0};
    float two[4] = {0, 1, 0, 0};
    float three[4] = {-1, 0, 0, 0};
    float four[4] = {0, -1, 0, 0};
    
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    
    glVertex4fv(origin);
    glVertex4fv(one);
    glVertex4fv(two);
    
    glVertex4fv(origin);
    glVertex4fv(two);
    glVertex4fv(three);
    
    glVertex4fv(origin);
    glVertex4fv(three);
    glVertex4fv(four);
    
    glVertex4fv(origin);
    glVertex4fv(four);
    glVertex4fv(one);

    glEnd();
}

void drawScene()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, -1.0, -10.0);
    
    // Rotate scene.
    glRotatef(Zangle, 0.0, 0.0, 1.0);
    glRotatef(Yangle, 0.0, 1.0, 0.0);
    glRotatef(Xangle, 1.0, 0.0, 0.0);
    
    drawGround();
    
    glutSwapBuffers();
}

void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.0f, 2.0, 5, 500);
    
    glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        case ' ':
            glutPostRedisplay();
            break;
        case 'x':
            Xangle += 5.0;
            if (Xangle > 360.0) Xangle -= 360.0;
            glutPostRedisplay();
            break;
        case 'X':
            Xangle -= 5.0;
            if (Xangle < 0.0) Xangle += 360.0;
            glutPostRedisplay();
            break;
        case 'y':
            Yangle += 5.0;
            if (Yangle > 360.0) Yangle -= 360.0;
            glutPostRedisplay();
            break;
        case 'Y':
            Yangle -= 5.0;
            if (Yangle < 0.0) Yangle += 360.0;
            glutPostRedisplay();
            break;
        case 'z':
            Zangle += 5.0;
            if (Zangle > 360.0) Zangle -= 360.0;
            glutPostRedisplay();
            break;
        case 'Z':
            Zangle -= 5.0;
            if (Zangle < 0.0) Zangle += 360.0;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void printInteraction()
{
    
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("BattleZone");
    setup();
    
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    
    glutMainLoop();
    
    return 0;
}

