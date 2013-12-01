//
//  TerrainObject.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "TerrainObject.h"
#include "BoundingBox.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

// setter for position struct
PositionStruct Position(GLfloat x,
                        GLfloat y,
                        GLfloat z)
{
    PositionStruct temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    return temp;
}

#pragma mark - Public methods
TerrainObject::TerrainObject(GLfloat x,
                             GLfloat y,
                             GLfloat z,
                             GLdouble size,
                             TerrainType type)
{
    // set the position
    _position = Position(x, y, z);
    _size = size;
    
    // Store the object in a displayList
    GLuint index = glGenLists(1);
    glNewList(index, GL_COMPILE);
    glColor3f(0.0, 0.0, 1.0);

    glTranslatef(_position.x, _position.y, _position.z);

    switch (type) {
        case Rock:
            glPushMatrix();
            glTranslatef(0, size/2.0f, 0);
            glutWireCube(size);
            glPopMatrix();
            break;
            
        case Tree:
            glPushMatrix();
            glRotatef(45, 0, 1, 0);
            glRotatef(90, -1, 0, 0);
            glutWireCone(size*.7, size*2, 4, 1);
            glPopMatrix();
            break;
            
        default:
            break;
    }
    glEndList();
    
    // Store the displayList
    _displayList = index;
}

void TerrainObject::renderObject()
{
    glPushMatrix();
    glCallList(_displayList);
    glPopMatrix();
}

#pragma mark - Collision methods
BoundingBox TerrainObject::bounds()
{
    Point2d topRight = createPoint2d(_position.x+(_size/2), _position.z+(_size/2));
    Point2d bottomLeft = createPoint2d(_position.x-(_size/2), _position.z-(_size/2));
    
    return BoundingBox(topRight, bottomLeft);
}

void TerrainObject::renderBounds()
{
    BoundingBox bounds = TerrainObject::bounds();
    
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