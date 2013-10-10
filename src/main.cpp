#include<cstdio>
#include<iostream>
#include "box.h"
#include "man.h"
using namespace std;

char MODE = 'N';
bool modeChange = false;
box * myBox;
man * myMan;


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

GLfloat xAngle = 19.8f;  // Rotational angle about the x-axis
GLfloat yAngle = -61.2f;  // Rotational angle about the y-axis
static float angle=0.0;
static float x=0.0f,y=0.0f,z=5.0f;
static float lx=0.0f,ly=0.0f,lz=-1.0f;
static float ratio;
static int lidAngle = 0;
static float baseHeight = 0.1;


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

  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f, 1.0f, 0.0f);
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



void orientMe(float ang) 
{
  lx = sin(ang);
  lz = -cos(ang);
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f, 1.0f, 0.0f);
}


void moveMeFlat(int i) 
{
  x = x + i*(lx)*0.1;
  z = z + i*(lz)*0.1;
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f,1.0f,0.0f);
}

void moveMeTangent(int i) 
{
  x = x - i*(lz)*0.1;
  z = z + i*(lx)*0.1;
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f,1.0f,0.0f);
}


void specialKey(int key, int x, int y) 
{
  if(MODE == 'N'){
    switch (key) {
    case GLUT_KEY_PAGE_UP : angle -= 0.01f;orientMe(angle);break;
    case GLUT_KEY_PAGE_DOWN : angle +=0.01f;orientMe(angle);break;
    case GLUT_KEY_UP : moveMeFlat(1);break;
    case GLUT_KEY_DOWN : moveMeFlat(-1);break;
    case GLUT_KEY_RIGHT : moveMeTangent(1);break;
    case GLUT_KEY_LEFT : moveMeTangent(-1);break;
    }
    glutPostRedisplay();
    return;
  }
  if(MODE == 'M'){
    myMan->specialKey(key,x,y);
    glutPostRedisplay();
    return;
  }
}

void processNormalKeys(unsigned char key, int x, int y) 
{
  if (key == 27) exit(0);
  if(modeChange){
    if(key == 'N' || key == 'n') MODE = 'N';
    if(key == 'M' || key == 'm') MODE = 'M';
    if(key == 'B' || key == 'b') MODE = 'B';
    modeChange = false;
    return;
  }
  if(key == 'Z' || key == 'z'){
    modeChange = true;
    return;
  }
  if(MODE == 'B'){
    float deltaHeight = 1.4/120;
    if (key == 'o' || key == 'O'){
        if(lidAngle > -120){lidAngle -= 2; 
          if(baseHeight < 0.8){
            baseHeight += deltaHeight;
          }
        }
        else return;
        myBox->resetBox(lidAngle, baseHeight);
        glutPostRedisplay();
        return;
    }
    if (key == 'c' || key == 'C'){
        if(lidAngle < 0){lidAngle += 2;
          if(baseHeight > 0.1){
            baseHeight -= deltaHeight;
          }
        }
        else return;
        myBox->resetBox(lidAngle, baseHeight);
        glutPostRedisplay();
        return;
    }
  }
  if(MODE == 'M'){
    myMan->processNormalKeys(key,x,y);
  }
}

void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  glPushMatrix();
    glTranslatef(-3.5,0.5,-5.0f);
    glScalef(0.5,0.5,0.5);
    glRotatef(-1.2, 1.0f, 0.0f, 0.0f);
    glRotatef(32.4, 0.0f, 1.0f, 0.0f);
    myMan->draw();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(2.5f, -1.8f, -5.0f);
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    myBox->draw();
  glPopMatrix();
  glutSwapBuffers();
}

void init(){
	myBox = new box();
  myMan = new man();
}

int main (int argc, char *argv[]) 
{

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640,360);
  glutCreateWindow("Assignment 2");
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glEnable (GL_TEXTURE_2D);
  glutDisplayFunc( display );
  glutReshapeFunc( resize );
  glutSpecialFunc(specialKey);
  glutKeyboardFunc(processNormalKeys);
  glutMouseFunc(mouse);        // Register handler for mouse event
  glutMotionFunc(mouseMove);   // Register handler for mouse move event
  init();
  glutMainLoop();
}