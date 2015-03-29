//
//  MovableObject.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "MovableObject.h"
#include "BoundingBox.h"
#include <math.h>

#define SQR(x) (x*x)
#define PIdiv180 M_PI/180.0f
#define NULL_VECTOR F3dVector(0.0f,0.0f,0.0f)

#pragma mark Vector Helpers
SF3dVector F3dVector ( float x, float y, float z )
{
	SF3dVector tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return tmp;
}

float GetF3dVectorLength( SF3dVector * v)
{
	return (float)(sqrt(SQR(v->x)+SQR(v->y)+SQR(v->z)));
}

SF3dVector Normalize3dVector( SF3dVector v)
{
	SF3dVector res;
	float l = GetF3dVectorLength(&v);
	if (l == 0.0f) return NULL_VECTOR;
	res.x = v.x / l;
	res.y = v.y / l;
	res.z = v.z / l;
	return res;
}

SF3dVector operator+ (SF3dVector v, SF3dVector u)
{
	SF3dVector res;
	res.x = v.x+u.x;
	res.y = v.y+u.y;
	res.z = v.z+u.z;
	return res;
}
SF3dVector operator- (SF3dVector v, SF3dVector u)
{
	SF3dVector res;
	res.x = v.x-u.x;
	res.y = v.y-u.y;
	res.z = v.z-u.z;
	return res;
}


SF3dVector operator* (SF3dVector v, float r)
{
	SF3dVector res;
	res.x = v.x*r;
	res.y = v.y*r;
	res.z = v.z*r;
	return res;
}

SF3dVector CrossProduct (SF3dVector * u, SF3dVector * v)
{
	SF3dVector resVector;
	resVector.x = u->y*v->z - u->z*v->y;
	resVector.y = u->z*v->x - u->x*v->z;
	resVector.z = u->x*v->y - u->y*v->x;
    
	return resVector;
}
float operator* (SF3dVector v, SF3dVector u)	//dot product
{
	return v.x*u.x+v.y*u.y+v.z*u.z;
}

#pragma mark - Public methods
// TODO: Make this initializer more robust
MovableObject::MovableObject(float x, float y, float z)
{
	Position = F3dVector (x, y,	z);
	ViewDir = F3dVector(0.0, 0.0, -1.0);
	RightVector = F3dVector (1.0, 0.0, 0.0);
	UpVector = F3dVector (0.0, 1.0, 0.0);
	RotatedX = RotatedY = RotatedZ = 0.0;
}

void MovableObject::Move (SF3dVector Direction)
{
	Position = Position + Direction;
}

void MovableObject::RotateX (float Angle)
{
	RotatedX += Angle;
	
	//Rotate viewdir around the right vector:
	ViewDir = Normalize3dVector(ViewDir*cos(Angle*PIdiv180)
								+ UpVector*sin(Angle*PIdiv180));
    
	//now compute the new UpVector (by cross product)
	UpVector = CrossProduct(&ViewDir, &RightVector)*-1;
}

void MovableObject::RotateY (float Angle)
{
	RotatedY += Angle;
	
	//Rotate viewdir around the up vector:
	ViewDir = Normalize3dVector(ViewDir*cos(Angle*PIdiv180)
								- RightVector*sin(Angle*PIdiv180));
    
	//now compute the new RightVector (by cross product)
	RightVector = CrossProduct(&ViewDir, &UpVector);
}

void MovableObject::RotateZ (float Angle)
{
	RotatedZ += Angle;
	
	//Rotate viewdir around the right vector:
	RightVector = Normalize3dVector(RightVector*cos(Angle*PIdiv180)
                                    + UpVector*sin(Angle*PIdiv180));
    
	//now compute the new UpVector (by cross product)
	UpVector = CrossProduct(&ViewDir, &RightVector)*-1;
}

void MovableObject::MoveForward(float Distance)
{
	Position = Position + (ViewDir*-Distance);
}

float MovableObject::distance(MovableObject a, MovableObject b)
{
    SF3dVector vector = F3dVector(b.Position.x-a.Position.x,
                                  b.Position.y-a.Position.y,
                                  b.Position.z-a.Position.z);
    return GetF3dVectorLength(&vector);
}

SF3dVector MovableObject::getPosition()
{
    return Position;
}

SF3dVector MovableObject::getDirection()
{
    return ViewDir;
}

float MovableObject::getRotation()
{
    return RotatedY;
}