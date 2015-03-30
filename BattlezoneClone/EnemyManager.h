//
//  EnemyManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/29/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__EnemyManager__
#define __BattlezoneClone__EnemyManager__

#include <stdio.h>

class Enemy;
class EnemyManager
{
public:
    EnemyManager();
    ~EnemyManager();
    
    // Pointer to the enemy object
    Enemy *enemy;
    
    // Create a new enemy
    void createEnemy();
    
    // Destroy the currentEnemy
    void removeEnemy();
    
    // Render the enemies
    void render();
    
    // run the enemy's AI routine
    void runAI();
    
    // check enemy collisions and return true if collision occurs
    bool enemyDidCollide();
};

#endif /* defined(__BattlezoneClone__EnemyManager__) */
