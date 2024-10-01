// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

#include "disk.h"

Disk::Disk() {
    mX = 0;
    mY = 0;
    mW = 0;
    mH = 0;
    mColor = "BLUE";
}

Disk::Disk(int xCoord, int yCoord, int width, int height) {
    mX = xCoord;
    mY = yCoord;
    mW = width;
    mH = height;
    mColor = "BLUE";
}

void Disk::draw(GWindow& gw) {
    // give Disk color
    gw.setColor(mColor);
    
    // draw Disk using bottom center as coordinates
    gw.fillRect(mX - mW/2, mY - mH, mW, mH);
    gw.drawRect(mX - mW/2, mY - mH, mW, mH);
}

void Disk::setX(int xCoord) {
    mX = xCoord;
}

void Disk::setY(int yCoord) {
    mY = yCoord;
}

int Disk::getHeight() {
    return mH;
}
