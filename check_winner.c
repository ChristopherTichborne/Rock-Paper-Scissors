/*
    Module to check winner status
*/

#include "system.h"

int check_winner(char localCharacter, char rivalCharacter)
{
    int gameStatus = 0;

    if(localCharacter != '_' || rivalCharacter != '_') {
        if(localCharacter == 'R' && rivalCharacter == 'S' ) {      // local selected rock and rival selected scissor
            gameStatus = 1;
        }

        else if(localCharacter == 'P' && rivalCharacter == 'R') {  // local selected paper and rival selected rock
            gameStatus = 1;
        }

        else if(localCharacter == 'S' && rivalCharacter == 'P' ) { // local selected scissor and rival selected paper
            gameStatus = 1;
        }

        else if(localCharacter == rivalCharacter) { // Draw
            gameStatus = 2;
        }

        else {
            gameStatus = 0;
        }
    }

    return gameStatus;
}
