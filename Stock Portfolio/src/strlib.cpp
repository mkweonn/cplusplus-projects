/* strlib.cpp
* This file splits a string given a delimiter to split on and returns a vector with each split component.
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/

#include "strlib.h"

std::vector<std::string> strSplit(const std::string& str, char splitChar) {
    std::vector<std::string> items; // vector to hold the components (split strings)
    std::string currentWord; // specific item to add to vector

    size_t delim = str.find(splitChar);  // get index of first occurence of delimiter
    size_t index = 0; // position in parsing
    
    while(delim != std::string::npos){ // while delimiter is found in string
        currentWord = str.substr(index, delim - index); // get item without delimiter
        items.push_back(currentWord); // add individual component into vector
        index = delim + 1; // index of next char following delimiter
        delim = str.find(splitChar, index); // get position of next occurence of delimiter starting at index left off
    }
    currentWord = str.substr(index, str.size() - index); // get last item
    items.push_back(currentWord); // add last item to vector
    
    return items;
}

