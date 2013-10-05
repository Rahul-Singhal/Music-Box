#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <GL/glut.h>

using namespace std;

static char mode = 'Q';
static char subMode = 'Q';

static float neck1=0,neck2=0,neck3=0;
static float neckFactor = 1;

static float shoulderLeft1=0,shoulderLeft2=0,shoulderLeft3=0;
static float shoulderFactor = 1;
static float shoulderRight1=0,shoulderRight2=0,shoulderRight3=0;

static float elbowLeft=0;
static float elbowFactor = 1;
static float elbowRight=0;

static float wristLeft1=0,wristLeft2=0,wristLeft3=0;
static float wristFactor = 1;
static float wristRight1=0,wristRight2=0,wristRight3=0;

static float hipLeft1=0,hipLeft2=0,hipLeft3=0;
static float hipFactor = 1;
static float hipRight1=0,hipRight2=0,hipRight3=0;

static float ankleLeft1=0,ankleLeft2=0,ankleLeft3=0;
static float ankleFactor = 1;
static float ankleRight1=0,ankleRight2=0,ankleRight3=0;

static float kneeLeft=0;
static float kneeFactor = 1;
static float kneeRight=0;

static float torso11=0,torso12=0,torso13=0;
static float torso1Factor = 1;

static float torso21=0,torso22=0,torso23=0;
static float torso2Factor = 1;



static float angleTheta=0.0,angleAlpha=0.0;
static float x=0.0f,y=0.0f,z=20.0f;
static float r=20.0f;
int count = 0;
float fraction = 0.01;

void resize(int w, int h)
{
  
  // Prevent a divide by zero, when window is too short
  // (you cant make a window of zero width).
  if(h == 0) h = 1;
  float ratio;
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
  gluLookAt(x, y, z, 0,0,0, 0.0f, 1.0f, 0.0f);
}

/*----------------------------------------------------------*/


static GLint faceDL;
static GLint neckDL;
static GLint torso1DL;
static GLint torso2DL;
static GLint torso3DL;
static GLint shoulderDL;
static GLint armDL;
static GLint thighDL;
static GLint legDL;
static GLint wristDL;
static GLint elbowDL;
static GLint forearmDL;
static GLint ankleDL;
static GLint footDL;
static GLint handDL;
void init();
void initFace();
void initNeck();
void initTorso1();
void initTorso2();
void initTorso3();
void initShoulder();
void initArm();
void initWrist();
void initElbow();
void initLeg();
void initThigh();
void initForearm();
void initAnkle();
void initHand();
void initFoot();
GLuint createFaceDL() ;
GLuint createNeckDL() ;
GLuint Torso1DL() ;
GLuint Torso2DL() ;
GLuint Torso3DL() ;
GLuint createShoulderDL() ;
GLuint createArmDL();
GLuint createWristDL();
GLuint createElbowDL();
GLuint createForearmDL() ;
GLuint createThighDL() ;
GLuint createLegDL() ;
GLuint createAnkleDL() ;
GLuint createHandDL() ;
GLuint createFootDL() ;
void struct_face();
void struct_neck();
void struct_torso1();
void struct_torso2();
void struct_torso3();
void struct_shoulder();
void struct_arm();
void struct_elbow();
void struct_wrist();
void struct_thigh();
void struct_leg();
void struct_forearm();
void struct_ankle();
void struct_hand();
void struct_foot();
/*----------------------------------------------------------*/

void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
		glTranslatef(0,2,0);
		glPushMatrix();

			glTranslatef(0,-4.5,0.0);
			  //Rotation for bending
			  //glRotatef(30,0,0,1); for bending aboud y axis
			  //glRotatef(90,1,0,0); //for bending about x axis
			  //glRotatef(30,0,1,0); for rotation about z axis
				glRotatef(torso21, 1,0,0);
				glRotatef(torso22, 0,1,0);
				glRotatef(torso23, 0,0,1);
			glTranslatef(0,4.5,0.0);

			//head and neck
			glPushMatrix();
				glTranslatef(0.0,-1.25,0.0);
				glRotatef(neck1, 1,0,0);
				glRotatef(neck2, 0,1,0);
				glRotatef(neck3, 0,0,1);
				glPushMatrix();
					glCallList(neckDL);
				glPopMatrix();
				glTranslatef(0.0,1.2,0.0);
				glPushMatrix();
					glCallList(faceDL);
				glPopMatrix();
			glPopMatrix();

	  

			glPushMatrix();
				glPushMatrix();
					glTranslatef(-0.6,-4.5,0.0);
					glCallList(torso2DL);
		  		glPopMatrix();

		  		//right ahnd , left hand and torso1
		  		glPushMatrix(); 
					glTranslatef(-1,-1.5,0.0);
					glTranslatef(1,0,0);
					//ROTATION FOR TORSO!
					glTranslatef(-1,0,0);
					glPushMatrix();
						glCallList(torso1DL);
					glPopMatrix();
			  		
			  		//right hand
			  		glPushMatrix();
						//Rotation and translation corresponding to shoulder movement here
						//glTranslatef(+1.25,-2.0,0.0);
						glTranslatef(2,-0.5,0);
						glRotatef(shoulderRight1, 1,0,0);
						glRotatef(shoulderRight2, 0,1,0);
						glRotatef(shoulderRight3, 0,0,1);
						glPushMatrix();
				 			glCallList(shoulderDL);
						glPopMatrix();
						glPushMatrix();
					  		//rotation corresponding to the complete arm
					  		glRotatef(-60, 0.0f, 0.0f, 1.0f);
					  		glRotatef(90, 0.0f, 1.0f, 0.0f);
					  		glPushMatrix();
								glCallList(armDL);
					  		glPopMatrix();
					  		glPushMatrix();
								//glRotatef(20,0,0,0);
								glTranslatef(0,0,3.0);
								//Rotation corresponding to elbow here
								glRotatef(elbowRight, 0,1,0);

								glPushMatrix();
						  			glCallList(elbowDL);
								glPopMatrix();
								glPushMatrix();
									//rotation for forearm
									glPushMatrix();
							  			glCallList(forearmDL);
									glPopMatrix();
									glPushMatrix();
										glTranslatef(0,0,2);
										//rotation for wrist
										glRotatef(wristRight1, 1,0,0);
										glRotatef(wristRight2, 0,1,0);
										glRotatef(wristRight3, 0,0,1);
										glPushMatrix();
								  			glCallList(wristDL);
									  		glPushMatrix();
												glCallList(handDL);
											glPopMatrix();
										glPopMatrix();
									glPopMatrix();
								glPopMatrix();
					  		glPopMatrix();
						glPopMatrix();
			  		glPopMatrix();

			  		//left hand
			  		glPushMatrix();
						//Rotation and translation corresponding to shoulder movement here
			  			glRotatef(shoulderLeft1, 1,0,0);
						glRotatef(shoulderLeft2, 0,1,0);
						glRotatef(shoulderLeft3, 0,0,1);
						//glTranslatef(+1.25,-2.0,0.0);
						glTranslatef(0,-0.5,0);
						glPushMatrix();
				 			glCallList(shoulderDL);
						glPopMatrix();
						glPushMatrix();
					  		//rotation corresponding to the complete arm
					  		glRotatef(-120, 0.0f, 0.0f, 1.0f);
					  		glRotatef(90, 0.0f, 1.0f, 0.0f);
					  		glPushMatrix();
								glCallList(armDL);
					  		glPopMatrix();
					  		glPushMatrix();
								//glRotatef(20,0,0,0);
								glTranslatef(0,0,3.0);
								//Rotation corresponding to elbow here
								glRotatef(elbowLeft, 0,1,0);
								glPushMatrix();
						  			glCallList(elbowDL);
								glPopMatrix();
								glPushMatrix();
									//rotation for forearm
									glPushMatrix();
							  			glCallList(forearmDL);
									glPopMatrix();
									glPushMatrix();
										glTranslatef(0,0,2);
										//rotation for wrist
										glRotatef(wristLeft1, 1,0,0);
										glRotatef(wristLeft2, 0,1,0);
										glRotatef(wristLeft3, 0,0,1);
										glPushMatrix();
								  			glCallList(wristDL);
									  		glPushMatrix();
												glCallList(handDL);
											glPopMatrix();
										glPopMatrix();
									glPopMatrix();
								glPopMatrix();
					  		glPopMatrix();
						glPopMatrix();
			  		glPopMatrix();
			  	glPopMatrix();
			glPopMatrix(); //torso2 closed
		glPopMatrix();

		// 	  //left hand
		// 	  glPushMatrix();
		// 		//Rotation and translation corresponding to shoulder movement here
		// 		glTranslatef(0,-0.5,0.0);
		// 		glPushMatrix();
		// 		  glCallList(shoulderDL);
		// 		glPopMatrix();
		// 		glPushMatrix();
		// 			  glRotatef(-120, 0.0f, 0.0f, 1.0f);
		// 			  glRotatef(90, 0.0f, 1.0f, 0.0f);
		// 			  glPushMatrix();
		// 				glCallList(armDL);
		// 			  glPopMatrix();
		// 			  glPushMatrix();
		// 				//glRotatef(20,0,0,0);
		// 				glTranslatef(0,0,3.0);
		// 				//Rotation corresponding to elbow here
		// 				glPushMatrix();
		// 				  glCallList(elbowDL);
		// 				glPopMatrix();
		// 				glPushMatrix();
		// 					glPushMatrix();
		// 					  glCallList(forearmDL);
		// 					glPopMatrix();
		// 					glPushMatrix();
		// 						glTranslatef(0,0,2);
		// 						//rotation for wrist
		// 						glPushMatrix();
		// 						  glCallList(wristDL);
		// 						  glPushMatrix();
		// 							glCallList(handDL);
		// 						glPopMatrix();
		// 						glPopMatrix();
		// 					glPopMatrix();
		// 				glPopMatrix();
		// 			  glPopMatrix();
		// 		glPopMatrix();
		// 	  glPopMatrix();
		// 	glPopMatrix();
		// glPopMatrix();
	

		

	glPushMatrix();


		glTranslatef(0,-4.7,0);
		//Rotation for the lower body
		glRotatef(torso11, 1,0,0);
		glRotatef(torso12, 0,1,0);
		glRotatef(torso13, 0,0,1);
		glTranslatef(0,4.7,0);
	  
	  glPushMatrix();
		glTranslatef(-0.6,-4.7,0.0);
		glCallList(torso3DL);
	  glPopMatrix();


	  
	  //left leg
	  glPushMatrix();
			glTranslatef(-0.55,-6.45,0.0);
			glRotatef(90,1,0,0);
				  glPushMatrix(); ///hip
					glCallList(elbowDL);
				  glPopMatrix();
				  
				  glPushMatrix();
						//rotation for thigh
				  		glRotatef(hipLeft1, 1,0,0);
						glRotatef(hipLeft2, 0,1,0);
						glRotatef(hipLeft3, 0,0,1);
						  glPushMatrix();
								glCallList(thighDL);
						  glPopMatrix();

						  
						  glPushMatrix(); ///knee
								glTranslatef(0,0,1.5);
								//rotation for knee
								glRotatef(kneeLeft, 1,0,0);
								glPushMatrix();
									glCallList(wristDL);
							glPopMatrix();

							glPushMatrix();
									glCallList(legDL);
							  glPopMatrix();


							  glPushMatrix();
								glTranslatef(0,0,1);
								//rotation for ankle
								glRotatef(ankleLeft1, 1,0,0);
								glRotatef(ankleLeft2, 0,1,0);
								glRotatef(ankleLeft3, 0,0,1);
								glPushMatrix();
									glCallList(ankleDL);
									glPushMatrix();
										glCallList(footDL);
									glPopMatrix();
								glPopMatrix();
							  glPopMatrix();

						  glPopMatrix();  
					glPopMatrix();
		glPopMatrix();


	  //right leg
	  glPushMatrix();
			glTranslatef(0.55,-6.45,0.0);
			glRotatef(90,1,0,0);
				  glPushMatrix(); ///hip
					glCallList(elbowDL);
				  glPopMatrix();
				  
				  glPushMatrix();
						//rotation for thigh
				  		glRotatef(hipRight1, 1,0,0);
						glRotatef(hipRight2, 0,1,0);
						glRotatef(hipRight3, 0,0,1);
						  glPushMatrix();
								glCallList(thighDL);
						  glPopMatrix();

						  
						  glPushMatrix(); ///knee
								glTranslatef(0,0,1.5);
								//rotation for knee
								glRotatef(kneeRight, 1,0,0);
								glPushMatrix();
									glCallList(wristDL);
							glPopMatrix();

							glPushMatrix();
									glCallList(legDL);
							  glPopMatrix();


							  glPushMatrix();
								glTranslatef(0,0,1);
								//rotation for ankle
								glRotatef(ankleRight1, 1,0,0);
								glRotatef(ankleRight2, 0,1,0);
								glRotatef(ankleRight3, 0,0,1);
								glPushMatrix();
									glCallList(ankleDL);
									glPushMatrix();
										glCallList(footDL);
									glPopMatrix();
								glPopMatrix();
							  glPopMatrix();

						  glPopMatrix();  
					glPopMatrix();
				glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
  
  

  
	
  glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) 
{
	
}

void init(){
	initFace();
	initNeck();
	initTorso1();
	initTorso2();
	initTorso3();
	initShoulder();
	initArm();
	initElbow();
	initWrist();
	initForearm();
	initLeg();
	initThigh();
	initHand();
	initFoot();
	initAnkle();
}

void initFace(){
	glEnable(GL_DEPTH_TEST);
	faceDL = createFaceDL();
}
void initNeck(){
	glEnable(GL_DEPTH_TEST);
	neckDL = createNeckDL();
}

void initTorso1(){
	glEnable(GL_DEPTH_TEST);
	torso1DL = Torso1DL();
}

void initTorso2(){
	glEnable(GL_DEPTH_TEST);
	torso2DL = Torso2DL();
}

void initTorso3(){
	glEnable(GL_DEPTH_TEST);
	torso3DL = Torso3DL();
}


void initShoulder(){
	glEnable(GL_DEPTH_TEST);
	shoulderDL = createShoulderDL();
}

void initHand(){
	glEnable(GL_DEPTH_TEST);
	handDL = createHandDL();
}

void initFoot(){
	glEnable(GL_DEPTH_TEST);
	footDL = createFootDL();
}

void initArm(){
	glEnable(GL_DEPTH_TEST);
	armDL = createArmDL();
}

void initAnkle(){
	glEnable(GL_DEPTH_TEST);
	ankleDL = createAnkleDL();
}

void initElbow(){
	glEnable(GL_DEPTH_TEST);
	elbowDL = createElbowDL();
}
void initWrist(){
	glEnable(GL_DEPTH_TEST);
	wristDL = createWristDL();
}
void initForearm(){
	glEnable(GL_DEPTH_TEST);
	forearmDL = createForearmDL();
}
void initThigh(){
	glEnable(GL_DEPTH_TEST);
	thighDL = createThighDL();
}
void initLeg(){
	glEnable(GL_DEPTH_TEST);
	legDL = createLegDL();
}



void specialKey(int key, int x, int y) {
	cout<<mode<<endl;
	switch(mode){
		case 'N':
			switch (key) {
				case GLUT_KEY_LEFT : if(neck3 < 28) neck3 += neckFactor; break;
				case GLUT_KEY_RIGHT : if(neck3 > -28) neck3 -= neckFactor;break;
				case GLUT_KEY_UP : if(neck1 > -23)  neck1 -= neckFactor; break;
				case GLUT_KEY_DOWN : if(neck1 < 44) neck1 += neckFactor;break;
				case GLUT_KEY_PAGE_UP: if(neck2 > -40) neck2 -= neckFactor;break;
				case GLUT_KEY_PAGE_DOWN: if(neck2 < 40) neck2 += neckFactor; break;
			}
			break;
		case 'S':
			switch(subMode){
				case 'L':
					switch(key){
						case GLUT_KEY_LEFT : if(shoulderLeft3 < 24) shoulderLeft3 += shoulderFactor; break;
						case GLUT_KEY_RIGHT : if(shoulderLeft3 > -158) shoulderLeft3 -= shoulderFactor;break;
						case GLUT_KEY_UP :  shoulderLeft1 -= shoulderFactor; break;
						case GLUT_KEY_DOWN : shoulderLeft1 += shoulderFactor;break;
						case GLUT_KEY_PAGE_UP: if(shoulderLeft2 > -65) shoulderLeft2 -= shoulderFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(shoulderLeft2 < 65) shoulderLeft2 += shoulderFactor; break;
					}
					break;
				case 'R':
					switch(key){
						case GLUT_KEY_LEFT : if(shoulderRight3 < 24) shoulderRight3 += shoulderFactor; break;
						case GLUT_KEY_RIGHT : if(shoulderRight3 > -158) shoulderRight3 -= shoulderFactor;break;
						case GLUT_KEY_UP : shoulderRight1 -= shoulderFactor; break;
						case GLUT_KEY_DOWN : shoulderRight1 += shoulderFactor;break;
						case GLUT_KEY_PAGE_UP: if(shoulderRight2 > -65) shoulderRight2 -= shoulderFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(shoulderRight2 < 65) shoulderRight2 += shoulderFactor; break;
					}
					break;
			}
			break;
		case 'W':
			switch(subMode){
				case 'L':
					switch(key){
						case GLUT_KEY_LEFT : if(wristLeft3 < 138) wristLeft3 += wristFactor; break;
						case GLUT_KEY_RIGHT : if(wristLeft3 > -177) wristLeft3 -= wristFactor;break;
						case GLUT_KEY_UP : if(wristLeft1 > -75) wristLeft1 -= wristFactor; break;
						case GLUT_KEY_DOWN : if(wristLeft1 < 75) wristLeft1 += wristFactor;break;
						case GLUT_KEY_PAGE_UP: if(wristLeft2 > -30) wristLeft2 -= wristFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(wristLeft2 < 30) wristLeft2 += wristFactor; break;
					}
					break;
				case 'R':
					switch(key){
						case GLUT_KEY_LEFT : if(wristRight3 < 138) wristRight3 += wristFactor; break;
						case GLUT_KEY_RIGHT : if(wristRight3 > -177) wristRight3 -= wristFactor;break;
						case GLUT_KEY_UP :  if(wristRight1 > -75) wristRight1 -= wristFactor; break;
						case GLUT_KEY_DOWN : if(wristRight1 < 75) wristRight1 += wristFactor;break;
						case GLUT_KEY_PAGE_UP: if(wristRight2 > -30) wristRight2 -= wristFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(wristRight2 < 30) wristRight2 += wristFactor; break;
					}
					break;
			}
			break;
		case 'E':
			switch(subMode){
				case 'L':
					switch(key){
						case GLUT_KEY_UP : if(elbowLeft > -160) elbowLeft -= elbowFactor; break;
						case GLUT_KEY_DOWN : if(elbowLeft < 0) elbowLeft += elbowFactor;break;
					}
					break;
				case 'R':
					switch(key){
						case GLUT_KEY_UP : if(elbowRight > -160) elbowRight -= elbowFactor; break;
						case GLUT_KEY_DOWN : if(elbowRight < 0) elbowRight += elbowFactor;break;
					}
					break;
			}
			break;

		case 'A':
			switch(subMode){
				case 'L':
					switch(key){
						case GLUT_KEY_LEFT : if(ankleLeft3 < 38) ankleLeft3 += ankleFactor; break;
						case GLUT_KEY_RIGHT : if(ankleLeft3 > -38) ankleLeft3 -= ankleFactor;break;
						case GLUT_KEY_UP : if(ankleLeft1 > -15) ankleLeft1 -= ankleFactor; break;
						case GLUT_KEY_DOWN : if(ankleLeft1 < 25) ankleLeft1 += ankleFactor;break;
						case GLUT_KEY_PAGE_UP: if(ankleLeft2 > -18) ankleLeft2 -= ankleFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(ankleLeft2 < 18) ankleLeft2 += ankleFactor; break;
					}
					break;
				case 'R':
					switch(key){
						case GLUT_KEY_LEFT : if(ankleRight3 < 38) ankleRight3 += ankleFactor; break;
						case GLUT_KEY_RIGHT : if(ankleRight3 > -38) ankleRight3 -= ankleFactor;break;
						case GLUT_KEY_UP : if(ankleRight1 > -15) ankleRight1 -= ankleFactor; break;
						case GLUT_KEY_DOWN : if(ankleRight1 < 25) ankleRight1 += ankleFactor;break;
						case GLUT_KEY_PAGE_UP: if(ankleRight2 > -18) ankleRight2 -= ankleFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(ankleRight2 < 18) ankleRight2 += ankleFactor; break;
					}
					break;
			}
			break;

		case 'K':
			switch(subMode){
				case 'L':
					switch(key){
						case GLUT_KEY_UP : if(kneeLeft > 0) kneeLeft -= kneeFactor; break;
						case GLUT_KEY_DOWN : if(kneeLeft < 136)  kneeLeft += kneeFactor;break;
					}
					break;
				case 'R':
					switch(key){
						case GLUT_KEY_UP : if(kneeRight > 0) kneeRight -= kneeFactor; break;
						case GLUT_KEY_DOWN : if(kneeRight < 136) kneeRight += kneeFactor;break;
					}
					break;
			}
			break;

		case 'H':
			switch(subMode){
				case 'L':
					switch(key){
						case GLUT_KEY_LEFT : if(hipLeft3 < 75) hipLeft3 += hipFactor; break;
						case GLUT_KEY_RIGHT : if(hipLeft3 > -60) hipLeft3 -= hipFactor;break;
						case GLUT_KEY_UP : if(hipLeft1 > -84) hipLeft1 -= hipFactor; break;
						case GLUT_KEY_DOWN : if(hipLeft1 < 16) hipLeft1 += hipFactor;break;
						case GLUT_KEY_PAGE_UP: if(hipLeft2 > -30) hipLeft2 -= hipFactor; break;
						case GLUT_KEY_PAGE_DOWN: if(hipLeft2 < 25) hipLeft2 += hipFactor; break;
					}
					break;
				case 'R':
					switch(key){
						case GLUT_KEY_LEFT : if(hipRight3 < 75) hipRight3 += hipFactor; break;
						case GLUT_KEY_RIGHT : if(hipRight3 > -60) hipRight3 -= hipFactor;break;
						case GLUT_KEY_UP : if(hipRight1 > -84) hipRight1 -= hipFactor; break;
						case GLUT_KEY_DOWN : if(hipRight1 < 16) hipRight1 += hipFactor;break;
						case GLUT_KEY_PAGE_UP: if(hipRight2 > -30) hipRight2 -= hipFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(hipRight2 < 25) hipRight2 += hipFactor; break;
					}
					break;
			}
			break;

		case 'V':
			switch (key) {
				case GLUT_KEY_LEFT : if(torso13 < 40) torso13 += torso1Factor; break;
				case GLUT_KEY_RIGHT : if(torso13 > -40) torso13 -= torso1Factor;break;
				case GLUT_KEY_UP : if(torso11 > -125) torso11 -= torso1Factor; break;
				case GLUT_KEY_DOWN : if(torso11 < 25) torso11 += torso1Factor;break;
				case GLUT_KEY_PAGE_UP: if(torso12 > -40) torso12 -= torso1Factor;break;
				case GLUT_KEY_PAGE_DOWN: if(torso12 < 40) torso12 += torso1Factor; break;
			}
			break;

		case 'B':
			switch (key) {
				case GLUT_KEY_LEFT : if(torso23 < 30) torso23 += torso2Factor; break;
				case GLUT_KEY_RIGHT : if(torso23 > -30) torso23 -= torso2Factor;break;
				case GLUT_KEY_UP : if(torso21 > -10) torso21 -= torso2Factor; break;
				case GLUT_KEY_DOWN : if(torso21 < 80) torso21 += torso2Factor;break;
				case GLUT_KEY_PAGE_UP: if(torso22 > -40) torso22 -= torso2Factor;break;
				case GLUT_KEY_PAGE_DOWN: if(torso22 < 40) torso22 += torso2Factor; break;
			}
			break;
		

	}
	glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y) 
{
  if (key == 27) exit(0);

  if(key == 'N' || key == 'n'){
  	mode = 'N';
  }

  if(key == 's' || key == 'S'){
  	mode = 'S';
  }

  if(key == 'e' || key == 'E'){
  	mode = 'E';
  }

  if(key == 'w' || key == 'W'){
  	mode = 'W';
  }

  if(key == 'h' || key == 'H'){
  	mode = 'H';
  }

  if(key == 'k' || key == 'K'){
  	mode = 'K';
  }

  if(key == 'a' || key == 'A'){
  	mode = 'A';
  }

  if(key == 'V' || key == 'v'){
  	mode = 'V';
  }

  if(key == 'B' || key == 'b'){
  	mode = 'B';
  }

  if(key == 'R' || key == 'r'){
  		subMode = 'R';
  }

  if(key == 'L' || key == 'l'){
  		subMode = 'L';
  }


}

GLuint createFaceDL()
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_face();
  glEndList();
  return(dl);
}

GLuint createNeckDL()
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_neck();
  glEndList();
  return(dl);
}

GLuint createtorso1DL()
{
	GLuint dl;
	dl = glGenLists(2);
	glNewList(dl,GL_COMPILE);
	struct_neck();
	glEndList();
	return(dl);
}

GLuint createHandDL()
{
	GLuint dl;
	dl = glGenLists(2);
	glNewList(dl,GL_COMPILE);
	struct_hand();
	glEndList();
	return(dl);
}

GLuint createFootDL()
{
	GLuint dl;
	dl = glGenLists(2);
	glNewList(dl,GL_COMPILE);
	struct_foot();
	glEndList();
	return(dl);
}


GLuint Torso1DL()
{
	GLuint dl;
	dl = glGenLists(3);
	glNewList(dl,GL_COMPILE);
	struct_torso1();
	glEndList();
	return(dl);
}


GLuint Torso2DL()
{
	GLuint dl;
	dl = glGenLists(9);
	glNewList(dl,GL_COMPILE);
	struct_torso2();
	glEndList();
	return(dl);
}

GLuint Torso3DL()
{
	GLuint dl;
	dl = glGenLists(10);
	glNewList(dl,GL_COMPILE);
	struct_torso3();
	glEndList();
	return(dl);
}
GLuint createShoulderDL()
{
	GLuint dl;
	dl = glGenLists(4);
	glNewList(dl,GL_COMPILE);
	struct_shoulder();
	glEndList();
	return(dl);
}
GLuint createArmDL()
{
	GLuint dl;
	dl = glGenLists(5);
	glNewList(dl,GL_COMPILE);
	struct_arm();
	glEndList();
	return(dl);
}
GLuint createElbowDL()
{
	GLuint dl;
	dl = glGenLists(6);
	glNewList(dl,GL_COMPILE);
	struct_elbow();
	glEndList();
	return(dl);
}
GLuint createWristDL()
{
	GLuint dl;
	dl = glGenLists(7);
	glNewList(dl,GL_COMPILE);
	struct_wrist();
	glEndList();
	return(dl);
}

GLuint createAnkleDL()
{
	GLuint dl;
	dl = glGenLists(8);
	glNewList(dl,GL_COMPILE);
	struct_ankle();
	glEndList();
	return(dl);
}

GLuint createForearmDL()
{
	GLuint dl;
	dl = glGenLists(8);
	glNewList(dl,GL_COMPILE);
	struct_forearm();
	glEndList();
	return(dl);
}

// GLuint createHandDL()
// {
// 	GLuint dl;
// 	dl = glGenLists(8);
// 	glNewList(dl,GL_COMPILE);
// 	struct_hand();
// 	glEndList();
// 	return(dl);
// }

// GLuint createFootDL()
// {
// 	GLuint dl;
// 	dl = glGenLists(8);
// 	glNewList(dl,GL_COMPILE);
// 	struct_foot();
// 	glEndList();
// 	return(dl);
// }

GLuint createThighDL()
{
	GLuint dl;
	dl = glGenLists(8);
	glNewList(dl,GL_COMPILE);
	struct_thigh();
	glEndList();
	return(dl);
}

GLuint createLegDL()
{
	GLuint dl;
	dl = glGenLists(8);
	glNewList(dl,GL_COMPILE);
	struct_leg();
	glEndList();
	return(dl);
}

void struct_foot(){
	glTranslatef(-0.25,0.6,0);
	glScalef(0.4,0.5,0.1);	
	struct_torso3();
}

void struct_hand(){
	glTranslatef(-0.18,0.1,0.3);
	glScalef(0.3,0.1,0.4);
	struct_torso3();
}



void struct_face(){
	glScalef(1.5,2,1);
	glColor3f(1,0,0);
	glutSolidSphere(0.5,20,20);
}

void struct_neck(){
	glScalef(1.5,2,1);
	glColor3f(0.5,0.5,0);
	glutSolidCube(0.25);
}

void struct_torso1(){
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0.75);
	glVertex3f(0.4,-3, 0.75);
	glVertex3f(1.6,-3, 0.75);
	glVertex3f(2,0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, -0.75);
	glVertex3f(0.4,-3, -0.75);
	glVertex3f(1.6,-3, -0.75);
	glVertex3f(2,0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -0.75);
	glVertex3f(0.4,-3, -0.75);
	glVertex3f(0.4,-3, 0.75);
	glVertex3f(0, 0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(1.6,-3, -0.75);
	glVertex3f(2,0, -0.75);
	glVertex3f(2,0, 0.75);
	glVertex3f(1.6,-3, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0.75);
	glVertex3f(2,0, 0.75);
	glVertex3f(2,0, -0.75);
	glVertex3f(0, 0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(0.4,-3, 0.75);
	glVertex3f(1.6,-3, 0.75);
	glVertex3f(1.6,-3, -0.75);
	glVertex3f(0.4,-3, -0.75);
	glEnd();
}



// void struct_torso2(){
// 	glBegin(GL_POLYGON);
// 	glColor3f(0.5, 0.5, 0);
// 	glVertex3f(0, 0, 0.75);
// 	glVertex3f(0,-0.2, 0.75);
// 	glVertex3f(1.2,-0.2, 0.75);
// 	glVertex3f(1.2,0, 0.75);
// 	glEnd();
// 	glBegin(GL_POLYGON);
// 	glColor3f(0, 1, 0);
// 	glVertex3f(0, 0, -0.75);
// 	glVertex3f(0,-0.2, -0.75);
// 	glVertex3f(1.2,-0.2, -0.75);
// 	glVertex3f(1.2,0, -0.75);
// 	glEnd();
// 	glBegin(GL_POLYGON);
// 	glColor3f(0, 0, 1);
// 	glVertex3f(0, 0, -0.75);
// 	glVertex3f(0,-0.2, -0.75);
// 	glVertex3f(0,-0.2, 0.75);
// 	glVertex3f(0, 0, 0.75);
// 	glEnd();
// 	glBegin(GL_POLYGON);
// 	glColor3f(0, 0, 1);
// 	glVertex3f(1.2,-0.2, -0.75);
// 	glVertex3f(1.2,0, -0.75);
// 	glVertex3f(1.2,0, 0.75);
// 	glVertex3f(1.2,-0.2, 0.75);
// 	glEnd();
// 	glBegin(GL_POLYGON);
// 	glColor3f(1, 0, 0);
// 	glVertex3f(0, 0, 0.75);
// 	glVertex3f(1.2,0, 0.75);
// 	glVertex3f(1.2,0, -0.75);
// 	glVertex3f(0, 0, -0.75);
// 	glEnd();
// 	glBegin(GL_POLYGON);
// 	glColor3f(1, 0, 0);
// 	glVertex3f(0,-0.2, 0.75);
// 	glVertex3f(1.2,-0.2, 0.75);
// 	glVertex3f(1.2,-0.2, -0.75);
// 	glVertex3f(0,-0.2, -0.75);
// 	glEnd();
// }

void struct_torso2(){
	glColor3f(0.5,0.5,0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glPushMatrix();
		glTranslatef(0.6,1.5,0);
		glRotatef(90,1,0,0);
		gluCylinder(quadratic,0.6,0.6,2, 20, 20);
	glPopMatrix();
}

void struct_torso3(){
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0.75);
	glVertex3f(-0.2,-1.5, 0.75);
	glVertex3f(1.4,-1.5, 0.75);
	glVertex3f(1.2,0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, -0.75);
	glVertex3f(-0.2,-1.5, -0.75);
	glVertex3f(1.4,-1.5, -0.75);
	glVertex3f(1.2,0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -0.75);
	glVertex3f(-0.2,-1.5, -0.75);
	glVertex3f(-0.2,-1.5, 0.75);
	glVertex3f(0, 0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(1.4,-1.5, -0.75);
	glVertex3f(1.2,0, -0.75);
	glVertex3f(1.2,0, 0.75);
	glVertex3f(1.4,-1.5, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0.75);
	glVertex3f(1.2,0, 0.75);
	glVertex3f(1.2,0, -0.75);
	glVertex3f(0, 0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(-0.2,-1.5, 0.75);
	glVertex3f(1.4,-1.5, 0.75);
	glVertex3f(1.4,-1.5, -0.75);
	glVertex3f(-0.2,-1.5, -0.75);
	glEnd();
}




void struct_shoulder(){
	glColor3f(0.5,0.5,0);
	glutSolidSphere(0.50,20,20);
}

void struct_elbow(){
	glColor3f(0.5,0.5,0);
	glutSolidSphere(0.35,20,20);
}

void struct_wrist(){
	glColor3f(0.5,0.5,0);
	glutSolidSphere(0.20,20,20);
}

void struct_ankle(){
	glColor3f(0.5,0.5,0);
	glutSolidSphere(0.15,20,20);
}

void struct_arm(){
	glColor3f(0,0,0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic,0.35,0.25, 3, 20, 20);
}

void struct_forearm(){
	glColor3f(0,0,0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic,0.20,0.18, 2, 20, 20);
}

void struct_thigh(){
	glColor3f(0,0,0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic,0.35,0.25, 1.5, 20, 20);
}

void struct_leg(){
	glColor3f(0,0,0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic,0.20,0.18, 1, 20, 20);
}

int main (int argc, char *argv[])
{

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640,360);
  glutCreateWindow( "Assignment 2" );
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  
  glutDisplayFunc( display );
  glutReshapeFunc( resize );
  glutMouseFunc( mouse );
  glutSpecialFunc(specialKey);
  glutKeyboardFunc(processNormalKeys);
  
  init();
  glutMainLoop();
}
