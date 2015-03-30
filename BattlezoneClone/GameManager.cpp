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
#include "ProjectileManager.h"

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
    projectileManager = new ProjectileManager();
}

// This method is called by the OpenGL displayFunc in main.cpp
// Draws all the objects in the game world
void GameManager::renderWorld()
{
    playerManager->updateCamera();
    worldManager->render();
    enemyManager->render();
    projectileManager->render();
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


#pragma mark - Destructor
GameManager::~GameManager()
{
    delete enemyManager;
    delete playerManager;
    delete worldManager;
    delete projectileManager;
}