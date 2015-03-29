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
#include "Player.h"
#include "Projectile.h"
#include "BoundingBox.h"
#include "EnemyManager.h"


#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PROJECTILE_MAX_DIST 100

#pragma mark - Public methods
GameManager::GameManager()
{
    // Empty Constructor
}

void GameManager::initializeGame(int numOfTerrainObjs, int gameArea)
{
    generateObjects(numOfTerrainObjs, gameArea);
    _enemyManager = new EnemyManager();
    initializePlayer();
}

// This method is called by the OpenGL displayFunc in main.cpp
// Should only draw objects
void GameManager::renderWorld()
{
    _player->updateCamera();

    drawGround();
    
    std::vector<TerrainObject *>::iterator it = _terrainObjects.begin();
    while (it != _terrainObjects.end()) {
        TerrainObject object = *_terrainObjects.at(it - _terrainObjects.begin());
        object.renderObject();
        it++;
    }
    
    _enemyManager->render();
    if (firing) {
        _playerProjectile->renderProjectile();
    }
}

// Called by the timerFunction in main.cpp
// Updates objects that need to be animated
void GameManager::animateGame()
{
    _enemyManager->runAI();
    
    if (firing) {
        _playerProjectile->move();
        
        // Remove if the projectile has gone too far
        if (MovableObject::distance(*_player, *_playerProjectile) >= PROJECTILE_MAX_DIST) {
            removeProjectile(_playerProjectile);
        }
        
        // remove if the projectile collides
        checkProjectileCollisions();
    }
}

// Called by the keyInput function in main.cpp
void GameManager::input(unsigned char key)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        case 'w':
            _player->MoveForward(-.5);
            if (playerDidCollide()) {
                _player->MoveForward(.5);
            }
            break;
        case 'a':
            _player->RotateY(3.0);
            break;
        case 's':
            _player->MoveForward(.5);
            if (playerDidCollide()) {
                _player->MoveForward(-.5);
            }

            break;
        case 'd':
            _player->RotateY(-3.0);
            break;
        case ' ':
            fire();
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

#pragma mark - Player Manager
void GameManager::initializePlayer()
{
    _player = new Player(0, .5, 0);
}

bool GameManager::playerDidCollide()
{
//    BoundingBox playerBB = _player->bounds();
//    
//    // collides with enemy tank?
//    BoundingBox enemyBB = _enemy->bounds();
//    if (playerBB.intersects(enemyBB)) {
//        return true;
//    }
//    
//    // check collisions with the landscape
//    std::vector<TerrainObject *>::iterator it = _terrainObjects.begin();
//    while (it != _terrainObjects.end()) {
//        TerrainObject object = *_terrainObjects.at(it - _terrainObjects.begin());
//        BoundingBox terrainBB = object.bounds();
//        if (playerBB.intersects(terrainBB)) {
//            return true;
//        }
//        it++;
//    }
    
    return false;
}

#pragma mark - Projectile Manager
void GameManager::fire()
{
    // Create a new projectile if one does not exist
    if (!firing) {
        firing = true;
        _playerProjectile = new Projectile(_player->getPosition(),
                                           _player->getDirection(),
                                           _player->getRotation());
    }
}

void GameManager::removeProjectile(Projectile *_projectile)
{
    if (_projectile != NULL) {
        delete _projectile;
    }
    firing = false;
}

void GameManager::checkProjectileCollisions()
{
//    BoundingBox enemyBB = _enemy->bounds();
//    
//    // collided with enemy?
//    if (enemyBB.containsPoint(createPoint2d(_playerProjectile->centerX(),
//                                            _playerProjectile->centerY()))) {
//        removeProjectile(_playerProjectile);
//        
//        // If the projectile hits the enemy, destroy it and create a new one
//        removeEnemy();
//        createEnemy();
//    }
//    
//    // collided with terrain?
//    std::vector<TerrainObject *>::iterator it = _terrainObjects.begin();
//    while (it != _terrainObjects.end()) {
//        TerrainObject object = *_terrainObjects.at(it - _terrainObjects.begin());
//        BoundingBox terrainBB = object.bounds();
//        if (terrainBB.containsPoint(createPoint2d(_playerProjectile->centerX(),
//                                                  _playerProjectile->centerY()))) {
//            removeProjectile(_playerProjectile);
//        }
//        it++;
//    }
    
}


#pragma mark - Terrain Manager
void GameManager::generateObjects(int n, int gridSize)
{
    for (int i = 0; i < n; i++) {
        
        // Generate random size between 1 and 3
        GLdouble size = (float)(rand() % 3)+1;
        
        // generate random x and z positions within the grid
        GLfloat x = (rand() % gridSize) - (gridSize/2);
        GLfloat z = (rand() % gridSize) - (gridSize/2);
        
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

#pragma mark - Destructor
GameManager::~GameManager()
{
    delete _enemyManager;
    delete _player;
    delete _playerProjectile;
}