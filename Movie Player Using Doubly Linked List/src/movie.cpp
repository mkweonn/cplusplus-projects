// ITP 365 Spring 2023
// HW08 – Doubly Linked List and Movie Player
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

#include "movie.h"
#include <fstream>

// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: filmName
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
    // stores name of the input movie file
    mFilmName = filmName;
    
    // film is a series of strings containing frames - acts as "tape"
    // clear list to ensure that the tape is empty
    mFilm.clear();

    // call loader
    loadTape();
    
    // moves the currFrameNum (tracks where in tape) and current position of reader to the movie's beginning
    rewind();
}

// Function: Destructor
// Purpose: Empties the list
// Input: None
// Returns: Nothing
MoviePlayer::~MoviePlayer()
{
    // ensure that the tape is empty
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
        // increment the currFrameNum counter to keep track how many has been viewed
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
        // decrement the currFrameNum counter to keep track frames viewed
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
        // dereference to get string (frame) in position
        return *pos;
}

// Function: delCurrFrame
// Purpose: Deletes the current frame, moves forward to the next one
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
    // if the user attempts to delete the last frame of the movie, do nothing
    if (pos != mFilm.end()) {
        // delete the current frame and move the tape forward 1 frame
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
    // get copy current frame - dereference to get the value
    std::string current = *pos;
    
    // insert copy before current to move tape to newly added frame
    pos = mFilm.insert(pos, current);
    
    // keeps track of how many frames have been viewed
    //currFrameNum++;
}

// Function: getCurrFrameNum
// Purpose: Gets the "index" that corresponds to the current frame
// Input: None
// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
    // returns current number of frames viewed
    return currFrameNum;
}

// Function: getNumFrames
// Purpose: Gets the total number of frames in the movie
// Input: None
// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
    // number of frames/items in tape
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
    // open the inputted text file
    std::ifstream inputFile(mFilmName);
    
    // check if file opened for invalid name
    if (!inputFile.is_open()) {
        // exception
        throw std::invalid_argument("File \"" + mFilmName + "\" didn't open successfully.");
    }
    
    // load contents by parsing out text file
    while (!inputFile.eof()) { // continue looping as long as it is not the end of file
        
        // first line of frame contains number
        std::string separator;
        std::getline(inputFile, separator); // grab number that indicates how many long the frame should be shown
        
        // add isDigit on separator at index 0
        
        // if no number don't add
        if(separator.empty()) {
            break;
        }
        
        // type cast to make it into an int
        int frameLength;
        std::stringstream ss(separator);
        ss >> frameLength;
        
//        // convert string to int
//        int length = std::stoi(separator);
      
        std::string frame =""; // stores a frame
        
        // loop rest of frame file to store/make frame
        // each frame is 13 lines of text
        for (int i=0; i < FRAMESIZE; i++){
            std::string line;
            std::getline(inputFile, line); // use std::get line to grab whole line
            
            // check if file is end of file for partial frames
            if (inputFile.eof()) {
                break;
            }
            
            // check for empty frames/empty lines to add
            if (line.empty()) {
                frame += "\n";
            }
            
            else
            {
                // check lines that end with backslash "\" and a space
                if (line.back() == '\\') {
                    line += " ";
                }
                
                // add each line that make up frame
                frame += line + "\n";
            }
        }
        
        // fills the ITPDoubleList with the animations/frame to amount of time it needs to be displayed
        for (int i=0; i < frameLength; i++) {
            // fill mFilm where each string is one frame to be displayed
            mFilm.push_back(frame);
        }
    }
    
    // close the input file
    inputFile.close();
}

