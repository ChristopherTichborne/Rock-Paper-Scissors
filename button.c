/* Button.c
 * Nic Page, Chris Tichborne
 * 16 October 2019
 * Module to set up button*/


#ifndef BUTTON_H
#define BUTTON_H

#include <avr/io.h>
#include "button.h"

#define BIT(x) (1 << (x))

/* Return non-zero if button pressed*/
int button_pressed_p (void)
{
    return (PIND & BIT(7));
}


/* Initialise the button*/
void button_init (void)
{
    DDRD |= (0 << 7);
}

#endif
