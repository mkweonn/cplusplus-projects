/* cypher.cpp
* This program uses a substitution cipher to encrypting or decrypting files.
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/
#include "cypher.h"
//#include <string>
#include <iostream>

    // Encrypts 2nd input
    void substitutionCypherEncrypt(const std::string& cypher, const std::string& input, std::string& output)
    {
        // alphabet to replace with cipher
        const std::string upper= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const std::string lower= "abcdefghijklmnopqrstuvwxyz";
        
        output = ""; // string to add encrypted text
        
        // loop through entire clear text
        for(int i=0; i < input.length(); i++){
            // check if upper case
            if(input[i] >= 'A' && input[i] <= 'Z'){
                for(int n=0; n<upper.length(); n++) {
                    if(input.at(i) == upper.at(n)){
                        // if input matches alphabet replace it with that same index in cipher
                        output += cypher.at(upper.find(input.at(i))); // add to string filled with encrypted text
                    }
                }
            }
            
            //check lower case with same concept
            else if(input[i] >= 'a' && input[i] <= 'z'){
                for(int n=0; n<lower.length(); n++) {
                    if(input.at(i) == lower.at(n)){
                        // add tolower since cypher is all caps to capture the lower case
                        output += tolower(cypher.at(lower.find(input.at(i))));
                    }
                }
            }
            
            // checking for special characters (spaces, new line, punctuation)
            else {
                output += input.at(i);
            }
        }
    }
    
    // Decrypts 2nd input
    void substitutionCypherDecrypt(const std::string& cypher, const std::string& input, std::string& output)
    {
        // alphabet to replace with cipher with
        // lower case and upper case to watch for capitlizations
        const std::string upper= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const std::string lower= "abcdefghijklmnopqrstuvwxyz";
        
        output = ""; //string fill with new decrypted text
        
        // loop through encrypted text
        for(int i=0; i < input.length(); i++){
            // check if upper case
            if(input[i] >= 'A' && input[i] <= 'Z'){
                for(int n=0; n<cypher.length(); n++) {
                    // if input matches cipher replace it with that same index in alphaber
                    if(input.at(i) == cypher.at(n)){
                        // finding replacement letter of cipher from alphabet to get clear text and adding to ouput
                        output += upper.at(cypher.find(input.at(i)));
                    }
                }
            }
            
            // check lower case with same concepts as upper case
            else if(input[i] >= 'a' && input[i] <= 'z'){
                for(int n=0; n<cypher.length(); n++) {
                    // using toupper to capture capitilization cases since cipher is all caps
                    if(toupper(input.at(i)) == cypher.at(n)){
                        output += lower.at(cypher.find(toupper(input.at(i))));
                    }
                }
            }
            
            // special characters (spaces, new line, punctuation)
            else {
                output += input.at(i);
            }
        }
    }
  
