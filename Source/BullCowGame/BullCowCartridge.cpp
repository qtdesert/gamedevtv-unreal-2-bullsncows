// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the 6 letter word.")); //TODO: Magic number remove!
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("forest"); //TODO: Move outside this function
    PrintLine(Input);
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You win!"));
    }
    else
    {
        PrintLine(TEXT("You loose... Try again!"));
    }
}
