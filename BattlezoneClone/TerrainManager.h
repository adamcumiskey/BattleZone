//
//  TerrainManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  This class generate the terrain and has a vector containing
//  all of the terrain primitives. generateObjects() should be
//  called within the setup of main to randomly generate the objects, and
//  renderTerrain() should be called in the displayFuntion to
//  draw each object

#ifndef __BattlezoneClone__TerrainManager__
#define __BattlezoneClone__TerrainManager__

#include <iostream>
#include <math.h>
#include <vector>

class TerrainObject;
class QuadTree;
class BoundingBox;
class TerrainManager
{
    
private:
    std::vector<TerrainObject *> _objects;
    
    // Quad tree for storing the points
    QuadTree *_quadTree;
    
    // Bounding box that stores the map
    BoundingBox *_boundingBox;
    
    // Inserts all objects into the quadTree and checks to see if there are any collisions
    void checkCollisions();
    
    // Draws an infinite plane
    void drawGround();
    
public:
    // Empty constructor.
    TerrainManager();
    // Destructor
    ~TerrainManager();
    
    // Randomly generate n objects within an n*n grid
    void generateObjects(int n, int gridSize);
    
    // Iterate through each terrain object and call its
    // renderObject() method
    void renderTerrain();
};

#endif /* defined(__BattlezoneClone__TerrainManager__) */
