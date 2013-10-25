#include "room.h"

void room::drawCube(GLfloat size, GLenum type)
{
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;
  for (i = 5; i >= 0; i--) {
    glBegin(type);
    glNormal3fv(&n[i][0]);
    glTexCoord2f (0.0, 0.0); glVertex3fv(&v[faces[i][0]][0]);
    glTexCoord2f (1.0, 0.0); glVertex3fv(&v[faces[i][1]][0]);
    glTexCoord2f (1.0, 1.0); glVertex3fv(&v[faces[i][2]][0]);
    glTexCoord2f (0.0, 1.0); glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

void APIENTRY room::glutSolidCube(GLdouble size)
{
  drawCube(size, GL_QUADS);
}

void room::draw(){
	glPushMatrix();
    glCallList(roomDL);
    glCallList(doorDL);
  glPopMatrix();
}

void room::initRoom(){
	glEnable(GL_DEPTH_TEST);
	roomDL = createRoomDL();
}

void room::initDoor(){
	glEnable(GL_DEPTH_TEST);
	doorDL = createDoorDL();
}

GLuint room::createRoomDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_room();
  glEndList();
  return(dl);
}

GLuint room::createDoorDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_door();
  glEndList();
  return(dl);
}

void room::struct_room(){
  glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    	glBindTexture(GL_TEXTURE_2D, texture1);
    	//glScalef(0.5,0.5,0.5);
    	//glColor3f(0.2,0.1,0.5);
    	glPushMatrix();
	    	//back wall
    		glTranslatef(0,0,-4);
	    	glScalef(12,8,0.1);
	      glutSolidCube(1);
	    glPopMatrix();

      glBindTexture(GL_TEXTURE_2D, texture3);
      //left wall
      //glColor3f(0.7,0.1,0.5);
      glPushMatrix();
      	glTranslatef(-5.95,0,0);
	      glScalef(0.1,8,8);
	      glutSolidCube(1);
	    glPopMatrix();

	    //right wall
      //glColor3f(0.7,0.2,0.9);
      glPushMatrix();
      	glTranslatef(5.95,0,0);
	      glScalef(0.1,8,8);
	      glutSolidCube(1);
	    glPopMatrix();

      glBindTexture(GL_TEXTURE_2D, texture5);
	    //top wall
      //glColor3f(0.2,0.34,0.12);
      glPushMatrix();
      	glTranslatef(0,3.95,0);
	      glScalef(12,0.1,8);
	      glutSolidCube(1);
	    glPopMatrix();

      glPushMatrix();
        glTranslatef(0,4,0);
        glScalef(0.4,7,0.4);
        glRotatef(90,1,0,0);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        gluQuadricTexture(quadratic,1);
        gluCylinder(quadratic,0.05,0.05,0.3, 20, 20);
      glPopMatrix();
      
      glBindTexture(GL_TEXTURE_2D, texture6);
      glPushMatrix();
        glTranslatef(0,1.5,0);
        glScalef(0.4,0.8,0.4);
        GLUquadricObj* Sphere;
        Sphere=gluNewQuadric();
        gluQuadricOrientation(Sphere,GLU_OUTSIDE);
        gluQuadricTexture(Sphere,1);
        gluSphere(Sphere,0.5,20,20);
      glPopMatrix();


      glBindTexture(GL_TEXTURE_2D, texture2);
    //bottom wall
      //glColor3f(0.2,0.34,0.12);
      glPushMatrix();
        glTranslatef(0,-3.95,0);
        glScalef(12,0.1,8);
        glutSolidCube(1);
      glPopMatrix();
	    

	    glBindTexture(GL_TEXTURE_2D, texture1);
	    //frontLeft wall
	    //glColor3f(0.6,0.4,0.62);
      glPushMatrix();
      	glTranslatef(-4,0,4);
	      glScalef(4,8,0.1);
	      glutSolidCube(1);
	    glPopMatrix();

	    glBindTexture(GL_TEXTURE_2D, texture1);
	    //frontRight wall
	    //glColor3f(0.6,0.4,0.62);
      glPushMatrix();
      	glTranslatef(4,0,4);
	      glScalef(4,8,0.1);
	      glutSolidCube(1);
	    glPopMatrix();

	    glBindTexture(GL_TEXTURE_2D, texture1);
	    //frontTop wall
	    //glColor3f(0.2,0.8,0.62);
      glPushMatrix();
      	glTranslatef(0,3,4);
	      glScalef(4,2,0.1);
	      glutSolidCube(1);
	    glPopMatrix();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);
}

void room::struct_door(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture4);
    glPushMatrix();
    	glPushMatrix();
		    //glColor3f(0.9,0.4,0.8);
	      glPushMatrix();
	      	glTranslatef(0,-1.0,4);
          glPushMatrix();
            glPushMatrix();
    		      glScalef(4,6,0.1);
    		      glutSolidCube(1);
            glPopMatrix();
          glPopMatrix();
		    glPopMatrix();
        glPushMatrix();
          glColor3f(0.24,0.121,0);
          glTranslatef(1.5,-1.0,4);
          glutSolidSphere(0.2,20,20);
          glColor3f(1,1,1);
        glPopMatrix();
    	glPopMatrix();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

room::room(){

	glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  textureLoader tLoader1("textures/wall4.bmp");

  glGenTextures(1, &texture2);
  glBindTexture(GL_TEXTURE_2D, texture2);
  textureLoader tLoader2("textures/floor2.bmp");

  glGenTextures(1, &texture3);
  glBindTexture(GL_TEXTURE_2D, texture3);
  textureLoader tLoader3("textures/wall5.bmp");

  glGenTextures(1, &texture5);
  glBindTexture(GL_TEXTURE_2D, texture5);
  textureLoader tLoader5("textures/roof3.bmp");

  glGenTextures(1, &texture4);
  glBindTexture(GL_TEXTURE_2D, texture4);
  textureLoader tLoader4("textures/wood3.bmp");

  glGenTextures(1, &texture6);
  glBindTexture(GL_TEXTURE_2D, texture6);
  textureLoader tLoader6("textures/light1.bmp");

	initRoom();
  initDoor();
}

