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

void setup()
{
    // Set the clear color to black and enable depth testing
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void drawScene()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glutSwapBuffers();
}

void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.0f, 2.0, 5, 300);
    
    glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int x, int y)
{
    
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

