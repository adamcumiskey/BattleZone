//
//  QuadTree.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/11/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "QuadTree.h"
#include "BoundingBox.h"
#include "TerrainObject.h"

#pragma mark - Public Methods
QuadTree::QuadTree()
{
    // blank constructor
}

QuadTree::QuadTree(int level, BoundingBox *bounds)
{
    _level = level;
    _bounds = bounds;
}

void QuadTree::insert(TerrainObject *object)
{
    if (_nodes[0] != NULL) {
        int index = getIndex(object);
        
        // Recursively insert the object until it doesn't
        // fit in any more quads
        if (index != -1) {
            _nodes[index]->insert(object);
            return;
        }
        _items.push_back(object);
        
        // If a node's capacity is exceded, split the quad
        // and add all of the objects
        if (_items.size() > MAX_OBJECTS && _level < MAX_LEVELS) {
            if (_nodes[0] == NULL) {
                split();
            }
            
            std::vector<TerrainObject *>::iterator objectsIterator;
            objectsIterator = _items.begin();
            while (objectsIterator != _items.end()) {
                TerrainObject *object = _items.at(objectsIterator - _items.begin());
                int index = getIndex(object);
                if (index != -1) {
                    _items.erase(objectsIterator);
                    _nodes[index]->insert(object);
                } else {
                    objectsIterator++;
                }
            }
        }
    }
}

std::vector<TerrainObject *> QuadTree::retrieve(std::vector<TerrainObject *> returnObjects,
                        TerrainObject *object)
{
    // Recursively find all of the objects that reside in the same node as the object
    int index = getIndex(object);
    if (index != -1 && _nodes[0] != NULL) {
        _nodes[index]->retrieve(returnObjects, object);
    }
    
    std::vector<TerrainObject *>::iterator it;
    returnObjects.insert(it, _items.begin(), _items.end());
    
    return returnObjects;
}

void QuadTree::clear()
{
    // Recursively set the nodes to null
    for (int i = 0; i < sizeof(*_nodes); i++) {
        if (_nodes[i] != NULL) {
            _nodes[i]->clear();
        }
    }
}

#pragma mark - Private Methods
void QuadTree::split()
{
    int width = (int)(_bounds->getWidth()/2);
    int height = (int)(_bounds->getHeight()/2);
    int x = (int)_bounds->getX();
    int y = (int)_bounds->getY();
    
    // Create a new quadtree for each quadrant
    
    // I
    _nodes[0] = new QuadTree(_level++, new BoundingBox(createPoint2d(width*2, height*2),
                                                   createPoint2d(width, height)));
    
    // II
    _nodes[1] = new QuadTree(_level++, new BoundingBox(createPoint2d(width, height*2),
                                                   createPoint2d(x, height)));
    
    // III
    _nodes[2] = new QuadTree(_level++, new BoundingBox(createPoint2d(width, height),
                                                   createPoint2d(x, y)));
    
    // IV
    _nodes[3] = new QuadTree(_level++, new BoundingBox(createPoint2d(width*2, height),
                                                   createPoint2d(width, y)));
    
}

int QuadTree::getIndex(TerrainObject *object)
{
    double verticalMidpoint = _bounds->getX() + (_bounds->getWidth()/2);
    double horizontalMidpoint = _bounds->getY() + (_bounds->getHeight()/2);
    
    bool topQuadrant = (object->bounds().getY() > horizontalMidpoint);
    bool bottomQuadrant = (object->bounds().getY() < horizontalMidpoint &&
                           object->bounds().getY() + object->bounds().getHeight() < horizontalMidpoint);
    bool leftQuadrant = (object->bounds().getX() < verticalMidpoint &&
                         object->bounds().getX() + object->bounds().getWidth() < verticalMidpoint);
    bool rightQuadrant = (object->bounds().getX() > verticalMidpoint);
    
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
    return *_bounds;
}

QuadTree::~QuadTree()
{
    delete[] *_nodes;
}