// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
    
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Check PlayerGuess
    {
        ProcessGuess(Input);
    }

    // Check if Isogram
    // Prompt to Guess again
    // Check right number of characters
    // Prompt to Guess again

    // Remove life
    
    // Check if Lives > 0
    // If Yes GuessAgain
    // Show lives left
    // If No show GameOver and HiddenWord?
    // Prompt to Play again, Press Enter to Play again?
    // Check User input
    // PlayAgain or Quit
}

void UBullCowCartridge::SetupGame()
{
    // Welcoming the Player
    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("forest");
    Lives = HiddenWord.Len();
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue...")); // Prompt Player for guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
    }
    else
    {
        PrintLine(TEXT("Lost a life!"));
        PrintLine(TEXT("%i"), --Lives);
        if (Lives > 0)
        {
            if (Guess.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("Sorry, try guessing again! \n You have %i lives left."), Lives);
            }
        }
        else
        {
            PrintLine(TEXT("You have no lives left!"));
            EndGame();
        }
    }
}
