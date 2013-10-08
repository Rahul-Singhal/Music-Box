#include "textureLoader.h"
#include <cstdio>
#include <iostream>
using namespace std;

textureLoader::textureLoader(const char* imagepath){
	this->imagepath = imagepath;
	readImage();
}

bool textureLoader::readImage(){
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int imageSize;   // = width*height*3

	FILE * file = fopen(imagepath,"rb");
	if (!file){
		printf("Image could not be opened\n"); return false;
	}
	//read the first 54 bytes to confirm if the texture is correct BMP
	if (fread(header, 1, 54, file)!=54 ){ 
		// If not 54 bytes read : problem
	    printf("Not a correct BMP file\n");
	    return false;
	}
	//first 2 bytes have to be 'B' and 'M'
	if ( header[0]!='B' || header[1]!='M' ){
	    printf("Not a correct BMP file\n");
	    return false;
	}

	//use the header information to get image attributes
	// Read ints from the byte array
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	// book keeping stuff
	if (imageSize==0)    imageSize=width*height*3;
	if (dataPos==0)      dataPos=54; 

	// Create a buffer
	data = new unsigned char [imageSize];
	 
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
	 
	//Everything is in memory now, the file can be closed
	fclose(file);

	//set the texture properties
	
	//unsigned char* pixels = tLoader1.getData();

   glShadeModel(GL_SMOOTH);               // Enable smooth shading of color
   //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set background (clear) color to white
   
   // Depth-buffer for hidden surface removal
   glClearDepth(1.0f);       // Set clear depth value to farthest
   glEnable(GL_DEPTH_TEST);  // Enable depth-buffer for hidden surface removal
   glDepthFunc(GL_LEQUAL);   // The type of depth testing to do
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glEnable(GL_TEXTURE_2D);  // Enable 2D texture 
   // Correct texture distortion in perpective projection
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, 
         GL_UNSIGNED_BYTE, data);  // Create texture from image data
	return true;

}

unsigned char* textureLoader::getData(){
	return data;
}

int textureLoader::getHeight(){
	return height;
}

int textureLoader::getWidth(){
	return width;
}