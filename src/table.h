#ifndef TABLE_H
#define TABLE_H

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

class table{
private:
	GLint surfaceDL;
	GLint holderDL;
	
	GLuint texture1 ;
	GLuint texture2 ;
	GLuint texture3 ;
	GLuint texture4 ;

	void initSurface();
	void initHolder();

	GLuint createSurfaceDL() ;
	GLuint createHolderDL() ;

	void struct_surface();
	void struct_holder();


	static void drawCube(GLfloat size, GLenum type);
	void glutSolidCube1(GLdouble size);
public:
	table();
	void draw();
};

#endif