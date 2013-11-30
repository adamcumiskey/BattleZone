//
//  BoundingBox.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/11/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "BoundingBox.h"
#include "MovableObject.h"
#include <math.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

Point2d createPoint2d(float x, float y)
{
    Point2d temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
/* ----------------- */

Point2d RotatePoint(Point2d pointToRotate, Point2d centerPoint, double angleInDegrees)
{
    double angleInRadians = angleInDegrees * (M_PI / 180);
    double cosTheta = cos(angleInRadians);
    double sinTheta = sin(angleInRadians);
    float x = (cosTheta * (pointToRotate.x - centerPoint.y) -
               sinTheta * (pointToRotate.y - centerPoint.y) + centerPoint.x);
    
    float  y = (sinTheta * (pointToRotate.x - centerPoint.x) +
                cosTheta * (pointToRotate.y - centerPoint.y) + centerPoint.y);
    
    return createPoint2d(x, y);
}

#pragma mark - Constructors
BoundingBox::BoundingBox()
{
    // default constructor
}

BoundingBox::BoundingBox(Point2d topRight,
                         Point2d bottomLeft)
{
    _topRight = topRight;
    _bottomLeft = bottomLeft;
    _topLeft = createPoint2d(_bottomLeft.x, _topRight.y);
    _bottomRight = createPoint2d(_topRight.x, _bottomLeft.y);
    
    _center.x = (_topRight.x+_bottomLeft.x)/2;
    _center.y = (_topRight.y+_bottomLeft.y)/2;
}

BoundingBox::BoundingBox(float x1, float y1,
                         float x2, float y2)
{
    _topRight = createPoint2d(x1, y1);
    _bottomLeft = createPoint2d(x2, y2);
    _topLeft = createPoint2d(_bottomLeft.x, _topRight.y);
    _bottomRight = createPoint2d(_topRight.x, _bottomLeft.y);
    
    _center.x = (_topRight.x+_bottomLeft.x)/2;
    _center.y = (_topRight.y+_bottomLeft.y)/2;
}

BoundingBox::BoundingBox(float size, float scaleX, float scaleY)
{
    
}

#pragma mark - Collition detection
bool BoundingBox::containsPoint(Point2d point)
{
    if (point.x <= _topRight.x &&
        point.x >= _bottomLeft.x &&
        point.y <= _topRight.y &&
        point.y >= _bottomLeft.y) {
        return true;
    } else return false;
}

bool BoundingBox::intersects(BoundingBox box)
{
    // Return true if either of the boxes have a corner within the other
    if (containsPoint(box._topRight) ||
        containsPoint(box._bottomLeft) ||
        containsPoint(box._topLeft) ||
        containsPoint(box._bottomRight)) {
        return true;
    } else if (box.containsPoint(_topRight) ||
               box.containsPoint(_bottomLeft) ||
               box.containsPoint(_topLeft) ||
               box.containsPoint(_bottomRight)) {
        return true;
    } else return false;
}

#pragma mark - Getters for postition and size
float BoundingBox::getWidth()
{
    return _topRight.x - _topLeft.x;
}

float BoundingBox::getHeight()
{
    return _topRight.y - _bottomRight.y;
}

float BoundingBox::getX()
{
    return _bottomLeft.x;
}

float BoundingBox::getY()
{
    return _bottomLeft.y;
}

void BoundingBox::moveToPosition(float x, float y, float z)
{
    _center.x = x; _center.y = z; // z represents 'y' in the xz plane
    _topLeft.x = (getWidth()/2)+_center.x;
    _topLeft.y = (getWidth()/2)+_center.y;
    _bottomLeft.x = (getHeight()/2)-_center.x;
    _bottomLeft.y = (getHeight()/2)-_center.y;
}
