/*
 * displayResults.h
 * Nic Page 41124128, Chris Tichborne 65767344
 * 16 October 2019
 * Header file for displayResults.c
*/


#ifndef DISPLAYRESULTS_H
#define DISPLAYRESULTS_H

#include "system.h"

/*Displays a character on the LED screen*/
void display_local(char localChar);

/*Displays a character corresponding to win status*/
void display_win_status(int gameStatus);

#endif

