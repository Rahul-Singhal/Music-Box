#ifndef LAMP_H
#define LAMP_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "textureLoader.h"
using namespace std;

class lamp{
private:
	GLint baseDL;
	GLint armLowerDL;
	GLint armUpperDL;
	GLint shadeDL;
	
	GLuint texture1 ;
	GLuint texture2 ;
	GLuint texture3 ;
	GLuint texture4 ;

	void initBase();
	void initArmLower();
	void initArmUpper();
	void initShade();

	GLuint createBaseDL() ;
	GLuint createArmLowerDL() ;
	GLuint createArmUpperDL() ;
	GLuint createShadeDL() ;

	void struct_base();
	void struct_armLower();
	void struct_armUpper();
	void struct_shade();


	static void drawCube(GLfloat size, GLenum type);
	void glutSolidCube1(GLdouble size);
public:
	lamp();
	void draw();
};

#endif