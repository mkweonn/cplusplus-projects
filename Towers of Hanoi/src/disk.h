// �2023 Nathan Greenfield
// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#pragma once

#include <iostream>
#include <string>
#include "gwindow.h"

class Disk
{
public:
    // A Disk is represented by a colored rectangle
    
    // Function: Disk default constructor
    // Purpose: Sets the Disk member variables to 0
    // Input: None
    // Returns: Nothing
	Disk();
    
    // Function: Disk parameterized constructor
    // Purpose: Sets the relevant member variables for the class
    // Input:
    //      1. An integer for the bottom center x coordinate
    //      2. An integer for the bottom center y coordinate
    //      3. An integer for the width of the Disk
    //      4. An integer for the height of the Disk
    // Returns: Nothing
	Disk(int xCoord, int yCoord, int width, int height);

    // Function: draw
    // Purpose: Uses the GWindow and the member variables to create/draw the colored rectangles that represent the Disks
    // Input: GWindow (by reference)
    // Returns: Nothing
	void draw(GWindow& gw);
    
    // Function: setX
    // Purpose: Sets the appropriate member variable
    // Input: x coordinate of bottom center of Disk
    // Returns: Nothing
	void setX(int xCoord);
    
    // Function: setY
    // Purpose: Sets the appropriate member variable
    // Input: y coordinate of bottom center of Disk
    // Returns: Nothing
	void setY(int yCoord);

    // Function: getHeight
    // Purpose: Gets the appropriate member variable
    // Input: None
    // Returns: An integer for the height of a Disk
	int getHeight();

private:
    // x coordinate for the bottom center of the Disk
	int mX;
    // y coordinate for the bottom center of the Disk
	int mY;
    // width of the Disk, in pixels
	int mW;
    // height of the Disk, in pixels
	int mH;
    // color of the Disk
	std::string mColor;
};
