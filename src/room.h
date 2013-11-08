#ifndef ROOM_H
#define ROOM_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
//#include <GLUT/glut.h>
//#include <OpenGL/gl.h>
//#include <OpenGL/glu.h>

#include <GL/glut.h>
#include "textureLoader.h"
using namespace std;

class room{
private:
	GLint roomDL;
	GLint doorDL;
	GLuint texture1 ;
	GLuint texture2 ;
	GLuint texture3 ;
	GLuint texture4 ;
	GLuint texture5 ;
	GLuint texture6 ;

	void initRoom();
	void initDoor();

	GLuint createRoomDL() ;
	GLuint createDoorDL() ;

	void struct_room();
	void struct_door();


	static void drawCube(GLfloat size, GLenum type);
	void glutSolidCube1(GLdouble size);
public:
	room();
	void draw();
};

#endif