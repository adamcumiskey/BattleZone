//
//  PlayerManager.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 3/29/15.
//  Copyright (c) 2015 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__PlayerManager__
#define __BattlezoneClone__PlayerManager__

#include <stdio.h>

class Player;
class PlayerManager
{
private:
    // Initialize the player
    void initializePlayer();
public:
    PlayerManager();
    ~PlayerManager();
    
    // Pointer to the player object
    Player *player;
    
    // update the camera postion
    void updateCamera();
    
    // Handle user input
    void handleKeyboardInput(unsigned char key);
    
    // check player collisions and return true if collision occurs
    bool playerDidCollide();
};

#endif /* defined(__BattlezoneClone__PlayerManager__) */
