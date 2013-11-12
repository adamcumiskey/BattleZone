//
//  QuadTree.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/11/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "QuadTree.h"

#pragma mark - Public Methods
QuadTree::QuadTree(int level, BoundingBox bounds)
{
    _level = level;
    _bounds = bounds;
}

void QuadTree::insert(TerrainObject object)
{
    
}

void QuadTree::clear()
{
    // Recursively set the nodes to null
    for (int i = 0; i < sizeof(*_nodes); i++) {
        if (_nodes[i] != NULL) {
            _nodes[i]->clear();
            delete _nodes[i];
        }
    }
}

#pragma mark - Private Methods
void QuadTree::split()
{
    int width = (int)(_bounds.getWidth()/2);
    int height = (int)(_bounds.getHeight()/2);
    int x = (int)_bounds.getX();
    int y = (int)_bounds.getY();
    
    // Create a new quadtree for each quadrant
    
    // I
    _nodes[0] = new QuadTree(_level++, BoundingBox(createPoint2d(width*2, height*2),
                                                   createPoint2d(width, height)));
    
    // II
    _nodes[1] = new QuadTree(_level++, BoundingBox(createPoint2d(width, height*2),
                                                   createPoint2d(x, height)));
    
    // III
    _nodes[2] = new QuadTree(_level++, BoundingBox(createPoint2d(width, height),
                                                   createPoint2d(x, y)));
    
    // IV
    _nodes[3] = new QuadTree(_level++, BoundingBox(createPoint2d(width*2, height),
                                                   createPoint2d(width, y)));
    
}

int QuadTree::getIndex(TerrainObject object)
{
    double verticalMidpoint = _bounds.getX() + (_bounds.getWidth()/2);
    double horizontalMidpoint = _bounds.getY() + (_bounds.getHeight()/2);
    
    bool topQuadrant = (object.getBounds().getY() > horizontalMidpoint);
    bool bottomQuadrant = (object.getBounds().getY() < horizontalMidpoint &&
                           object.getBounds().getY() + object.getBounds().getHeight() < horizontalMidpoint);
    bool leftQuadrant = (object.getBounds().getX() < verticalMidpoint &&
                         object.getBounds().getX() + object.getBounds().getWidth() < verticalMidpoint);
    bool rightQuadrant = (object.getBounds().getX() > verticalMidpoint);
    
    // Return the index of the correct quadrant
    if (topQuadrant && rightQuadrant) {
        return 0;
    } else if (topQuadrant && leftQuadrant) {
        return 1;
    } else if (bottomQuadrant && leftQuadrant) {
        return 2;
    } else if (bottomQuadrant && rightQuadrant) {
        return 3;
    } else return -1; // return -1 if it doesn't fully fit within a quadrant
}

BoundingBox QuadTree::getBounds()
{
    return _bounds;
}

QuadTree::~QuadTree()
{
    clear();
}