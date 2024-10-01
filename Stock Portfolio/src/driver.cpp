/* driver.cpp
* This program .
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/

#include "driver.h"
#include "strlib.h"
#include <iostream>
#include <fstream>

bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    std::vector<std::string> line = strSplit(inString, '|'); // parse string with stock information
    
    // String needs to be in the form: "symbol|name|purchase price|# shares"
    if(line.size() != 4 ) {
        return false;
    }
    
    std::string symbol = line[0];
    std::string name = line[1];
//    Money purchase = Money(std::stod(line[2]));
    double shares = std::stod(line[3]);
    
    Stock newStock = Stock(name, symbol, Money(std::stod(line[2])), shares);
    inPort.addStock(newStock); // add new stock in portfolio
    
//    inPort[symbol] = newStock; // add to portfolio
//    inPort.emplace(symbol, newStock);

     // check if portfolio has the symbol
//    if(!inPort.containsStock(symbol)) {
//        return false; // true if stock added successfully
//    }
    return true;
}

bool updateStock(StockPortfolio& inPort, const std::string& inString) {
    std::vector<std::string> line = strSplit(inString, '|'); // parse string with stock information to update
    
    // String needs to be in the form: "symbol|current price"
    if(line.size() != 2 ) {
        return false;
    }
//    Money purchase = Money(std::stoi(line[1]));

    if(!inPort.containsStock(line[0])) { // making sure non-existing empty stock
        std::cout << "Error. Does not contain Stock." << std::endl;
        return false; // true if stock updated successfully
    }
    inPort[line[0]].setCurrentPrice(std::stod(line[1])); // update/set current price
    
    // check if current price is set to new value
//    if(inPort[symbol].getCurrPrice() == purchase){
//        return true; // true if stock updated successfully
//    }

    return true;
}

bool processFile(StockPortfolio& inPort, const std::string& inString) {
    // Open the input file
    std::ifstream inputFile(inString); // fileName is string with file name
    
    // Check if file opened
    if (!inputFile.is_open()) {
        std::cout << "Unable to load file \"" << inString << "\"!" <<std::endl;
        return false;
    }
    
    bool returnVal = true;
    // Load contents
    while (!inputFile.eof()) { // Continue looping as long as it is not the end of file
        std::string line;
        std::getline(inputFile, line); // use std::get line to read and grab whole line
       
        if(line.empty()) { // ignore empty lines
            continue;
        }
        
        else if(line[0] == '+') { // check if has plus sign which indicates updating
//            std::string symbolPlus = line;
            std::string symbol = line.substr(1);
            returnVal = updateStock(inPort, symbol); // update stock and return true or false depending on false conditions
        
        }
        else {
            returnVal  = buyStock(inPort, line); // add stock and return true or false depending on false conditions
        }
    }
    
    // Close the input file
    inputFile.close();
    
    // return true if open sucessfully
    return returnVal;
}

