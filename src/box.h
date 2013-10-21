#ifndef BOX_H
#define BOX_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <GL/glut.h>
#include "man.h"
using namespace std;


class box{

private:

	/*enumerate box parts*/
	 GLint mainDL;
	 GLint bottomBoxDL;
	 GLint boxLidDL;
	 GLint boxBaseDL;
	 GLuint texture1 ;
	 GLuint texture2 ;
	 GLuint texture3 ;
	 float baseHeight;
	 float lidAngle;

	/*enumerate box struct functions*/
	void initBottomBox();
	void initBoxLid();
	void initBoxBase();
	GLuint createBottomBoxDL() ;
	GLuint createBoxLidDL() ;
	GLuint createBoxBaseDL() ;
	void struct_bottomBox();
	void struct_boxLid();
	void struct_boxBase();


	static void drawBox(GLfloat size, GLenum type);
	void APIENTRY glutSolidCube(GLdouble size);

public:
	box();
	void draw();
	void resetBox(float lidAngle, float baseHeight);

};

#endif