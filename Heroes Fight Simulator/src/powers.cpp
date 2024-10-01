/* powers.cpp
* This program creates the child classes for the power base class. It gets the results of different powers fighting.
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/

#include "powers.h"
#include <iostream>

// constructor of the appropriate child classes sets mPowerID
POWER_ID Power::getID()
{
    POWER_ID power = mPowerID; // return enum value
    
	return  power;
}

// Power functions for each child power

// Strength

// constructor sets member variables
StrengthPower::StrengthPower(){
    mDescription = "Superhuman Strength";
    mPowerID = POWER_STRENGTH;
}

// use() function returns a string of action when power is used
std::string StrengthPower::use() {
    std::string action = "SMASH!!";
    
    return action;
}

// return result of fight with another power
// 1 is win, -1 is lose, 0 is tie
int StrengthPower::fight(Power* other){
    // compare powers
    POWER_ID otherID = other -> getID();

    if(otherID == POWER_FLIGHT){
        std::cout << "FLIGHT WINS - They soar out of reach of the attack and into the wild blue yonder!" << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_GADGETS){
        std::cout << "STRENGTH WINS - Sorry, Siri can't save you this time. Looks like the gadget is in pieces." << std::endl;
        return 1;
    }
    
    else if(otherID == POWER_INTEL){
        std::cout << "INTELLIGENCE WINS - Guess brain does beat brawn." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_LASER){
        std::cout << "STRENGTH WINS - No need for high-tech laser beams. These muscles made those lasers into mere sparkles." << std::endl;
        return 1;
    }
    
    else if(otherID == POWER_NATIONAL){
        std::cout << "STRENGTH WINS - Your confidence is too weak." << std::endl;
        return 1;
    }
    
    else {
        std::cout << "TIE - You both take a smack." << std::endl;
        return 0;
    }
}

// Flight

// constructor sets member variables
FlightPower::FlightPower(){
    mDescription = "Ability to fly";
    mPowerID = POWER_FLIGHT;
}

// use() function returns a string of action when power is used
std::string FlightPower::use() {
    std::string action = "flies away, maybe far from this place. Whoosh!";
    
    return action;
}

// return result of fight with another power
// 1 is win, -1 is lose, 0 is tie
int FlightPower::fight(Power* other){
    POWER_ID otherID = other -> getID();

    if(otherID == POWER_STRENGTH){
        std::cout << "FLIGHT WINS - They soar out of reach of the attack and into the wild blue yonder!"  << std::endl;
        return 1;
    }
    
    else if(otherID == POWER_GADGETS){
        std::cout << "GADGET WINS - You can't always get away. My tech is too fast for you." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_INTEL){
        std::cout << "FLIGHT WINS - Your smarts won't take you too far." << std::endl;
        return 1;
    }
    
    else if(otherID == POWER_LASER){
        std::cout << "LASER WINS - Catch up with the technology already." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_NATIONAL){
        std::cout << "FLIGHT WINS - Your pride is too slow." << std::endl;
        return 1;
    }
    
    else {
        std::cout << "TIE - You both fly far away and lose each other." << std::endl;
        return 0;
    }
}


// Laser

// constructor sets member variables
LaserPower::LaserPower(){
    mDescription = "Can shoot lasers";
    mPowerID = POWER_LASER;
}

// use() function returns a string of action when power is used
std::string LaserPower::use() {
    std::string action = "shoots lasers from their eyes. PEWPEWPEW!";
    
    return action;
}

// return result of fight with another power
// 1 is win, -1 is lose, 0 is tie
int LaserPower::fight(Power* other){
    POWER_ID otherID = other -> getID();

    if(otherID == POWER_FLIGHT){
        std::cout << "LASER WINS - Catch up with the technology already."<< std::endl;
        return 1;
    }
    
    else if(otherID == POWER_GADGETS){
        std::cout << "GADGET WINS - Your eyes are nothing compared to my tech." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_INTEL){
        std::cout << "LASER WINS - Your intelligence is in flames." << std::endl;
        return 1;
    }
    
    else if(otherID == POWER_STRENGTH){
        std::cout << "STRENGTH WINS - No need for high-tech laser beams. These muscles made those lasers into mere sparkles."<< std::endl;
        return -1;
    }
    
    else if(otherID == POWER_NATIONAL){
        std::cout << "LASER WINS - Looks like your pride is vaporized." << std::endl;
        return 1;
    }
    
    else {
        std::cout << "TIE - We both got burned." << std::endl;
        return 0;
    }
}
    
// Intel

// constructor sets member variables
IntelPower::IntelPower() {
    mDescription = "Superhuman Intelligence";
    mPowerID = POWER_INTEL;
}

// use() function returns a string of action when power is used
std::string IntelPower::use() {
    std::string action = "ponders deeply.";
    
    return action;
}

// return result of fight with another power
// 1 is win, -1 is lose, 0 is tie
int IntelPower::fight(Power* other){
    POWER_ID otherID = other -> getID();

    if(otherID == POWER_FLIGHT){
        std::cout << "FLIGHT WINS - Your smarts won't take you too far." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_GADGETS){
        std::cout << "INTELLIGENCE WINS - The glitch in the gadget is discovered!" << std::endl;
        return 1;
    }
    
    else if(otherID == POWER_STRENGTH){
        std::cout << "INTELLIGENCE WINS - Guess brain does beat brawn."<< std::endl;
        return 1;
    }
    
    else if(otherID == POWER_LASER){
        std::cout << "LASER WINS - Your intelligence is in flames." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_NATIONAL){
        std::cout << "INTELLIGENCE WINS - Your nationalism got outsmarted." << std::endl;
        return 1;
    }
    
    else {
        std::cout << "TIE - We both got roasted." << std::endl;
        return 0;
    }
}
    
// Gadget

// constructor sets member variables
GadgetPower::GadgetPower(){
    mDescription = "Uses some crazy gadgets";
    mPowerID = POWER_GADGETS;
}

// use() function returns a string of action when power is used
std::string GadgetPower::use() {
    std::string action = "uses what's (hopefully) the right tool for the job.";
    
    return action;
}

// return result of fight with another power
// 1 is win, -1 is lose, 0 is tie
int GadgetPower::fight(Power* other){
    POWER_ID otherID = other -> getID();

    if(otherID == POWER_FLIGHT){
        std::cout << "GADGET WINS - You can't always get away. My tech is too fast for you."<< std::endl;
        return 1;
    }
    
    else if(otherID == POWER_STRENGTH){
        std::cout << "STRENGTH WINS - Sorry, Siri can't save you this time. Looks like the gadget is in pieces." << std::endl;
        
        return -1;
    }
    
    else if(otherID == POWER_INTEL){
        std::cout << "INTELLIGENCE WINS - The glitch in the gadget is discovered!" << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_LASER){
        std::cout << "GADGET WINS - Your eyes are nothing compared to my tech." << std::endl;
        return 1;
    }
    
    else if(otherID == POWER_NATIONAL){
        std::cout << "GADGET WINS - Flags and anthems are no match for our tech." << std::endl;
        return 1;
    }
    
    else {
        std::cout << "TIE - Technology both crashed on us." << std::endl;
        return 0;
    }
}
    
// National

// constructor sets member variables
NationalPower::NationalPower(){
    mDescription = "A strong belief in their mother country";
    mPowerID = POWER_NATIONAL;
}

// use() function returns a string of action when power is used
std::string NationalPower::use() {
    std::string action = "screams AMERICA F*** YEAH!!";
    
    return action;
}

// return result of fight with another power
// 1 is win, -1 is lose, 0 is tie
int NationalPower::fight(Power* other){
    POWER_ID otherID = other -> getID();

    if(otherID == POWER_FLIGHT){
        std::cout << "FLIGHT WINS - Your pride is too slow." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_GADGETS){
        std::cout << "GADGET WINS - Flags and anthems are no match for our tech." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_INTEL){
        std::cout << "INTELLIGENCE WINS - Your nationalism got outsmarted." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_STRENGTH){
        std::cout << "STRENGTH WINS - Your confidence is too weak." << std::endl;
        return -1;
    }
    
    else if(otherID == POWER_LASER){
        std::cout << "LASER WINS - Looks like your pride is vaporized."  << std::endl;
        return -1;
    }
    
    else {
        std::cout << "TIE - Looks like we disappointed our country." << std::endl;
        return 0;
    }
}

//generate power from inputted string
Power* powerFactory(const std::string& powerName)
{
    Power* newPower = nullptr;
    
    // check to see which power and match them
    if(powerName == "strength") {
        // pointer to a newly created power (on the heap)
        newPower = new StrengthPower();
    }
    
    else if(powerName == "flight") {
        newPower = new FlightPower();
    }
    
    else if(powerName == "laser") {
        newPower = new LaserPower();
    }
       
    else if(powerName == "intel") {
        newPower = new IntelPower();
    }
       
    else if(powerName == "gadget") {
        newPower = new GadgetPower();
    }
    
    else if(powerName == "national") {
        newPower = new NationalPower();
    }
    
	return newPower;
}

// send power description to inputted stream
std::ostream& operator<<(std::ostream& out, const Power& p)
{
	out << p.mDescription;
	return out;
}
