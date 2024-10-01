/* fight.cpp
* This program allows superheroes to fight against one another and has the function that is run by main.
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/

#include "fight.h"
#include <random>
//#include <fstream>
//#include <string>
//#include <vector>

#include <ostream>

bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector)
{
    // Open the input file
    std::ifstream inputFile(fileName); // fileName is string with file name
    
    if(!heroVector.empty()) { // If the vector contains data, delete it before reading in data.
        heroVector.clear();
    }
    
    // Check if file opened
    if (!inputFile.is_open()) {
        std::cout << "Unable to load file \"" << fileName << "\"!" <<std::endl;
        return false;
    }
    
    // Load contents -- heroVector contains heros
    while (!inputFile.eof()) { // Continue looping as long as it is not the end of file
        std::string line; // each line is hero descriptions
        std::getline(inputFile, line); // use std::get line to read and grab whole line
        Hero* hero = new Hero(line); // call hero constructor to create hero pointers for each line of input (new objects)
        heroVector.push_back(hero); // add each hero pointers as one item in vector
    }
    
    // Close the input file
    inputFile.close();
    
    // return true if open sucessfully
	return true;
}

// picking heroes to fight
Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in)
{
    int choice = -1;

    out << prompt; // output stream to use to prompt user choice of hero
    in >> choice;
    
    // continue asking if it is not a valid index
    // 0 is first valid index for choice
    while (choice < 0 || choice >= heroVector.size()) {
        out << prompt;
        in >> choice; // input stream user choice
    }

    Hero* heroPicked = heroVector[choice]; // pointer to the hero at the appropriate index
    
	return heroPicked; // return chosen hero
}


// Displays fight results to stream and COUT
void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output)
{
    // reset the heroes’ health (in case they’ve fought before)
    heroA -> resetHealth();
    heroB -> resetHealth();
    
    while((heroA -> getHealth() != 0) && (heroB -> getHealth() != 0)) { // fight while they both have health
        Power* powerA = heroA -> useRandomPower(); // get a random power
        Power* powerB = heroB -> useRandomPower();
        
        // current health
        output << heroA -> getName() << " has " << heroA -> getHealth() << " health" << std::endl; //
        output << heroB -> getName() << " has " << heroB -> getHealth() << " health" << std::endl; //
        
//        // action of power they use
//        output << heroA -> getName() << " " << powerA -> use() << std::endl;
//        output << heroB -> getName() << " " << powerB -> use() << std::endl;
        
        // two powers fight and get result of round
        int results = powerA -> fight(powerB);
        
        
        if (results == 1) { // hero A wins so...
            heroB -> takeDamage(); // hero B loses 1 health
            
        }
        else if (results == -1) { // hero A loses so...
            heroA -> takeDamage(); // hero B loses 1 health
        }
        
        else { // results == 0
            // in the event of a tie, both lose health
            heroA -> takeDamage();
            heroB -> takeDamage();
        }
        output << "---------------------------------------" << std::endl;
    }
    
    // final health/resulr
    if(heroB -> getHealth() == 0) {
        output << heroA -> getName() << " WINS!!!" << std::endl; // indicate winner
    }
    else if(heroA -> getHealth() == 0) {
        output << heroB -> getName() << " WINS!!!" << std::endl; // indicate winner
    }
    else if (heroA -> getHealth() == 0 && heroB -> getHealth() == 0){
        output << heroA -> getName() << " and " << heroB -> getName() << "LOSE!!!"; // indicate winner
    }
}

int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed)
{
    // open the 2 files to generate input/output streams to pass in other fight function
    std::ifstream in(inputFileName);
    std::ofstream out(outputFileName);
    
    if(!in.is_open()) {
        std::cout << "Error. Unable to load file!"<< std::endl;
        return false;
    }
    
    int fightResult = fight(in, out, seed); // call other fight function
    
    return fightResult;
}

// main calls this - interacts with user
int fight(std::istream& input, std::ostream& output, unsigned seed)
{
    std::srand(seed); // unsigned int to use as the random number generator seed
    std::vector<Hero*> heroVector;
    
    int userOption;
    userOption = 0; // set to a initial value to go through loop once
    output << "Seed: " << seed << std::endl;
    
    
    while (userOption != 4){ // while user doesn't want to quit, continue menu options
        output << '\n';
        output << "Choose an option: " << std::endl;
        output << "1. Load Heroes" << std::endl;
        output << "2. Print Hero Roster" << std::endl;
        output << "3. Hero Fight! " << std::endl;
        output << "4. Quit " << std::endl;
        output << "> ";
        input >> userOption;
        output << '\n';
        
        if(userOption == 1){ // get file name from user to load heroes
            output << "Enter the file to load: ";
            std::string fileName;
            input >> fileName;
            // add file function
            loadHeroes(fileName, heroVector); // add the information from file to vector
        }
        
        else if(userOption == 2){ // use output stream to display heroes and their powers
            size_t heroNum = heroVector.size();
            output << "The following " << heroNum << " heroes are loaded..." << std::endl;
            output << "---------------------------------------" << std::endl;
            
            for(int i=0; i < heroNum; i++) {
                Hero* heroLoad = heroVector[i]; // outputs the operator from hero which includes each hero and their powers
                output << *heroLoad; // dereference
                output << "---------------------------------------" << std::endl;
            }
        }
        
        // users select which heroes to fight and then they play rounds
        else if(userOption == 3){
            // list the heroes and respective indices
            for (int i=0; i < heroVector.size(); i++) {
                    output << i << ": " << heroVector[i]->getName() << std::endl; // output heroes available
                }
            // prompt the user for 2 heroes to fight
            std::string firstPrompt = "Select your first hero: ";
            std::string secondPrompt = "Select your second hero: ";
        
            // get user selection
            Hero* firstHero = selectHero(heroVector, firstPrompt, output, input);
            Hero* secondHero = selectHero(heroVector, secondPrompt, output, input);
            output << "---------------------------------------" << std::endl;
            
            // heroes fight and results outputted
            heroCombat(firstHero, secondHero, output);
        }
        
        else if(userOption == 4){
            output << "Goodbye" << std::endl;
        }
        
        else {
            output << "Error. Enter a valid number" << std::endl;
        }
    }
    return 0; // 0 for success
}
