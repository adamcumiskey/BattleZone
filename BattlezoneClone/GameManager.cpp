//
//  GameManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "GameManager.h"
#include "TerrainObject.h"
#include "Enemy.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

GameManager::GameManager()
{
    // Empty Constructor
}

void GameManager::initializeGame(int numOfTerrainObjs, int gameArea)
{
    generateObjects(numOfTerrainObjs, gameArea);
    createEnemy();
}

#pragma mark - Enemy Manager
void GameManager::createEnemy()
{
    _enemy = new Enemy(5, 0, 5, 0);
}

#pragma mark - Terrain Manager
void GameManager::generateObjects(int n, int gridSize)
{
    for (int i = 0; i < n; i++) {
        
        // Generate random size between 1 and 3
        GLdouble size = (float)(rand() % 3);
        
        // generate random x and z positions within the grid
        GLfloat x = (rand() % gridSize) - (gridSize/2);
        GLfloat z = (rand() % gridSize) - (gridSize/2);
        
        std::cout << "( " << x << ", " << z << ")" << std::endl;
        
        // set the y to touch the ground
        GLfloat y = 0;
        
        // Generate a type
        TerrainType type = rand() % 2;
        
        TerrainObject *object = new TerrainObject(x,
                                                  y,
                                                  z,
                                                  size,
                                                  type);
        _terrainObjects.push_back(object);
    }
}

void GameManager::updateGame()
{
    drawGround();
    
    std::vector<TerrainObject *>::iterator it = _terrainObjects.begin();
    while (it != _terrainObjects.end()) {
        TerrainObject object = *_terrainObjects.at(it - _terrainObjects.begin());
        object.renderObject();
        it++;
    }
    
    _enemy->renderEnemy();
}

void GameManager::drawGround()
{
    // Draw 4 triangles from the origin with
    // 4 unit vertecies located at infinity
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.75, 0.0);
    glVertex4f(0, 0, 0, 1);
    glVertex4f(1, 0, 0, 0);
    glVertex4f(0, 0, 1, 0);
    glVertex4f(-1, 0, 0, 0);
    glVertex4f(0, 0, -1, 0);
    glVertex4f(1, 0, 0, 0);
    glEnd();
}