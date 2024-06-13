/*
Student Name : Brody Jeanes
Student ID : 10568619
*/

/*In this section, the libraries that are required for the program to run are called and included into the source file. */
#include "Dictionary.h"
#include <fstream>
#include <iostream>
#include <algorithm>

/*
In this section, task 1 is completed. The task1LoadDict() module takes the users input from main() and the structure Word to check and open a file for the program to read.
This part is completed in main(). If the user inputs a file that is not located within the directory of this file,
then it will output an error message. If the user inputs a correct file name, the program will load and parse the dictionary file inside of the loaded file.
The user can enter 'default' to load the default dictionary included with this program. When a dictionary is loaded, each line will be read individually to check if it is in a valid format.
Task 1 will check to see if the first line begins with <word>, if it does, then it will parse each line to its corresponding variable, (e.g, first line will be the word name, second is the
definition, etc.) Once it hits the bottom of that individual word, it will stop at </word> and then parse that word into the dictionary. The file will then close if there are no more words.
This section of code was last updated on 24/04/2023, by Brody Jeanes - 10568619
*/

Dictionary::Dictionary() {} /* This is the constructor */

void Dictionary::task1LoadDict(std::string dict, std::vector<Word>& Dictionary)
{
	std::ifstream dictFile(dict); /* This line opens the file that the user specifies to open. */
	if (!dictFile.is_open())
	{
		std::cout << "Error Encountered Opening File, Please Try Again" << std::endl;
	}

	std::string dictLines;
	while (std::getline(dictFile, dictLines)) /* This reads each line when the file is open. */
	{
		if (dictLines == "<word>") /* This checks to see in the loaded dictionary when the first word is written */
		{
			Word newDictWord;
			getline(dictFile, newDictWord.wordName);
			getline(dictFile, newDictWord.wordDefinition);
			getline(dictFile, newDictWord.wordType);
			getline(dictFile, dictLines);
			Dictionary.push_back(newDictWord);
		}
	}

	dictFile.close(); /* This line closes the file. */
}

/*
In this section, task 2 is completed. The task2SearchWord() module takes the users input from main() and outputs the searched word. If the word that was inputted cannot be found in the dictionary,
then an error message will output. If the word is found in the loaded dictionary then the word type that was loaded in the dictionary is then temporarily updated for display
by converting the letter to its correspoing word. (e.g 'n' is converted to [noun]). The word's defintion is also fetched and displayed to the user. This section of code was last updated
on 24/04/2023, by Brody Jeanes - 10568619
*/

void Dictionary::task2SearchWord(std::string dictSearch, std::vector<Word>& Dictionary)
{
	bool dictSearchSuccessful = false;
	for (const Word& word : Dictionary) /* This for loop will check ever word loaded in the dictionary and see if any match the users input in the if statement below. */
	{
		if (word.wordName == dictSearch)
		{
			dictSearchSuccessful = true;
			std::string tempWordType;
			if (word.wordType == "n")
			{
				tempWordType = "[noun]";
			}
			else if (word.wordType == "v")
			{
				tempWordType = "[verb]";
			}
			else if (word.wordType == "adv")
			{
				tempWordType = "[adverb]";
			}
			else if (word.wordType == "adj")
			{
				tempWordType = "[adjective]";
			}
			else if (word.wordType == "prep")
			{
				tempWordType = "[preposition]";
			}
			else if (word.wordType == "misc")
			{
				tempWordType = "[miscellaneous]";
			}
			else if (word.wordType == "pn")
			{
				tempWordType = "[proper noun]";
			}
			else if (word.wordType == "nv")
			{
				tempWordType = "[noun and verb]";
			}

			std::cout << "---------------------------------" << std::endl << "Word : " << word.wordName << std::endl << std::endl << "Word Type : " << tempWordType << std::endl << std::endl << "Word Definition : " << word.wordDefinition << std::endl;
		}
	}

	if (!dictSearchSuccessful)
	{
		std::cout << std::endl << "Word cannot be found within this dictioanry" << std::endl;
	}
}

/*
In this section, task 3 is completed. The task3DisplayZ() module displays all the words loaded within the dictionary that have more than three 'z' characters.
The for loop will check every word loaded in the dictionary and check every character of ever word individually for the character 'z'. Once it finds a z, then it increments a counter by 1.
If the counter is greater than 3 by the end of that individual word, it will display that word to the user. It will do this for every word within the loaded dictionary. If there are no words
with more than 3 z's then it will print out a different message. This section of code was last updated on the 24/04/2023, by Brody Jeanes - 10568619.
*/

void Dictionary::task3DisplayZ(const std::vector<Word>& Dictionary)
{
	bool anyZWords = false;
	for (const Word& word : Dictionary) /* This for loop will check ever word loaded in the dictionary and will increment a counter for ever z character it finds within one word for every word in the below if statement. */
	{
		int dictZWords = 0;
		for (char Zees : word.wordName)
		{
			if (Zees == 'z')
			{
				dictZWords++;
			}
		}
		if (dictZWords > 3)
		{
			anyZWords = true;
			std::cout << std::endl << "There are " << dictZWords << " z's contained within the word " << word.wordName << std::endl << std::endl;
		}
	}
	if (!anyZWords)
	{
		std::cout << std::endl << "There are no words in this dictionary with more than 3 z's" << std::endl;
	}
}

/*
In this section, task 4 is completed. The task4AddWord() module allows the user to enter a new word, word type, and word definition and save that dictionary to a file.
The module obtains the users inputs through main() which are then parsed to task4AddWord(). A new structure instance is created of Word so that the users inputs can be added to the dictionary.
The program then asks the user to enter the name of the file that they would like to save the updated dictionary to. If the user enters an already existing file, then that file will be updated.
If the user enters a file that doesnt exist, a new file will be created with the dictionary's contents loaded into it. The file is then closed and returns back to main(). This section of
the code was last updated the 24/04/2023, by Brody Jeanes - 10568619.
*/

void Dictionary::task4AddWord(std::string newWordName, std::string newWordType, std::string newWordDefinition, std::vector<Word>& Dictionary)
{
	std::string newFileName;
	Word addWord;
	addWord.wordName = newWordName;
	addWord.wordType = newWordType;
	addWord.wordDefinition = newWordDefinition;
	Dictionary.push_back(addWord);
	std::cout << std::endl << "Saving Word To Dictionary " << std::endl;


	std::cout << "Enter A File Name To Save The Dictionary To : ";
	getline(std::cin, newFileName);


	std::ofstream newDictFile(newFileName); /* Updates or Creates a new output file for the dictionary to be updated to. */
	for (const Word& word : Dictionary) /* This for loop will check ever word loaded in the dictionary. */
	{
		newDictFile << "<word>" << std::endl << word.wordName << std::endl << word.wordDefinition << std::endl << word.wordType << std::endl << "</word>" << std::endl;
	}
	newDictFile.close(); /* This line closes the file. */
	std::cout << "Updated Dictionary Saved To " << newFileName << std::endl;
}
