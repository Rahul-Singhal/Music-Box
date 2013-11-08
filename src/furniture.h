#ifndef FURNITURE_H
#define FURNITURE_H

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

class furniture{
private:
	GLint boxDL;
	GLint coverDL;
	GLuint texture1 ;
	GLuint texture2 ;
	GLuint texture3 ;
	GLuint texture4 ;

	void initBox();
	void initCover();

	GLuint createBoxDL() ;
	GLuint createCoverDL() ;

	void struct_box();
	void struct_cover();


	static void drawCube(GLfloat size, GLenum type);
	void glutSolidCube1(GLdouble size);
public:
	furniture();
	void draw();
};

#endif