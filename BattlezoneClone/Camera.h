//
//  Camera.h
//  BattlezoneClone
//
// Adapted from http://www.opengl.org/sdk/docs/tutorials/CodeColony/camera.php

#define PI 3.1415926535897932384626433832795
#define PIdiv180 (PI/180.0)

#ifndef __BattlezoneClone__Camera__
#define __BattlezoneClone__Camera__

#include <iostream>

#endif /* defined(__BattlezoneClone__Camera__) */

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

struct SF3dVector  //Float 3d-vect, normally used
{
	GLfloat x,y,z;
};
struct SF2dVector
{
	GLfloat x,y;
};
SF3dVector F3dVector ( GLfloat x, GLfloat y, GLfloat z );

class CCamera
{
private:
	
	SF3dVector ViewDir;
	SF3dVector RightVector;
	SF3dVector UpVector;
	SF3dVector Position;
    
	GLfloat RotatedX, RotatedY, RotatedZ;
	
public:
	CCamera(GLfloat x, GLfloat y, GLfloat z);
	void Render ( void );	//executes some glRotates and a glTranslate command
    //Note: You should call glLoadIdentity before using Render
    
	void Move ( SF3dVector Direction );
	void RotateX ( GLfloat Angle );
	void RotateY ( GLfloat Angle );
	void RotateZ ( GLfloat Angle );
    
	void MoveForward ( GLfloat Distance );
	void MoveUpward ( GLfloat Distance );
	void StrafeRight ( GLfloat Distance );
    
    
    
};