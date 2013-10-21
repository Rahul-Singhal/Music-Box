#include<cstdio>
#include<iostream>
#include <GL/glut.h>
#include "box.h"
#include "man.h"
#include "room.h"
#include "lamp.h"
#include "table.h"
#include "furniture.h"
#include "shelf.h"
#include <vector>
#include "textfile.h"
using namespace std;

char MODE = 'N';
bool SUBMODE = false;
bool modeChange = false;
bool bezier_flag=false;
box * myBox;
man * myMan;
room * myRoom;
lamp * myLamp;
table * myTable;
furniture * myFurniture1;
furniture * myFurniture2;
shelf * myShelf;
shelf * sideShelf1;
shelf * sideShelf2;
bool lighting1 = false;
bool lighting2 = false;


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
static float x=0.2f,y=0.0f,z=19.6f;
static float lx=0.0f,ly=0.0f,lz=-1.0f;
static float ratio;
static int lidAngle = 0;
static float baseHeight = 0.1;
static float translateV = 9.6;
static float translateV_local = 9.6;


static vector<vector<float> > control_points;
static char MODEDIV = 'Q';
static float interPar=0.0f;
static double unX=0.0f,unY=0.0f,unZ=0.0f;

void GetOGLPos(int , int);

//Light parameters

GLfloat light_position[]={1,1,1, 1.0};
GLfloat light_position1[]={0,14.6,0, 1.0};
GLfloat light_diffuse[]={0.5,0.5,0.5, 1.0};
GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};
GLfloat light_ambient[]={0.3, 0.3, 0.3, 1.0};


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
  gluPerspective(45, ratio, 0.1, 1000.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f, 1.0f, 0.0f);
}


void mouse(int button, int state, int x, int y)
{
  // update the button state
  if(button == GLUT_LEFT_BUTTON)
  {
    if(MODE == 'S'){
        if(SUBMODE==false){
            GetOGLPos(x,y);
            SUBMODE=true;
            glutPostRedisplay();
        }
    }
  }
}

void bezierInit(){
  GLfloat ctrlpoints[control_points.size()][3];
  for(int i=0;i<control_points.size();i++){
      for(int j=0;j<3;j++){
          ctrlpoints[i][j]=control_points[i][j];
      }
  }
  glShadeModel(GL_FLAT);
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3,control_points.size(), &ctrlpoints[0][0]);
  glEnable(GL_MAP1_VERTEX_3);
}

// Handler for mouse move event
void mouseMove(int x, int y)
{
  
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
  x = x + i*(lx)*0.2;
  z = z + i*(lz)*0.2;
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f,1.0f,0.0f);
}

void moveMeTangent(int i) 
{
  x = x - i*(lz)*0.2;
  z = z + i*(lx)*0.2;
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f,1.0f,0.0f);
}


void specialKey(int key, int x, int y) 
{
  if(MODE == 'N'){
    switch (key) {
    case GLUT_KEY_PAGE_UP : angle -= 0.05f;orientMe(angle);break;
    case GLUT_KEY_PAGE_DOWN : angle +=0.05f;orientMe(angle);break;
    case GLUT_KEY_UP : moveMeFlat(2);break;
    case GLUT_KEY_DOWN : moveMeFlat(-2);break;
    case GLUT_KEY_RIGHT : moveMeTangent(2);break;
    case GLUT_KEY_LEFT : moveMeTangent(-2);break;
    case GLUT_KEY_F1 : translateV += 0.4;break;
    case GLUT_KEY_F2 : translateV -= 0.4;break;
    }
    glutPostRedisplay();
    return;
  }
  if(MODE == 'M'){
    myMan->specialKey(key,x,y);
    glutPostRedisplay();
    return;
  }

  if(MODE == 'S'){
    switch (key) {
    case GLUT_KEY_F5 : interPar=0.1;break;
    case GLUT_KEY_F6 : interPar=-0.1;break;
    case GLUT_KEY_PAGE_UP : angle -= 0.05f;orientMe(angle);break;
    case GLUT_KEY_PAGE_DOWN : angle +=0.05f;orientMe(angle);break;
    case GLUT_KEY_UP : moveMeFlat(2);break;
    case GLUT_KEY_DOWN : moveMeFlat(-2);break;
    case GLUT_KEY_RIGHT : moveMeTangent(2);break;
    case GLUT_KEY_LEFT : moveMeTangent(-2);break;
    case GLUT_KEY_F1 : translateV += 0.4;break;
    case GLUT_KEY_F2 : translateV -= 0.4;break;
    }
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
    if(key == 's' || key == 'S') MODE = 'S';
    if(key == '6') {lighting1 = !lighting1; glutPostRedisplay();} 
    if(key == '7') {lighting2 = !lighting2; glutPostRedisplay();} 
    modeChange = false;
    return;
  }
  if(key == 'Z' || key == 'z'){
    bezier_flag=false;
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

  if(MODE == 'S'){
    if(key == 'F' || key == 'f'){   
      vector <float> temp;
      if(MODE=='S' && MODEDIV=='1'){
          
          temp.push_back(unX+interPar);
          temp.push_back(unY);
          temp.push_back(unZ);
          control_points.push_back(temp);
      }
      else if(MODE=='S' && MODEDIV=='2'){
          //translateV_local = translateV;
          temp.push_back(unX);
          temp.push_back(unY+interPar);
          temp.push_back(unZ);
          control_points.push_back(temp);
      }
      else if(MODE=='S' && MODEDIV=='3'){
          //translateV_local = translateV;
          temp.push_back(unX);
          temp.push_back(unY);
          temp.push_back(unZ+interPar);
          control_points.push_back(temp);
      }
      
      MODE = 'S'; SUBMODE=false;MODEDIV='Q';
      glutPostRedisplay();
      return;
    }

    if(key=='1'){
        if(MODE=='S'){
            MODEDIV='1';
            translateV_local = translateV;
            interPar=0;
            glutPostRedisplay();
            return;
        }
    }
    if(key=='2'){
        if(MODE=='S'){
            MODEDIV='2';
            translateV_local = translateV;
            interPar=0;
            glutPostRedisplay();
            return;
        }
    }
    if(key=='3'){
        if(MODE=='S'){
            MODEDIV='3';
            translateV_local = translateV;
            interPar=0;
            glutPostRedisplay();
            return;
        }
    }

    if(key == 'E' || key == 'e'){
        MODE='N';
        bezier_flag=true;
        bezierInit();
        glutPostRedisplay();
        return;
    }
  }

}

void GetOGLPos(int x, int y)
{
   
    double modelview[16], projection[16];
  int viewport[4];
  float z = 1;
  
  /*Read the projection, modelview and viewport matrices
     using the glGet functions.*/
  glGetDoublev( GL_PROJECTION_MATRIX, projection );
  glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
  glGetIntegerv( GL_VIEWPORT, viewport );
    
  //Read the window z value from the z-buffer
  glReadPixels( x, viewport[3]-y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z );
    
  //Use the gluUnProject to get the world co-ordinates of
  //the point the user clicked and save in objx, objy, objz.
  gluUnProject( x, viewport[3]-y, z, modelview, projection, viewport, &unX, &unY, &unZ );
    interPar=0;
}

//position of lamp light is (2,4.6,-5.8)

void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //cout<<"lx "<<lx<<" ly "<<ly<<" lz "<<lz<<" x "<<x<<" y "<<y<<" z "<<z<<" angle "<<angle<<" tra "<<translateV<<endl;
  //glEnable(GL_LIGHTING);
  if(lighting1){glEnable(GL_LIGHTING); glEnable(GL_LIGHT0); cout<<"light 0 enabled"<<endl;}
  else {glDisable(GL_LIGHT0); cout<<"light 0 disabled"<<endl;}

  if(lighting2){glEnable(GL_LIGHTING); glEnable(GL_LIGHT1); cout<<"light 1 enabled"<<endl;}
  else {glDisable(GL_LIGHT1); cout<<"light 1 disabled"<<endl;}
  glShadeModel(GL_SMOOTH);


  glPushMatrix();
    glTranslatef(0,translateV, 0);
    glPushMatrix();
    glTranslatef(2,-5,-5.8);
    glutSolidCube(0.5);
    glPopMatrix();
    glPushMatrix();
      //glTranslatef(0,8,0);
      glPushMatrix();
        glScalef(8,4,10);
        myRoom->draw();
        glPushMatrix();
          glTranslatef(0,0,-3.8);
          glScalef(0.125,0.25,0.1);
          glScalef(3,3,2);
          myShelf->draw();
        glPopMatrix();
        glPushMatrix();
          glTranslatef(-5.7,0,0);
          glScalef(0.125,0.25,0.1);
          glScalef(3,3,2);
          glRotatef(90,0,1,0);
          sideShelf1->drawOther();
        glPopMatrix();

        glPushMatrix();
          glTranslatef(5.7,0,0);
          glScalef(0.125,0.25,0.1);
          glScalef(3,3,2);
          glRotatef(-90,0,1,0);
          sideShelf2->drawOther();
        glPopMatrix();

      glPopMatrix();
      glPushMatrix(); 
        glTranslatef(0,-10,0);
        glPushMatrix();
          glTranslatef(0,0,-5);
          glPushMatrix();
            glScalef(3,3,3);
            myTable->draw();
          glPopMatrix();
          glPushMatrix();
            glScalef(1.2,1.2,1.2);
            glTranslatef(-3,0,0);
            glRotatef(30,0,1,0);
            myBox->draw();
            glPushMatrix();
              //glTranslatef(0,2.3,0);
              glTranslatef(0,baseHeight,0);
              glTranslatef(0,1.3,0);
              glScalef(0.18,0.165,0.18);
              myMan->draw();
            glPopMatrix();
          glPopMatrix();
          glPushMatrix();
            glScalef(3,3,3);
            glTranslatef(1.5,0.3,0);
            glRotatef(-30,0,1,0);
            myLamp->draw();
          glPopMatrix();
        glPopMatrix();
      glPopMatrix();
      glPushMatrix();
        glTranslatef(-30,-6.5,-25);
        glScalef(3,3,3);
        myFurniture1->draw();
      glPopMatrix();
      glPushMatrix();
        glTranslatef(30,-6.5,-25);
        glScalef(3,3,3);
        glRotatef(-60,0,1,0);
        myFurniture2->draw();
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();


  //BEZIER
  glPushMatrix();
  glTranslatef(0,translateV-9.6,0);
  
  if(MODE=='S' && SUBMODE==true && MODEDIV=='1'){
    // cout<<"ptX is"<<unX+interPar<<endl;
    // cout<<"ptY is"<<unY<<endl;
    // cout<<"ptZ is"<<unZ<<endl;
        glPushMatrix();
        glTranslatef(0,9.6-translateV_local,0);
        glColor3f(1.0, 0.0, 0.0);
        glLineWidth(4.0f);
        glBegin(GL_LINES);
        glVertex3f(-1000, unY, unZ);
        glVertex3f(+1000, unY, unZ);
        glEnd();

        glColor3f(0.0, 1.0, 0.0);
      unX=unX+interPar;
      glTranslatef(unX, unY, unZ);
      glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
    glColor3f(1,1,1);
  }
    
  if(MODE=='S' && SUBMODE==true && MODEDIV=='2'){
      // cout<<"ptX is"<<unX<<endl;
      // cout<<"ptY is"<<unY+interPar<<endl;
      // cout<<"ptZ is"<<unZ<<endl;
      glPushMatrix();
      glTranslatef(0,9.6-translateV_local,0);
      glColor3f(1.0, 0.0, 0.0);
      glLineWidth(4.0f);
      glBegin(GL_LINES);
      glVertex3f(unX, -1000, unZ);
      glVertex3f(unX, 1000, unZ);
      glEnd();
      
      glColor3f(0.0, 1.0, 0.0);
      unY=unY+interPar;
      glTranslatef(unX, unY, unZ);
      glutSolidSphere(0.1, 20, 20);
      glPopMatrix();
      glColor3f(1,1,1);
  }
    
  if(MODE=='S' && SUBMODE==true && MODEDIV=='3'){
      // cout<<"ptX is"<<unX<<endl;
      // cout<<"ptY is"<<unY<<endl;
      // cout<<"ptZ is"<<unZ+interPar<<endl;
      glPushMatrix();
      glTranslatef(0,9.6-translateV_local,0);
      glColor3f(1.0, 0.0, 0.0);
      glLineWidth(4.0f);
      glBegin(GL_LINES);
      glVertex3f(unX, unY, -1000);
      glVertex3f(unX, unY, 1000);
      glEnd();
      
      glColor3f(0.0, 1.0, 0.0);
      unZ=unZ+interPar;
      glTranslatef(unX, unY, unZ);
      glutSolidSphere(0.1, 20, 20);
      glPopMatrix();
      glColor3f(1,1,1);
  }

  if(bezier_flag==true){
      glBegin(GL_LINE_STRIP);
      glColor3f(0, 0, 0);
      for (int i = 0; i <= 30; i++)
          glEvalCoord1f((GLfloat) i/30.0);
      glEnd();
      /* The following code displays the control points as dots. */
      GLfloat ctrlpoints[control_points.size()][3];
      for(int i=0;i<control_points.size();i++){
          for(int j=0;j<3;j++){
              ctrlpoints[i][j]=control_points[i][j];
          }
      }
      glPointSize(5.0);
      glColor3f(0.5, 0.5, 0.5);
      glBegin(GL_POINTS);
      for (int i = 0; i < control_points.size(); i++)
          glVertex3fv(&ctrlpoints[i][0]);
      glEnd();
      glColor3f(1,1,1);
  }
  glPopMatrix();
  glutSwapBuffers();
}

void display1( void )
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glDisable(GL_LIGHTING);
  glEnable(GL_LIGHTING);
  //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,1);
  glShadeModel(GL_SMOOTH);
  glPushMatrix();
    glTranslatef(0,translateV, 0);
      glPushMatrix();
        glTranslatef(2,-5,-5.8);
        glutSolidCube(0.5);
      glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-9,0);
    myBox->draw();
    glPopMatrix();
  glPopMatrix();
  glutSwapBuffers();
}

void init(){
  myBox = new box();
  myMan = new man();
  myRoom = new room();
  myTable = new table();
  myLamp = new lamp();
  myFurniture1 = new furniture();
  myFurniture2 = new furniture();
  myShelf = new shelf();
  sideShelf1 = new shelf();
  sideShelf2 = new shelf();

  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
  glLightfv(GL_LIGHT0,GL_POSITION,light_position);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  //glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

  glEnable(GL_LIGHT1);
  glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

  //glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);
  //glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);
}

int main (int argc, char *argv[]) 
{

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640,360);
  glutCreateWindow("Assignment 2");
  glClearDepth( 1.0 );
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glEnable (GL_TEXTURE_2D);
  glutDisplayFunc( display);
  glutReshapeFunc( resize );
  glutSpecialFunc(specialKey);
  glutKeyboardFunc(processNormalKeys);
  glutMouseFunc(mouse);        // Register handler for mouse event
  glutMotionFunc(mouseMove);   // Register handler for mouse move event
  init();
  glutMainLoop();
}