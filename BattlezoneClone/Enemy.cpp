//
//  Enemy.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/23/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "Enemy.h"
#include "BoundingBox.h"
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
    _AIState = AI_NONE;
    
    distanceMoved = 0;
    angleTurned = 0;
    currentDirection = -1;
    
    // Store the object in a displayList
    GLuint index = glGenLists(1);
    glNewList(index, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);

    glRotated(90, 0, 1, 0);
    
    // Base of the tank
    glPushMatrix();
    glTranslated(0, -.25, 0);
    glScalef(2, .5, 1.25);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Top of the tank
    glPushMatrix();
    glTranslatef(0, .2, 0);
    glScalef(1.25, .4, .75);
    glutWireCube(1);
    glPopMatrix();
    
    // Cannon
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, .3, 1.12);
    glScalef(.1, .1, 1);
    glutWireCube(1);
    glPopMatrix();
    
    
    glEndList();
    
    _displayList = index;
}


#pragma mark - Public methods
void Enemy::render()
{
    glPushMatrix();
    glTranslatef(Position.x, Position.y, Position.z);
    glRotated(RotatedY, 0, 1, 0);
    glCallList(_displayList);
    glPopMatrix();
}

void Enemy::setAIState(EnemyState newState)
{
    _AIState = newState;
    
    // reset the params
    distanceMoved = 0;
    angleTurned = 0;
    currentDirection = -1;
}

EnemyState Enemy::getAIState()
{
    return _AIState;
}

#pragma mark - AI Methods

void Enemy::move()
{
    MoveForward(-TANK_SPEED);
    distanceMoved += TANK_SPEED;
}

void Enemy::reverse()
{
    MoveForward(TANK_SPEED);
    distanceMoved += TANK_SPEED;
}

void Enemy::turn()
{
    if (currentDirection == LEFT) {
        RotateY(TURN_SPEED);
    } else {
        RotateY(-TURN_SPEED);
    }
    angleTurned += TURN_SPEED;
}

// NOTE: Doesn't work very well
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
    
    if (!(angle <= 5) && !(angle <= -5)) {
        if (targetVector.x < ViewDir.x || targetVector.z < ViewDir.z) {
            turn();
        } else if (targetVector.x > ViewDir.x || targetVector.z > ViewDir.z) {
            turn();
        }
    }
}

void Enemy::fire()
{
    
}

void Enemy::setTurnDirection(Direction direction)
{
    currentDirection = direction;
}

float Enemy::getDistanceMoved()
{
    return distanceMoved;
}

float Enemy::getAngleTurned()
{
    return angleTurned;
}

#pragma mark - Collision methods
BoundingBox Enemy::bounds()
{
    Point2d center = createPoint2d(Position.x, Position.z);
    Point2d topRight = createPoint2d(center.x+.65, center.y+1);
    Point2d bottomLeft = createPoint2d(center.x-.65, center.y-1);
    
    return BoundingBox(topRight, bottomLeft);
}

void Enemy::renderBounds()
{
    BoundingBox bounds = Enemy::bounds();
    
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, .01, 0);
    glRotated(90, 1, 0, 0);
    glRectd(bounds.getTopRight().x,
            bounds.getTopRight().y,
            bounds.getBottomLeft().x,
            bounds.getBottomLeft().y);
    glPopMatrix();
}