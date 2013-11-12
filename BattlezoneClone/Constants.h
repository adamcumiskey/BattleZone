//
//  Constants.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/11/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#ifndef BattlezoneClone_Constants_h
#define BattlezoneClone_Constants_h

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

/* Coordinate struct */
struct Point2d {
    GLfloat x, y;
};

Point2d createPoint2d(GLfloat x, GLfloat y)
{
    Point2d temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
/* ----------------- */

#endif
