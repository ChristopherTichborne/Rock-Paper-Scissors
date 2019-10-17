/*
 * ircharsend.h
 * Nic Page 41124128, Chris Tichborne 65767344
 * 16 October 2019
 * Header file for ircharsend.c
*/

#ifndef IRCHARSEND_H
#define IRCHARSEND_H

#include "system.h"

/* Send character choice to rival board and set choice sent flag high */
int send_character(char choice);

/* Retrieve character choice from rival board as char*/
char recieve_character(void);

#endif
