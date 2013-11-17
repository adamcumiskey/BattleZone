//
//  TerrainObject.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  Object that represents a piece of terrain at a fixed position
//  Can be either a pyramid or cube shape

#ifndef __BattlezoneClone__TerrainObject__
#define __BattlezoneClone__TerrainObject__

#include <iostream>

#endif /* defined(__BattlezoneClone__TerrainObject__) */

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

struct PositionStruct {
    GLfloat x, y, z;
};
PositionStruct Position(GLfloat x,
                        GLfloat y,
                        GLfloat z);

enum {
    Rock,
    Tree,
}; typedef int TerrainType;

class BoundingBox;
class TerrainObject
{
private:
    PositionStruct _position;
    GLuint _displayList;
    BoundingBox *_bounds;
    
public:
    TerrainObject(GLfloat x,
                  GLfloat y,
                  GLfloat z,
                  GLdouble size,
                  TerrainType type);
    
    void renderObject();
    BoundingBox getBounds();
};