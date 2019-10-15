#include "../fonts/font5x7_1.h"
#include "tinygl.h"
#include "system.h"

void display_local(char localChar)
{
    char buffer[2];
    buffer[0] = localChar;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

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
