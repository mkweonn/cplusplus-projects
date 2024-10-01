/* money.cpp
* This file holds the money class, different operators, and outstream/instream.
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/

#include "money.h"

// Money default constructor
Money::Money() {
    mCents = 0;  // sets member variables to 0
}

// Money parameterized constructors
Money::Money(long long inDollars, long long inCents) {
    mCents = (inDollars * 100) + inCents;
}

Money::Money(double inDollars) { // decimal with number of dollars and cents (to right decimal)
    mCents = inDollars * 100;
}

Money::Money(long long inCents) {
    mCents = inCents;
}

Money::Money(int inCents) {
    mCents = inCents;
}

// Arithmetic assignment operators

// add other money into this money
Money& Money::operator+=(const Money& right) {
    mCents += right.mCents; // a += b
    return *this; // output current object, returned by reference
}

// subtracts other money into this money
Money& Money::operator-=(const Money& right) {
    mCents -= right.mCents; //  a -= b
    return *this; // output current object, returned by reference
}

//  multiplies the money by the scalar
Money& Money::operator*=(double right) {
    mCents *= right; // a *= b
    // return mCents;
    return *this; // output current object, returned by reference
}

// divides the money by the scalar
Money& Money::operator/=(double right) {
    mCents /= right; // a /= b
    // return mCents;
    return *this; // output current object, returned by reference
}


// Comparison operators

bool operator<(const Money& left, const Money& right) {
    if(left.mCents < right.mCents) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>(const Money& left, const Money& right) {
    if(left.mCents > right.mCents) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<=(const Money& left, const Money& right) {
    if(left.mCents <= right.mCents) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>=(const Money& left, const Money& right){
    if(left.mCents >= right.mCents) {
        return true;
    }
    else {
        return false;
    }
}
bool operator==(const Money& left, const Money& right) {
    if(left.mCents == right.mCents) {
        return true;
    }
    else {
        return false;
    }
}
bool operator!=(const Money& left, const Money& right){
    if(left.mCents != right.mCents) {
        return true;
    }
    else {
        return false;
    }
}

// Binary arithmetic operators
 
// add two money inputs
Money operator+(const Money& left, const Money& right) {
    Money returnVal = left;
    returnVal.mCents += right.mCents; // c = a + b
    
    return returnVal; // new money object that contains the combined value
}

// subtract two money inputs
Money operator-(const Money& left, const Money& right){
    Money returnVal = left;
    returnVal.mCents -= right.mCents; // c = a - b
    
    return returnVal;
}

//  multiplies the scaler into the money
Money operator*(const Money& left, double right) {
    Money returnVal = left;
    returnVal.mCents *= right; //  c = a * b
    
    return returnVal; // new money object that contains the combined value
}

// divides the scaler into the money
Money operator/(const Money& left, double right) {
    Money returnVal = left;
    returnVal.mCents /= right; // c = a / b
    
    return returnVal; // new money object that contains the combined value
}

// Output stream operator
std::ostream& operator<<(std::ostream& out, const Money& money) {
//    float num = (float)money.mCents / 100;
//    int totalMoney = (int)(num * 100 + 0.5);
//

    // get amount of full dollars
    long long wholeNum = money.mCents / 100;
    // only 2 digits for cents
    long long decimal = money.mCents % 100;

    if(money.mCents < 0){
        // making them postive to avoid double negative signs
        wholeNum = -wholeNum;
        decimal = -decimal;
        // negative after the "$" but before the numbers
        out <<  "$-" << wholeNum << ".";
    }
    else {
        out << "$" << wholeNum << ".";
    }
    
    if (decimal < 10) { // leading zero
        out << 0 << decimal;
    }
    else {
        out << decimal;
    }
    return out;
}

// Input stream operator
std::istream& operator>>(std::istream& in, Money& money){
    double moneyInput;
    in >> moneyInput;
    
    // store everything in the member variable for the Money
    money.mCents = moneyInput * 100;
    
    return in;
}
