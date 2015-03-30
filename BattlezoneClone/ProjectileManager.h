//
//  ProjectileManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/29/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__ProjectileManager__
#define __BattlezoneClone__ProjectileManager__

#include <stdio.h>

class Projectile;
class ProjectileManager
{
public:
    // store the current projectile
    Projectile *playerProjectile;
    
    // bool to keep track of whether the player has an active projectile
    bool firing;
    
    // remove the current projectile
    void removeProjectile(Projectile *projectile);
    
    void render();
};

#endif /* defined(__BattlezoneClone__ProjectileManager__) */
