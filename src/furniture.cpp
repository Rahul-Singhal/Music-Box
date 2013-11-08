#include "furniture.h"

void furniture::drawCube(GLfloat size, GLenum type)
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

void furniture::glutSolidCube1(GLdouble size)
{
  drawCube(size, GL_QUADS);
}

void furniture::draw(){
  glPushMatrix();
    glTranslatef(0,-1.5,0);
    glRotatef(30,0,1,0);
    glCallList(coverDL);
    glTranslatef(0,-1,1);
    glCallList(boxDL);
    glTranslatef(0,1,-0.3);
    glCallList(boxDL);
    glTranslatef(0,1,-0.3);
    glCallList(boxDL);
  glPopMatrix();
}



void furniture::initBox(){
  glEnable(GL_DEPTH_TEST);
  boxDL = createBoxDL();
}

void furniture::initCover(){
  glEnable(GL_DEPTH_TEST);
  coverDL = createCoverDL();
}



GLuint furniture::createBoxDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_box();
  glEndList();
  return(dl);
}

GLuint furniture::createCoverDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_cover();
  glEndList();
  return(dl);
}


void furniture::struct_box(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture1);
    glPushMatrix();
      glPushMatrix();
        //back
        glTranslatef(0,0,-0.9);
        glScalef(2,1,0.2);
        glutSolidCube1(1);
      glPopMatrix();
      glPushMatrix();
        //left
        glTranslatef(-0.9,0,0);
        glScalef(0.2,1,2);
        glutSolidCube1(1);
      glPopMatrix();

      glPushMatrix();
        //right
        glTranslatef(0.9,0,0);
        glScalef(0.2,1,2);
        glutSolidCube1(1);
      glPopMatrix();

      glPushMatrix();
        //bottom
        glTranslatef(0,-0.4,0);
        glScalef(2,0.2,2);
        glutSolidCube1(1);
      glPopMatrix();

      glPushMatrix();
        //front
        glTranslatef(0,0,0.9);
        glScalef(2,0.8,0.2);
        glutSolidCube1(1);
      glPopMatrix();

      glBindTexture(GL_TEXTURE_2D, texture2);
      glPushMatrix();
        //handle
        glTranslatef(0,0,1);
        glScalef(0.4,0.1,0.1);
        glutSolidCube1(1);
      glPopMatrix();
  
    glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}


void furniture::struct_cover(){
  glEnable(GL_TEXTURE_2D);
    glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture2);
      glPushMatrix();
        //back
        glTranslatef(0,0,-1);
        glScalef(2,3,0.2);
        glutSolidCube1(1);
      glPopMatrix();
      glPushMatrix();
        //left
        glTranslatef(-1,0,0);
        glScalef(0.2,3,2);
        glutSolidCube1(1);
      glPopMatrix();

      glPushMatrix();
        //right
        glTranslatef(1,0,0);
        glScalef(0.2,3,2);
        glutSolidCube1(1);
      glPopMatrix();

      glPushMatrix();
        //bottom
        glTranslatef(0,-1.5,0);
        glScalef(2,0.2,2);
        glutSolidCube1(1);
      glPopMatrix();

      glPushMatrix();
        //top
        glTranslatef(0,1.5,0);
        glScalef(2,0.2,2);
        glutSolidCube1(1);
      glPopMatrix();

      
  
    glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}



furniture::furniture(){

  glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  textureLoader tLoader1("textures/table2.bmp");

  glGenTextures(1, &texture2);
  glBindTexture(GL_TEXTURE_2D, texture2);
  textureLoader tLoader2("textures/wood3.bmp");

  initBox();
  initCover();
}

