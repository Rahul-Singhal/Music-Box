#include "lamp.h"

void lamp::drawCube(GLfloat size, GLenum type)
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

void lamp::glutSolidCube1(GLdouble size)
{
  drawCube(size, GL_QUADS);
}

void lamp::draw(){
	glPushMatrix();
    //draw base
    //glRotatef(90,1,0,0);
    glCallList(baseDL);
    //glTranslatef(0,0.3,0);
    glPushMatrix();
      glCallList(armLowerDL);
      glTranslatef(0,0.9,0);
      //rotation for upper arm
      glRotatef(45,0,0,1);
      glPushMatrix();
        glCallList(armUpperDL);
        glTranslatef(0,0.9,0);
        //rotation for shade
        //glRotatef(45,0,0,1);
        glPushMatrix();
          glRotatef(-60,0,1,0);
          glCallList(shadeDL);
        glPopMatrix();
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();
}

void lamp::initBase(){
  glEnable(GL_DEPTH_TEST);
  baseDL = createBaseDL();
}

void lamp::initArmLower(){
  glEnable(GL_DEPTH_TEST);
  armLowerDL = createArmLowerDL();
}

void lamp::initArmUpper(){
  glEnable(GL_DEPTH_TEST);
  armUpperDL = createArmUpperDL();
}


void lamp::initShade(){
	glEnable(GL_DEPTH_TEST);
	shadeDL = createShadeDL();
}

GLuint lamp::createBaseDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_base();
  glEndList();
  return(dl);
}

GLuint lamp::createArmLowerDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_armLower();
  glEndList();
  return(dl);
}

GLuint lamp::createArmUpperDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_armUpper();
  glEndList();
  return(dl);
}

GLuint lamp::createShadeDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_shade();
  glEndList();
  return(dl);
}


void lamp::struct_base(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture1);
  glPushMatrix();
    //glColor3f(0.3,0.5,0.1);
    //glScalef(0.2,0.2,0.2);
    glRotatef(90,1,0,0);
    glPushMatrix();
      GLUquadricObj *quadratic;
      quadratic = gluNewQuadric();
      gluQuadricTexture(quadratic,1);
      gluDisk(quadratic, 0,0.4,20,20);
      gluCylinder(quadratic,0.4,0.8,0.3, 20, 20);
      glTranslatef(0,0,0.3);
      gluDisk(quadratic, 0,0.8,20,20);
    glPopMatrix();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void lamp::struct_armUpper(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture2);
  glPushMatrix();
    //glScalef(0.2,0.2,0.2);
    glScalef(0.3,1.5,0.5);
    glRotatef(-90,1,0,0);
    glPushMatrix();
      GLUquadricObj *quadratic;
      quadratic = gluNewQuadric();
      gluQuadricTexture(quadratic,1);
      gluDisk(quadratic, 0,0.2,20,20);
      gluCylinder(quadratic,0.2,0.2,0.6, 20, 20);
      glTranslatef(0,0,0.6);
      gluDisk(quadratic, 0,0.2,20,20);
      //glTranslatef(0,0,-0.6);
    glPopMatrix();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void lamp::struct_shade(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture2);
  glPushMatrix();
    //glScalef(0.2,0.2,0.2);
    glPushMatrix();
      GLUquadricObj *quadratic;
      quadratic = gluNewQuadric();
      gluQuadricTexture(quadratic,1);
      gluDisk(quadratic, 0,0.2,20,20);
      gluCylinder(quadratic,0.2,0.4,0.5,20, 20);
      glTranslatef(0,0,0.4);
      //gluDisk(quadratic, 0,0.4,20,20);
    glPopMatrix();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void lamp::struct_armLower(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture2);
  glPushMatrix();
    //glScalef(0.2,0.2,0.2);
    glScalef(0.3,1.5,0.5);
    glRotatef(-90,1,0,0);
    glPushMatrix();
      GLUquadricObj *quadratic;
      quadratic = gluNewQuadric();
      gluQuadricTexture(quadratic,1);
      gluDisk(quadratic, 0,0.2,20,20);
      gluCylinder(quadratic,0.2,0.2,0.6, 20, 20);
      glTranslatef(0,0,0.6);
      gluDisk(quadratic, 0,0.2,20,20);
    glPopMatrix();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

lamp::lamp(){

	glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  textureLoader tLoader1("textures/lamp1.bmp");

  glGenTextures(1, &texture2);
  glBindTexture(GL_TEXTURE_2D, texture2);
  textureLoader tLoader2("textures/lamp2.bmp");

  glGenTextures(1, &texture3);
  glBindTexture(GL_TEXTURE_2D, texture3);
  textureLoader tLoader3("textures/stone2_part2.bmp");


	initBase();
  initShade();
  initArmUpper();
  initArmLower();
}

