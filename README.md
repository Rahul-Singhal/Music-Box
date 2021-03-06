Music-Box
=========

An animated music box created in openGL.


### LINK TO THE VIDEO CREATED USING THE ANIMATION
------------------------------------------------------
http://www.youtube.com/watch?v=0qq6_tL3cv4&feature=youtu.be


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
		8.furniture.cpp
		9.furniture.h
		10.lamp.cpp
		11.lamp.h
		12.room.h
		13.room.cpp
		14.shelf.cpp
		15.shelf.h
		16.table.h
		17.table.cpp

	2. textures: Contained files are
		1.cap1.bmp
		2.lamp1.bmp
		3.light1.bmp
		4.shirt21.bmp
		5.skin1.bmp
		6.skin3.bmp
		7.stone2_part2.bmp
		8.tv1.bmp
		9.wall5.bmp
		10.wood4.bmp
		11.floor2.bmp
		12.lamp2.bmp
		13.roof3.bmp
		14.shirt22.bmp
		15.skin2.bmp
		15.stone2_part1.bmp
		17.table2.bmp
		18.wall4.bmp
		19.wood3.bmp
		20.wood5.bmp

	3. Makefile: To copile and generate the binaries.

	4. README: This file.

	5. Resources: A sample keyframe.txt file.


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
1. In this mode we enable the user to interact with the camera capturing the entire world. 
2. To activate this mode press the keys 'Z' and 'N' in order.
3. Use 'UP' and 'DOWN' arrow keys to move the camera towards and away from the objects respectively.
4. Use 'LEFT' and 'RIGHT' arrow keys to move the camera to the left and right respectively.
5. Use 'F1' and 'F2' keys to rotate the camera clockwise and anti-clockwise about its current position

#### MODE 2:
--------
1. In this mode, the user is able to control the box using the keyboard keys.
2. Use the key 'O' to open the box.
3. Use the key 'C' to close the box.

#### MODE 3:
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

2. How to make the body parts move, huh? Pretty easy! Use the keys ('UP', 'DOWN') , ('LEFT','RIGHT') and ('F1','F2') to control the 3 degrees of freedom.

3. In case of just one degree of freedom, use the keys 'UP' and 'DOWN' arrow keys to move the part.

#### MODE 4:
--------

1. This mode is to let user draw points for the bezier curve.Activate this mode by pressing 'Z' followed by an 'S'.
2. Now to draw a bezier curve, click a point anywhere in the room. This will create a point on the clicked object.
3. Press '1', '2' and '3' keys to activate the movement of this clicked point. Move the point on the axes using the keys 'F5' and 'F6'.
4. Now press 'F' to freeze the current point. Click any other point and go to step 3 to control that point or click 'E' to draw the bezier curve.

#### MODE 5:
--------

1. This mode lets user switch on and off the lights installed in the room. There are two lights
	a. Lamp(Switch it on and off by using the keys 'Z' and then an '6')
	b. Room Light(Switch it on and off by using the keys 'Z' and then an '7')


#### MODE 6:
-------

1. This is the mode in which user is allowed to capture frames from the 3D model by moving here and there in the virtual world.
2. This mode is basically the record mode.
3. Activate this mode by pressing 'Z' and then 'R'. Now at any state in the world, if you want to save the state, press 'F10'. The state variables of all the objects will be stored in a file named 'keyframes.txt'.

#### MODE 7:
-------

1. This is the playback mode in which the user sees the animation created by interpolating between the states that were saved by him during the record mode.
2. Uncomment the line 288 in the file main.cpp to store the 'ppm' images corresponding to these interpolated frames if you want to create some video later using these images.
3. The images will be stored in 'dump' folder.



									"HAVE FUN PLAYING WITH THE OBJECTS!!"






