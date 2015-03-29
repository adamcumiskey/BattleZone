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
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "WorldManager.h"


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
    worldManager = new WorldManager(numOfTerrainObjs, gameArea);
    enemyManager = new EnemyManager();
    playerManager = new PlayerManager();
}

// This method is called by the OpenGL displayFunc in main.cpp
// Draws all the objects in the game world
void GameManager::renderWorld()
{
    playerManager->updateCamera();
    worldManager->render();
    enemyManager->render();
    
    if (firing) {
        _playerProjectile->renderProjectile();
    }
}

// Called by the timerFunction in main.cpp
// Updates objects that need to be animated
void GameManager::animateGame()
{
    enemyManager->runAI();
    
//    if (firing) {
//        _playerProjectile->move();
//        
//        // Remove if the projectile has gone too far
//        if (MovableObject::distance(*_player, *_playerProjectile) >= PROJECTILE_MAX_DIST) {
//            removeProjectile(_playerProjectile);
//        }
//        
//        // remove if the projectile collides
//        checkProjectileCollisions();
//    }
}

// Called by the keyInput function in main.cpp
void GameManager::input(unsigned char key)
{
    playerManager->handleKeyboardInput(key);
    glutPostRedisplay();
}


#pragma mark - Projectile Manager
void GameManager::fire()
{
//    // Create a new projectile if one does not exist
//    if (!firing) {
//        firing = true;
//        _playerProjectile = new Projectile(_player->getPosition(),
//                                           _player->getDirection(),
//                                           _player->getRotation());
//    }
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




#pragma mark - Destructor
GameManager::~GameManager()
{
    delete enemyManager;
    delete playerManager;
    delete worldManager;
    delete _playerProjectile;
}