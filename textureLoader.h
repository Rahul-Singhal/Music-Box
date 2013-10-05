#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

class textureLoader{
	private:
		const char* imagepath;
		unsigned int dataPos;     // Position in the file where the actual data begins
		unsigned int width, height;
		// Actual RGB data
		unsigned char * data;
		bool readImage();
	public:
		textureLoader(const char* imagepath);
		unsigned char* getData();
		int getHeight();
		int getWidth();
};

#endif