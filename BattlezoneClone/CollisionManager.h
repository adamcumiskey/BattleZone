//
//  CollisionManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/31/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__CollisionManager__
#define __BattlezoneClone__CollisionManager__

#include <stdio.h>
#include <vector>

class QuadTree;
class TerrainObject;
class CollisionManager
{
private:
    
    QuadTree *quadTree;
    
public:
    CollisionManager(std::vector<TerrainObject *> terrainObjects, int gridSize);
    ~CollisionManager();
};

#endif /* defined(__BattlezoneClone__CollisionManager__) */
