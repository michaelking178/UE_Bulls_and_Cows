// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    PrintLine(TEXT("Please guess the secret isogram:"));
    HiddenWord = TEXT("dog");
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    PrintLine(TEXT("You guessed: " + Input));

    if (Input == HiddenWord) {
        PrintLine(TEXT("You are correct! YOU WIN!"));
    }
    else {
        PrintLine(TEXT("You are wrong. YOU LOSE."));
    }
}



/* GAME LOOP
    1. Welcome the user
    2. Set up the game
        a. Set the HiddenWord
        b. Set the player lives
    3. Take a guess
    4. Check if the guess is correct
        a. Correct
            i. Deliver WIN message
        b. Incorrect
            i. Deliver INCORRECT message
            ii. Deprecate player lives
            iii. If lives run out, deliver LOSE message
    5. Restart or Quit
*/