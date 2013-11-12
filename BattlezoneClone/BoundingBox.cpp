//
//  BoundingBox.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/11/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "BoundingBox.h"

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
}

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

GLfloat BoundingBox::getWidth()
{
    return _topRight.x - _topLeft.x;
}

GLfloat BoundingBox::getHeight()
{
    return _topRight.y - _bottomRight.y;
}

GLfloat BoundingBox::getX()
{
    return _bottomLeft.x;
}

GLfloat BoundingBox::getY()
{
    return _bottomLeft.y;
}