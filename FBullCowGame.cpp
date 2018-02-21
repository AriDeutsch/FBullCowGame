//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Ari Deutsch on 18/7/17.
//  Copyright © 2017 Ari Deutsch. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <time.h>
#include <stdlib.h>
#include <map>
//#include <boost/algorithm/string/trim.hpp>

// type aliases to make Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

/******************************************************************************************************************************/

FBullCowGame::FBullCowGame()
{
    srand(time(NULL));
    DictionarySize = 15;
    /*******/
    My3LetterIsogramDictionary[0] = "eat";My3LetterIsogramDictionary[1] = "tea";My3LetterIsogramDictionary[2] = "pea";
    My3LetterIsogramDictionary[3] = "sip";My3LetterIsogramDictionary[4] = "pot";My3LetterIsogramDictionary[5] = "pod";
    My3LetterIsogramDictionary[6] = "dog";My3LetterIsogramDictionary[7] = "ant";My3LetterIsogramDictionary[8] = "and";
    My3LetterIsogramDictionary[9] = "run";My3LetterIsogramDictionary[10] = "ran";My3LetterIsogramDictionary[11] = "cat";
    My3LetterIsogramDictionary[12] = "god";My3LetterIsogramDictionary[13] = "bad";My3LetterIsogramDictionary[14] = "top";
    /*******/
    My4LetterIsogramDictionary[0] = "sour";My4LetterIsogramDictionary[1] = "pour";My4LetterIsogramDictionary[2] = "fast";
    My4LetterIsogramDictionary[3] = "word";My4LetterIsogramDictionary[4] = "fork";My4LetterIsogramDictionary[5] = "sink";
    My4LetterIsogramDictionary[6] = "game";My4LetterIsogramDictionary[7] = "from";My4LetterIsogramDictionary[8] = "damn";
    My4LetterIsogramDictionary[9] = "read";My4LetterIsogramDictionary[10] = "salt";My4LetterIsogramDictionary[11] = "milk";
    My4LetterIsogramDictionary[12] = "wind";My4LetterIsogramDictionary[13] = "rain";My4LetterIsogramDictionary[14] = "many";
    /*******/
    My5LetterIsogramDictionary[0] = "grape";My5LetterIsogramDictionary[1] = "today";My5LetterIsogramDictionary[2] = "brick";
    My5LetterIsogramDictionary[3] = "bling";My5LetterIsogramDictionary[4] = "treck";My5LetterIsogramDictionary[5] = "waltz";
    My5LetterIsogramDictionary[6] = "wreck";My5LetterIsogramDictionary[7] = "draft";My5LetterIsogramDictionary[8] = "frown";
    My5LetterIsogramDictionary[9] = "float";My5LetterIsogramDictionary[10] = "jokes";My5LetterIsogramDictionary[11] = "party";
    My5LetterIsogramDictionary[12] = "pound";My5LetterIsogramDictionary[13] = "thump";My5LetterIsogramDictionary[14] = "sound";
    /*******/
    My6LetterIsogramDictionary[0] = "grapes";My6LetterIsogramDictionary[1] = "friday";My6LetterIsogramDictionary[2] = "trucks";
    My6LetterIsogramDictionary[3] = "thrice";My6LetterIsogramDictionary[4] = "mobile";My6LetterIsogramDictionary[5] = "plants";
    My6LetterIsogramDictionary[6] = "gamers";My6LetterIsogramDictionary[7] = "hunter";My6LetterIsogramDictionary[8] = "chairs";
    My6LetterIsogramDictionary[9] = "planet";My6LetterIsogramDictionary[10] = "planes";My6LetterIsogramDictionary[11] = "jumper";
    My6LetterIsogramDictionary[12] = "carpet";My6LetterIsogramDictionary[13] = "quirky";My6LetterIsogramDictionary[14] = "jumble";
    /*******/
    My7LetterIsogramDictionary[0] = "grumble";My7LetterIsogramDictionary[1] = "saintly";My7LetterIsogramDictionary[2] = "vibrant";
    My7LetterIsogramDictionary[3] = "threads";My7LetterIsogramDictionary[4] = "plucked";My7LetterIsogramDictionary[5] = "drastic";
    My7LetterIsogramDictionary[6] = "farming";My7LetterIsogramDictionary[7] = "placebo";My7LetterIsogramDictionary[8] = "godlike";
    My7LetterIsogramDictionary[9] = "metrics";My7LetterIsogramDictionary[10] = "virtual";My7LetterIsogramDictionary[11] = "gravity";
    My7LetterIsogramDictionary[12] = "clothes";My7LetterIsogramDictionary[13] = "viaduct";My7LetterIsogramDictionary[14] = "archive";
    /*******/
    My8LetterIsogramDictionary[0] = "acronyms";My8LetterIsogramDictionary[1] = "ligament";My8LetterIsogramDictionary[2] = "vanquish";
    My8LetterIsogramDictionary[3] = "bachelor";My8LetterIsogramDictionary[4] = "novelist";My8LetterIsogramDictionary[5] = "watchful";
    My8LetterIsogramDictionary[6] = "campfire";My8LetterIsogramDictionary[7] = "obituary";My8LetterIsogramDictionary[8] = "yourself";
    My8LetterIsogramDictionary[9] = "enthalpy";My8LetterIsogramDictionary[10] = "pandemic";My8LetterIsogramDictionary[11] = "saboteur";
    My8LetterIsogramDictionary[12] = "harmonic";My8LetterIsogramDictionary[13] = "question";My8LetterIsogramDictionary[14] = "triangle";
    /*******/
    My9LetterIsogramDictionary[0] = "abduction";My9LetterIsogramDictionary[1] = "facetious";My9LetterIsogramDictionary[2] = "machinery";
    My9LetterIsogramDictionary[3] = "biography";My9LetterIsogramDictionary[4] = "foresight";My9LetterIsogramDictionary[5] = "secondary";
    My9LetterIsogramDictionary[6] = "champions";My9LetterIsogramDictionary[7] = "formative";My9LetterIsogramDictionary[8] = "unethical";
    My9LetterIsogramDictionary[9] = "deflation";My9LetterIsogramDictionary[10] = "keyboards";My9LetterIsogramDictionary[11] = "universal";
    My9LetterIsogramDictionary[12] = "depravity";My9LetterIsogramDictionary[13] = "juxtapose";My9LetterIsogramDictionary[14] = "wordsmith";
    /*******/
    My10LetterIsogramDictionary[0] = "background";My10LetterIsogramDictionary[1] = "judgmental";My10LetterIsogramDictionary[2] = "hospitable";
    My10LetterIsogramDictionary[3] = "bankruptcy";My10LetterIsogramDictionary[4] = "juxtaposed";My10LetterIsogramDictionary[5] = "graciously";
    My10LetterIsogramDictionary[6] = "binoculars";My10LetterIsogramDictionary[7] = "monarchist";My10LetterIsogramDictionary[8] = "formidable";
    My10LetterIsogramDictionary[9] = "duplicates";My10LetterIsogramDictionary[10] = "waveringly";My10LetterIsogramDictionary[11] = "complaints";
    My10LetterIsogramDictionary[12] = "flashpoint";My10LetterIsogramDictionary[13] = "shockingly";My10LetterIsogramDictionary[14] = "aftershock";
    
}

/******************************************************************************************************************************/

void FBullCowGame::Reset(DifficultyLevel Difficulty)
{
    TMap <DifficultyLevel,FString> WordSelector{{Easy , My3LetterIsogramDictionary[(rand())%DictionarySize]},
                                                {Intermediate , My4LetterIsogramDictionary[(rand())%DictionarySize]},
                                                {Challenging , My5LetterIsogramDictionary[(rand())%DictionarySize]},
                                                {Tough , My6LetterIsogramDictionary[(rand())%DictionarySize]},
                                                {Hard , My7LetterIsogramDictionary[(rand())%DictionarySize]},
                                                {Nightmare , My8LetterIsogramDictionary[(rand())%DictionarySize]},
                                                {JediMaster , My9LetterIsogramDictionary[(rand())%DictionarySize]},
                                                {YouHateYourself , My10LetterIsogramDictionary[(rand())%DictionarySize]}};
    
    // random word chosen from one of three dictionaries
    MyIsogram = WordSelector[Difficulty];
    
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

/******************************************************************************************************************************/

// getter functions
int32 FBullCowGame::GetMaxTries()const
{
    TMap <int32,int32> WordLengthToMaxTries{{3,4},{4,8},{5,10},{6,15},{10,30}};
    return WordLengthToMaxTries[GetIsogramLength()];
}
FString FBullCowGame::GetHiddenIsogram()const{return MyIsogram;}
int32 FBullCowGame::GetCurrentTry()const{return MyCurrentTry;}
int32 FBullCowGame::GetIsogramLength()const{return MyIsogram.length();}
bool FBullCowGame::IsGameWon()const { return bGameIsWon; }

/******************************************************************************************************************************/

bool FBullCowGame::IsIsogram(FString Guess)
{
    
    bool alphabet[26] = {false};
    
    for(int32 i = 0; i < GetIsogramLength(); i++)
    {
        if(alphabet[(Guess[i])-'a']){return false;}
        
        alphabet[(Guess[i])-'a'] = true;
    }
    return true;
}

/******************************************************************************************************************************/

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
    if(Guess.size() != GetIsogramLength()){return EGuessStatus::Wrong_Length;}
    
    for(int32 i = 0; i < GetIsogramLength(); i++)
    {
        if( '0' <= Guess[i] && Guess[i] <= '9' ){return EGuessStatus::Has_Integers;}
        if(std::isspace(Guess[i])){return EGuessStatus::Has_Spaces;}
        if(!islower(Guess[i])){return EGuessStatus::Has_Capitals;}
    }
    
    if(!IsIsogram(Guess)){return EGuessStatus::Not_Isogram;} // IsIsogram will return true if it is an isogram, false otherwise
    
    return EGuessStatus::Guess_Is_Valid;
}

/******************************************************************************************************************************/

FBullCowResults FBullCowGame::CalculateAndReturnBullsAndCows(FString Guess)
{
    // entering this function means that a valid guess has been entered by the user and thus the current try counter should be incremented
    MyCurrentTry++;
    
    FBullCowResults BullCowValues;
    int CowLetterCounter = 0;
    int BullLetterCounter = 0;
    
    for(int32 i = 0; i < GetIsogramLength(); i++)
    {
        
        if(Guess[i] == MyIsogram[i])
        {
            BullCowValues.Bulls++;
            BullCowValues.BullLetters[BullLetterCounter++] = Guess[i];
            continue;
        }
        for(int32 j = 0; j < GetIsogramLength(); j++)
        {
            if(Guess[i] == MyIsogram[j])
            {
                BullCowValues.Cows++;
                BullCowValues.CowLetters[CowLetterCounter++] = Guess[i];
                break;
            }
        }
    }
    bGameIsWon = (BullCowValues.Bulls == MyIsogram.length());
    return BullCowValues;;
}

