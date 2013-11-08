//
//  main.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/6/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  Main file for the battlezone program. All OpenGL main loop logic should go here.

#include <iostream>
#include "Camera.h"
#include "TerrainManager.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define TABLE_WIDTH 4000
#define TABLE_HEIGHT 2000

CCamera Camera(0.0, 0.5, 0.0);
TerrainManager terrainManager;

void setup()
{
    // Set the clear color to black and enable depth testing
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    
    terrainManager.generateObjects(100, 50);
}

void drawGround()
{
    // Draw 4 triangles from the origin with
    // 4 unit vertecies located at infinity
    glBegin(GL_TRIANGLE_FAN);
    glVertex4f(0, 0, 0, 1);
    glVertex4f(1, 0, 0, 0);
    glVertex4f(0, 0, 1, 0);
    glVertex4f(-1, 0, 0, 0);
    glVertex4f(0, 0, -1, 0);
    glVertex4f(1, 0, 0, 0);
    glEnd();
}

void drawScene()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.0, 1.0, 0.0);

    // Draw the camera
    Camera.Render();
    
    drawGround();
    
    terrainManager.renderTerrain();
    
    glutSwapBuffers();
}

void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.0f, 2.0, 1, 50);
    
    glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        case 'w':
            Camera.MoveForward(-.5);
            break;
        case 'a':
            Camera.RotateY(5.0);
            break;
        case 's':
            Camera.MoveForward(.5);
            break;
        case 'd':
            Camera.RotateY(-5.0);
            break;
        default:
            break;
    }
    glutPostRedisplay();
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

