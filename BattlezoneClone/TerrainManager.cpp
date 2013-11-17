//
//  TerrainManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "TerrainManager.h"
#include "TerrainObject.h"
#include "QuadTree.h"
#include "BoundingBox.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

TerrainManager::TerrainManager()
{
   
}

void TerrainManager::generateObjects(int n, int gridSize)
{
    boundingBox = new BoundingBox(25.0f, 25.0f, -25.0f, -25.0f);
    quadTree = new QuadTree(0, *boundingBox);
    
    
    for (int i = 0; i < n; i++) {
        
        // Generate random size between .1 and 1.1
        GLdouble size = 1;
        
        // generate random x and z positions within the grid
        GLfloat x = (rand() % gridSize) - (gridSize/2);
        GLfloat z = (rand() % gridSize) - (gridSize/2);
        
        // set the y to touch the 4ground
        GLfloat y = 0;
        
        // Generate a type
        TerrainType type = rand() % 2;
                
        TerrainObject *object = new TerrainObject(x,
                                             y,
                                             z,
                                             size,
                                             type);
        _objects.push_back(object);
        
        quadTree->insert(*object);
    }
}

void TerrainManager::renderTerrain()
{
    drawGround();
    
    std::vector<TerrainObject *>::iterator it = _objects.begin();
    while (it != _objects.end()) {
        TerrainObject object = *_objects.at(it - _objects.begin());
        object.renderObject();
        it++;
    }
}

void TerrainManager::drawGround()
{
    // Draw 4 triangles from the origin with
    // 4 unit vertecies located at infinity
    glBegin(GL_TRIANGLE_FAN);
    glVertex4f(0, 0, 0, 1);
    glVertex4f(1, 0, 0, 0);
    glVertex4f(0, 0, 1, 0);
    glVertex4f(-1, 0, 0, 0);
    glVertex4f(0, 0, -1, 0);
    glVertex4f(1, 0, 0, 0);
    glEnd();
}