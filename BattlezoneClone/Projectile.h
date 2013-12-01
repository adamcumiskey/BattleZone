//
//  Projectile.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__Projectile__
#define __BattlezoneClone__Projectile__

#include <iostream>
#include "MovableObject.h"

class Player;
class Projectile : public MovableObject
{
private:
    int _displayList;
public:
    Projectile(SF3dVector playerPosition, SF3dVector direction, float angle);
    
    void renderProjectile();
    void move();
    
    float centerX();
    float centerY();
};

#endif /* defined(__BattlezoneClone__Projectile__) */
