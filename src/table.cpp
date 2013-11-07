#include "table.h"

void table::drawCube(GLfloat size, GLenum type)
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

void table::glutSolidCube1(GLdouble size)
{
  drawCube(size, GL_QUADS);
}

void table::draw(){
	glPushMatrix();
    //draw base
    //glRotatef(90,1,0,0);
    glCallList(holderDL);
    //glTranslatef(0,2,0);
    glPushMatrix();
      glCallList(surfaceDL);
    glPopMatrix();
    
  glPopMatrix();
}

void table::initHolder(){
  glEnable(GL_DEPTH_TEST);
  holderDL = createHolderDL();
}

void table::initSurface(){
  glEnable(GL_DEPTH_TEST);
  surfaceDL = createSurfaceDL();
}

GLuint table::createHolderDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_holder();
  glEndList();
  return(dl);
}

GLuint table::createSurfaceDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_surface();
  glEndList();
  return(dl);
}


void table::struct_holder(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture1);
  glPushMatrix();
    //glScalef(0.2,0.2,0.2);
    glRotatef(90,1,0,0);
    glPushMatrix();
      GLUquadricObj *quadratic;
      quadratic = gluNewQuadric();
      gluQuadricTexture(quadratic,1);
      gluDisk(quadratic, 0,0.4,20,20);
      gluCylinder(quadratic,0.4,0.8,2, 20, 20);
      glTranslatef(0,0,2);
      gluDisk(quadratic, 0,0.8,20,20);
    glPopMatrix();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void table::struct_surface(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture1);
  glPushMatrix();
    glScalef(1,1,0.8);
    glPushMatrix();
      glRotatef(90,1,0,0);
      glPushMatrix();
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        gluQuadricTexture(quadratic,1);
        gluDisk(quadratic, 0,3,20,20);
        gluCylinder(quadratic,3,3,0.2, 20, 20);
        glTranslatef(0,0,0.2);
        gluDisk(quadratic, 0,3,20,20);
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}


table::table(){

	glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  textureLoader tLoader1("textures/table2.bmp");

  glGenTextures(1, &texture2);
  glBindTexture(GL_TEXTURE_2D, texture2);
  textureLoader tLoader2("textures/stone2_part1.bmp");

  glGenTextures(1, &texture3);
  glBindTexture(GL_TEXTURE_2D, texture3);
  textureLoader tLoader3("textures/stone2_part2.bmp");


	initHolder();
  initSurface();
}

