/*
 * button.h
 * Nic page, Chris Tichborne
 * 16 October 2019
 * Header file for button.c
*/


#ifndef BUTTON_H
#define BUTTON_H


/** Return non-zero if button pressed.  */
int button_pressed_p (void);


/** Initialise the button  */
void button_init (void);
#endif
