#include "shelf.h"

void shelf::drawCube(GLfloat size, GLenum type)
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

void APIENTRY shelf::glutSolidCube(GLdouble size)
{
  drawCube(size, GL_QUADS);
}

void shelf::draw(){
	glPushMatrix();
    glCallList(shelfDL);
  glPopMatrix();
}


void shelf::drawOther(){
  glPushMatrix();
    glScalef(1,1,0.5);
    glCallList(shelfOtherDL);
    glPushMatrix();
      glTranslatef(2,2,1.5);
      glCallList(shelfOtherDL);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(2,-2,1.5);
      glCallList(shelfOtherDL);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-2,2,1.5);
      glCallList(shelfOtherDL);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-2,-2,1.5);
      glCallList(shelfOtherDL);
    glPopMatrix();
  glPopMatrix();
}


void shelf::initShelf(){
	glEnable(GL_DEPTH_TEST);
	shelfDL = createShelfDL();
}

void shelf::initShelfOther(){
  glEnable(GL_DEPTH_TEST);
  shelfOtherDL = createShelfOtherDL();
}


GLuint shelf::createShelfDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_shelf();
  glEndList();
  return(dl);
}

GLuint shelf::createShelfOtherDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_shelfOther();
  glEndList();
  return(dl);
}

void shelf::struct_shelf(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture1);
    //left
    glPushMatrix();
      glTranslatef(-1,0,0);
      glScalef(0.2,8.8,2);
    	glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-1,0,1);
      glScalef(0.2,8.8,1.5);
      GLUquadricObj* Sphere;
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //right
    glPushMatrix();
      glTranslatef(1,0,0);
      glScalef(0.2,8.8,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(1,0,1);
      glScalef(0.2,8.8,1.5);
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //lower
    glPushMatrix();
      glTranslatef(0,-1,0);
      glScalef(8.8,0.2,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,-1,1);
      glScalef(8.8,0.2,1.5);
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //lower-lower
    glPushMatrix();
      glTranslatef(0,-3,0);
      glScalef(6,0.2,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,-3,1);
      glScalef(6,0.2,1.5);
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //upper
    glPushMatrix();
      glTranslatef(0,1,0);
      glScalef(8.8,0.2,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,1,1);
      glScalef(8.8,0.2,1.5);
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //upper-upper
    glPushMatrix();
      glTranslatef(0,3,0);
      glScalef(6,0.2,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,3,1);
      glScalef(6,0.2,1.5);
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //right-right
    glPushMatrix();
      glTranslatef(3,0,0);
      glScalef(0.1,2,2);
      glutSolidCube(1);
    glPopMatrix();

    //right
    glPushMatrix();
      glTranslatef(2.1,0,0);
      glScalef(0.1,2,2);
      glutSolidCube(1);
    glPopMatrix();

    //right-mid
    glPushMatrix();
      glTranslatef(1.6,0,0);
      glScalef(1,0.1,2);
      glutSolidCube(1);
    glPopMatrix();

    //right-right-mid1
    glPushMatrix();
      glTranslatef(2.5,0.3,0);
      glScalef(0.9,0.1,2);
      glutSolidCube(1);
    glPopMatrix();


    //right-right-mid2
    glPushMatrix();
      glTranslatef(2.5,-0.3,0);
      glScalef(0.9,0.1,2);
      glutSolidCube(1);
    glPopMatrix();

    //left-left
    glPushMatrix();
      glTranslatef(-3,0,0);
      glScalef(0.1,2,2);
      glutSolidCube(1);
    glPopMatrix();

    //left
    glPushMatrix();
      glTranslatef(-2.1,0,0);
      glScalef(0.1,2,2);
      glutSolidCube(1);
    glPopMatrix();

    //left-mid
    glPushMatrix();
      glTranslatef(-1.6,0,0);
      glScalef(1,0.1,2);
      glutSolidCube(1);
    glPopMatrix();

    //left-left-mid1
    glPushMatrix();
      glTranslatef(-2.5,0.3,0);
      glScalef(0.9,0.1,2);
      glutSolidCube(1);
    glPopMatrix();


    //left-left-mid2
    glPushMatrix();
      glTranslatef(-2.5,-0.3,0);
      glScalef(0.9,0.1,2);
      glutSolidCube(1);
    glPopMatrix();

    //tv
    glBindTexture(GL_TEXTURE_2D, texture2);
    glPushMatrix();
      glTranslatef(0,-0.2,0);
      glScalef(0.8,0.8,0.6);
      glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-2.5,1.5,0);
      //glScalef(0.8,0.8,0.6);
      glutSolidTeapot(0.6);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(2.5,1.5,0);
      glRotatef(180,0,1,0);
      glutSolidTeapot(0.6);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void shelf::struct_shelfOther(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture1);
    //left
    glPushMatrix();
      glTranslatef(-1,0,0);
      glScalef(0.2,2,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-1,0,0.5);
      glScalef(0.2,2,1);
      GLUquadricObj* Sphere;
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //right
    glPushMatrix();
      glTranslatef(1,0,0);
      glScalef(0.2,2,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(1,0,0.5);
      glScalef(0.2,2,1);
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //lower
    glPushMatrix();
      glTranslatef(0,-1,0);
      glScalef(2,0.2,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,-1,0.5);
      glScalef(2,0.2,1);
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();

    //upper
    glPushMatrix();
      glTranslatef(0,1,0);
      glScalef(2,0.2,2);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,1,0.5);
      glScalef(2,0.2,1);
      Sphere=gluNewQuadric();
      gluQuadricTexture(Sphere,1);
      gluSphere(Sphere,0.5,20,20);
    glPopMatrix();


    
    glDisable(GL_TEXTURE_2D);
}


shelf::shelf(){

	glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  textureLoader tLoader1("textures/table2.bmp");

  glGenTextures(1, &texture2);
  glBindTexture(GL_TEXTURE_2D, texture2);
  textureLoader tLoader2("textures/tv1.bmp");

  glGenTextures(1, &texture5);
  glBindTexture(GL_TEXTURE_2D, texture5);
  textureLoader tLoader5("textures/roof3.bmp");

  glGenTextures(1, &texture4);
  glBindTexture(GL_TEXTURE_2D, texture4);
  textureLoader tLoader4("textures/wood3.bmp");

	initShelf();
  initShelfOther();
}

