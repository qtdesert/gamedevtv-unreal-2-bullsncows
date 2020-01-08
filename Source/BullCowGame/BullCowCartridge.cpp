// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Welcoming the Player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the 6 letter word.")); //TODO: Magic number remove!
    PrintLine(TEXT("Press enter to continue..."));
    
    SetupGame();

    // Prompt Player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checking PlayerGuess

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You win!"));
    }
    else
    {
        PrintLine(TEXT("You loose... Try again!"));
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
    HiddenWord = TEXT("forest");
    Lives = 4;
}
