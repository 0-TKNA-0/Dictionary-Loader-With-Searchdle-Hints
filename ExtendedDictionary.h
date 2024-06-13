/*
Student Name : Brody Jeanes
Student ID : 10568619
*/

/* 
In this section, the ExtendedDictionary header file is created. This header file contains a default constructor which initialises the values to the data members
of an object. This header file initialises the four main functions in the ExtendedDictionary.cpp file. The header file also contains two private variables and
two private functions which are used to assist the four main functions in the ExtendedDiction.cpp file.  
This section of code was last updated on 02/04/2023, by Brody Jeanes - 10568619
*/

#pragma once

#ifndef EXTENDEDDICTIONARY_H
#define EXTENDEDDICTIONARY_H

#include "Dictionary.h"

class ExtendedDictionary : public Dictionary
{
public:
    ExtendedDictionary(); /* Default Constructor */

    /* These lines initialise the functions from the ExtendedDictionary.cpp file so they can be utilised*/
    void task5Palindromes(std::vector<Word>& Dictionary);
    void task6RhymingWords(std::string RhymeInput, std::vector<Word>& Dictionary, std::string LastLetters);
    void task7GuessFourthWord(std::vector<Word>& Dictionary);
    void task8CheatSearchdle(std::vector<Word>& Dictionary);

    /* These lines initialise the functions to be used within the ExtendedDictionary.cpp file*/
private:
    int loadHighScore();
    void saveHighScore(int score);
    std::string hideDefinitionWord(const std::string& wordDefinition);
    int currentHighScore;
};
#endif