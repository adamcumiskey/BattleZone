//
//  Player.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "Player.h"
#include "BoundingBox.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

Player::Player(float x, float y, float z) : MovableObject(x, y, z)
{
    // Just initialize from the base
}

void Player::updateCamera()
{
    SF3dVector ViewPoint;
    ViewPoint.x = Position.x + ViewDir.x;
    ViewPoint.y = Position.y + ViewDir.y;
    ViewPoint.z = Position.z + ViewDir.z;
    
    gluLookAt(Position.x, Position.y, Position.z,
              ViewPoint.x, ViewPoint.y, ViewPoint.z,
              UpVector.x, UpVector.y, UpVector.z);
}

void Player::MoveForward(float distance)
{
    MovableObject::MoveForward(distance);
    
    //std::cout << "Current Postition: (" << Position.x << ", " << Position.z << ")" << std::endl;
}

BoundingBox Player::bounds()
{
    Point2d center = createPoint2d(Position.x, Position.z);
    Point2d unrotatedTR = createPoint2d(Position.x+1, Position.z+.65);
    Point2d unrotatedBL = createPoint2d(Position.x-1, Position.z-.65);
    
    Point2d topRight = RotatePoint(unrotatedTR, center, RotatedY);
    Point2d bottomLeft = RotatePoint(unrotatedBL, center, RotatedY);
    
    return BoundingBox(topRight, bottomLeft);
}