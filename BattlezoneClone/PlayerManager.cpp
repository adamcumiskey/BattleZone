//
//  PlayerManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/29/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#include "PlayerManager.h"
#include "Player.h"


PlayerManager::PlayerManager()
{
    initializePlayer();
}

void PlayerManager::initializePlayer()
{
    player = new Player(0, .5, 0);
}

void PlayerManager::updateCamera()
{
    player->updateCamera();
}

void PlayerManager::handleKeyboardInput(unsigned char key)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        case 'w':
            player->MoveForward(-.5);
            if (playerDidCollide()) {
                player->MoveForward(.5);
            }
            break;
        case 'a':
            player->RotateY(3.0);
            break;
        case 's':
            player->MoveForward(.5);
            if (playerDidCollide()) {
                player->MoveForward(-.5);
            }
            
            break;
        case 'd':
            player->RotateY(-3.0);
            break;
        case ' ':
//            fire();
            break;
        default:
            break;
    }
}

bool PlayerManager::playerDidCollide()
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

PlayerManager::~PlayerManager()
{
    delete player;
}