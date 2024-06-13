/*
Student Name : Brody Jeanes
Student ID : 10568619
*/

/*In this section, the libraries that are required for the program to run are called and included into the source file. */
#include "ExtendedDictionary.h"
#include <random>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

ExtendedDictionary::ExtendedDictionary() : Dictionary() {} /* This is the constructor */

/*
In this section, task 5 is completed. The task5Palindromes() module sorts through all of the words in the loaded dictionary, from back to front, and front to back
to find all of the palidromes within the dictionary. If the program finds some palindromes, it will output them in a list. If there are no palidromes found in the
dictionary, then a message will state that No Palindromes Found.
This section of code was last updated on 02/05/2023, by Brody Jeanes - 10568619
*/

void ExtendedDictionary::task5Palindromes(std::vector<Word>& Dictionary)
{
    bool foundPalindrome = false;
    std::vector<std::string> findPalindromes; /* This line creates a new vector for the palindromes */
    for (const auto& word : Dictionary)
    {
        std::string palindrome = word.getName();
        std::string reverseWord = palindrome;
        reverse(reverseWord.begin(), reverseWord.end()); /* This line flips the word and saves the word as a new variable */
        if (palindrome == reverseWord)
        {
            findPalindromes.push_back(palindrome);
            foundPalindrome = true;
        }
    }

    if (!foundPalindrome)
    {
        std::cout << "No Palindromes Found." << std::endl;
    }
    else
    {
        std::cout << "Palindromes Found : " << std::endl << std::endl;
        for (const auto& palindrome : findPalindromes) /* This for loop outputs all of the palindromes that were found within the loaded dictionary */
        {
            std::cout << palindrome << std::endl;
        }
    }
}

/*
In this section, task 6 is completed. The task6RhymingWords() module takes the users input from main() and outputs words that rhyme with the users word from
the loaded dictionary. If there are no words that rhyme with the inputted word, then it will state No Rhyming Words Found. The user must input a word with three
or more characters in it for the program to work, otherwise an error message will output stating it requires three or more characters
This section of code was last updated on 02/05/2023, by Brody Jeanes - 10568619
*/

void ExtendedDictionary::task6RhymingWords(std::string RhymeInput, std::vector<Word>&Dictionary, std::string LastLetters)
{
    std::vector<Word> rhymingWords; /* This line creates a new vector for the rhyming words */
    for (const auto& RhymeWord : Dictionary) 
    {
        if (RhymeWord.wordName.length() >= 3 && RhymeWord.wordName.substr(RhymeWord.wordName.length() - 3) == LastLetters) /* This line checks if the length of each individual word wihtin the dictionary has atleast 3 characters and that the last three letters in each word are equal to the last three letters in the users inputted rhyming word */
        {
            rhymingWords.push_back(RhymeWord);
        }
    }
    
    if (rhymingWords.size() > 0) /* This line checks to see if any words were saved that rhyme with the users input, if they do it will output them */
    {
        std::cout << "Words that rhyme with '" << RhymeInput << "':" << std::endl << std::endl;
        for (const auto& rhyme : rhymingWords)
        {
            std::cout << rhyme.wordName << std::endl;
        }
    }
    else
    {
        std::cout << "No Rhyming Words Found." << std::endl;
    }
}

/* 
This small module is used to load the highscore of task 7. it will search for a file called highscore.txt and if it can find it, it will open it and load the number
from the file and return that number to the currenthighscore variable. If there is no file called highscore.txt then the program will create a new file to save the next score to
This section of code was last updated on 08/05/2023, by Brody Jeanes - 10568619
*/
int ExtendedDictionary::loadHighScore()
{
    std::ifstream HighScoreFile("highscore.txt");
    if (HighScoreFile.is_open()) /* Checks to see if the highscore file is open. if it is, it will load the number that is located within. If it cant, it will create a new file and enter 0 in it. */
    {
        int currentHighScore;
        HighScoreFile >> currentHighScore;
        HighScoreFile.close(); /* Closes the file */
        return currentHighScore;
    }
    else 
    {
        std::cout << "Failed to open high score file!" << std::endl;
        return 0;
    }
}

/*
This small module is used to save the highscore of task 7. It will check to see if the highscore file exists, if it does, then it will overwrite the highscore with the new highscore.
if there is no file called highscore.txt then it will create a new file and save the new highscore to it.
This section of code was last updated on 08/05/2023, by Brody Jeanes - 10568619
*/
void ExtendedDictionary::saveHighScore(int currentHighScore)
{
    std::ofstream HighScoreFile("highscore.txt");
    if (HighScoreFile.is_open()) 
    {
        HighScoreFile << currentHighScore;
        HighScoreFile.close(); /* Closes the file */
    }
    else 
    {
        std::cout << "Failed to save high score!" << std::endl;
    }
}

/* 
This module is used to hide the fourth word in the definition within task 7. It first creates a new vector called individualWords. Then it will split each word from the selected word
definition into its own seperated words. It does this between each space so it knows when a word starts and stops. It will then find the fourth word within the definition and it will
then replace the fourth definition word with underscores. Once it replaces that specific fourth word with underscores it will return that word and join it back with the original definition words.
This section of code was last updated on 08/05/2023, by Brody Jeanes - 10568619
*/
std::string ExtendedDictionary::hideDefinitionWord(const std::string& wordDefinition)
{
    std::string hiddenDefinition;

    /* These lines split the word definition into individual words */ 
    std::vector<std::string> individualWords;
    std::string defWord;
    for (char word : wordDefinition) 
    {
        if (word == ' ') 
        {
            individualWords.push_back(defWord);
            defWord.clear();
        }
        else 
        {
            defWord += word;
        }
    }
    individualWords.push_back(defWord);

    /* These lines replace the fourth word with underscores */
    for (size_t i = 0; i < individualWords.size(); i++) 
    {
        if (i == 3) 
        {
            hiddenDefinition += std::string(individualWords[i].length(), '_') + " ";
        }
        else 
        {
            hiddenDefinition += individualWords[i] + " ";
        }
    }
    return hiddenDefinition;
}

/*
In this section, task 7 is completed. The task7GuessFourthWord() module first calls to load the highscore using the loadHighScore() module. 
It then looks at every words definition from the loaded dictionary and attempts at adding it to a new vector called descriptionWith4Words. 
If there are no word definitions that have more than 4 words, then an error message will output. It then takes a random word from the loaded dictionary, 
then it takes that word's definition runs it through the hideDefinitionWord() module which replaces the fourth word in the definition with underscores. Then it outputs
the word and definition and asks the user to input what they think the fourth word of the definition is. If the user guesses it correctly, they will gain 10 points and the
game will continue, displaying another word with its definition. If the user guesses incorrectly, the program will save their score if their score is higher than the highscore
and run the saveHighScore() module and return to the menu.
This section of code was last updated on 08/05/2023, by Brody Jeanes - 10568619
*/
void ExtendedDictionary::task7GuessFourthWord(std::vector<Word>& Dictionary)
{
    int score = 0;
    currentHighScore = loadHighScore(); /* Saves the function loadHighScore to a variable for ease of use. */
    std::cout << "Welcome to Guess the Fourth Word!" <<std::endl<< "Current High Score : " << currentHighScore << std::endl << std::endl;

    std::vector<Word> descriptionWith4Words;

    for (const auto& word : Dictionary) 
    {
        if (std::count(word.wordDefinition.begin(), word.wordDefinition.end(), ' ') >= 4) /* Checks to see if the definition has more than 4 words*/
        {
            descriptionWith4Words.push_back(word);
        }
    }

    if (descriptionWith4Words.empty()) 
    {
        std::cout << "There Are No Words With More Than 4 Words In Their Definitions Found Within The Loaded Dictionary." << std::endl;
        return;
    }

    /* 
    These lines of code are used to generate a random order of selection of words from the loaded dictionary. 
    This section of code was used from the cppReference website - https://en.cppreference.com/w/cpp/numeric/random/random_device
    */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, descriptionWith4Words.size() - 1);
    
    while (true)
    {
        Word selectedWord = descriptionWith4Words[distr(gen)];
        std::string hiddenDefinition = ExtendedDictionary::hideDefinitionWord(selectedWord.wordDefinition); /* This section parses the definition to the hideDefinitionWord() function */

        std::cout << "The Word Is : " << selectedWord.wordName << std::endl;
        std::cout << "Definition : " << hiddenDefinition << std::endl;

        std::string guessInput;
        std::cout << std::endl << "Guess the Missing Word : ";
        std::cin >> guessInput;

        std::string missingWord;
        int spaceCount = 0;
        for (char space : selectedWord.wordDefinition)
        {
            if (space == ' ')
            {
                spaceCount++;
            }
            if (spaceCount == 3 && space != ' ')
            {
                missingWord.push_back(space);
            }
        }

        std::transform(guessInput.begin(), guessInput.end(), guessInput.begin(), ::tolower);
        std::transform(missingWord.begin(), missingWord.end(), missingWord.begin(), ::tolower);

        if (guessInput == missingWord)
        {
            std::cout << std::endl << "Congratulations! You Guessed The Word Correcttly." << std::endl;
            score += 10;
            std::cout << "Your Current Score Is Now" << score << std::endl << std::endl;


            if (score > currentHighScore) 
            {
                currentHighScore = score;
                std::cout << "You Have Achieved A New High Score Of : " << currentHighScore << std::endl << std::endl;
                saveHighScore(currentHighScore); /* Saves the current high score */
            }
            continue;
        }
        else 
        {
            std::cout << std::endl << "That Is Incorrect. The Missing Word Is : " << missingWord << std::endl;
            std::cout << "Your Final Score : " << score << std::endl;
            break;
        }
    }
}

/*
In this section, task 8 is completed. The task8CheatSeacrchdle() module takes the users input from main() and filters the dictionary based on the users input. 
First, the program asks for the mystery word. The user will be prompted to input the mystery words length in, then the known "gray letters" which are the excluded letters. the user then will be prompted to input any known "green letters"
in and finally the user will be asked to input the position of any known letters if they known the position. The program will then sort through the loaded dictionary using the given critearia and output a list
of words that could be the word used in the searchdle. The more specific the user is with their input, the more likely the program will output the correct word. Finally, if the user enters '9', the program will simply close.
This section of code was last updated on 09/05/2023, by Brody Jeanes - 10568619
*/
void ExtendedDictionary::task8CheatSearchdle(std::vector<Word>& Dictionary) 
{
    /* This section of code obtains length of the mystery word. */
    int mysteryWordLength;
    bool validLength = false;
    while (!validLength) 
    {
        std::cout << "Enter The Length of The Mystery Word: ";
        if (std::cin >> mysteryWordLength && mysteryWordLength > 0) 
        {
            validLength = true;
        }
        else 
        {
            std::cout << "Invalid Input. Enter a Valid Integer Greater Than 0." << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    /* This section of code obtains the excluded letter(s) that must be in the word. */
    std::string grayLetters;
    bool validGrayInput = false;
    while (!validGrayInput)
    {
        std::cout << std::endl << "Enter The Letter(s) to Exclude (Seperate Letters With a Comma ','. E.g. g,f,c): ";
        std::getline(std::cin, grayLetters);
        std::transform(grayLetters.begin(), grayLetters.end(), grayLetters.begin(), ::tolower);
        if (grayLetters.find_first_not_of(",") != std::string::npos) 
        {
            grayLetters.erase(std::remove(grayLetters.begin(), grayLetters.end(), ','), grayLetters.end());
            grayLetters.erase(std::remove(grayLetters.begin(), grayLetters.end(), ' '), grayLetters.end());
            validGrayInput = true;

            for (char possibleIntegers : grayLetters)
            {
                if (!isalpha(possibleIntegers))
                {
                    validGrayInput = false;
                    std::cout << "Invalid Input. Please Only Enter Characters." << std::endl;
                    break;
                }
            }
        }
        else 
        {
            std::cout << "Please Enter at Least One Letter to Exclude." << std::endl;
        }
    }
    
    /* This section of code obtains the required letter(s) that must be in the word. */
    std::string greenLetters;
    bool validGreenInput = false;
    while (!validGreenInput)
    {
        std::cout << std::endl << "Enter the Letter(s) That are Required (Seperate Letters With a Comma ','. E.g a,e,i): ";
        std::getline(std::cin, greenLetters);
        std::transform(greenLetters.begin(), greenLetters.end(), greenLetters.begin(), ::tolower);
        if (greenLetters.find_first_not_of(",") != std::string::npos) 
        {
            greenLetters.erase(std::remove(greenLetters.begin(), greenLetters.end(), ','), greenLetters.end());
            greenLetters.erase(std::remove(greenLetters.begin(), greenLetters.end(), ' '), greenLetters.end());
            validGreenInput = true;
        
            for (char possibleIntegers : greenLetters)
            {
                if (!isalpha(possibleIntegers))
                {
                    validGreenInput = false;
                    std::cout << "Invalid Input. Please Only Enter Characters." << std::endl;
                    break;
                }
            }
        }
        else
        {
            std::cout << "Please Enter at Least One Letter to Include." << std::endl;
        }
    }
    
    /* This section of code obtains the positions of the letters that must be in the word if they are known by the user */
    std::string positionLetters;
    bool validPosition = false;
    while (!validPosition) 
    {
        std::cout << std::endl << "Enter the Letter(s) and Their Positions Within The Word." << std::endl << "(E.g. a2g4f1, This Would Signify That 'a' is The 2nd Letter In This Word), if Unknown, Leave Blank : ";
        std::getline(std::cin, positionLetters);

        std::transform(positionLetters.begin(), positionLetters.end(), positionLetters.begin(), ::tolower);
        positionLetters.erase(std::remove(positionLetters.begin(), positionLetters.end(), ' '), positionLetters.end());

        validPosition = true;

        for (int i = 0; i < positionLetters.length(); i += 2) 
        {
            if (!std::isalpha(positionLetters[i]) || !std::isdigit(positionLetters[i + 1])) 
            
            {
                validPosition = false;
                std::cout << "Invalid Input. Please enter positions in the format (letter number)." << std::endl;
                break;
            }
        }
    }
    
    /* 
    NOTE: Used cplusplus website - https://cplusplus.com/reference/map/map/ to assist with saving the position of the letters and searching through the 
    dictionary. Also used code from geeksforgeeks website - https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
    */

    /*
    This section of code parses the positionLetters variable and stores them in a map from the library module 'map' and the library module 'sstream'.
    */

    std::map<int, char> positionMap;
    std::stringstream ss(positionLetters);
    char letter;
    int position;
    while (ss >> letter >> position) 
    {
        positionMap[position] = letter;
    }

    /*
    NOTE: Used cplusplus website - https://cplusplus.com/reference/map/map/ to assist with saving the position of the letters and searching through the
    dictionary. Also used code from geeksforgeeks website - https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
    */

    /* 
    This section of code filters through the loaded dictionary based on the criteria that the user has inputted. First it will check the length of the word, and 
    find all words within the dictionary that have the same length. Next it will check for the excluded letters (gray letters) and remove those words from the
    dictionary if any words have any of the excluded letters. Next it will check for the required letters (green letters) and remove any word that does not have any
    of the required letters that were inputted by the user from the dictionary. Finally it will check the position of each inputted letter if any was given 
    */

    std::vector<Word> filteredWords;
    for (const auto& word : Dictionary) 
    {
        /* Check the length of the mystery word against all of the words in the loaded dictionary */
        if (word.getName().length() != mysteryWordLength) 
        {
            continue;
        }

        /* Check the excluded letters of the mystery word against all of the words in the loaded dictionary */
        bool excluded = false;
        for (const auto& isExcluded : grayLetters) 
        {
            if (word.getName().find(isExcluded) != std::string::npos) 
            {
                excluded = true;
                break;
            }
        }
        if (excluded) 
        {
            continue;
        }

        /* Check the required letter of the mystery word against all of the words in the loaded dictionary */
        bool required = true;
        for (const auto& isRequired : greenLetters) 
        {
            if (word.getName().find(isRequired) == std::string::npos) 
            {
                required = false;
                break;
            }
        }
        if (!required) 
        {
            continue;
        }

        /* Check the letters position of the mystery word against all of the words in the loaded dictionary */
        bool position = true;
        for (const auto& inPosition : positionMap) 
        {
            if (word.getName().length() < inPosition.first || word.getName()[inPosition.first - 1] != inPosition.second) 
            {
                position = false;
                break;
            }
        }
        if (!position) 
        {
            continue;
        }

        filteredWords.push_back(word);
    }

    /*
    This part of the code uses the printDefinition function from the word class to print out all of the filtered words that match the criteria from the users 
    inputs
    */

    std::cout << std::endl << filteredWords.size() << " Words Found That Match the Criteria: " << std::endl;
    for (auto& word : filteredWords) 
    {
        word.printDefinition(); /* Uses the printDefinition() function from the word.h file */
    }
}