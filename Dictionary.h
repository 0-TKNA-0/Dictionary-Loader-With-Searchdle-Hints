/*
Student Name : Brody Jeanes
Student ID : 10568619
*/

/*
In this section, the Dictionary header file is created. This header file contains a default constructor which initialises the values to the data members
of an object. This header file initialises the four main functions in the Dictionary.cpp file. The header file also contains one private vector which is used to
assist the four main functions in the Dictionary.cpp file.
This section of code was last updated on 01/04/2023, by Brody Jeanes - 10568619
*/

#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include "Word.h"

class Dictionary
{
public:
    Dictionary(); /* Default Constructor */

    /* These lines initialise the functions from the Dictionary.cpp file so they can be utilised */
    void task1LoadDict(std::string dict, std::vector<Word>& Dictionary);
    void task2SearchWord(std::string dictSearch, std::vector<Word>& Dictionary);
    void task3DisplayZ(const std::vector<Word>& Dictionary);
    void task4AddWord(std::string wordName, std::string wordType, std::string wordDefinition, std::vector<Word>& Dictionary);

private:
    std::vector<Word> words; /* This line creates a new vector of Word objects called words*/
};
#endif