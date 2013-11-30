//
//  Enemy.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/23/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "Enemy.h"
#include <math.h>

#define SQR(x) (x*x)
#define PIdiv180 M_PI/180.0f

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define TANK_SPEED 0.02f
#define TURN_SPEED 1.0f
#define MAX_ROTATION 40.0f

#pragma mark - Constructors
Enemy::Enemy(float x, float y, float z) : MovableObject(x, y, z)
{
    _currentState = AI_NONE;
    
    // Store the object in a displayList
    GLuint index = glGenLists(1);
    glNewList(index, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);

    glRotated(90, 0, 1, 0);
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
    glRotated(RotatedY, 0, 1, 0);
    glCallList(_displayList);
    glPopMatrix();
}

void Enemy::changeAIToState(EnemyState newState)
{
    _currentState = newState;
}

#pragma mark - AI Methods

void Enemy::move()
{
    MoveForward(TANK_SPEED);
}

void Enemy::turn(Direction direction)
{
    if (direction == LEFT) {
        RotateY(TURN_SPEED);
    } else {
        RotateY(-TURN_SPEED);
    }
}

void Enemy::aim(SF3dVector targetPosition)
{
    // Get the vector between the tank and the player
    SF3dVector targetVector = F3dVector(targetPosition.x-Position.x,
                                        targetPosition.y-Position.y,
                                        targetPosition.z-Position.z);
    
    // normalize the vector
    float length = sqrtf(SQR(targetVector.x) + SQR(targetVector.y) + SQR(targetVector.z));
    targetVector.x = targetVector.x/length;
    targetVector.y = targetVector.y/length;
    targetVector.z = targetVector.z/length;
    
    // find the dot product
    float dotProduct = (targetVector.x*ViewDir.x +
                        targetVector.y*ViewDir.y +
                        targetVector.z*ViewDir.z);
    
    float angle = (acosf(dotProduct)*(180/M_PI));
    
    printf("Angle %f\n", angle);
    if (!(angle <= 5) && !(angle <= -5)) {
        if (targetVector.x < ViewDir.x || targetVector.z < ViewDir.z) {
            turn(LEFT);
        } else if (targetVector.x > ViewDir.x || targetVector.z > ViewDir.z) {
            turn(RIGHT);
        }
    }
}

void Enemy::fire()
{
    
}


