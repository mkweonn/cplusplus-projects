// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

#include "towers.h"

int promptForDisks() {
    int diskNum;
    // get number of disks to start wtih
    std::cout << "Enter the number of Disks to start with (2-10): ";
    std::cin >> diskNum;
    
    // loop prompt to reject anything not in range
    while (diskNum < MINDISKS || diskNum > MAXDISKS) {
        std::cout << "Enter a valid number of Disks to start with (2-10): ";
        std::cin >> diskNum;
    }
    return diskNum;
}

void promptForPegs(int& startPeg, int& endPeg) {
    // get starting peg
    std::cout << "Enter the Peg to start with (1-3): ";
    std::cin >> startPeg;
    
    // loop reject anything not in range
    while (startPeg < 1 || startPeg > 3) {
        std::cout << "Enter a valid Peg to start with (1-3): ";
        std::cin >> startPeg;
    }
    
    // get ending peg
    std::cout << "Enter the Peg to end with (1-3). Make sure it is not the same as the starting Peg: ";
    std::cin >> endPeg;
    
    // loop reject anything not in range
    while (endPeg < 1 || endPeg > 3 || endPeg == startPeg) {
        std::cout << "Enter a valid Peg to end with (1-3). Make sure it is not the same as the starting Peg: ";
        std::cin >> endPeg;
    }
    startPeg--; // decrement for index in vectors used later
    endPeg--;
}

int promptForPause() {
    int pauseNum;
    // get pause time
    std::cout << "Enter the number of milliseconds to pause between images in the animation (1-1000000): ";
    std::cin >> pauseNum;
    
    // loop prompt to reject anything not in range
    while (pauseNum < 1 || pauseNum > MAXPAUSELEN) {
        std::cout << "Enter a valid number of milliseconds to pause between images in the animation (1-1000000): ";
        std::cin >> pauseNum;
    }
    return pauseNum;
}

void promptForWindowSize(int& windowW, int& windowH) {
    // get window width
    std::cout << "Enter a size for the window width (800-4096): ";
    std::cin >> windowW;
    
    // loop reject anything not in range
    while (windowW < MINSCREENWIDTH || windowW > MAXSCREENWIDTH) {
        std::cout << "Enter a valid size for the window width (800-4096): ";
        std::cin >> windowW;
    }
    
    // get window height
    std::cout << "Enter a size for the window height (600-2160): ";
    std::cin >> windowH;
    
    // loop reject anything not in range
    while (windowH < MINSCREENHEIGHT || windowH > MAXSCREENHEIGHT) {
        std::cout << "Enter a valid size for the window height (600-2160): ";
        std::cin >> windowH;
    }
}

void draw(GWindow& gw, std::vector<Peg>& pegVector, int pauseTime) {
    gw.clear(); // clear the graphics currently in the window
    
    // call draw function for each Peg (with Disks)
    for(int i=0; i < pegVector.size(); i++) {
        pegVector[i].draw(gw);
    }
    
    // pause function (with the last input) at the end of draw
    pause(pauseTime);
}

void moveDisk(GWindow& gw, std::vector<Peg>& pegVector, int startPeg, int destinPeg, int pauseLength) {
    // remove topmost Disk from start Peg
    Disk moveDisk = pegVector[startPeg].removeDisk();
    
    // adds it to the destination Peg
    pegVector[destinPeg].addDisk(moveDisk);
    
    // calls the draw function
    draw(gw, pegVector, pauseLength);
}

void towerSolve(GWindow& gw, std::vector<Peg>& pegVector, int startPeg, int destinPeg, int diskNum, int pauseLength) {
    // Peg selection indices "0", "1", "2" add up to 3
    int tempPeg = 3 - (startPeg + destinPeg); // subtracting the two pegs to find the number of temp peg
    
    // recursive solution
    // stop drawing/moving when number of disks on start is 0
    if(diskNum == 0) { // base case
        return;
    }
    else {
        // Transfer all but last disk to tempPeg
        towerSolve(gw, pegVector, startPeg, tempPeg, diskNum - 1, pauseLength);
        // move bottomost disk to destination
        moveDisk(gw, pegVector, startPeg, destinPeg, pauseLength);
        // Transfer the rest of pegs on tempPeg to destination
        towerSolve(gw, pegVector, tempPeg,destinPeg, diskNum - 1, pauseLength);
    }
}

int towerRun() { // runs animation
    // get window size
    int windWidth;
    int windHeight;
    promptForWindowSize(windWidth, windHeight);
    
    // get number of Disks
    int diskNum = promptForDisks();
    
    // get start and end Pegs
    int start;
    int end;
    promptForPegs(start, end);
    
    int pauseTime = promptForPause();
    
    // create window
    GWindow gw(windWidth, windHeight);
    
    // create the GWindow with the 3 Peg objects accomodating for different window sizes
    Peg peg1 = Peg(windWidth/4, windHeight-25, windWidth/70, windHeight-50);
    Peg peg2 = Peg((windWidth/4)*2, windHeight-25, windWidth/70, windHeight-50);
    Peg peg3 = Peg((windWidth/4)*3, windHeight-25, windWidth/70, windHeight-50);
    
    // store them in a Vector
    std::vector<Peg> pegVector;
    pegVector.push_back(peg1);
    pegVector.push_back(peg2);
    pegVector.push_back(peg3);
    
    // Create the appropriate number of Disk objects and place them on the correct starting Peg.
    // add number of disks selected to vector
    int biggerW = 0;
    for(int i=0; i < diskNum; i++) {
        Disk disk = Disk(windWidth/4, windHeight-25, (windWidth/4) - biggerW, (windHeight/diskNum)-30);
        pegVector[start].addDisk(disk);
        biggerW = biggerW + 30; // making each subsequent one bigger in width to get pyramid shape
    }
    
    // draw
    draw(gw, pegVector, pauseTime);
 
    // recursion/towers of hanoi solution
    towerSolve(gw, pegVector, start, end, diskNum, pauseTime);
    
    pause(pauseTime);
          
    return 0;
}
