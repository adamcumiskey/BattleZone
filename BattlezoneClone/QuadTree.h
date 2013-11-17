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

#ifndef __BattlezoneClone__QuadTree__
#define __BattlezoneClone__QuadTree__

#include <iostream>
#include <vector>

#endif /* defined(__BattlezoneClone__QuadTree__) */


#define MAX_OBJECTS 10
#define MAX_LEVELS 5

class BoundingBox;
class TerrainObject;
class QuadTree
{
private:
    std::vector<TerrainObject> *_items;
    
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
    
    void insert(TerrainObject object);
    void clear(); // Clears the QuadTree
};