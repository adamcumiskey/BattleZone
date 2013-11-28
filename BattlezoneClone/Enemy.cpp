//
//  Enemy.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/23/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "Enemy.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#pragma mark - Constructors
Enemy::Enemy(float x, float y, float z) : MovableObject(x, y, z)
{
    _currentState = AI_NONE;
    
    // Store the object in a displayList
    GLuint index = glGenLists(1);
    glNewList(index, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);

    // Base of the tank
    glPushMatrix();
    glScalef(2, .5, 1.25);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Top of the tank
    glPushMatrix();
    glTranslatef(0, .45, 0);
    glScalef(1.25, .4, .75);
    glutWireCube(1);
    glPopMatrix();
    
    // Cannon
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, .5, 1.12);
    glScalef(.1, .1, 1);
    glutWireCube(1);
    glPopMatrix();
    
    glEndList();
    
    _displayList = index;
}


#pragma mark - Public methods
void Enemy::renderEnemy()
{
    glPushMatrix();
    glTranslatef(Position.x, Position.y, Position.z);
    glCallList(_displayList);
    glPopMatrix();
}

void Enemy::updateEnemy()
{
    switch (_currentState) {
        case AI_NONE:
            break;
            
        case AI_MOVE:
            break;
            
        case AI_TURN:
            break;
            
        case AI_AIM:
            break;
            
        case AI_FIRE:
            break;
            
        default:
            break;
    }
}

void Enemy::changeAIToState(EnemyState newState)
{
    _currentState = newState;
}
