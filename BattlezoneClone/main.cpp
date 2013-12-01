//
//  main.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/6/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  Main file for the battlezone program. All OpenGL setup and main loop functions should go here.
//  The GameManager takes care of all of the all the state.

#include <iostream>
#include "GameManager.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

GameManager gameManager;

void setup()
{
    // Set the clear color to black and enable depth testing
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    srand((uint32_t)time(0)); // get a better random seed
    
    gameManager.initializeGame(100, 400);
}

void drawScene()
{
    glPolygonMode(GL_BACK, GL_FILL);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glLineWidth(2.0); // looks nicer
    
    gameManager.renderWorld(); // draw all objects
    
    glutSwapBuffers();
}

void animate(int value)
{
    gameManager.animateGame(); // update animated objects
    glutTimerFunc(10, animate, 1);
    glutPostRedisplay();
}

void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.0f, 2.0, 1, 500);
    
    glMatrixMode(GL_MODELVIEW);
}

void keyInput(unsigned char key, int x, int y)
{
    gameManager.input(key); // send input to the game manager
}

void printInteraction()
{
    std::cout << "Use WASD to move the tank" << std::endl;
    std::cout << "Press space to fire" << std::endl;
}

int main(int argc, char **argv)
{
    printInteraction();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("BattleZone");
    setup();
    
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutTimerFunc(10, animate, 1);
    
    glutMainLoop();
    
    return 0;
}