/* stock.cpp
* This file holds the stock class with getters/setters and a output stream.
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/

#include "stock.h"

// parameterized constructor
Stock::Stock(std::string inName, std::string inSymbol, const Money& inPurPrice, double inNumShares) {
    mPurchasePrice = inPurPrice;
    mCurrentPrice = inPurPrice; // is this same as purchase price in beginning *************
    mName = inName;
    mSymbol = inSymbol;
    mNumShares = inNumShares;
}

// Stock default constructor
Stock::Stock() {
    // set object's member variables
    mPurchasePrice = 0; // Money object 
    mCurrentPrice = 0; // Money object
    mName = "";
    mSymbol = "";
    mNumShares = 0.0;
}

//  Getters

Money Stock::getCurrPrice() const {
    return mCurrentPrice;
}

Money Stock::getPurPrice() const {
    return mPurchasePrice;
    
}
std::string Stock::getSymbol() const {
    return mSymbol;
}
std::string Stock::getName() const {
    return mName;
}
double Stock::getNumShares() const {
    return mNumShares;
}

Money Stock::getChange() const {
    Money change = mCurrentPrice - mPurchasePrice; // reflect change in stock's value
    
    return change;
}

// Setter
void Stock::setCurrentPrice(const Money& inCurrPrice) {
    mCurrentPrice = inCurrPrice;
}

// display the stock to the output stream
std::ostream& operator<<(std::ostream& out, const Stock& stock) {
    out << stock.mSymbol << " : " << stock.mNumShares << " @ " << stock.mCurrentPrice;
    return out;
}

