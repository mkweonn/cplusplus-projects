/* fileio.cpp
* This program uses read and write files.
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/
#include "fileio.h"
#include <fstream>
#include <iostream>
//#include <string>
// using namespace std;

// Read in a file and modify the inputted vector of strings
// Use return value (true/false) to indicate success
bool getData(const std::string& inputLocation, std::vector<std::string>& data)
{
    // Open the input file
    std::ifstream inputFile(inputLocation); // inputLocation is string with file name
    
    // Check if file opened
    if (!inputFile.is_open()) {
        std::cout << "File \"" << inputLocation << "\" didn't open successfully." <<std::endl;
        return false;
    }
    
    // Load contents -- vector "data" contains file contents
    while (!inputFile.eof()) { // Continue looping as long as it is not the end of file
        std::string line;
        std::getline(inputFile, line); // use std::get line to grab whole line
        data.push_back(line); // add each line from file as one item in vector
    }
    
    // Close the input file
    inputFile.close();

	return true;
}

// Output the vector of strings to the inputted file name
// Use return value (true/false) to indicate success
bool putData(const std::string& outputLocation, const std::vector<std::string>& data)
{
    // Open the output file
    std::ofstream outputFile(outputLocation); // outputLocation is string with file name to write to
    
    // Check if file opened
    if (!outputFile.is_open()) {
        std::cout << "File \"" << outputLocation << "\" didn't open successfully." <<std::endl;
        return false;
    }
    
    // Output item in the vector as line of text
//    std::vector data;
    for (int i=0; i < data.size(); i++) {
        outputFile << data[i] << std::endl;
    }

    // Close the output file
    outputFile.close();
    
	return true;
}
