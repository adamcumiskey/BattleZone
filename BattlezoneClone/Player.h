//
//  Player.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__Player__
#define __BattlezoneClone__Player__

#include <iostream>
#include "MovableObject.h"

class Player : public MovableObject
{
private:
    
public:
    Player(float x, float y, float z);
    
    void MoveForward(float distance);
    
    // render the scene from the camera
    void updateCamera();
};

#endif /* defined(__BattlezoneClone__Player__) */
