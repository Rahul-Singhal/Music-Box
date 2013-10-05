#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <GL/glut.h>
#include "textureLoader.h"
using namespace std;


static void
drawBox(GLfloat size, GLenum type)
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

void APIENTRY
glutSolidCube(GLdouble size)
{
  drawBox(size, GL_QUADS);
}



static float angleTheta=0.0,angleAlpha=0.0,ratio;
static float x=0.0f,y=0.0f,z=20.0f;
static float lookAtX, lookAtY, lookAtZ;
static float r1,r2;
static float r=20.0f;
static int lidAngle = 0;
int count = 0;
float deltaTheta = 0.1;

void resize(int w, int h)
{
  
  // Prevent a divide by zero, when window is too short
  // (you cant make a window of zero width).
  if(h == 0) h = 1;
  
  ratio = 1.0f * w / h;
  // Reset the coordinate system before modifying
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  // Set the viewport to be the entire window
  glViewport(0, 0, w, h);
  
  // Set the clipping volume
  gluPerspective(45, ratio, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  lookAtX = 0.0f;
  lookAtY = 1.0f;
  lookAtZ = 0.0f;
  gluLookAt(x, y, z, 0,0,0, lookAtX, lookAtY, lookAtZ);
}

/*----------------------------------------------------------*/
/*enumerate box parts*/
static GLint mainDL;
static GLint bottomBoxDL;
static GLint boxLidDL;
static GLuint textureID ;
/*enumerate box struct functions*/
void init();
void initBottomBox();
void initBoxLid();
GLuint createBottomBoxDL() ;
GLuint createBoxLidDL() ;
void struct_bottomBox();
void struct_boxLid();
/*----------------------------------------------------------*/

void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glBindTexture(GL_TEXTURE_2D, textureID);
  glColor3f(0.7,0.7,0.7);
  glBegin(GL_QUADS);
        glTexCoord2i(0,0);
        glVertex3i(-10, 10, 0);

        glTexCoord2i(1,0);
        glVertex3i(-10, -10, 0);
        
        glTexCoord2i(1,1);
        glVertex3i(10, -10, 0);
        
        glTexCoord2i(0,1);
        glVertex3i(10, 10, 0);
        
        
    glEnd();
  
  glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) 
{
	
}

void init(){

  textureLoader tLoader1("./wood.bmp");
  unsigned char* data = tLoader1.getData();
  int width = tLoader1.getWidth();
  int height = tLoader1.getHeight();
  cout<<"hey there"<<endl;
  glGenTextures(1, &textureID);
  //glBindTexture(GL_TEXTURE_2D, textureID);
  glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  
  glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
}



void specialKey(int key, int x, int y) {
	
}

void processNormalKeys(unsigned char key, int x, int y) 
{
  
}



int main (int argc, char *argv[]) 
{

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640,360);
  glutCreateWindow("Assignment 2");
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glEnable (GL_TEXTURE_2D);
  glutDisplayFunc( display );
  glutReshapeFunc( resize );
  glutMouseFunc( mouse );
  glutSpecialFunc(specialKey);
  glutKeyboardFunc(processNormalKeys);
  init();
  glutMainLoop();
}
