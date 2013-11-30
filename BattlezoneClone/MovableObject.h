//
//  MovableObject.h
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#ifndef __BattlezoneClone__MovableObject__
#define __BattlezoneClone__MovableObject__

#include <iostream>

struct SF3dVector  //Float 3d-vect, normally used
{
	float x,y,z;
};
struct SF2dVector
{
	float x,y;
};
SF3dVector F3dVector ( float x, float y, float z );

class BoundingBox;
class MovableObject
{
protected:
	SF3dVector ViewDir;
	SF3dVector RightVector;
	SF3dVector UpVector;
	SF3dVector Position;
    
	float RotatedX, RotatedY, RotatedZ;
    
public:
    MovableObject(float x, float y, float z);
    
    void Move ( SF3dVector Direction );
	void RotateX ( float Angle );
	void RotateY ( float Angle );
	void RotateZ ( float Angle );
    
	void MoveForward ( float Distance );
    
    static float distance(MovableObject a, MovableObject b);
    
    SF3dVector getPosition();
    SF3dVector getDirection();
    float getRotation();
};

#endif /* defined(__BattlezoneClone__MovableObject__) */
