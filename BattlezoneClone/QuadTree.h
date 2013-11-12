//
//  QuadTree.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/11/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__QuadTree__
#define __BattlezoneClone__QuadTree__

#include <iostream>
#include <vector>
#include "TerrainObject.h"

#endif /* defined(__BattlezoneClone__QuadTree__) */


#define MAX_OBJECTS 10
#define MAX_LEVELS 5


class QuadTree
{
private:
    std::vector<TerrainObject> objects;
    int level;
    QuadTree *nodes[4]; // pointer to the array of the 4 nodes of this quad
    
public:
    
};