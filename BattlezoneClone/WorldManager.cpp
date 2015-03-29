//
//  WorldManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/29/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#include "WorldManager.h"
#include "TerrainObject.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

WorldManager::WorldManager(int n, int gridSize)
{
    generateObjects(n, gridSize);
}

#pragma mark - Terrain Manager
void WorldManager::generateObjects(int n, int gridSize)
{
    for (int i = 0; i < n; i++) {
        
        // Generate random size between 1 and 3
        GLdouble size = (float)(rand() % 3)+1;
        
        // generate random x and z positions within the grid
        GLfloat x = (rand() % gridSize) - (gridSize/2);
        GLfloat z = (rand() % gridSize) - (gridSize/2);
        
        // set the y to touch the ground
        GLfloat y = 0;
        
        // Generate a type
        TerrainType type = rand() % 2;
        
        TerrainObject *object = new TerrainObject(x,
                                                  y,
                                                  z,
                                                  size,
                                                  type);
        terrainObjects.push_back(object);
    }
}

void WorldManager::render()
{
    drawGround();
    renderObjects();
}

void WorldManager::drawGround()
{
    // Draw 4 triangles from the origin with
    // 4 unit vertecies located at infinity
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.75, 0.0);
    glVertex4f(0, 0, 0, 1);
    glVertex4f(1, 0, 0, 0);
    glVertex4f(0, 0, 1, 0);
    glVertex4f(-1, 0, 0, 0);
    glVertex4f(0, 0, -1, 0);
    glVertex4f(1, 0, 0, 0);
    glEnd();
}

void WorldManager::renderObjects()
{
    std::vector<TerrainObject *>::iterator it = terrainObjects.begin();
    while (it != terrainObjects.end()) {
        TerrainObject object = *terrainObjects.at(it - terrainObjects.begin());
        object.renderObject();
        it++;
    }
}

#pragma mark - Destructor

WorldManager::~WorldManager()
{
    for (auto &object : terrainObjects) {
        delete object;
    }
}