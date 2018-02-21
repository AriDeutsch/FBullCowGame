//
//  main.cpp
//  BullCowGame
//
//  Created by Ari Deutsch on 17/7/17.
//  Copyright © 2017 Ari Deutsch. All rights reserved.
//
/*
This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic, see the FBullCowGame class.
 */


#include "FBullCowGame.hpp"
#include <iostream>

// type aliases to make Unreal friendly
using FText = std::string;
using int32 = int;


//function prototypes
FText GetValidGuess();
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; //global game instance

/* BCGame methods available:
 
 void Reset(int32 DifficultyLevel);
 int32 GetMaxTries() const;
 int32 GetCurrentTry() const;
 int32 GetIsogramLength()const;
 EGuessStatus CheckGuessValidity(FString Guess);
 FBullCowResults CalculateAndReturnBullsAndCows(FString Guess);
 bool IsGameWon()const;
 FString GetHiddenIsogram()const;
 */

/******************************************************************************************************************************/

int main()
{
    
    bool bPlayAgain;
    do
    {
        std::cout << FText(50, '\n');
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while(bPlayAgain); //loop continues if user wishes to play again
    
    std::cout << "Bye Bye";
    return 0;
}

/******************************************************************************************************************************/

void PrintIntro()
{
    
    
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl << std::endl;
    
    std::cout << "        }   {        ___         " << std::endl;
    std::cout << "        (o o)       (o o)          " << std::endl;
    std::cout << "  /------\\ /         \\ /------\\" << std::endl;
    std::cout << " /| BULL |o           o| COW  |\\ " << std::endl;
    std::cout << "* |-,----|             |------| *" << std::endl;
    std::cout << "  ^      ^             ^      ^" << std::endl << std::endl;
    
    std::cout << "Instructions:" << std::endl << std::endl;
    std::cout << "Your goal is to guess a secret isogram word (i.e. a word with no repeating letters)." << std::endl << std::endl;
    std::cout << "For each guess, you can see how many Bulls & Cows you got for that guess." << std::endl << std::endl;
    std::cout << "A 'Bull' means you guessed a correct letter in its right position." << std::endl << std::endl;
    std::cout << "A 'Cow' means you guessed a correct letter but not in the right position." << std::endl << std::endl;
    std::cout << "For example:\nIf the secret isogram was: 'wreck',\nand you guessed the word:  'water', then your results summary would be as follows:" << std::endl << std::endl;
    std::cout << "No. of Bulls = 1\tThe bull is: w\nNo. of Cows  = 2\tThe cows are: e, r" << std::endl << std::endl << std::endl;
    
    //int variable for user input
    int32 DifficultyLevel_Integer = 0;
    
    // variable confirms difficulty selection
    FText Response;
    
    do{
        std::cout << "Enter difficulty level (1-5), 5 being the hardest: ";
        //load input and clear buffer
        std::cin >> DifficultyLevel_Integer;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        
        while (DifficultyLevel_Integer < 1 || DifficultyLevel_Integer > 5)
        {
            std::cout << "Invalid difficulty level. Input must be a number between 1 and 5"
            << std::endl; // repeatedly request valid input
            std::cout << "Please enter valid difficulty level: ";
            //load input and clear buffer
            std::cin >> DifficultyLevel_Integer;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
        }
        
        DifficultyLevel Difficulty = Challenging;
        
        switch (DifficultyLevel_Integer) {
            case 1:
                Difficulty = Easy;
                break;
            case 2:
                Difficulty = Intermediate;
                break;
            case 3:
                Difficulty = Challenging;
                break;
            case 4:
                Difficulty = Tough;
                break;
            case 5:
                Difficulty = Hard;
                break;
            case 6:
                Difficulty = Nightmare;
                break;
            case 7:
                Difficulty = JediMaster;
                break;
            case 8:
                Difficulty = YouHateYourself;
                break;
            default:
                break;
        }
        
        BCGame.Reset(Difficulty); // new game play requires that the 'current try' value and the 'maximum number of tries allowed' be reset
        
        // Array of names simply used for output of level to
        FString Difficulty_StringOutput[] = {"'Easy' (3 letter words)", "'Intermediate' (4 letter words)",
            "'Challenging' (5 letter words)", "'Tough' (6 letter words)",
            "'Hard' (7 letter words)", "'Nightmare' (8 letter words)",
            "'Jedi Master' (9 letter words)", "'You Hate Yourself' (10 letter words)"};
        
        std::cout << "You have chosen " << Difficulty_StringOutput[Difficulty] << ". Is this correct? (y/n): ";
        //'no' response causes input request to be repeated
        
        std::cin >> Response; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << std::endl;
        
    }while(Response[0] != 'Y' && Response[0] != 'y');
    
    std::cout << "Can you guess the "<< BCGame.GetIsogramLength() << " letter isogram I'm thinking of?" << std::endl;
    
    return;
}

/******************************************************************************************************************************/

// organises routine for core game play
void PlayGame()
{
    
    FText Guess; // declare 'Guess' variable
    FBullCowResults Result; // declare variable of type 'struct FBullCowResults'. For each new guess, the bull and cow amounts and letters will be assigned to it
    int32 MaxTries = BCGame.GetMaxTries();
    while(BCGame.GetCurrentTry() <= MaxTries)
    {
        
        Guess = GetValidGuess(); // request current guess from user, and assign it to variable 'Guess'
        
        Result = BCGame.CalculateAndReturnBullsAndCows(Guess);
        
        if(BCGame.IsGameWon())
        {
            std::cout << "\nBullseye! You guessed the word! Well done!" << std::endl << std::endl;
            return;
        }
        
        
        std::cout << std::endl << "No. of Bulls = " << Result.Bulls;
        if(Result.Bulls > 0)
        {
            std::cout << (Result.Bulls > 1?" \tThe bulls are: ":" \tThe bull is: ");
            for(int i = 0; i < Result.Bulls; i++)
            {
                std::cout << (!i?"":", ") << Result.BullLetters[i];
            }
        }
        std::cout << std::endl;
        
        std::cout << "No. of Cows = " << Result.Cows;
        if(Result.Cows > 0)
        {
            std::cout << (Result.Cows > 1?" \tThe cows are: ":" \tThe cow is: ");
            for(int i = 0; i < Result.Cows; i++)
            {
                std::cout << (!i?"":", ") << Result.CowLetters[i];
            }
        }
        std::cout << std::endl << std::endl;
        
    }
    std::cout << "\nYou have run out of guesses. The secret word was " << BCGame.GetHiddenIsogram() << ". Better luck next time :(" << std::endl << std::endl;
    return;
}

/******************************************************************************************************************************/

FText GetValidGuess()
{
    FText Guess;
    
    
    // error checking
    EGuessStatus Status;
    do{
        
        std::cout << std::endl << "You have " << BCGame.GetMaxTries()-BCGame.GetCurrentTry()+1 << " guesses left." << std::endl;
        std::cout << "Guess number " << BCGame.GetCurrentTry() << "; Enter guess: ";
        
        //load input
        std::cin >> Guess; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        Status = BCGame.CheckGuessValidity(Guess); // status of guess validity will determine what error message to put
        switch (Status)
        {
            case EGuessStatus::Not_Isogram:
                std::cout << "Guess can not have repeating letters." << std::endl;
                break;
            case EGuessStatus::Has_Spaces:
                std::cout << "Guess can not have spaces between letters." << std::endl;
                break;
            case EGuessStatus::Has_Integers:
                std::cout << "Guess can not have numbers." << std::endl;
                break;
            case EGuessStatus::Wrong_Length:
                std::cout << "Guess must be exactly " << BCGame.GetIsogramLength() << " letters long." << std::endl;
                break;
            case EGuessStatus::Has_Capitals:
                std::cout << "Guess must not contain uppercase letters." << std::endl;
                break;
            default:;
        }
    }while(Status != EGuessStatus::Guess_Is_Valid);
    
    return Guess;
}

/******************************************************************************************************************************/

bool AskToPlayAgain()
{
    std::cout << "Would you like to play again? (y/n)? ";
    
    FText Response = "";
    
    getline(std::cin,Response);
    
    std::cout << std::endl << std::endl << std::endl;
    
    return (Response[0] == 'Y' || Response[0] == 'y');
    // 'yes' means play again, otherwise exit game
}
