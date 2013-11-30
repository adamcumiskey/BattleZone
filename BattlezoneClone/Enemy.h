//
//  Enemy.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/23/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__Enemy__
#define __BattlezoneClone__Enemy__

#include <iostream>
#include "MovableObject.h"

enum {
    AI_NONE, // Inactive
    AI_MOVE, // Moving forward
    AI_TURN, // Turning to a new direction
    AI_AIM, // Turning towards the Player
    AI_FIRE // Firing a shell at the player
}; typedef int EnemyState;

enum {
    LEFT,
    RIGHT
}; typedef int Direction;

class Enemy : public MovableObject
{
private:
    EnemyState _currentState;
    int _displayList;
    
public:
    Enemy(float x, float y, float z);
    
    void renderEnemy();
    void changeAIToState(EnemyState newState);
    
    void move();
    void turn(Direction direction);
    void aim(SF3dVector targetPosition);
    void fire();
    
    BoundingBox bounds();
};

#endif /* defined(__BattlezoneClone__Enemy__) */
