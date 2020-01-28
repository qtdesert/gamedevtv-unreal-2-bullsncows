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
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The Hidden Word is %i characters long. \n You have lost!"), HiddenWord.Len());
                EndGame();
            }
        }
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
    Lives = 4;
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter to continue...")); // Prompt Player for guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again."));
}
