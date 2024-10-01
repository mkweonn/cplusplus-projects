// �2023 Nathan Greenfield
// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#pragma once

#include "disk.h"
#include "peg.h"
#include "gwindow.h"

#include <vector>
#include <iostream>

// Function: promptForDisks
// Purpose: Prompts the user for the number of Disks to start with (2-10)
// Input: none
// Returns: An integer representing the number of Disks the user requested
int promptForDisks();

// Function: promptForPegs
// Purpose:  Prompts the user for a starting Peg and ending Peg numbers (1-3). Stores the starting Peg value in the 1st input and the ending Peg value in the 2nd input
// Input: two integers
// Returns: Nothing
void promptForPegs(int& input1, int& input2);

// Function: promptForPause
// Purpose: Prompts the user for the number milliseconds to pause between images in the animation (1-1000000)
// Input: None
// Returns: The number entered by the user
int promptForPause();

// Function: promptForWindowSize
// Purpose: Prompts the user for a width and height for the graphics window
// Input: two integers representing window size
// Returns: Nothing
void promptForWindowSize(int& windowW, int& windowH);

// Function: draw
// Purpose:  draws all the Pegs (and therefore all the Disks on the Pegs)
// Input: A GWindow (by reference), the vector of Pegs (by reference), and an integer
// Returns: Nothing
void draw(GWindow& gw, std::vector<Peg>& pegVector, int pauseTime);

// Function: towerSolve
// Purpose: Removes the topmost Disk from the start Peg, adds it to the destination Peg, and then calls the draw function
// Input:
//      1. GWindow object (by reference)
//      2. Peg collection (by reference)
//      3. starting Peg (represented with an int)
//      4. destination Peg (represented with an int)
//      5. pause length (represented by an int)
// Returns: Nothing
void moveDisk(GWindow& gw, std::vector<Peg>& pegVector, int startPeg, int destinPeg, int pauseLength);

// Function: towerSolve
// Purpose: Uses recursion and the moveDisk function to recursively move all the Disks from the source Peg to the target Peg
// Input:
//      1. GWindow object (by reference)
//      2. Peg collection (by reference)
//      3. starting Peg (represented with an int)
//      4. destination Peg (represented with an int)
//      5. number of disks to move
//      6. pause duration
// Returns: Nothing
void towerSolve(GWindow& gw, std::vector<Peg>& pegVector, int startPeg, int destinPeg, int diskNum, int pauseLength);

// Function: towerRun
// Purpose: Calls all needed function to implement animation
// Input: None
// Returns:
int towerRun();

const int MINSCREENWIDTH = 800;
const int MINSCREENHEIGHT = 600;
const int MAXSCREENWIDTH = 4096;
const int MAXSCREENHEIGHT = 2160;
const int MINDISKS = 2;
const int MAXDISKS = 10;
const int NUMPEGS = 3;
const int MAXPAUSELEN = 1000000;
