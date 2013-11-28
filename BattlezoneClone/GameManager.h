//
//  GameManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//
//  This class will take care of the game state, including rendering
//  the world, checking collisions, managing the enemy object, and
//  managing the player object.

#ifndef __BattlezoneClone__GameManager__
#define __BattlezoneClone__GameManager__

#include <iostream>
#include <vector>

class TerrainObject;
class Enemy;
class Player;
class GameManager
{
private:
    // Pointer to the player object
    Player *_player;
    
    // Initialize the player
    void initializePlayer();
    
    // Pointer to the enemy object
    Enemy *_enemy;
    
    // Create a new enemy
    void createEnemy();
    
    
    // Vector containing all of the terrain objects
    std::vector<TerrainObject *> _terrainObjects;
    
    // Randomly generate n objects within an n*n grid
    void generateObjects(int n, int gridSize);
    
    // Draws an infinite plane
    void drawGround();
    
public:
    GameManager();
    
    void initializeGame(int numOfTerrainObjs, int gameArea);
    
    // Called every frame to take care of updating the game world
    void updateGame();
    
    // Process keyboard interrupts
    void input(unsigned char key);
};


#endif /* defined(__BattlezoneClone__GameManager__) */
