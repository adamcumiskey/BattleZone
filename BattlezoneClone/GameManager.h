//
//  GameManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  This class will take care of the game state, including rendering
//  the world, checking collisions, managing the enemy object,
//  managing the player object, and managing the projectiles fired.

#ifndef __BattlezoneClone__GameManager__
#define __BattlezoneClone__GameManager__

#include <iostream>
#include <vector>

class TerrainObject;
class Enemy;
class Player;
class Projectile;
class EnemyManager;
class GameManager
{
private:
    
    // Pointer to the player object
    Player *_player;
    // Initialize the player
    void initializePlayer();
    // check player collisions and return true if collision occurs
    bool playerDidCollide();
    
    // store the current projectile
    Projectile *_playerProjectile;
    // fire a bullet for the player
    void fire();
    // bool to keep track of whether the player has an active projectile
    bool firing;
    // remove the current projectile
    void removeProjectile(Projectile *_projectile);
    // check bullet collisions
    void checkProjectileCollisions();
    
    // Controller for Enemy objects
    EnemyManager *_enemyManager;
    
    // Vector containing all of the terrain objects
    std::vector<TerrainObject *> _terrainObjects;
    // Randomly generate n objects within an n*n grid
    void generateObjects(int n, int gridSize);
    // Draws an infinite green plane
    void drawGround();
    
public:
    GameManager();
    ~GameManager();
    
    // set up the game
    void initializeGame(int numOfTerrainObjs, int gameArea);
    
    // Renders the current gameWorld
    void renderWorld();
    
    // Called every animate call
    void animateGame();
    
    // Process keyboard interrupts
    void input(unsigned char key);
};


#endif /* defined(__BattlezoneClone__GameManager__) */
