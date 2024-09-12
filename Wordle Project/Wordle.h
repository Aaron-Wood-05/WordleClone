#ifndef WORDLE_H
#define WORDLE_H

#include <iostream> 
#include <cstdlib>
#include <cctype> // to use toUpper()
#include <ctime> // to ensure the process of picking a word is random
#include <iomanip> // to manipulate the output to the user
#include <fstream> // since we need to pull from the text file

using namespace std;

string randomWord();  //randomly selects a word from file, called at the start of driver
void compareWord(string, string);  //compares the key word with the users
//void printResult();
bool isUpperCheck(string);



#endif