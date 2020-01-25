// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    PrintLine(TEXT("Please enter your name:"));
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("dog");
    PrintLine(Input);
}



/* GAME LOOP
    1. Welcome the user
    2. Set the HiddenWord
    3. Take a guess
    4. Check if the guess is correct
    5. Win or Lose
*/