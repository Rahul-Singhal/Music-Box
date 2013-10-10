#ifndef MAN_H
#define MAN_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <GL/glut.h>
using namespace std;

class man{
private:
	char mode;
	char subMode;

	float neck1,neck2,neck3;
	float neckFactor;

	float shoulderLeft1,shoulderLeft2,shoulderLeft3;
	float shoulderFactor;
	float shoulderRight1,shoulderRight2,shoulderRight3;

	float elbowLeft;
	float elbowFactor;
	float elbowRight;

	float wristLeft1,wristLeft2,wristLeft3;
	float wristFactor;
	float wristRight1,wristRight2,wristRight3;

	float hipLeft1,hipLeft2,hipLeft3;
	float hipFactor;
	float hipRight1,hipRight2,hipRight3;

	float ankleLeft1,ankleLeft2,ankleLeft3;
	float ankleFactor;
	float ankleRight1,ankleRight2,ankleRight3;

	float kneeLeft;
	float kneeFactor;
	float kneeRight;

	float torso11,torso12,torso13;
	float torso1Factor;

	float torso21,torso22,torso23;
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
	void print();

public:
	man();
	void draw();
	void processNormalKeys(unsigned char key, int x, int y);
	void specialKey(int key, int x, int y);
};

#endif