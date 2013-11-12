//
//  BoundingBox.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/11/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  Defines a 2d rectangle and defines methods for checking
//  weather it intersects with another rectangle. Every object
//  that is collidable will have a bounding box associated with it
//  to check collisions. In addition, is used to define the box that
//  defines each node of the QuadTree data structure

#ifndef __BattlezoneClone__BoundingBox__
#define __BattlezoneClone__BoundingBox__

#include <iostream>
#include "Constants.h"

#endif /* defined(__BattlezoneClone__BoundingBox__) */

class BoundingBox
{
private:
    Point2d _topRight, _bottomLeft, _topLeft, _bottomRight;
    
public:
    BoundingBox();
    BoundingBox(Point2d topRight,
                Point2d bottomLeft);
    
    // Return true if the point is within the bounding box
    bool containsPoint(Point2d point);
    
    // Return true if the two boxes intersect at any point
    bool intersects(BoundingBox box);
    
    // Getters for the width and height and position of the box
    GLfloat getWidth();
    GLfloat getHeight();
    GLfloat getX();
    GLfloat getY();
};