//
//  TerrainObject.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  Object that represents a piece of terrain at a fixed position
//  Can be either a pyramid or iscohedron

#ifndef __BattlezoneClone__TerrainObject__
#define __BattlezoneClone__TerrainObject__

#include <iostream>

struct PositionStruct {
    float x, y, z;
};
PositionStruct Position(float x,
                        float y,
                        float z);

enum {
    Rock,
    Tree,
}; typedef int TerrainType;

class BoundingBox;
class TerrainObject
{
private:
    PositionStruct _position;
    float _size;
    
public:
    TerrainObject(float x,
                  float y,
                  float z,
                  double size,
                  TerrainType type);
    
    void renderObject();
    BoundingBox bounds();
    void renderBounds();
    
    int _displayList;

};

#endif /* defined(__BattlezoneClone__TerrainObject__) */