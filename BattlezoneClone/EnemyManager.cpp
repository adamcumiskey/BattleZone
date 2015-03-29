//
//  EnemyManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/29/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#include "EnemyManager.h"
#include "BoundingBox.h"
#include "Enemy.h"
#include "Player.h"
#include "TerrainObject.h"

EnemyManager::EnemyManager()
{
    createEnemy();
}

void EnemyManager::createEnemy()
{
    float x = (rand() % 100) - (50);
    float z = (rand() % 100) - (50);
    float angle = rand() % 360;
    
    enemy = new Enemy(x, .5, z);
    enemy->RotateY(angle);
    enemy->setAIState(AI_MOVE);
}

void EnemyManager::removeEnemy()
{
    delete enemy;
}

void EnemyManager::render()
{
    enemy->render();
}

void EnemyManager::runAI()
{
    EnemyState state = enemy->getAIState();
    switch (state) {
        case AI_NONE:
            break;
            
        case AI_MOVE:
            // If the enemy hits something, reverse and turn.
            // Or, if it has moved a certain distance, turn
            // Else move forward
            
            if (enemyDidCollide()) {
                enemy->setAIState(AI_REVERSE);
            } else if (enemy->getDistanceMoved() >= 10) {
                enemy->setAIState(AI_TURN);
                enemy->setTurnDirection(rand() % 2);
            } else {
                enemy->move();
            }
            break;
            
        case AI_REVERSE:
            // After reversing a certain distance,
            // turn and move forward
            
            if (enemy->getDistanceMoved() >= 3) {
                enemy->setAIState(AI_TURN);
                enemy->setTurnDirection(rand() % 2);
            } else {
                enemy->reverse();
            }
            break;
            
        case AI_TURN:
            // Turn until a certain angle is reached,
            // then move
            
            if (enemy->getAngleTurned() > 45) {
                enemy->setAIState(AI_MOVE);
            } else {
                enemy->turn();
            }
            break;
            
        default:
            break;
    }
}

// TODO: Refactor to use QuadTree
bool EnemyManager::enemyDidCollide()
{
//    BoundingBox enemyBB = enemy->bounds();
//    
//    // check collisions with player
//    if (enemyBB.intersects(_player->bounds())) {
//        return true;
//    }
//    
//    // check terrain collisions
//    std::vector<TerrainObject *>::iterator it = _terrainObjects.begin();
//    while (it != _terrainObjects.end()) {
//        TerrainObject object = *_terrainObjects.at(it - _terrainObjects.begin());
//        BoundingBox terrainBB = object.bounds();
//        if (terrainBB.intersects(enemyBB)) {
//            return true;
//        }
//        it++;
//    }
    
    return false;
}

EnemyManager::~EnemyManager()
{
    delete enemy;
}
