/* displayResults.c
 * Nic Page 41124128, Chris Tichborne 65767344
 * 16 October 2019
 * Module to display characters and results of game*/

#include "../fonts/font5x7_1.h"
#include "tinygl.h"
#include "system.h"

/*Displays a character on the LED screen*/
void display_local(char localChar)
{
    char buffer[2];
    buffer[0] = localChar;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

/*Displays a character corresponding to win status*/
void display_win_status(int gameStatus)
{
    char buffer[2];
    char winDrawLoss = ' ';

    if (gameStatus == 1) {
        winDrawLoss = 'W';
    } else if (gameStatus == 0) {
        winDrawLoss = 'L';
    } else {
        winDrawLoss = 'D';
    }

    buffer[0] = winDrawLoss;
    buffer[1] = '\0';
    tinygl_text (buffer);
}
