//
//  TerrainManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "TerrainManager.h"

TerrainManager::TerrainManager()
{

}

void TerrainManager::generateObjects(int n, int gridSize)
{
    for (int i = 0; i < n; i++) {
        
        // Generate random size between .1 and 1.1
        GLdouble size = 1;
        
        // generate random x and z positions within the grid
        GLfloat x = (rand() % gridSize) - (gridSize/2);
        GLfloat z = (rand() % gridSize) - (gridSize/2);
        
        // set the y to touch the ground
        GLfloat y = 0;
        
        // Generate a type
        TerrainType type = rand() % 2;
                
        TerrainObject object = TerrainObject(x,
                                             y,
                                             z,
                                             size,
                                             type);
        objects.push_back(object);
    }
}

void TerrainManager::renderTerrain()
{
    objectIterator = objects.begin();
    while (objectIterator != objects.end()) {
        objectIterator->renderObject();
        objectIterator++;
    }
}