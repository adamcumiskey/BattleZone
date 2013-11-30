//
//  Projectile.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "Projectile.h"
#include "BoundingBox.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PROJECTILE_SPEED 1

Projectile::Projectile(SF3dVector playerPosition, SF3dVector direction, float angle) : MovableObject(playerPosition.x, playerPosition.y, playerPosition.z)
{
    ViewDir = direction;
    
    // Store the object in a displayList
    GLuint index = glGenLists(1);
    glNewList(index, GL_COMPILE);
    glRotated(angle, 0, 1, 0);
    glColor3f(1.0, 0.0, 0.0);
    glutWireSphere(.1, 10, 10);
    glEndList();
        
    _displayList = index;
}

void Projectile::renderProjectile()
{
    glPushMatrix();
    glTranslatef(Position.x, Position.y, Position.z);
    glRotated(RotatedY, 0, 1, 0);
    glCallList(_displayList);
    glPopMatrix();
}

void Projectile::move()
{
    MoveForward(-PROJECTILE_SPEED);
}

BoundingBox Projectile::bounds()
{
    Point2d center = createPoint2d(Position.x, Position.z);
    Point2d unrotatedTR = createPoint2d(Position.x+.05, Position.z+.05);
    Point2d unrotatedBL = createPoint2d(Position.x-.05, Position.z-.05);
    
    Point2d topRight = RotatePoint(unrotatedTR, center, RotatedY);
    Point2d bottomLeft = RotatePoint(unrotatedBL, center, RotatedY);
    
    return BoundingBox(topRight, bottomLeft);
}