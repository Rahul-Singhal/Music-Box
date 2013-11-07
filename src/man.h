#ifndef MAN_H
#define MAN_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
using namespace std;

//state of man is:
// neck1, neck2, neck3,
// shoulderLeft1,shoulderLeft2,shoulderLeft3,
// shoulderRight1,shoulderRight2,shoulderRight3,
// wristLeft1,wristLeft2,wristLeft3,
// wristRight1,wristRight2,wristRight3,
// ankleLeft1,ankleLeft2,ankleLeft3,
// ankleRight1,ankleRight2,ankleRight3,
// hipLeft1,hipLeft2,hipLeft3,
// hipRight1,hipRight2,hipRight3,
// elbowLeft,elbowRight,
// kneeLeft, kneeRight,
// torso11, torso12, torso13,
// torso21, torso22, torso23

class man{
private:
	char mode;
	char subMode;

	float neck1,neck2,neck3;
	float neck1IF,neck2IF,neck3IF;
	float neckFactor;

	float shoulderLeft1,shoulderLeft2,shoulderLeft3;
	float shoulderLeft1IF,shoulderLeft2IF,shoulderLeft3IF;
	float shoulderFactor;
	float shoulderRight1,shoulderRight2,shoulderRight3;
	float shoulderRight1IF,shoulderRight2IF,shoulderRight3IF;

	float elbowLeft;
	float elbowLeftIF;
	float elbowFactor;
	float elbowRight;
	float elbowRightIF;

	float wristLeft1,wristLeft2,wristLeft3;
	float wristLeft1IF,wristLeft2IF,wristLeft3IF;
	float wristFactor;
	float wristRight1,wristRight2,wristRight3;
	float wristRight1IF,wristRight2IF,wristRight3IF;

	float hipLeft1,hipLeft2,hipLeft3;
	float hipLeft1IF,hipLeft2IF,hipLeft3IF;
	float hipFactor;
	float hipRight1,hipRight2,hipRight3;
	float hipRight1IF,hipRight2IF,hipRight3IF;

	float ankleLeft1,ankleLeft2,ankleLeft3;
	float ankleLeft1IF,ankleLeft2IF,ankleLeft3IF;
	float ankleFactor;
	float ankleRight1,ankleRight2,ankleRight3;
	float ankleRight1IF,ankleRight2IF,ankleRight3IF;

	float kneeLeft;
	float kneeLeftIF;
	float kneeFactor;
	float kneeRight;
	float kneeRightIF;

	float torso11,torso12,torso13;
	float torso11IF,torso12IF,torso13IF;
	float torso1Factor;

	float torso21,torso22,torso23;
	float torso21IF,torso22IF,torso23IF;
	float torso2Factor;

	float angleTheta,angleAlpha;
	float x,y,z;
	float r;
	int count;
	float fraction;

	/*----------------------------------------------------------*/

	GLint noseDL;
	GLint lipsDL;
	GLint eyesDL;
	GLint stickDL;
	GLint capDL;
	GLint faceDL;
	GLint neckDL;
	GLint torso1DL;
	GLint torso2DL;
	GLint torso3DL;
	GLint shoulderDL;
	GLint armDL;
	GLint thighDL;
	GLint legDL;
	GLint wristDL;
	GLint elbowDL;
	GLint forearmDL;
	GLint ankleDL;
	GLint footDL;
	GLint handDL;

	GLuint texture1 ; //skin2
	GLuint texture2 ; //shirt21
	GLuint texture3; //skin3
	GLuint texture4; //shirt22
	GLuint texture5; //cap1
	GLuint texture6; //skin1



	/*----------------------------------------------------------*/

	void initNose();
	void initEyes();
	void initStick();
	void initLips();
	void initCap();
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
	GLuint createNoseDL();
	GLuint createStickDL();
	GLuint createLipsDL();
	GLuint createEyesDL();
	GLuint createCapDL();
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
	GLuint createtorso1DL();
	void struct_nose();
	void struct_lips();
	void struct_eyes();
	void struct_stick();
	void struct_cap();
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

public:
	man();
	void draw();
	void processNormalKeys(unsigned char key, int x, int y);
	void specialKey(int key, int x, int y);
	void getState(FILE * fp);
	void setState(FILE * fp, int numFrames);
	void nextFrame();
};

#endif