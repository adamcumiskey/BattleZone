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
Enemy::Enemy()
{
    // blank constructor
}

Enemy::Enemy(float x, float y, float z, float angle)
{
    _xPos = x;
    _yPos = y;
    _zPos = z;
    _angle = angle;
    _currentState = AI_NONE;
    
    // Store the object in a displayList
    GLuint index = glGenLists(1);
    glNewList(index, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);
    glutWireCube(1.0);
    glScalef(0, .33, 0); // make the tank a rectangular box
    glEndList();
    
    _displayList = index;
}

#pragma mark - Public methods
void Enemy::renderEnemy()
{
    glCallList(_displayList);
}

void Enemy::updateEnemy()
{
    switch (_currentState) {
        case AI_NONE:
            break;
            
        case AI_MOVE:
            move();
            break;
            
        case AI_TURN:
            turn();
            break;
            
        case AI_AIM:
            aim();
            break;
            
        case AI_FIRE:
            fire();
            break;
            
        default:
            break;
    }
}

void Enemy::changeAIToState(EnemyState newState)
{
    _currentState = newState;
}

#pragma mark - Private methods
void Enemy::move()
{
    
}

void Enemy::turn()
{
    _angle += 5;
}

void Enemy::aim()
{
    
}

void Enemy::fire()
{
    
}