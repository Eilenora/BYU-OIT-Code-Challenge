// Hangman Coding Challenge Real.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cctype>

const std::string words[10] = { "zebra", "coyote", "candle", "fish", "visual", "aluminum", "jacket", "crypt", "awkward", "jazz" };

void printGallows(int numIncorrectGuesses)
{
    if (numIncorrectGuesses == 0)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl;
        std::cout << "     |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 1)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "  O  |  " << std::endl << "     |  " << std::endl;
        std::cout << "     |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 2)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "  O  |  " << std::endl << "  |  |  " << std::endl;
        std::cout << "     |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 3)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "  O  |  " << std::endl << " -|  |  " << std::endl;
        std::cout << "     |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 4)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "  O  |  " << std::endl << " -|- |  " << std::endl;
        std::cout << "     |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 5)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "  O /|  " << std::endl << " -|- |  " << std::endl;
        std::cout << "     |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 6)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "\\ O /|  " << std::endl << " -|- |  " << std::endl;
        std::cout << "     |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 7)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "\\ O /|  " << std::endl << " -|- |  " << std::endl;
        std::cout << " /   |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 8)
    {
        std::cout << "  ----  " << std::endl << "  |  |  " << std::endl << "\\ O /|  " << std::endl << " -|- |  " << std::endl;
        std::cout << " / \\ |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 9)
    {
        std::cout << "  ----  " << std::endl << "o |  |  " << std::endl << "\\ O /|  " << std::endl << " -|- |  " << std::endl;
        std::cout << " / \\ |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 10)
    {
        std::cout << "  ----  " << std::endl << "o | o|  " << std::endl << "\\ O /|  " << std::endl << " -|- |  " << std::endl;
        std::cout << " / \\ |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else if (numIncorrectGuesses == 11)
    {
        std::cout << "  ----  " << std::endl << "o | o|  " << std::endl << "\\ O /|  " << std::endl << " -|- |  " << std::endl;
        std::cout << "_/ \\ |  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
    else
    {
        std::cout << "  ----  " << std::endl << "o | o|  " << std::endl << "\\ O /|  " << std::endl << " -|- |  " << std::endl;
        std::cout << "_/ \\_|  " << std::endl << "     |  " << std::endl << "     |  " << std::endl << " ______ " << std::endl;
    }
}

void printBoard(std::string board, std::string incorrectGuesses, int numCorrectGuess, int numIncorrectGuess)
{
    std::cout << std::endl << "Current Board: " << std::endl;
    std::cout << board << std::endl;
    std::cout << "Gallows: " << std::endl;
    printGallows(numIncorrectGuess);
    std::cout << "Letters not in word: " << std::endl;
    std::cout << incorrectGuesses << std::endl;
    std::cout << "Number of Correct Guesses: " << numCorrectGuess << std::endl;
    std::cout << "Number of Incorrect Guesses: " << numIncorrectGuess << std::endl;
}

bool checkGuess(std::string board, std::string incorrectGuesses, std::string userGuessString)
{
    bool validGuess = false;
    int numLetters = board.length();
    int numIncorrectGuesses = incorrectGuesses.length();
    char userGuess = userGuessString.at(0);
    if (userGuessString.length() != 1)
    {
        std::cout << "Please only guess 1 letter at a time. Please guess a single letter: ";
        return false;
    }
    if (isalpha(userGuess))
        validGuess = true;
    else
    {
        std::cout << "Invalid input. Please guess a letter: ";
        return false;
    }
    for (int i = 0; i < numLetters; ++i)
    {
        if (board.at(i) == userGuess)
        {
            std::cout << "You have already guessed this letter. Please guess a new letter: ";
            return false;
        }
    }
    for (int i = 0; i < numIncorrectGuesses; ++i)
    {
        if (incorrectGuesses.at(i) == userGuess)
        {
            std::cout << "You have already guessed this letter. Please guess a new letter: ";
            return false;
        }
    }
    return true;
}

void updateBoard(std::string& board, std::string& incorrectGuesses, std::string word, char userGuess)
{
    int numLetters = board.length();
    bool letterFound = false;
    for (int i = 0; i < numLetters; ++i)
    {
        if (word.at(i) == userGuess)
        {
            board.at(i) = userGuess;
            letterFound = true;
        }
    }
    if (letterFound == false)
        incorrectGuesses = incorrectGuesses + userGuess + " ";
}

bool checkAnswer(std::string board, std::string word, char userGuess)
{

    int numLetters = board.length();
    for (int i = 0; i < numLetters; ++i)
    {
        if (word.at(i) == userGuess)
            return true;
    }
    return false;
}

bool checkIfFinished(std::string board)
{
    int numLetters = board.length();
    for (int i = 0; i < numLetters; ++i)
    {
        if (board.at(i) == '_')
            return false;
    }
    return true;
}

int playGame()
{
    //Randomly Select Word
    srand((int)time(0));
    int randIndex = rand() % 10;
    std::string wordToGuess = words[randIndex];
    //Tell User How many letters their word has
    int numLetters = wordToGuess.length();
    std::cout << "The word you are trying to guess has " << numLetters << " letters." << std::endl;
    //Initialize the game board
    std::string board = "";
    for (int i = 0; i < numLetters; ++i) {
        board = board + "_";
    }
    bool gameFinished = false;
    std::string userGuessString;
    char userGuess;
    int numCorrectGuesses = 0;
    int numIncorrectGuesses = 0;
    std::string incorrectGuesses = "";
    //run The game
    while (gameFinished == false) {
        printBoard(board, incorrectGuesses, numCorrectGuesses, numIncorrectGuesses);
        std::cout << std::endl << "Guess a letter: ";
        std::cin >> userGuessString;
        userGuessString.at(0) = tolower(userGuessString.at(0));
        //check for valid input
        while (!checkGuess(board, incorrectGuesses, userGuessString))
        {
            std::cin >> userGuessString;
            userGuessString.at(0) = tolower(userGuessString.at(0));
        }
        userGuess = userGuessString.at(0);
        //Updates the Board
        updateBoard(board, incorrectGuesses, wordToGuess, userGuess);
        //Checks if the Users guess is in the word
        if (checkAnswer(board, wordToGuess, userGuess))
        {
            numCorrectGuesses++;
            std::cout << "That letter is in the word!" << std::endl;
        }
        else
        {
            numIncorrectGuesses++;
            std::cout << "Sorry, that letter is not in the word." << std::endl;
        }
        //Checks if the entire word has been guessed
        if (checkIfFinished(board))
            gameFinished = true;
    }

    std::cout << std::endl << "Congratulations! You won the game!" << std::endl;
    std::cout << "The word was: " << wordToGuess << std::endl;
    std::cout << "You guessed the word in " << numCorrectGuesses + numIncorrectGuesses << " attempts! Good job!" << std::endl;

    std::cout << std::endl << "Would you like to play again? Enter yes or no." << std::endl;
    std::string playAgain;
    std::cin >> playAgain;
    while (playAgain != "yes" && playAgain != "no")
    {
        std::cout << "Invalid Answer. Please enter yes or no." << std::endl;
        std::cin >> playAgain;
        std::cout << std::endl;
    }
    if (playAgain == "yes")
        return 1;
    else if (playAgain == "no")
        return 0;
}

int main()
{
    //Welcome User
    std::cout << "Hello user! Welcome to Hangman!" << std::endl;
    std::cout << "The goal of the game is to guess the randomly assigned word, by inputting letters, using as few guesses as possible.";
    std::cout << std::endl << std::endl;
    while (playGame() == 1);
    std::cout << "Thank you for playing!" << std::endl;
    return 0;
}
