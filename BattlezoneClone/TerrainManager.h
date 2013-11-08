//
//  TerrainManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__TerrainManager__
#define __BattlezoneClone__TerrainManager__

#include <iostream>
#include <vector>
#include "TerrainObject.h"

#endif /* defined(__BattlezoneClone__TerrainManager__) */


class TerrainManager
{
    
private:
    std::vector<TerrainObject> objects;
    std::vector<TerrainObject>::iterator objectIterator;
    
    void addObject(TerrainObject object);
    
public:
    TerrainManager();
    void generateObjects(int n, int gridSize);
    void renderTerrain();
};