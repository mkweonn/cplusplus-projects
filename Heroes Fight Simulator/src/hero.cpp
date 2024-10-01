/* hero.cpp
* This program .
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/

#include "hero.h"
#include "strlib.h"
#include <iostream>
#include <random>
//#include <vector>
//#include <string>

Hero::Hero(const std::string& heroDef)
{
    // heroDef includes string with a hero's name, powers, and starting health separated by '|'
    
    std::vector<std::string> line = strSplit(heroDef, '|'); // parse

    mMaxHealth = std::stoi (line[2]); // max health hero can have determined by input file
    mHealth = std::stoi (line[2]);
    mName = line[0];
    
    std::string& powersList = line[1];
    // powers separated y ','
    std::vector<std::string> comma = strSplit(powersList, ',');
    
    // go from vector of strings to vector of powers
    for(int i=0; i < comma.size(); i++) {
        Power* powersNew = powerFactory(comma[i]); // populate vector of powers
        mPowers.push_back(powersNew);
    }
}

std::string Hero::getName()
{
    std::string name = mName;
	return name;
}

Power* Hero::useRandomPower()
{
    int randomNum = std::rand() % mPowers.size(); // get random number in range with amount of powers
    
    Power* randomPower = mPowers[randomNum]; // pointer to random power
	return randomPower;
}

// Returns the current health of the hero
int Hero::getHealth()
{
    int health = mHealth;
	
	return health;
}

// Causes the hero to take one point of damage
void Hero::takeDamage()
{
    mHealth = getHealth() - 1;
}

// Resets the heroes' health to the max value
void Hero::resetHealth()
{
    mHealth = mMaxHealth;
}

// display name and power
std::ostream& operator<<(std::ostream& out, const Hero& h)
{
	out << h.mName << " has the following powers..." << std::endl;
	
	for (int i = 0; i < h.mPowers.size(); i++)
	{
		std::cout << "\t" << *(h.mPowers[i]) << std::endl;
	}

	return out;
}
