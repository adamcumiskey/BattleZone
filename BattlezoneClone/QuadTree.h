//
//  QuadTree.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/11/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  Based on http://gamedev.tutsplus.com/tutorials/implementation/quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space/
//
//  Data structure to recursively partition 2d space
//  This class will be used to check the collisions of
//  all the collidable objects.


#ifndef __BattlezoneClone__QuadTree__
#define __BattlezoneClone__QuadTree__

#include <iostream>
#include <vector>

#define MAX_OBJECTS 10
#define MAX_LEVELS 5

class BoundingBox;
class TerrainObject;
class QuadTree
{
private:
    std::vector<TerrainObject *> _items;
    
    int _level;
    BoundingBox *_bounds;
    QuadTree *_nodes[4]; // pointer to the array of the 4 nodes of this quad
    
    void split(); // Split a node into 4 subnodes
    int getIndex(TerrainObject object); // Determine the node that the object is in
    BoundingBox getBounds();
    
public:
    QuadTree();
    QuadTree(int level, BoundingBox bounds);
    ~QuadTree();
    
    // Insert a new object into the tree
    void insert(TerrainObject object);
    
    // Retreive a vector of all the possible collision objects
    std::vector<TerrainObject *> retrieve(std::vector<TerrainObject *> returnObjects,
                                          TerrainObject object);
    
    void clear(); // Clears the QuadTree
};

#endif /* defined(__BattlezoneClone__QuadTree__) */
