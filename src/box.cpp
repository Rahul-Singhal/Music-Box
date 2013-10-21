#include "box.h"
#include "textureLoader.h"

void box::drawBox(GLfloat size, GLenum type)
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

void APIENTRY box::glutSolidCube(GLdouble size)
{
  drawBox(size, GL_QUADS);
}

void box::draw(){
  glPushMatrix();
    glCallList(bottomBoxDL);
    glCallList(boxBaseDL);
    glCallList(boxLidDL);
  glPopMatrix();
}


 
void box::resetBox(float lidAngle, float baseHeight){
  this->lidAngle = lidAngle;
  this->baseHeight = baseHeight;
  boxLidDL = createBoxLidDL();
  boxBaseDL = createBoxBaseDL();
}


box::box(){
  lidAngle = 0;
  baseHeight = 0.1;

   glGenTextures(1, &texture1);
   glBindTexture(GL_TEXTURE_2D, texture1);
   textureLoader tLoader1("textures/wood3.bmp");

   glGenTextures(1, &texture2);
   glBindTexture(GL_TEXTURE_2D, texture2);
   textureLoader tLoader2("textures/wood4.bmp");

   glGenTextures(1, &texture3);
   glBindTexture(GL_TEXTURE_2D, texture3);
   textureLoader tLoader3("textures/wood5.bmp");
   
  initBottomBox();
  initBoxBase();
  initBoxLid();
}

void box::initBottomBox(){
	glEnable(GL_DEPTH_TEST);
	bottomBoxDL = createBottomBoxDL();
}

void box::initBoxLid(){
  glEnable(GL_DEPTH_TEST);
  boxLidDL = createBoxLidDL();
}

void box::initBoxBase(){
  glEnable(GL_DEPTH_TEST);
  boxBaseDL = createBoxBaseDL();
}


GLuint box::createBottomBoxDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_bottomBox();
  glEndList();
  return(dl);
}

GLuint box::createBoxBaseDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_boxBase();
  glEndList();
  return(dl);
}

GLuint box::createBoxLidDL() 
{
  GLuint dl;
  dl = glGenLists(2);
  glNewList(dl,GL_COMPILE);
  glPushMatrix();
    glTranslatef(0.0,1,-1);
    glRotatef(lidAngle,1.0,0,0);
    struct_boxLid();
    // glRotatef(-1*lidAngle,1.0,0,0);
    // glTranslatef(0.0,-1,1);
  glPopMatrix();
  glEndList();
  return(dl);
}

void box::struct_bottomBox(){
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture2);
  	  /*bottom plane*/
  	  glPushMatrix();
  		  glScalef(3.0f,0.1f,2.0f);
  		  glutSolidCube(1);
  	  glPopMatrix();
  	  //glColor3F(0.7,0.45,0.2);
      //glBindTexture(GL_TEXTURE_2D, texture1);
  	  /*left plane*/
  	  glPushMatrix();
  	  	  glTranslatef(-1.5,0.46,0);
  	      glScalef(0.1f,1.0f,2.0f);
  	      glutSolidCube(1);
  	  glPopMatrix();
  	  //glColor3F(0,0,1);
  	  /*right plane*/
  	  glPushMatrix();
  	  	  glTranslatef(1.5,0.46,0);
  	      glScalef(0.1f,1.0f,2.0f);
  	      glutSolidCube(1);
  	  glPopMatrix();
  	  
  	  //glColor3F(0.3,0.3,0.3);
  	  /*back plane*/
  	  glPushMatrix();
  	  	  glTranslatef(0,0.46,-1);
  	      glScalef(3.0f,1.0f,0.1f);
  	      glutSolidCube(1);
  	  glPopMatrix();
  	  
  	  //glColor3F(1,0,0);
  	  /*front plane*/
  	  glPushMatrix();
  	  	  glTranslatef(0,0.46,1);
  	      glScalef(3.0f,1.0f,0.1f);
  	      glutSolidCube(1);
  	  glPopMatrix();
    glPopMatrix();

}

void box::struct_boxBase(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture3);
    glPushMatrix();
      glTranslatef(0,baseHeight,0);
      glScalef(3.0f,0.1f,2.0f);
      glutSolidCube(1);
    glPopMatrix();
}

void box::struct_boxLid(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture1);
  glPushMatrix();
    glTranslatef(0,0.9,1);
    glRotatef(180,1.0,0,0);
      glPushMatrix();
        //glColor3F(0.0,0.0,0.0);
        /*bottom plane*/
        glPushMatrix();
          glScalef(3.0f,0.1f,2.0f);
          glutSolidCube(1);
        glPopMatrix();
        //glColor3F(0.7,0.45,0.2);
        //glBindTexture(GL_TEXTURE_2D, texture1);
        /*left plane*/
        glPushMatrix();
            glTranslatef(-1.5,0.46,0);
            glScalef(0.1f,1.0f,2.0f);
            glutSolidCube(1);
        glPopMatrix();
        //glColor3F(0,0,1);
        /*right plane*/
        glPushMatrix();
            glTranslatef(1.5,0.46,0);
            glScalef(0.1f,1.0f,2.0f);
            glutSolidCube(1);
        glPopMatrix();
        
        //glColor3F(0.3,0.3,0.3);
        /*back plane*/
        glPushMatrix();
            glTranslatef(0,0.46,-1);
            glScalef(3.0f,1.0f,0.1f);
            glutSolidCube(1);
        glPopMatrix();
        
        //glColor3F(1,0,0);
        /*front plane*/
        glPushMatrix();
            glTranslatef(0,0.46,1);
            glScalef(3.0f,1.0f,0.1f);
            glutSolidCube(1);
        glPopMatrix();
      glPopMatrix();
  glPopMatrix();
}




