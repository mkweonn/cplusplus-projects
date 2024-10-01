// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

#include "peg.h"

Peg::Peg() {
    mX = 0;
    mY = 0;
    mW = 0;
    mH = 0;
    color = "BLACK";
    diskVect.clear();
}

Peg::Peg(int xCoord, int yCoord, int width, int height) {
    mX = xCoord;
    mY = yCoord;
    mW = width;
    mH = height;
    color = "BLACK";
    diskVect.clear();
//    xCenter = ;
//    curTop = ;
}

void Peg::draw(GWindow& gw) {
    // draw peg
    // give Peg color
    gw.setColor(color);
    // draw Peg using bottom center as coordinates
    gw.fillRect(mX - mW/2, mY - mH, mW, mH);
    gw.drawRect(mX - mW/2, mY - mH, mW, mH);
    
    // call draw function for all of the Disk "on" the Peg
    for(int i=0; i < diskVect.size(); i++) {
        diskVect[i].draw(gw);
    }
}

void Peg::addDisk(Disk disk) {
    disk.setX(mX);
    int diskNum = (int)diskVect.size();
    
    // set y coordinate accomodating the heights of the disks already on the Peg
    // going up the window is decreasing Y (so subtract from mY)
    disk.setY(mY - (diskNum * disk.getHeight())); // multipling the height of disk with the amount of disks already on the Peg (or vector)
//    disk.setY(mY - disk.getHeight()* diskVect.size());
   
    // add disk to vector
    diskVect.push_back(disk);
}

Disk Peg::removeDisk() {
    // get last Disk in vector
    Disk lastDisk = diskVect[diskVect.size()-1];
    
    // remove last element
    diskVect.pop_back();
    return lastDisk;
}
