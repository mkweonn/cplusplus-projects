// �2023 Nathan Greenfield
// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#pragma once

#include <string>

#include <vector>
#include "gwindow.h"

#include "disk.h"

class Peg
{
public:
    // A Peg represented by a thin, black, vertical rectangle
    
    // Function: Peg default constructor
    // Purpose: Sets the Peg  x, y, width, and height member variables to 0
    // Input: None
    // Returns: Nothing
	Peg();

    // Function: Peg parameterized constructor
    // Purpose: Sets the relevant member variables for the class
    // Input:
    //      1. An integer for the bottom center x coordinate
    //      2. An integer for the bottom center y coordinate
    //      3. An integer for the width of the Peg
    //      4. An integer for the height of the Peg
    // Returns: Nothing
	Peg(int xCoord, int yCoord, int width, int height);

    // Function: draw
    // Purpose: Uses the GWindow and the member variables to draw the Peg and all of the Disks that are “on” that Peg
    // Input: GWindow (by reference)
    // Returns: Nothing
	void draw(GWindow& gw);
    
    // Function: addDisk
    // Purpose: Disk Object is added at the end of the Vector (for performance)
    // Input: Disk Object
    // Returns: Nothing
	void addDisk(Disk disk);
    
    // Function: removeDisk
    // Purpose: remove the last Disk on that Peg
    // Input: None
    // Returns: The removed Disk Object
	Disk removeDisk();
    
private:
    // x coordinate for the bottom center of the Peg
	int mX;
    // y coordinate for the bottom center of the Peg
	int mY;
    // width of the Peg, in pixels
	int mW;
    // height of the Peg, in pixels
	int mH;
    
//	int xCenter;
//	int curTop;

    // color of the Peg
	std::string color;
    // Vector of Disks member variable which will contain all the Disk objects that are “on" that Peg
	std::vector<Disk> diskVect;
};
