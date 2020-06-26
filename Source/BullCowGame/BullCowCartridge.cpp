// Fill out your copyright notice in the Description page of Project Settings.
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() {
    Super::BeginPlay();
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(WordList, *WordListPath);
    
    SetupGame();
    PrintLine(TEXT("Total available words: %i"), WordList.Num());
    for (int32 i = 0; i < 10; i++)
    {
        if (WordList[i].Len() >= 4 && WordList[i].Len() <= 8)
        {
            PrintLine(TEXT("%s"), *WordList[i]);
        }
    }
    PrintLine(TEXT("**DEBUG** HiddenWord is %s."), *HiddenWord);
}

void UBullCowCartridge::SetupGame() {
    HiddenWord = TEXT("powder");
    PlayerLives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    PrintLine(TEXT("Lives: %i"), PlayerLives);
    PrintLine(TEXT("Please guess the %i-letter secret isogram:"), HiddenWord.Len());

    const TCHAR HW[] = TEXT("powder");
    PrintLine(TEXT("Character 1 of the hidden word is %c"), HiddenWord[0]);
    PrintLine(TEXT("The 4th character of the HW is: %c"), HW[3]);
}

void UBullCowCartridge::OnInput(const FString &Input) {
    ClearScreen();
    if (bGameOver) {
        SetupGame();
        return;
    }
    ProcessGuess(Input);
}

void UBullCowCartridge::ProcessGuess(FString Guess) {
    PrintLine(TEXT("You guessed: " + Guess));
    if (Guess == HiddenWord) {
        PrintLine(TEXT("You are correct! YOU WIN!"));
        EndGame();
        return;
    }
    else if (Guess.Len() != HiddenWord.Len()) {
        PrintLine(TEXT("That is not the correct length!"));
        return;
    }

    if (!bIsIsogram(Guess))
    {
        PrintLine(TEXT("Your guess must be an isogram!"));
        return;
    }
    
    PlayerLives--;
    if (PlayerLives <= 0) {
        PrintLine("YOU LOSE!");
        EndGame();
        return;
    }
    PrintLine(TEXT("Wrong! Remaining Lives: %i"), PlayerLives);
    PrintLine(TEXT("Guess again!"));
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("Please press ENTER to play again..."));
}

bool UBullCowCartridge::bIsIsogram(FString guess) const {
    int32 length = guess.Len();
    for(int32 i = 0; i < length; i++) {
        for (int32 j = i + 1; j < length; j++)
        {
            if (guess[i] == guess[j]) 
            {
                return false;
            }
        }
    }
    return true;
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