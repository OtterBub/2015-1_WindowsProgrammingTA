/*
* Copyright (c) 2006-2007 Erin Catto http://www.gphysics.com
*
* Permission to use, copy, modify, distribute and sell this software
* and its documentation for any purpose is hereby granted without fee,
* provided that the above copyright notice appear in all copies.
* Erin Catto makes no representations about the suitability 
* of this software for any purpose.  
* It is provided "as is" without express or implied warranty.
*/

#ifndef __BOX2D_H__
#define __BOX2D_H__

#include <string.h>
#include <Windows.h>
#include "..\GDIRect.h"

#include "World.h"
#include "Body.h"
#include "Joint.h"

World& CreateWorld( Vec2 grav, int iter );

namespace
{
	Body bodies[200];
	Joint joints[100];
	
	Body* bomb = NULL;

	float timeStep = 1.0f / 60.0f;
	int iterations = 10;
	Vec2 gravity(0.0f, -10.0f);

	int numBodies = 0;
	int numJoints = 0;

	int demoIndex = 0;

	World world = World( gravity, iterations );
}

//void DrawText(int x, int y, char *string)
//{
//	int len, i;
//
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	int w = glutGet(GLUT_WINDOW_WIDTH);
//	int h = glutGet(GLUT_WINDOW_HEIGHT);
//	gluOrtho2D(0, w, h, 0);
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//
//	glColor3f(0.9f, 0.6f, 0.6f);
//	glRasterPos2i(x, y);
//	len = (int) strlen(string);
//	for (i = 0; i < len; i++)
//		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
//
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//}

void DrawBody(Body* body, HDC hdc);

void DrawJoint(Joint* joint, HDC hdc);

void LaunchBomb();

// Single box
void Demo1(Body* b, Joint* j);

// A simple pendulum
void Demo2(Body* b, Joint* j);

// Varying friction coefficients
void Demo3(Body* b, Joint* j);

// A vertical stack
void Demo4(Body* b, Joint* j);

// A pyramid
void Demo5(Body* b, Joint* j);

// A teeter
void Demo6(Body* b, Joint* j);

// A suspension bridge
void Demo7(Body* b, Joint* j);

// Dominos
void Demo8(Body* b, Joint* j);

// A multi-pendulum
void Demo9(Body* b, Joint* j);

void InitDemo(int index);

void SimulationLoop( HDC hdc );

void Keyboard(unsigned char key, int x, int y);

void Reshape(int width, int height);

//int main(int argc, char** argv)
//{
//	InitDemo(0);
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
//	glutInitWindowSize(800, 800);
//	glutCreateWindow("Box2D");
//
//	glutReshapeFunc(Reshape);
//	glutDisplayFunc(SimulationLoop);
//	glutKeyboardFunc(Keyboard);
//	glutIdleFunc(SimulationLoop);
//
//	glutMainLoop();
//
//	return 0;
//}

#endif