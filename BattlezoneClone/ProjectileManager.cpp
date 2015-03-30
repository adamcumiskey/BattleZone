//
//  ProjectileManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/29/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#include "ProjectileManager.h"
#include "Projectile.h"

void ProjectileManager::render()
{
    if (firing) {
        playerProjectile->render();
    }
}

void ProjectileManager::removeProjectile(Projectile *projectile)
{
    if (projectile != NULL) {
        delete projectile;
    }
    firing = false;
}