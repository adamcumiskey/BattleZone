//
//  TerrainManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/7/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "TerrainManager.h"
#include "TerrainObject.h"
#include "QuadTree.h"
#include "BoundingBox.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

TerrainManager::TerrainManager()
{
   
}

void TerrainManager::generateObjects(int n, int gridSize)
{
		// Construct the quadtree with the same bounding box as the terrain
		// I need to change this from using hard coded values.
    _boundingBox = new BoundingBox(25.0f, 25.0f, -25.0f, -25.0f);
    _quadTree = new QuadTree(0, *_boundingBox);
    
    for (int i = 0; i < n; i++) {
        
        // Generate random size between .1 and 1.1
        GLdouble size = 1;
        
        // generate random x and z positions within the grid
        GLfloat x = (rand() % gridSize) - (gridSize/2);
        GLfloat z = (rand() % gridSize) - (gridSize/2);
        
        // set the y to touch the 4ground
        GLfloat y = 0;
        
        // Generate a type
        TerrainType type = rand() % 2;
                
        TerrainObject *object = new TerrainObject(x,
                                             y,
                                             z,
                                             size,
                                             type);
        _objects.push_back(object);
    }
}

void TerrainManager::renderTerrain()
{
    drawGround();
    
    std::vector<TerrainObject *>::iterator it = _objects.begin();
    while (it != _objects.end()) {
        TerrainObject object = *_objects.at(it - _objects.begin());
        object.renderObject();
        it++;
    }
}

// Haven't got this to work yet. I need to recheck my pointer
// logic in the quadtree class.
// I also think that this function doesn't belong in this class
// I should be able to construct a const QuadTree for all of the
// terrain objects and check collisions for moving objects against
// that.
void TerrainManager::checkCollisions()
{
    // Clear the current tree
    _quadTree->clear();
    
    // Insert all of objects back into the tree
    std::vector<TerrainObject *>::iterator it = _objects.begin();
    while (it != _objects.end()) {
        TerrainObject object = *_objects.at(it - _objects.begin());
        _quadTree->insert(object);
        it++;
    }
    
    // Return a list of all of the potential collitions
    std::vector<TerrainObject *> collidableObjects;
    it = _objects.begin(); // reset the iterator
    while (it != _objects.end()) {
        collidableObjects.clear();
        
        TerrainObject object = *_objects.at(it - _objects.begin());
        _quadTree->retrieve(collidableObjects, object);
        it++;
    }
}

void TerrainManager::drawGround()
{
    // Draw 4 triangles from the origin with
    // 4 unit vertecies located at infinity
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 1.0, 0.0);
    glVertex4f(0, 0, 0, 1);
    glVertex4f(1, 0, 0, 0);
    glVertex4f(0, 0, 1, 0);
    glVertex4f(-1, 0, 0, 0);
    glVertex4f(0, 0, -1, 0);
    glVertex4f(1, 0, 0, 0);
    glEnd();
}

#pragma mark - Destructor
TerrainManager::~TerrainManager()
{
    delete _quadTree;
    delete _boundingBox;
    delete &_objects;
}
