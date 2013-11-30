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
//  defines each node of the QuadTree data structure. I may need to
//  rethink that later, as I may want the bounding box to be a property
//  of an abstract Collidable class which all my collidible objects will
//  subclass.

#ifndef __BattlezoneClone__BoundingBox__
#define __BattlezoneClone__BoundingBox__

#include <iostream>

/* Coordinate struct */
struct Point2d {
    float x, y;
};
Point2d createPoint2d(float x, float y);
Point2d RotatePoint(Point2d pointToRotate, Point2d centerPoint, double angleInDegrees);

class BoundingBox
{
private:
    Point2d _topRight, _bottomLeft, _topLeft, _bottomRight;
    Point2d _center;
    
public:
    BoundingBox();
    BoundingBox(Point2d topRight,
                Point2d bottomLeft);
    BoundingBox(float x1, float y1,
                float x2, float y2);
    BoundingBox(float size, float scaleX, float scaleY);
    
    // Return true if the point is within the bounding box
    bool containsPoint(Point2d point);
    
    // Return true if the two boxes intersect at any point
    bool intersects(BoundingBox box);
    
    // Getters for the width and height and position of the box
    float getWidth();
    float getHeight();
    float getX();
    float getY();
    
    void moveToPosition(float x, float y, float z);
    void rotate(float angle);
};

#endif /* defined(__BattlezoneClone__BoundingBox__) */

