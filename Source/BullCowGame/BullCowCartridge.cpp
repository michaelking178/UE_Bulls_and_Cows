// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// When the game starts
void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();

    // Welcome the player
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    PrintLine(TEXT("Please guess the secret isogram:"));
    
    SetupGame();
}

// When the player hits enter
void UBullCowCartridge::OnInput(const FString &Input)
{
    ClearScreen();
    PrintLine(TEXT("You guessed: " + Input));

    if (Input == HiddenWord) {
        PrintLine(TEXT("You are correct! YOU WIN!"));
    }
    else {
        // Check if the word is the correct length
        if (Input.Len() != HiddenWord.Len()) {
            PrintLine(TEXT("That is not the correct length!"));
            return;
        }

        // TODO: Check if the word is an isogram
        // If no: Prompt to guess again (no life deprecation)

        PlayerLives--;
        if (PlayerLives <= 0) {
            // TODO: End game if player lives <= 0    
            PrintLine("YOU LOSE!");
        }
        else {
            // TODO: If lives are still greater than 0, show remaining lives and guess again
            PrintLine(TEXT("Guess again!"));
        }
    }
    // TODO: Play again message
}

void UBullCowCartridge::SetupGame() {
    HiddenWord = TEXT("dog");
    PlayerLives = 3;
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