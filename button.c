/* Button.c
 * Nic Page 41124128, Chris Tichborne 65767344
 * 16 October 2019
 * Module to set up button*/

#ifndef BUTTON_H
#define BUTTON_H

#include <avr/io.h>
#include "button.h"

#define BIT(x) (1 << (x))

/* Initialise the button*/
void button_init (void)
{
    DDRD |= (0 << 7);
}


/* Return non-zero if button pressed*/
int button_pressed_p (void)
{
    return (PIND & BIT(7));
}

#endif
