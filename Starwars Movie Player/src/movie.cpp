// ITP 365 Spring 2023
// HW06 – Vector and Poker Hands
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "movie.h"

// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: None
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
    // holds the current frame the film is on
        
    // Stores the name of the input file that stores the movie file
    mFilmName = filmName;
    
    // film is made a series of strings containing frames - acts as "tape"
    // clear list to ensure that the tape is empty
    mFilm.clear();

    // Stores the current position of the reader
    // track where you are in the tape
    
    // call loader
    loadTape();
    
    rewind();
}

// Function: Destructor
// Purpose: Empties the list
// Input: None
// Returns: Nothing
MoviePlayer::~MoviePlayer()
{
    // ensure that the tape is empty here
    mFilm.clear();
}

// Function: goFwrd
// Purpose: Moves the current "frame" forward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goFwrd()
{
    // checking that you are not moving past end of tape
    if (currFrameNum < mFilm.size()){
        // increment the currFrameNum counter
        currFrameNum++;
        // move the tape forward 1 frame
        pos++;
    }
}

// Function: goBack
// Purpose: Moves the current "frame" backward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goBack()
{
    // checking that you are not moving past beginning of tape
    if (pos != mFilm.begin()){
        // decrement the currFrameNum counter
        currFrameNum--;
        // move the tape backward 1 frame
        pos--;
    }
}

// Function: rewind
// Purpose: Moves the current "frame" to the movie's beginning again
// Input: None
// Returns: Nothing
void MoviePlayer::rewind()
{
    // position to beginning to start tape over again
    pos = mFilm.begin();
    // keep track of the currFrameNum counter
    currFrameNum = 1;
}

// Function: getCurrFrame
// Purpose: Gets the string that contains the current "frame" as stored
// in the list "mFilm"
// Input: None
// Returns: String with the current "frame"
std::string MoviePlayer::getCurrFrame()
{
//	return *(new std::string);
    // return the current currFrameNum counter
    return *pos;
}

// Function: delCurrFrame
// Purpose: Deletes the current frame, moves forward to the next one
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
	// TODO: Fill in
    // delete the current frame and move the tape forward 1 frame.
    // If the user attempts to delete the last frame of the movie, do nothing
    if (pos != mFilm.end()) {
        pos = mFilm.erase(pos);
    }
}

// Function: copyCurrFrame
// Purpose: Copies current frame and places the copy BEFORE the current frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::copyCurrFrame()
{
    // copy the current frame and move the tape to the newly added frame

    // get copy current frame - dereference to get the value
    std::string current = *pos;
    
    // insert copy before current
    pos = mFilm.insert(pos, current);
    
    // keeps track of how many frames have been viewed
    //currFrameNum++; // *******************
}

// Function: getCurrFrameNum
// Purpose: Gets the "index" that corresponds to the current frame
// Input: None
// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
    // returns a string with the contents of the current frame
	return currFrameNum;
}

// Function: getNumFrames
// Purpose: Gets the total number of frames in the movie
// Input: None
// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
    // number of frames/items in movie
	return mFilm.size();
}

// Function: getFrameSize
// Purpose: Gives the number of lines in a frame
// For how big the "screen" for the film should be
// Input: None
// Returns: The value stored in FRAMESIZE
unsigned int MoviePlayer::getFrameSize() const
{
    // gets the number of lines in a frame
	return FRAMESIZE;
}

// Function: load_tape
// Purpose: Uses mFilmName (set by constructor) to fill
// mFilm with strings that make up the movie to display
// Input: None
// Returns: Nothing
void MoviePlayer::loadTape()
{
    //This function should open the inputted text file. Assume the user only enters one of the “.ani” files. This function parses out the text file, makes up the frames, and fills the ITPDoubleList with the animations.
    
    // Open the input file
    std::ifstream inputFile(mFilmName); // inputLocation is string with file name
    
    // Check if file opened for invalid name // not sure this worked ***************
    if (!inputFile.is_open()) {
        throw std::invalid_argument("File \"" + mFilmName + "\" didn't open successfully.");
    }
    
    // Load contents
    while (!inputFile.eof()) { // Continue looping as long as it is not the end of file
        
        // grab first line of frame which contain num
        std::string separator;
        std::getline(inputFile, separator); // grab number that indicates how many long the frame should be shown
        int frameLength;
        
        // add check for isdigit on separator// at index 0
        
        if(separator.empty()) {
            break;
        }
        
        std::stringstream ss(separator);
        ss >> frameLength;
        
//        // convert string to int
//        int length = std::stoi(separator);
      
        std::string frame =""; // stores a frame
        
        // loop rest of frame file to store frame
        for (int i=0; i < FRAMESIZE; i++){
            std::string line;
            std::getline(inputFile, line); // use std::get line to grab whole line
            
            // check if file is end of file for partial frames
            if (inputFile.eof()) {
                break;
            }
            
            // check for empty frames/empty lines
            if (line.empty()) {
                frame += "\n";
            }
            else
            {
                // check lines that end with backslash "\" and a space
                if (line.back() == '\\') {
                    line += " ";
                    // look at specific position (only at the end)
                }
                
                // add each line that make up frame
                // each frame is 13 lines of text
                frame += line + "\n";
            }
        }
        
        // add frame to amount of time it needs to be displayed
       
        for (int i=0; i < frameLength; i++) {
            // add to the film where each string is one frame to be displayed
            mFilm.push_back(frame);
        }
    }
    
    // Close the input file
    inputFile.close();
}

// Some input files have a few empty frames. These may just be empty lines. Be sure your
// code detects empty lines appropriately in the loadTape function.
// some files end with blank line


