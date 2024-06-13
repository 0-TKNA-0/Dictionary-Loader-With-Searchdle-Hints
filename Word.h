/*
Student Name : Brody Jeanes
Student ID : 10568619
*/

/* 
In this section, the Word header file is created. This header file contains the Word structure from the first assignment which has been converted to a Word class.
The word class includes the three main string variables which are required for each word and their definition / type wihtin the dictionary. It also includes three
getters and three setters to initialise the main string variables. This header file contains a default constructor which initialises the values to the data members
of an object. This file also contains the printDefinition fuction which, when run, outputs the "Currently Selected" word, definition and the type of word.
This section of code was last updated on 01/04/2023, by Brody Jeanes - 10568619
*/

#pragma once

#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>

class Word
{
public:
    std::string wordName;
    std::string wordDefinition;
    std::string wordType;

    /* Default Constructor */
    Word() {}

    /* Getters */
    std::string getName() const { return wordName; }
    std::string getType() const { return wordType; }
    std::string getDefinition() const { return wordDefinition; }

    /* Setters */
    void setName(std::string n) { wordName = n; }
    void setType(std::string t) { wordType = t; }
    void setDefinition(std::string d) { wordDefinition = d; }

    /* The PrintDefinition Function */
    void printDefinition() const
    {
        std::cout << "---------------------------------" << std::endl << "Word : " << wordName << std::endl << std::endl << "Word Type : " << wordType << std::endl << std::endl << "Word Definition : " << wordDefinition << std::endl;
    }
};
#endif
