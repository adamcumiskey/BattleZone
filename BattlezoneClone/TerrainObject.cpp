//
//  TerrainObject.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "TerrainObject.h"

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

TerrainObject::TerrainObject(GLfloat x,
                             GLfloat y,
                             GLfloat z,
                             GLdouble size,
                             TerrainType type)
{
    // Store the object in a displayList
    GLuint index = glGenLists(1);
    glNewList(index, GL_COMPILE);
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(_position.x, _position.y, _position.z);
    
    switch (type) {
        case Rock:
            glPushMatrix();
            glScalef(size, size, size);
            glutWireIcosahedron();
            glPopMatrix();
            break;
            
        case Tree:
            glutWireOctahedron();
            break;
            
        default:
            break;
    }
    glEndList();
    
    
    // Store the displayList and position
    _displayList = index;
    _position = Position(x, y, z);
}

void TerrainObject::renderObject()
{
    glCallList(_displayList);
}

BoundingBox TerrainObject::getBounds()
{
    return _bounds;
}