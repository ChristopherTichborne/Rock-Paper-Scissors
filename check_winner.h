/*
 * check_winner.h
 * Nic page, Chris Tichborne
 * 16 October 2019
 * Header file for check_winner.c
*/


#ifndef CHECK_WINNER_H
#define CHECK_WINNER_H

#include "system.h"

/* Sets game status flag to win, loss, or draw and returns as int */
int check_winner(char localCharacter, char rivalCharacter);

#endif
