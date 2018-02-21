//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Ari Deutsch on 18/7/17.
//  Copyright © 2017 Ari Deutsch. All rights reserved.
//

#pragma once
#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>

// type aliases to make Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowResults
{
    int32 Bulls = 0;
    int32 Cows = 0;
    char CowLetters[5];
    char BullLetters[5];
};

enum class EGuessStatus
{
    Has_Spaces,
    Has_Integers,
    Wrong_Length,
    Has_Capitals,
    Not_Isogram,
    Guess_Is_Valid
};

enum DifficultyLevel
{
    Easy,
    Intermediate,
    Challenging,
    Tough,
    Hard,
    Nightmare,
    JediMaster,
    YouHateYourself
};

class FBullCowGame
{
public:
    
    FBullCowGame();
    void Reset(DifficultyLevel Difficulty);
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetIsogramLength()const;
    EGuessStatus CheckGuessValidity(FString Guess);
    FBullCowResults CalculateAndReturnBullsAndCows(FString Guess);
    bool IsGameWon()const;
    FString GetHiddenIsogram()const;
    
    
    
    
private:
    
    //initialised by constructor or Reset function
    int32 MyCurrentTry;
    int32 DictionarySize;
    FString MyIsogram;
    bool bGameIsWon;
    bool IsIsogram(FString Guess);
    FString My3LetterIsogramDictionary[15];
    FString My4LetterIsogramDictionary[15];
    FString My5LetterIsogramDictionary[15];
    FString My6LetterIsogramDictionary[15];
    FString My7LetterIsogramDictionary[15];
    FString My8LetterIsogramDictionary[15];
    FString My9LetterIsogramDictionary[15];
    FString My10LetterIsogramDictionary[15];
};
#endif /* FBullCowGame_hpp */
