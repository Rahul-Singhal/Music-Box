#include<cstdio>
#include<iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "box.h"
#include "man.h"
#include "room.h"
#include "lamp.h"
#include "table.h"
#include "furniture.h"
#include "shelf.h"
#include <vector>
#include <cstdio>
using namespace std;

static int fps=100;
static int numFrames = 100;
static int timeFrame=numFrames/fps;
static int curFrame = 0;

FILE * keyFrameFile;

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

bool recordMode = false;
bool playbackMode = false;
bool endPlayback=false;



static int numPoints = 300;
static int lidAngle = 0;
static float baseHeight = 0.1;

char MODE = 'N';
int SUBMODE = 0;
int modeChange = 0;
int bezier_flag= 0;
int lighting1 = 0;
int lighting2 = 0;

GLfloat xAngle = 19.8f;  // Rotational angle about the x-axis
GLfloat yAngle = -61.2f;  // Rotational angle about the y-axis
static float angle=0.0;
static float x=0.2f,y=0.0f,z=19.6f;
static float lx=0.0f,ly=0.0f,lz=-1.0f;
static float myratio=1;
static float translateV = 9.6;
static float translateV_local = 9.6;

static float u=0;
static float xCube=0,yCube=0,zCube=0;
static char MODEDIV = 'Q';
static float interPar=0.0f;
static double unX=0.0f,unY=0.0f,unZ=0.0f;


static int numPointsIF = 300;
static int lidAngleIF = 0;
static float baseHeightIF = 0.1;

char MODEIF = 'N';
int SUBMODEIF = 0;
int modeChangeIF = 0;
int bezier_flagIF= 0;
int lighting1IF = 0;
int lighting2IF = 0;

GLfloat xAngleIF = 19.8f;  // Rotational angle about the x-axis
GLfloat yAngleIF = -61.2f;  // Rotational angle about the y-axis
static float angleIF=0.0;
static float xIF=0.2f,yIF=0.0f,zIF=19.6f;
static float lxIF=0.0f,lyIF=0.0f,lzIF=-1.0f;
static float myratioIF=1;
static float translateVIF = 9.6;
static float translateV_localIF = 9.6;

static float uIF=0;
static float xCubeIF=0,yCubeIF=0,zCubeIF=0;
static char MODEDIVIF = 'Q';
static float interParIF=0.0f;
static double unXIF=0.0f,unYIF=0.0f,unZIF=0.0f;


static vector< vector <float> > bezPoints;
static vector<vector<float> > control_points;


//Function Definitions
void GetOGLPos(int , int);

//Light parameters

GLfloat light_position[]={1,1,1, 1.0};
GLfloat light_diffuse[]={0.2,0.2,0.2, 1.0};
GLfloat light_specular[]={0.0, 0.0, 0.0, 1.0};
GLfloat light_ambient[]={0.1, 0.1, 0.1, 1.0};

GLfloat light_position1[]={0,13.6,0, 1.0};
GLfloat light_diffuse1[]={0.5,0.5,0.5, 1.0};
GLfloat light_specular1[]={0.0, 0.0, 0.0, 1.0};
GLfloat light_ambient1[]={0.3, 0.3, 0.3, 1.0};


bool setState();
void nextFrame();
void setInitialFrame();


void saveState(){
  cout<<"File Made"<<endl;
  myBox->getState(keyFrameFile);
  myMan->getState(keyFrameFile);
  fprintf(keyFrameFile, "%d,%f,%d,%c,%d,%d,%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%c,%f,%g,%g,%g\n", 
    numPoints, baseHeight,lidAngle,MODE,SUBMODE,modeChange,bezier_flag,lighting1,lighting2,xAngle,yAngle,angle,x,y,z,
    lx,ly,lz,myratio,translateV,translateV_local,u,xCube,yCube,zCube,MODEDIV,interPar,unX,unY,unZ);
}

void interPolateFrames(int i){
    if(endPlayback==false){
    if(i > numFrames){
    if(setState()) glutTimerFunc(timeFrame, interPolateFrames, 1);
    else return;
  }
  else{
    nextFrame();
      glutPostRedisplay();

    //after every 20 ms
    glutTimerFunc(timeFrame, interPolateFrames, i+1);
        }
    }
}

bool setState(){
  //check if the file has ended!
    if(!feof(keyFrameFile)){
  if(!myBox->setState(keyFrameFile, numFrames)){
    //file ended
    return false;
  } 
  myMan->setState(keyFrameFile, numFrames);
    
  fscanf(keyFrameFile, "%d,%f,%d,%c,%d,%d,%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%c,%f,%lf,%lf,%lf\n", 
    &numPointsIF, &baseHeightIF,&lidAngleIF,&MODEIF,&SUBMODEIF,&modeChangeIF,&bezier_flagIF,&lighting1IF,&lighting2IF,&xAngleIF,&yAngleIF,&angleIF,&xIF,&yIF,&zIF,
    &lxIF,&lyIF,&lzIF,&myratioIF,&translateVIF,&translateV_localIF,&uIF,&xCubeIF,&yCubeIF,&zCubeIF,&MODEDIVIF,&interParIF,&unXIF,&unYIF,&unZIF);

  //numPoints = numPointsIF;
  baseHeightIF = (baseHeightIF - baseHeight)/numFrames;
  lidAngle = lidAngleIF;
  //MODE = MODEIF;
  //SUBMODE = SUBMODEIF;
  //modeChange = modeChangeIF;
  ///bezier_flag = bezier_flagIF;
  //lighting1 = lighting1IF;
  //lighting2 = lighting2IF;
  xAngleIF = (xAngleIF - xAngle)/numFrames;
  yAngleIF = (yAngleIF - yAngle)/numFrames;
  angleIF = (angleIF - angle)/numFrames;
  xIF = (xIF - x)/numFrames;
  yIF = (yIF - y)/numFrames;
  zIF = (zIF - z)/numFrames;

  lxIF = (lxIF - lx)/numFrames;
  lyIF = (lyIF - lx)/numFrames;
  lzIF = (lzIF - lz)/numFrames;
  myratioIF = (myratioIF - myratio)/numFrames;
  translateVIF = (translateVIF - translateV)/numFrames;
  translateV_localIF = (translateV_localIF - translateV_local)/numFrames;
  uIF = (uIF - u)/numFrames;
  xCubeIF = (xCubeIF - xCube)/numFrames;
  yCubeIF = (yCubeIF - yCube)/numFrames;
  zCubeIF = (zCubeIF - zCube)/numFrames;
  //MODEDIV = MODEDIVIF;
  interParIF = (interParIF - interPar)/numFrames;
  unXIF = (unXIF - unX)/numFrames;
  unYIF = (unYIF - unY)/numFrames;
  unZIF = (unZIF - unZ)/numFrames;

        }
    else {
        fclose(keyFrameFile);
        endPlayback=true;
        MODE='N';
        
    }
    return true;
}



void playBack(){
    cout<<"In Playback"<<endl;
  if(!myBox->setState(keyFrameFile, 1)) return;
  myMan->setState(keyFrameFile, 1);
  fscanf(keyFrameFile, "%d,%f,%d,%c,%d,%d,%d,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%c,%f,%lf,%lf,%lf\n", 
    &numPointsIF, &baseHeightIF,&lidAngleIF,&MODEIF,&SUBMODEIF,&modeChangeIF,&bezier_flagIF,&lighting1IF,&lighting2IF,&xAngleIF,&yAngleIF,&angleIF,&xIF,&yIF,&zIF,
    &lxIF,&lyIF,&lzIF,&myratioIF,&translateVIF,&translateV_localIF,&uIF,&xCubeIF,&yCubeIF,&zCubeIF,&MODEDIVIF,&interParIF,&unXIF,&unYIF,&unZIF);
    
    baseHeightIF = (baseHeightIF - baseHeight)/numFrames;
  
  setInitialFrame();
  glutPostRedisplay();

  setState();
  interPolateFrames(1);
  //fclose(keyFrameFile);
}

void setInitialFrame(){
  myBox->nextFrame();
  myMan->nextFrame();
  
  numPoints = numPointsIF;
  baseHeight = baseHeightIF;
  lidAngle = lidAngleIF;
  MODE = MODEIF;
  SUBMODE = SUBMODEIF;
  modeChange = modeChangeIF;
  bezier_flag = bezier_flagIF;
  lighting1 = lighting1IF;
  lighting2 = lighting2IF;
  xAngle = xAngleIF;
  yAngle = yAngleIF;
  angle = angleIF;
  x = xIF;
  y = yIF;
  z = zIF;

  lx = lxIF;
  ly = lyIF;
  lz = lzIF;
  myratio = myratioIF;
  translateV = translateVIF;
  translateV_local = translateV_localIF;
  u = uIF;
  xCube = xCubeIF;
  yCube = yCubeIF;
  zCube = zCubeIF;
  MODEDIV = MODEDIVIF;
  interPar = interParIF;
  unX = unXIF;
  unY = unYIF;
  unZ = unZIF;

  return;
}

void nextFrame(){
  if(curFrame == numFrames){
    cout<<"new line read"<<endl;
    curFrame=0;
    myBox->nextFrame();
    myMan->nextFrame();
    baseHeight += baseHeightIF;
    lidAngle += lidAngleIF;
    MODE = MODEIF;
    SUBMODE = SUBMODEIF;
    modeChange = modeChangeIF;
    bezier_flag = bezier_flagIF;
    lighting1 = lighting1IF;
    lighting2 = lighting2IF;
    xAngle += xAngleIF;
    yAngle += yAngleIF;
    angle += angleIF;
    x += xIF;
    y += yIF;
    z += zIF;

    lx += lxIF;
    ly += lyIF;
    lz += lzIF;
    myratio += myratioIF;
    translateV += translateVIF;
    translateV_local += translateV_localIF;
    u += uIF;
    xCube += xCubeIF;
    yCube += yCubeIF;
    zCube += zCubeIF;
    MODEDIV = MODEDIVIF;
    interPar += interParIF;
    unX += unXIF;
    unY += unYIF;
    unZ += unZIF;

    glutPostRedisplay();
    return;
  }
  else{
    cout<<"Curr frame "<<curFrame<<endl;
    myBox->nextFrame();
    myMan->nextFrame();
    
    //numPoints += numPointsIF;
    baseHeight += baseHeightIF;
    lidAngle += lidAngleIF;
    //MODE = MODEIF;
    //SUBMODE = SUBMODEIF;
    //modeChange = modeChangeIF;
    //bezier_flag = bezier_flagIF;
    //lighting1 = lighting1IF;
    //lighting2 = lighting2IF;
    xAngle += xAngleIF;
    yAngle += yAngleIF;
    angle += angleIF;
    x += xIF;
    y += yIF;
    z += zIF;

    lx += lxIF;
    ly += lyIF;
    lz += lzIF;
    myratio += myratioIF;
    translateV += translateVIF;
    translateV_local += translateV_localIF;
    u += uIF;
    xCube += xCubeIF;
    yCube += yCubeIF;
    zCube += zCubeIF;
    //MODEDIV = MODEDIVIF;
    interPar += interParIF;
    unX += unXIF;
    unY += unYIF;
    unZ += unZIF;

    curFrame++;
    glutPostRedisplay();
  }
}



void timer(int t) {
    if(MODE=='E'){
        if(t>numPoints){t=numPoints;MODE='N'; return;}
        vector <float> v=bezPoints[t];
        float x=v[0];
        float y=v[1];
        float z=v[2];
        xCube=x;
        yCube=y;
        zCube=z;
        
        glutPostRedisplay();
        glutTimerFunc(10, timer, (t+1));
        
    }

}
void resize(int w, int h)
{
  
  if(h == 0) h = 1;
  myratio = 1.0f * w / h;
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, myratio, 0.1, 1000.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f, 1.0f, 0.0f);
}


void mouse(int button, int state, int x, int y)
{

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

vector <float> deCasteljau(int i,int j){
    if(i==0)
        return control_points[j];
    else{
        vector <float> v1=deCasteljau(i-1,j);
        vector <float> v2=deCasteljau(i-1, j+1);
        vector <float> v1n,v2n;
        v1n.push_back(v1[0]*(1-u));
        v1n.push_back(v1[1]*(1-u));
        v1n.push_back(v1[2]*(1-u));
        v2n.push_back(v2[0]*(u));
        v2n.push_back(v2[1]*(u));
        v2n.push_back(v2[2]*(u));
        vector<float> v;
        v.push_back(v1n[0]+v2n[0]);
        v.push_back(v1n[1]+v2n[1]);
        v.push_back(v1n[2]+v2n[2]);
        return v;
    }
}

void bezPar(int t){
    u=(float)t/numPoints;
    vector <float> v;
    v= deCasteljau((int)control_points.size()-1,0);
    bezPoints[t]=v;
}


void bezierInit(){

  GLfloat ctrlpoints[control_points.size()][3];

  for(int i=0;i<control_points.size();i++){
      for(int j=0;j<3;j++){
          ctrlpoints[i][j]=control_points[i][j];
      }
  }
    
    for (int i = 0; i <=numPoints; i++)
        bezPar(i);
    bezier_flag=true;
   glutTimerFunc(10, timer, 0);
  glShadeModel(GL_FLAT);
}

// Handler for mouse move event
void mouseMove(int x, int y){}

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
  if(recordMode && (key == GLUT_KEY_F10)){
    saveState();
    return; 
  }
    
  

  if(MODE == 'N'  || MODE == 'E'){
    switch (key) {
    case GLUT_KEY_F3 : angle -= 0.05f;orientMe(angle);break;
    case GLUT_KEY_F4  : angle +=0.05f;orientMe(angle);break;
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
    case GLUT_KEY_F3 : angle -= 0.05f;orientMe(angle);break;
    case GLUT_KEY_F4  : angle +=0.05f;orientMe(angle);break;
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
  if (key == 27) {
    if(keyFrameFile) fclose(keyFrameFile);
    exit(0);
  }
  if(modeChange){
    if(key == 'N' || key == 'n') MODE = 'N';
    if(key == 'M' || key == 'm') MODE = 'M';
    if(key == 'B' || key == 'b') MODE = 'B';
    if(key == 's' || key == 'S') {
      MODE = 'S'; u = 0; 
      bezPoints.clear(); 
      control_points.clear();  
      bezPoints.resize(numPoints+1);
      for(int i=0;i<=numPoints;i++){
        bezPoints[i].resize(3);
      }
    }
    if(key == '6') {lighting1 = !lighting1; glutPostRedisplay();} 
    if(key == '7') {lighting2 = !lighting2; glutPostRedisplay();}
    if(key == 'P' || key == 'p') {
        endPlayback=false;
      keyFrameFile = fopen ("keyframes.txt","r");
      if (keyFrameFile==NULL){
          cout<<"Error opening file"<<endl;
      }
      else playBack();
    }
    if(key == 'R' || key == 'r') {
      //turn on the record mode
      recordMode =  !(recordMode);
      cout<<"Record mode toggled!"<<endl;
      if(recordMode){
        keyFrameFile = fopen ("keyframes.txt","w+");
      }
      else{
        if(keyFrameFile) fclose(keyFrameFile);
      }
    }
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
          temp.push_back(unX);
          temp.push_back(unY+interPar);
          temp.push_back(unZ);
          control_points.push_back(temp);
      }
      else if(MODE=='S' && MODEDIV=='3'){
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
        MODE='E';
      
        vector <float> v;
        v.push_back(1); //last point
        v.push_back(2);
        v.push_back(3);
        control_points.push_back(v);
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
  
  glGetDoublev( GL_PROJECTION_MATRIX, projection );
  glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
  glGetIntegerv( GL_VIEWPORT, viewport );
    
  glReadPixels( x, viewport[3]-y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z );
    
  gluUnProject( x, viewport[3]-y, z, modelview, projection, viewport, &unX, &unY, &unZ );
    interPar=0;
}

//position of lamp light is (2,4.6,-5.8)

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glDisable(GL_TEXTURE_2D);
  glPushMatrix();
  glTranslatef(0,translateV-16.5  ,0);
  glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(1000,0,1000);
    glVertex3f(1000,0,-1000);
    glVertex3f(-1000,0,-1000);
    glVertex3f(-1000,0,1000);
  glEnd();
  glPopMatrix();
  glColor3f(1,1,1);

    if(bezier_flag==true && MODE=='E'){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45, myratio, 0.1, 1000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(xCube, yCube, zCube, -5, 0, -4, 0, 1, 0);
    }
        
  if(lighting1){glEnable(GL_LIGHTING); glEnable(GL_LIGHT0);}
  else {glDisable(GL_LIGHT0);}

  if(lighting2){glEnable(GL_LIGHTING); glEnable(GL_LIGHT1);}
  else {glDisable(GL_LIGHT1);}
  glShadeModel(GL_SMOOTH);

  glPushMatrix();
    glTranslatef(0,translateV, 0);
    glPushMatrix();
    glTranslatef(2,-5,-5.8);
    glutSolidCube(0.5);
    glPopMatrix();
    glPushMatrix();
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
          glTranslatef(0,0.5,-5);
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
    cout<<"hghjjh "<<baseHeight<<endl;
              glTranslatef(0,baseHeight,0);
              glTranslatef(0,1.3,0);
              glScalef(0.18,0.16,0.18);
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
      /* The following code displays the control points as dots. */
      glPushMatrix();
      glPointSize(3);
      glBegin(GL_LINE_STRIP);

      glColor3f(0, 0, 0);
      for (int i = 0; i <=numPoints; i++){
          vector <float> v=bezPoints[i];
          glVertex3f(v[0],v[1],v[2]);
      }
      glEnd();
      glPopMatrix();
      GLfloat ctrlpoints[control_points.size()][3];
      for(int i=0;i<control_points.size();i++){
          for(int j=0;j<3;j++){
              ctrlpoints[i][j]=control_points[i][j];
          }
      }
      glPointSize(5.0);
      glColor3f(1, 0, 0);
      glPushMatrix();
        glBegin(GL_POINTS);
        for (int i = 0; i < control_points.size(); i++)
            glVertex3fv(&ctrlpoints[i][0]);
        glEnd();
      glPopMatrix();
      glColor3f(1,1,1);
  }

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

  glEnable(GL_DEPTH_TEST);

  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);

  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0,GL_POSITION,light_position);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,0.5);
  glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0);
  glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0002);

  glEnable(GL_LIGHT1);
  glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
  glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);

}

int main (int argc, char *argv[]) 
{

  bezPoints.resize(numPoints+1);
    for(int i=0;i<=numPoints;i++){
        bezPoints[i].resize(3);
    }
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
