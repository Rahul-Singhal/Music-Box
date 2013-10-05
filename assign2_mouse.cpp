#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <GL/glut.h>
#include "textureLoader.h"
using namespace std;


// Variable to control the speed of rotation with the mouse
#define DEGREES_PER_PIXEL  0.6f

// Structure to keep track of the mouse state 
typedef struct {
  bool leftButton;
  bool rightButton;
  int x;
  int y;
} MouseState;

MouseState mouseState = {false, false, 0, 0};

// Animation
GLfloat xAngle = 0.0f;  // Rotational angle about the x-axis
GLfloat yAngle = 0.0f;  // Rotational angle about the y-axis


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



static float ratio;
static int lidAngle = 0;

void resize(int w, int h)
{
  
  // Prevent a divide by zero, when window is too short
  // (you cant make a window of zero width).
  if(h == 0) h = 1;
  
  ratio = 1.0f * w / h;
  // Reset the coordinate system before modifying

  // Set the viewport to be the entire window
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // Set the clipping volume
  gluPerspective(45, ratio, 0.1, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
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
  glLoadIdentity();   // Reset the view
  glTranslatef(0.0f, 0.0f, -10.0f);
  glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
  glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
  
  glPushMatrix();
    glCallList(bottomBoxDL);
    glCallList(boxLidDL);
  glPopMatrix();
  glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
  // update the button state
  if(button == GLUT_LEFT_BUTTON)
  {
    if(state == GLUT_DOWN)
      mouseState.leftButton = true;
    else
      mouseState.leftButton = false;
  }
  if(button == GLUT_RIGHT_BUTTON)
  {
    if(state == GLUT_DOWN)
      mouseState.rightButton = true;
    else
      mouseState.rightButton = false;
  }
  
  // update the mouse position, so we can track the mouse move
  mouseState.x = x;
  mouseState.y = y;
}

// Handler for mouse move event
void mouseMove(int x, int y)
{
  // Calculate the displacement in movement 
  int xDelta = mouseState.x - x;
  int yDelta = mouseState.y - y;

  // Commit the mouse position 
  mouseState.x = x;
  mouseState.y = y;

  // If left button is down, change the rotation angle for next frame 
  if(mouseState.leftButton) {
    xAngle -= yDelta * DEGREES_PER_PIXEL;
    yAngle -= xDelta * DEGREES_PER_PIXEL;
  }
  glutPostRedisplay();
}

void init(){

  textureLoader tLoader1("./images.bmp");
  unsigned char* pixels = tLoader1.getData();
  int width = tLoader1.getWidth();
  int height = tLoader1.getHeight();

   glShadeModel(GL_SMOOTH);               // Enable smooth shading of color
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set background (clear) color to white
   
   // Depth-buffer for hidden surface removal
   glClearDepth(1.0f);       // Set clear depth value to farthest
   glEnable(GL_DEPTH_TEST);  // Enable depth-buffer for hidden surface removal
   glDepthFunc(GL_LEQUAL);   // The type of depth testing to do



   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, 
         GL_UNSIGNED_BYTE, pixels);  // Create texture from image data
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   
   glEnable(GL_TEXTURE_2D);  // Enable 2D texture 
   
   // Correct texture distortion in perpective projection
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  

  initBottomBox();
  initBoxLid();
}

void initBottomBox(){
	glEnable(GL_DEPTH_TEST);
	bottomBoxDL = createBottomBoxDL();
}

void initBoxLid(){
  glEnable(GL_DEPTH_TEST);
  boxLidDL = createBoxLidDL();
}


void specialKey(int key, int x, int y) {
	
}

void processNormalKeys(unsigned char key, int x, int y) 
{
  if (key == 27) exit(0);
  if (key == 'o' || key == 'O'){
      if(lidAngle > -80)lidAngle -= 2;
      else return;
      boxLidDL = createBoxLidDL();
      glutPostRedisplay();
      return;
  }
  if (key == 'c' || key == 'C'){
      if(lidAngle < 0)lidAngle += 2;
      else return;
      boxLidDL = createBoxLidDL();
      glutPostRedisplay();
      return;
  }
}

GLuint createBottomBoxDL() 
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_bottomBox();
  glEndList();
  return(dl);
}

GLuint createBoxLidDL() 
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
  glEndList();
  return(dl);
}

void struct_bottomBox(){
	  glColor3f(0.8,0.8,0.8);
	  /*bottom plane*/
	  glPushMatrix();
		  glScalef(3.0f,0.1f,2.0f);
		  glutSolidCube(1);
	  glPopMatrix();
	  //glColor3F(0.7,0.45,0.2);
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
}

void struct_boxLid(){
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
  glutMouseFunc(mouse);        // Register handler for mouse event
  glutMotionFunc(mouseMove);   // Register handler for mouse move event
  init();
  glutMainLoop();
}
