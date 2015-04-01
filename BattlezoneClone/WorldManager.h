//
//  WorldManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/29/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//
//  Controller the static world objects in the game

#ifndef __BattlezoneClone__WorldManager__
#define __BattlezoneClone__WorldManager__

#include <stdio.h>
#include <vector>

class CollisionManager;
class TerrainObject;
class WorldManager
{
private:
    // Randomly generate n objects within an n*n grid
    void generateObjects(int n, int gridSize);
    
    // Draws an infinite green plane
    void drawGround();
    
    // Renders all the objects
    void renderObjects();
    
    void deleteObject(TerrainObject *object);
    
    CollisionManager *collisionManager;
public:
    WorldManager(int n, int gridSize);
    ~WorldManager();
    
    /* 
     * At the moment, this controller generates random objects in a single grid.
     * To support an infinite map some data structure is needed to store all the
     * grids that get generated as the player moves around and render only the appropriate grids
     */
    
    // Vector containing all of the terrain objects
    std::vector<TerrainObject *> terrainObjects;
    
    void render();
};

#endif /* defined(__BattlezoneClone__WorldManager__) */
