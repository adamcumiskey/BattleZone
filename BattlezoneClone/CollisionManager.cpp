//
//  CollisionManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/31/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#include "CollisionManager.h"
#include "TerrainObject.h"
#include "QuadTree.h"
#include "BoundingBox.h"

CollisionManager::CollisionManager(std::vector<TerrainObject *> terrainObjects, int gridSize)
{
    Rect rect = MakeRect(0, 0, gridSize, gridSize);
    BoundingBox *bounds = new BoundingBox(rect);
    quadTree = new QuadTree(0, bounds);
    for (auto &terrainObject : terrainObjects) {

    }
}

CollisionManager::~CollisionManager()
{
    delete quadTree;
}