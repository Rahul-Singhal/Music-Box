#include <GL/glut.h>
#include "man.h"
#include "textureLoader.h"

void man::draw()
{
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
				glTranslatef(0.0,-1.5,0.0);
		        //glTranslatef(0.0,-1.25,0.0);
				glRotatef(neck1, 1,0,0);
				glRotatef(neck2, 0,1,0);
				glRotatef(neck3, 0,0,1);
				glPushMatrix();
		            glRotatef(-90, 1,0,0);
					glCallList(neckDL);
				glPopMatrix();
				glTranslatef(0.0,1.2,0.0);
				glPushMatrix();

                    glCallList(faceDL);
                    glTranslatef(-0.25,0.05,1.0);
                    glColor3f(0,0,0);
                    glTranslatef(0,0,-0.5);
                    glCallList(eyesDL);
                    glTranslatef(+0.25,-0.05,-1.0);
                    glTranslatef(+0.25,0.05,1.0);
                    glColor3f(0,0,0);
                    glCallList(eyesDL);
                    glTranslatef(-0.25,-0.05,-1.0);
                    glColor3f(1,1,1);
                    glTranslatef(0,0,1.0);
                    glPushMatrix();
                        glCallList(noseDL);
                    glPopMatrix();
                    glTranslatef(0,0,-1.0);
    
                    glColor3f(1,0,0);
                    glTranslatef(0,-0.25,0.9);
                    glCallList(lipsDL);
                    glTranslatef(0,+0.25,-0.9);
                    glColor3f(1,1,1);
                    glTranslatef(0,0,0.5);
				glPopMatrix();
				glPushMatrix();
                    glTranslatef(0,0.6,0.0);
                    glCallList(capDL);
                glPopMatrix();
			glPopMatrix();




			glPushMatrix();
				glPushMatrix();
					glTranslatef(-0.6,-4.5,0.0);
					glCallList(torso2DL);
		  		glPopMatrix();

		  		//right hand , left hand and torso1
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
												glRotatef(90, 1,0,0);
												glRotatef(-30, 0,1,0);
                                                glCallList(stickDL);
											glPopMatrix();
										glPopMatrix();
									glPopMatrix();
								glPopMatrix();
					  		glPopMatrix();
						glPopMatrix();
			  		glPopMatrix();

			  		//left hand
			  		glPushMatrix();
			  			glTranslatef(0,-0.5,0);
						//Rotation and translation corresponding to shoulder movement here
			  			glRotatef(shoulderLeft1, 1,0,0);
						glRotatef(shoulderLeft2, 0,1,0);
						glRotatef(shoulderLeft3, 0,0,1);
						//glTranslatef(+1.25,-2.0,0.0);
						glTranslatef(0,0.5,0);
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
}

man::man(){

	mode = 'Q';
	subMode = 'Q';

	neck1=0;neck2=0;neck3=0;
	neckFactor = 1;

	shoulderLeft1=0;shoulderLeft2=0;shoulderLeft3=0;
	shoulderFactor = 1;
	shoulderRight1=0;shoulderRight2=0;shoulderRight3=0;

	elbowLeft=0;
	elbowFactor = 1;
	elbowRight=0;

	wristLeft1=0;wristLeft2=0;wristLeft3=0;
	wristFactor = 1;
	wristRight1=0;wristRight2=0;wristRight3=0;

	hipLeft1=0;hipLeft2=0;hipLeft3=0;
	hipFactor = 1;
	hipRight1=0;hipRight2=0;hipRight3=0;

	ankleLeft1=0;ankleLeft2=0;ankleLeft3=0;
	ankleFactor = 1;
	ankleRight1=0;ankleRight2=0;ankleRight3=0;

	kneeLeft=0;
	kneeFactor = 1;
	kneeRight=0;

	torso11=0;torso12=0;torso13=0;
	torso1Factor = 1;

	torso21=0;torso22=0;torso23=0;
	torso2Factor = 1;

	angleTheta=0.0;angleAlpha=0.0;
	x=0.0f;y=0.0f;z=20.0f;
	r=20.0f;
	count = 0;
	fraction = 0.01;

	glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    textureLoader tLoader1("textures/skin2.bmp");

    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    textureLoader tLoader2("textures/shirt21.bmp");

    glGenTextures(1, &texture3);
    glBindTexture(GL_TEXTURE_2D, texture3);
    textureLoader tLoader3("textures/skin3.bmp");

	glGenTextures(1, &texture4);
    glBindTexture(GL_TEXTURE_2D, texture4);
    textureLoader tLoader4("textures/shirt22.bmp");    

    glGenTextures(1, &texture5);
    glBindTexture(GL_TEXTURE_2D, texture5);
    textureLoader tLoader5("textures/cap1.bmp");

    glGenTextures(1, &texture6);
    glBindTexture(GL_TEXTURE_2D, texture6);
    textureLoader tLoader6("textures/skin1.bmp");


    initNose();
    initCap();
    initEyes();
    initLips();
    initStick();
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

void man::initEyes(){
	glEnable(GL_DEPTH_TEST);
	eyesDL = createEyesDL();
}
void man::initNose(){
	glEnable(GL_DEPTH_TEST);
	noseDL = createNoseDL();
}

void man::initLips(){
	glEnable(GL_DEPTH_TEST);
	lipsDL = createLipsDL();
}
void man::initStick(){
	glEnable(GL_DEPTH_TEST);
	stickDL = createStickDL();
}

void man::initCap(){
	glEnable(GL_DEPTH_TEST);
	capDL = createCapDL();
}

void man::initFace(){
	glEnable(GL_DEPTH_TEST);
	faceDL = createFaceDL();
}
void man::initNeck(){
	glEnable(GL_DEPTH_TEST);
	neckDL = createNeckDL();
}

void man::initTorso1(){
	glEnable(GL_DEPTH_TEST);
	torso1DL = Torso1DL();
}

void man::initTorso2(){
	glEnable(GL_DEPTH_TEST);
	torso2DL = Torso2DL();
}

void man::initTorso3(){
	glEnable(GL_DEPTH_TEST);
	torso3DL = Torso3DL();
}


void man::initShoulder(){
	glEnable(GL_DEPTH_TEST);
	shoulderDL = createShoulderDL();
}

void man::initHand(){
	glEnable(GL_DEPTH_TEST);
	handDL = createHandDL();
}

void man::initFoot(){
	glEnable(GL_DEPTH_TEST);
	footDL = createFootDL();
}

void man::initArm(){
	glEnable(GL_DEPTH_TEST);
	armDL = createArmDL();
}

void man::initAnkle(){
	glEnable(GL_DEPTH_TEST);
	ankleDL = createAnkleDL();
}

void man::initElbow(){
	glEnable(GL_DEPTH_TEST);
	elbowDL = createElbowDL();
}
void man::initWrist(){
	glEnable(GL_DEPTH_TEST);
	wristDL = createWristDL();
}
void man::initForearm(){
	glEnable(GL_DEPTH_TEST);
	forearmDL = createForearmDL();
}
void man::initThigh(){
	glEnable(GL_DEPTH_TEST);
	thighDL = createThighDL();
}
void man::initLeg(){
	glEnable(GL_DEPTH_TEST);
	legDL = createLegDL();
}


void man::specialKey(int key, int x, int y) {
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
						case GLUT_KEY_RIGHT : if(shoulderRight3 < 158) shoulderRight3 += shoulderFactor; break;
						case GLUT_KEY_LEFT : if(shoulderRight3 > -24) shoulderRight3 -= shoulderFactor;break;
						case GLUT_KEY_UP : shoulderRight1 -= shoulderFactor; break;
						case GLUT_KEY_DOWN : shoulderRight1 += shoulderFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(shoulderRight2 > -65) shoulderRight2 -= shoulderFactor;break;
						case GLUT_KEY_PAGE_UP: if(shoulderRight2 < 65) shoulderRight2 += shoulderFactor; break;
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
						case GLUT_KEY_RIGHT : if(wristRight3 < 177) wristRight3 += wristFactor; break;
						case GLUT_KEY_LEFT : if(wristRight3 > -138) wristRight3 -= wristFactor;break;
						case GLUT_KEY_UP :  if(wristRight1 > -75) wristRight1 -= wristFactor; break;
						case GLUT_KEY_DOWN : if(wristRight1 < 75) wristRight1 += wristFactor;break;
						case GLUT_KEY_PAGE_DOWN: if(wristRight2 > -30) wristRight2 -= wristFactor;break;
						case GLUT_KEY_PAGE_UP: if(wristRight2 < 30) wristRight2 += wristFactor; break;
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
						case GLUT_KEY_PAGE_DOWN: if(ankleRight2 > -18) ankleRight2 -= ankleFactor;break;
						case GLUT_KEY_PAGE_UP: if(ankleRight2 < 18) ankleRight2 += ankleFactor; break;
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
						case GLUT_KEY_LEFT : if(hipRight3 < 60) hipRight3 += hipFactor; break;
						case GLUT_KEY_RIGHT : if(hipRight3 > -75) hipRight3 -= hipFactor;break;
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
}

void man::processNormalKeys(unsigned char key, int x, int y) 
{

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

GLuint man::createNoseDL()
{
    GLuint dl;
    dl = glGenLists(1);
    glNewList(dl,GL_COMPILE);
    struct_nose();
    glEndList();
    return(dl);
}


GLuint man::createStickDL()
{
    GLuint dl;
    dl = glGenLists(1);
    glNewList(dl,GL_COMPILE);
    struct_stick();
    glEndList();
    return(dl);
}


GLuint man::createEyesDL()
{
    GLuint dl;
    dl = glGenLists(1);
    glNewList(dl,GL_COMPILE);
    struct_eyes();
    glEndList();
    return(dl);
}


GLuint man::createLipsDL()
{

    GLuint dl;
    dl = glGenLists(1);
    glNewList(dl,GL_COMPILE);
    struct_lips();
    glEndList();
    return(dl);
}

GLuint man::createFaceDL()
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_face();
  glEndList();
  return(dl);
}

GLuint man::createCapDL()
{
    GLuint dl;
    dl = glGenLists(13);
    glNewList(dl,GL_COMPILE);
    struct_cap();
    glEndList();
    return(dl);
}

GLuint man::createNeckDL()
{
  GLuint dl;
  dl = glGenLists(1);
  glNewList(dl,GL_COMPILE);
  struct_neck();
  glEndList();
  return(dl);
}

GLuint man::createtorso1DL()
{
	GLuint dl;
	dl = glGenLists(2);
	glNewList(dl,GL_COMPILE);
	struct_neck();
	glEndList();
	return(dl);
}

GLuint man::createHandDL()
{
	GLuint dl;
	dl = glGenLists(2);
	glNewList(dl,GL_COMPILE);
	struct_hand();
	glEndList();
	return(dl);
}

GLuint man::createFootDL()
{
	GLuint dl;
	dl = glGenLists(2);
	glNewList(dl,GL_COMPILE);
	struct_foot();
	glEndList();
	return(dl);
}


GLuint man::Torso1DL()
{
	GLuint dl;
	dl = glGenLists(3);
	glNewList(dl,GL_COMPILE);
	struct_torso1();
	glEndList();
	return(dl);
}


GLuint man::Torso2DL()
{
	GLuint dl;
	dl = glGenLists(9);
	glNewList(dl,GL_COMPILE);
	struct_torso2();
	glEndList();
	return(dl);
}

GLuint man::Torso3DL()
{
	GLuint dl;
	dl = glGenLists(10);
	glNewList(dl,GL_COMPILE);
	struct_torso3();
	glEndList();
	return(dl);
}

void man::struct_eyes(){
    GLUquadricObj* Sphere;
    Sphere=gluNewQuadric();
    gluSphere(Sphere,0.05,20,20);
    glColor3f(1, 1, 1);
}

void man::struct_cap(){

    glBindTexture(GL_TEXTURE_2D, texture5);
    glEnable (GL_TEXTURE_2D);
    GLUquadricObj* quadric;
    quadric=gluNewQuadric();
    gluQuadricTexture(quadric,1);
    glRotatef(-90, 1,0,0);
    glPushMatrix();
        gluCylinder(quadric,0.65,0.65,2, 20, 20);
        gluDisk(quadric, 0.0,1,20, 1);
        gluCylinder(quadric,1,1,0.5, 20, 20);
        glTranslatef(0,0,0.5);
    gluDisk(quadric, 0.0f,1,20, 1); 
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
	//glutSolidSphere(0.5,20,20);
}

void man::struct_stick(){
    glColor3f(0.9375,0.910,1 );
    //glGenTextures(1, &textureSkin);
    //glBindTexture(GL_TEXTURE_2D, textureSkin);
    
    //textureLoader tLoader1("./skin1.bmp");
    //glEnable (GL_TEXTURE_2D);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
    //gluQuadricTexture(quadratic,1);
	gluCylinder(quadratic,0.2,0.2, 25, 20, 20);
    glColor3f(1, 1, 1);
   // glDisable(GL_TEXTURE_2D);
    
}

void man::struct_nose(){
    glColor3f(1,0,0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic,0.09,0,2, 20, 20);
    glColor3f(1, 1, 1);
}


void man::struct_lips(){
    //glColor3f(1,0,0);
    glScalef(2,1,1);
	struct_eyes();
    glColor3f(1, 1, 1);
}


GLuint man::createShoulderDL()
{
	GLuint dl;
	dl = glGenLists(4);
	glNewList(dl,GL_COMPILE);
	struct_shoulder();
	glEndList();
	return(dl);
}
GLuint man::createArmDL()
{
	GLuint dl;
	dl = glGenLists(5);
	glNewList(dl,GL_COMPILE);
	struct_arm();
	glEndList();
	return(dl);
}
GLuint man::createElbowDL()
{
	GLuint dl;
	dl = glGenLists(6);
	glNewList(dl,GL_COMPILE);
	struct_elbow();
	glEndList();
	return(dl);
}
GLuint man::createWristDL()
{
	GLuint dl;
	dl = glGenLists(7);
	glNewList(dl,GL_COMPILE);
	struct_wrist();
	glEndList();
	return(dl);
}

GLuint man::createAnkleDL()
{
	GLuint dl;
	dl = glGenLists(8);
	glNewList(dl,GL_COMPILE);
	struct_ankle();
	glEndList();
	return(dl);
}

GLuint man::createForearmDL()
{
	GLuint dl;
	dl = glGenLists(8);
	glNewList(dl,GL_COMPILE);
	struct_forearm();
	glEndList();
	return(dl);
}


GLuint man::createThighDL()
{
	GLuint dl;
	dl = glGenLists(8);
	glNewList(dl,GL_COMPILE);
	struct_thigh();
	glEndList();
	return(dl);
}

GLuint man::createLegDL()
{
	GLuint dl;
	dl = glGenLists(8);
	glNewList(dl,GL_COMPILE);
	struct_leg();
	glEndList();
	return(dl);
}

void man::struct_foot(){
	glColor3f(0.457,0.808,0.9375);
	glTranslatef(-0.25,0.6,0);
	glScalef(0.4,0.5,0.1);	
	glBegin(GL_POLYGON);
    glTexCoord4f (0.0, 0.0, 0, 0.75);
	glVertex3f(0, 0, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (1.0, 1.0); 
	glVertex3f(1.4,-1.5, 0.75);
    glTexCoord4f (0.0, 0.75, 0, 0.75);
	glVertex3f(1.2,0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(1.2,0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.2,0, -0.75);
    glTexCoord2f (1.0, 1.0); 
	glVertex3f(1.2,0, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(1.4,-1.5, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.2,0, 0.75);
    glTexCoord2f (1.0, 1.0); 
	glVertex3f(1.2,0, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.4,-1.5, 0.75);
    glTexCoord2f (1.0, 1.0); 
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(-0.2,-1.5, -0.75);
	glEnd();
	glColor3f(1,1,1);
}

void man::struct_hand(){
	glTranslatef(-0.18,0.1,0.3);
	glScalef(0.3,0.1,0.4);
    
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
    glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.4,-1.5, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(1.2,0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(1.2,0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.2,0, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.2,0, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(1.4,-1.5, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.2,0, 0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.2,0, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.4,-1.5, 0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(-0.2,-1.5, -0.75);
	glEnd();
    glDisable(GL_TEXTURE_2D);
}



void man::struct_face(){
	glScalef(1.5,2,1);
    
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
    GLUquadricObj* Sphere;
    Sphere=gluNewQuadric();
    gluQuadricTexture(Sphere,1);
    gluSphere(Sphere,0.5,20,20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_neck(){  //I changed it to cylinder so that I can apply texture
    
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
    gluQuadricTexture(quadratic,1);
	gluCylinder(quadratic,0.375,0.375, 0.5, 20, 20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_torso1(){
    glBindTexture(GL_TEXTURE_2D, texture2);
    glEnable (GL_TEXTURE_2D);
	glBegin(GL_QUADS);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, 0.75);
    glTexCoord4f (0.0, 0.0, 0, 0.6);
	glVertex3f(0.4,-3, 0.75);
    glTexCoord4f (0.6, 0.0, 0, 0.6);
	glVertex3f(1.6,-3, 0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(2,0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(0.4,-3, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.6,-3, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(2,0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(0.4,-3, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(0.4,-3, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(1.6,-3, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(2,0, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(2,0, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(1.6,-3, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(2,0, 0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(2,0, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0.4,-3, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.6,-3, 0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.6,-3, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0.4,-3, -0.75);
	glEnd();
    glDisable(GL_TEXTURE_2D) ;
}




void man::struct_torso2(){
	glColor3f(0,0,0);
    //glEnable (GL_TEXTURE_2D);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
    //gluQuadricTexture(quadratic,1);
	glPushMatrix();
		glTranslatef(0.6,1.5,0);
		glRotatef(90,1,0,0);
		gluCylinder(quadratic,0.6,0.6,2, 20, 20);
	glPopMatrix();
    //glDisable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
}

void man::struct_torso3(){
    
    glBindTexture(GL_TEXTURE_2D, texture4);
    glEnable (GL_TEXTURE_2D);
    
    
	glBegin(GL_POLYGON);
    glTexCoord4f (0.0, 0.0, 0, 0.75);
	glVertex3f(0, 0, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (1.0, 1.0); 
	glVertex3f(1.4,-1.5, 0.75);
    glTexCoord4f (0.0, 0.75, 0, 0.75);
	glVertex3f(1.2,0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(1.2,0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(0, 0, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(-0.2,-1.5, -0.75);
    glTexCoord2f (1.0, 1.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.2,0, -0.75);
    glTexCoord2f (1.0, 1.0); 
	glVertex3f(1.2,0, 0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(1.4,-1.5, 0.75);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.2,0, 0.75);
    glTexCoord2f (1.0, 1.0); 
	glVertex3f(1.2,0, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(0, 0, -0.75);
	glEnd();
	glBegin(GL_POLYGON);
    glTexCoord2f (0.0, 0.0);
	glVertex3f(-0.2,-1.5, 0.75);
    glTexCoord2f (1.0, 0.0);
	glVertex3f(1.4,-1.5, 0.75);
    glTexCoord2f (1.0, 1.0); 
	glVertex3f(1.4,-1.5, -0.75);
    glTexCoord2f (0.0, 1.0);
	glVertex3f(-0.2,-1.5, -0.75);
	glEnd();
    glDisable(GL_TEXTURE_2D);
}



void man::struct_shoulder(){
	
    glBindTexture(GL_TEXTURE_2D, texture3);
    glEnable (GL_TEXTURE_2D);
    GLUquadricObj* Sphere;
    Sphere=gluNewQuadric();
    gluQuadricTexture(Sphere,1);
    gluSphere(Sphere,0.5,20,20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_elbow(){
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
    GLUquadricObj* Sphere;
    Sphere=gluNewQuadric();
    gluQuadricTexture(Sphere,1);
    gluSphere(Sphere,0.35,20,20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_wrist(){
    
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
    GLUquadricObj* Sphere;
    Sphere=gluNewQuadric();
    gluQuadricTexture(Sphere,1);
    gluSphere(Sphere,0.2,20,20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_ankle(){
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
    GLUquadricObj* Sphere;
    Sphere=gluNewQuadric();
    gluQuadricTexture(Sphere,1);
    gluSphere(Sphere,0.15,20,20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_arm(){
   
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
    gluQuadricTexture(quadratic,1);
	gluCylinder(quadratic,0.35,0.25, 3, 20, 20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_forearm(){
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
    gluQuadricTexture(quadratic,1);
	gluCylinder(quadratic,0.20,0.18, 2, 20, 20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_thigh(){
    glBindTexture(GL_TEXTURE_2D, texture1);
    glEnable (GL_TEXTURE_2D);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
    gluQuadricTexture(quadratic,1);
	gluCylinder(quadratic,0.35,0.25, 1.5, 20, 20);
    glDisable(GL_TEXTURE_2D);
}

void man::struct_leg(){
    glBindTexture(GL_TEXTURE_2D, texture6);
    glEnable (GL_TEXTURE_2D);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
    gluQuadricTexture(quadratic,1);
	gluCylinder(quadratic,0.20,0.18, 1, 20, 20);
    glDisable(GL_TEXTURE_2D);
}