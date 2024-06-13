/*
Student Name : Brody Jeanes
Student ID : 10568619
*/

/*In this section, the libraries that are required for the program to run are called and included into the source file. */
#include "Word.h"
#include "Dictionary.h"
#include "ExtendedDictionary.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

/*
In this section, this is where the user inputs all of their required inputs for the other modules to run. When the program is run, a screen with a list of modules will appear.
The user can enter a number between 1-9 to enter into the corresponding module. The user must have a dictionary loaded to enter modules 2-4, therefore it is recommended that the
user enters '1' first and proceeds to enter a file name. If the user enters '2', they will be able to use the task 2 module which will allow them to search for a word that is in the loaded
dictionary. If the word entered is not in the loaded dictionary, an error message will appear. If the user enters '3', then module 3 will be loaded. This will display to the user, all of
the words in the currenlty loaded dictionary with more than 3 'z's. If the user enters '4' then the user will be able to manually enter a word. The inputed word must only use characters a-z or -.
If the user enters a character that doesnt meet the criteria, then a while loop will keep asking for the word until the user inputs a correct word name.
If the word already exists, the user will be prompted to re enter a word. The user must also enter a valid word type, which are listed. And then finally, the user can enter a word description.
Once they have entered all 3 inputs, the program will then ask the user where they would like to save the updated dictionary to. The user can either enter an already existing file name to update
that dicitonary OR, the can enter a new file name which will create a new file with that dicitonary loaded inside. If the user enters a '5' then the task 5 module will run which shows all of the palidromes 
in the loaded dictionary. If there are no palidromes found in the dictionary, then a message will state that no palindromes could be found. If the user enters a '6' then the task 6 module will run which
allows the user to input a word and the program will output any words that rhyme with the inputted word. If no rhyming words are found, then a message will output stating that no words could be found.
The users inputted word must also have at least 3 or more characters in order for the rhyming program to accept it as a valid input, otherwise an error message will ask for another input.
If the user enters '7' then the task 7 module will run which allows the user to play a little guessing game. A random word will be selected from the loaded dictionary and the fourth word located in the 
words definition will be removed. The user then will be shown the word and the word definition without the fourth definition word and the user must guess what that word in the definition is. If they guess
it correctly, they will gain 10 points and will be given another word. If they guess it incorrectly, then they will lose and be brought back to the menu. The score is saved to a different file which,
when the task 7 module is ran, then program will display the current highscore if it can locate the file storing the highscore number, otherwise it will create a new file and a new score will be added to
the high score when the user gets a score for the first time. If the user enters '8' then the program will run the task 8 module which allows the user to "cheat" at the online guessing game known
as Searchdle. The user will be prompted to input the mystery words length in, then the known "gray letters" which are the excluded letters. the user then will be prompted to input any known "green letters"
in and finally the user will be asked to input the position of any known letters if they known the position. The program will then sort through the loaded dictionary using the given critearia and output a list
of words that could be the word used in the searchdle. The more specific the user is with their input, the more likely the program will output the correct word. Finally, if the user enters '9', the program will simply close.
This section of the program was last updated on 09/05/2023 and was written by Brody Jeanes - 10568619.
*/
int main()
{
	Dictionary dictionary;
	ExtendedDictionary extendedDictionary;
	int taskMenu;
	vector<Word> Dictionary;
	string dict;
	string dictSearch;
	string newWordName;
	string newWordType;
	string newWordDefinition;

	while (true)
	{
		cout << "-------------------------------------------------------------" << endl << "01 - Load a Dictionary File " << endl << "02 - Search for a Word Within The Loaded Dictionary " << endl << "03 - Find And Display All Words With More Than Three 'z's" << endl << "04 - Add A Word To The Dictionary " << endl << "05 - Find And Display All Palindromes" << endl << "06 - Search For A Rhyming Word" << endl << "07 - Guess The Fourth Word From The Definition" << endl << "08 - Cheat At Searchle" << endl << "09 - Exit The Program" << endl << "-------------------------------------------------------------" << endl << "Enter : ";

		if (!(cin >> taskMenu))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); /* This line ignore all users inputs and outputs an error message if the doesnt input a integer. */
			cout << endl << "Invalid Input, Try Again." << endl;
			continue;
		}
		cout << "-------------------------------------------------------------" << endl;

		switch (taskMenu)
		{
		case 1:
			cout << "Enter a file name or type 'default' for the default dictionary file." << endl << endl << "File Name : ";
			cin.ignore();

			getline(cin, dict);

			transform(dict.begin(), dict.end(), dict.begin(), [](unsigned char lowercaseDefault) { return tolower(lowercaseDefault); }); /* This line takes the users input and converts every character into lowercase. */

			if (dict == "default")
			{
				dict = "dictionary_2023S1.txt";
			}

			cout << endl << "Now Loading " << dict << endl;

			dictionary.task1LoadDict(dict, Dictionary); /* This line calls upon the task 1 module and parses the 'dict' and 'Dictionary' variables through. */
			break;
		case 2:
			if (Dictionary.empty()) /* This line checks to see if there is a dictionary loaded. If there is no dictionary loaded, then it ouptputs this error message. */
			{
				cout << endl << "No Dictionary Has Been Loaded. Please Load A Dictionary And Try Again." << endl << endl;
			}
			else
			{
				cout << "Enter a Word : ";
				cin.ignore();
				getline(cin, dictSearch);

				transform(dictSearch.begin(), dictSearch.end(), dictSearch.begin(), [](unsigned char dictionarySearch) { return tolower(dictionarySearch); }); /* This line takes the users input and converts every character into lowercase. */

				dictionary.task2SearchWord(dictSearch, Dictionary); /* This line calls upon the task 2 module and parses the 'dictSearch' and 'Dictionary' variables through. */
			}
			break;
		case 3:
			if (Dictionary.empty()) /* This line checks to see if there is a dictionary loaded. If there is no dictionary loaded, then it ouptputs this error message. */
			{
				cout << endl << "No Dictionary Has Been Loaded. Please Load A Dictionary And Try Again." << endl << endl;
			}
			dictionary.task3DisplayZ(Dictionary); /* This line calls upon the task 3 module and parses the 'Dictionary' variable through. */
			break;
		case 4:
			if (Dictionary.empty()) /* This line checks to see if there is a dictionary loaded. If there is no dictionary loaded, then it ouptputs this error message. */
			{
				cout << endl << "No Dictionary Has Been Loaded. Please Load A Dictionary And Try Again." << endl << endl;
			}
			else
			{
				bool running = true;
				while (running)
				{
					cin.ignore();
					cout << "Enter Word Name : ";
					getline(cin, newWordName);

					newWordName.erase(remove(newWordName.begin(), newWordName.end(), ' '), newWordName.end()); /* This line removes any space that the user inputs into the prompt and joins the words together. */

					bool validInput = all_of(newWordName.begin(), newWordName.end(), [](char validCharacter) { return isalpha(validCharacter) || validCharacter == '-'; }); /* This line checks to see if the users input only contains characters between a-z and -. */

					while (!validInput) /* This while loop will only run when the users input doesnt meet the criteria being a-z or -. */
					{
						cout << "Invalid Input. Enter only characters a-z and hyphen '-' : ";
						getline(cin, newWordName);
						newWordName.erase(remove(newWordName.begin(), newWordName.end(), ' '), newWordName.end()); /* This line removes any space that the user inputs into the prompt and joins the words together. */
						validInput = all_of(newWordName.begin(), newWordName.end(), [](char validCharacter) { return isalpha(validCharacter) || validCharacter == '-'; });  /* This line checks to see if the users input only contains characters between a-z and -. */
					}

					transform(newWordName.begin(), newWordName.end(), newWordName.begin(), [](unsigned char lowercaseNewWord) { return tolower(lowercaseNewWord); }); /* This line takes the users input and converts every character into lowercase. */

					bool wordInDict = false;
					for (const Word& word : Dictionary) /* This for loop will check ever word loaded in the dictionary and see if any match the users input in the if statement below. */
					{
						if (newWordName == word.wordName)
						{
							cout << endl << "------------------------------------------------------------------------------------------" << endl << "Error: Word Already Exists, Elevated Privileges Required To Edit Existing Words. Press Enter To Continue ";
							cout << endl << "------------------------------------------------------------------------------------------";
							wordInDict = true;
							break;
						}
					}
					if (!wordInDict)
					{
						bool addingWord = true;
						while (addingWord)
						{
							cout << endl << "Enter Word Type (n, v, adv, adj, prep, misc, pn, nv) : ";
							getline(cin, newWordType);
							transform(newWordType.begin(), newWordType.end(), newWordType.begin(), [](unsigned char lowercaseNewType) { return tolower(lowercaseNewType); }); /* This line takes the users input and converts every character into lowercase. */
							if (newWordType == "n" || newWordType == "v" || newWordType == "adv" || newWordType == "adj" || newWordType == "prep" || newWordType == "misc" || newWordType == "pn" || newWordType == "nv")
							{
								cout << endl << "Enter Word Defintion : ";
								getline(cin, newWordDefinition);
								dictionary.task4AddWord(newWordName, newWordType, newWordDefinition, Dictionary); /* This line calls upon the task 4 module and parses the 'newWordName', 'newWordType', 'newWordDefinition' and 'Dictionary' variables through. */
								addingWord = false;

								while (true)
								{
									cout << endl << "Do you want to add another word? (y/n) : ";
									char choice;
									cin >> choice;
									if (choice == 'n' || choice == 'N')
									{
										running = false;
										break;
									}
									if (choice == 'y' || choice == 'Y')
									{
										running = true;
										break;
									}
									else
									{
										cout << endl << "That Is Not A Valid Input, Please Try Again";
									}
								}

							}
							else
							{
								cout << endl << "Error: Invalid Word Type." << endl;
							}
						}
					}
				}
			}
			break;
		case 5:
			if (Dictionary.empty()) /* This line checks to see if there is a dictionary loaded. If there is no dictionary loaded, then it ouptputs this error message. */
			{
				cout << endl << "No Dictionary Has Been Loaded. Please Load A Dictionary And Try Again." << endl << endl;
			}
			else 
			{
				extendedDictionary.task5Palindromes(Dictionary); /* This line calls upon the task 5 module and parses the "Dictionary" variable through. */
			}
			break;
		case 6:
			if (Dictionary.empty()) /* This line checks to see if there is a dictionary loaded. If there is no dictionary loaded, then it ouptputs this error message. */
			{
				cout << endl << "No Dictionary Has Been Loaded. Please Load A Dictionary And Try Again." << endl << endl;
			}
			else 
			{
				string RhymeInput;
				cout << "Enter Word Name: ";
				cin >> RhymeInput;
				if (dict.length() < 3) 
				{
					cout << "Error: The Given Word Needs To Be Three Or More Characters Long." << endl;
					break;
				}
				else 
				{
					string LastLetters = RhymeInput.substr(RhymeInput.length() - 3);
					extendedDictionary.task6RhymingWords(RhymeInput, Dictionary, LastLetters);  /* This line calls upon the task 6 module and parses the "RyhmeInput", "Dictionary", "LastLetters" variables through. */
				}
			}
			break;
		case 7:
			if (Dictionary.empty()) /* This line checks to see if there is a dictionary loaded. If there is no dictionary loaded, then it ouptputs this error message. */
			{
				cout << endl << "No Dictionary Has Been Loaded. Please Load A Dictionary And Try Again." << endl << endl;
			}
			else 
			{
				extendedDictionary.task7GuessFourthWord(Dictionary);  /* This line calls upon the task 7 module and parses the "Dictionary" variable through. */
			}
			break;
		case 8:
			if (Dictionary.empty()) /* This line checks to see if there is a dictionary loaded. If there is no dictionary loaded, then it ouptputs this error message. */
			{
				cout << endl << "No Dictionary Has Been Loaded. Please Load A Dictionary And Try Again." << endl << endl;
			}
			else
			{
				std::cout << "Welcome to 'Cheat at Searchdle!'" << std::endl << "Instructions : " << std::endl << "Enter The Length Of The Mystery Word And Then Specify The Criteria To Filter The Results." << std::endl << "You Will Be Given A List Of Words From The Dictionary That Match The Criteria Which Should Allow Solving The Searchdle Easier." << std::endl;
				std::cout << "-------------------------------------------------------------" << std::endl;
				extendedDictionary.task8CheatSearchdle(Dictionary);  /* This line calls upon the task 8 module and parses the "Dictionary" variable through. */
			}
			break;
		case 9:
			cout << endl << "---------------------------------" << endl << "     Now Exiting The Program" << endl << "---------------------------------" << endl;
			exit(0); /* This line closes the program. */
		default:
			cout << endl << "Invalid Input, Try Again." << endl; /* If an unexpected character is inputed, then this error message will be outputed.*/
			break;

		}
	}
}