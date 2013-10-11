Music-Box
=========

An animated music box created in openGL.


### CONTENTS:
----------------------
This tar archive contains following folders with listed files:

	1. src: Contained files are
		1.textureLoader.h
		2.1.textureLoader.cpp
		3.man.h
		4.man.cpp
		5.box.h
		6.box.cpp
		7.main.cpp

	2. textures: Contained files are
		1.cap1.bmp
		2.shirt21.bmp
		3.shirt22.bmp
		4.skin1.bmp
		5.skin2.bmp
		6.skin3.bmp
		7.wood1.bmp
		8.wood2.bmp
		9.wood3.bmp

	3. Makefile: To copile and generate the binaries.

	4. README: This file.


### HOW TO RUN:
------------------------
1. Extract the archive and change the directory into that folder.
2. Run, "make". This will generate the executable binary in the bin folder.
3. Run that binary using the command "./bin/music_box"


### INSTRUCTIONS TO INTERACT WITH THE OBJECTS:
-----------------------------------------

There are 4 modes of interaction that we provide in this package.

#### MODE 1:
--------
1. You can rotate the box in any direction by pressing the left mouse button and dragging it to apply the desired rotation.
2. Click, drag and enjoy!

#### MODE 2:
--------
1. In this mode we enable the user to interact with the camera capturing the entire world. 
2. To activate this mode press the keys 'Z' and 'N' in order.
3. Use 'UP' and 'DOWN' arrow keys to move the camera towards and away from the objects respectively.
4. Use 'LEFT' and 'RIGHT' arrow keys to move the camera to the left and right respectively.
5. Use 'PAGE_UP' and 'PAGE_DOWN' keys to rotate the camera clockwise and anti-clockwise about its current position

#### MODE 3:
--------
1. In this mode, the user is able to control the box using the keyboard keys.
2. Use the key 'O' to open the box.
3. Use the key 'C' to close the box.

#### MODE 4:
--------
1. The most amazing controls that the user can get!! In this mode, the user can interact with the man in the world.

	Body_part	|	How to activate interaction	|	Degrees of Freedom
	---------	|	----------------------------	|	------------------
			|					|
	Neck		|	Press 'N'.			|		3
	Shoulder left	|	Press 'S' and then 'L'		|		3
	Shoulder Right	|	Press 'S' and then 'R'		|		3
	Elbow left 	|	Press 'E' and then 'L'		|		1
	Elbow Right 	|	Press 'E' and then 'R'		|		1
	Wrist left 	|	Press 'W' and then 'L'		|		3
	Wrist Right 	|	Press 'W' and then 'R'		|		3
	Hand left 	|	Press 'H' and then 'L'		|		3
	Hand Right 	|	Press 'H' and then 'R'		|		3
	Knee left 	|	Press 'K' and then 'L'		|		1
	Knee Right 	|	Press 'K' and then 'R'		|		1
	Ankle left 	|	Press 'A' and then 'L'		|		3
	Ankle Right 	|	Press 'A' and then 'R'		|		3
	Upper Torso	|	Press 'V'			|		3
	Lower Torso	|	Press 'B'			|		3

2. How to make the body parts move, huh? Pretty easy! Use the keys ('UP', 'DOWN') , ('LEFT','RIGHT') and ('PAGE_UP','PAGE_DOWN') to control the 3 degrees of freedom.

3. In case of just one degree of freedom, use the keys 'UP' and 'DOWN' arrow keys to move the part.


											"HAVE FUN PLAYING WITH THE OBJECTS!!"






