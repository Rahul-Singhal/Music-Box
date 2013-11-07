#ifndef BOX_H
#define BOX_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "man.h"
using namespace std;


//state of box {baseHeight,lidAngle}


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
	 //state variables
	 float baseHeight;
	 float lidAngle;
	 float baseHeightIF;
	 float lidAngleIF;

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
	void glutSolidCube1(GLdouble size);

public:
	box();
	void draw();
	void resetBox(float lidAngle, float baseHeight);
	//this function will append the state of box in the file
	void getState(FILE * fp);
	bool setState(FILE * fp, int numFrames);
	void nextFrame();

};

#endif