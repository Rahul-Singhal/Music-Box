#ifndef SHELF_H
#define SHELF_H

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

class shelf{
private:
	GLint shelfDL;
	GLint shelfOtherDL;
	GLuint texture1 ;
	GLuint texture2 ;
	GLuint texture3 ;
	GLuint texture4 ;
	GLuint texture5 ;

	void initShelf();
	void initShelfOther();
	
	GLuint createShelfDL() ;
	GLuint createShelfOtherDL() ;

	void struct_shelf();
	void struct_shelfOther();

	static void drawCube(GLfloat size, GLenum type);
	void glutSolidCube1(GLdouble size);
public:
	shelf();
	void draw();
	void drawOther();
};

#endif