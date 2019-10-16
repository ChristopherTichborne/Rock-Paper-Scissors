/*
    Module for selection of rock, paper, or scissors.
    'R' for rock, 'P' for paper, and 'S' for scissors.
*/

#include "system.h"
#include "navswitch.h"
char character_choice(char choice)
{

    if (navswitch_push_event_p(NAVSWITCH_EAST))    // East/Right for rock selection
    {
        choice = 'R';
    }

    if (navswitch_push_event_p(NAVSWITCH_NORTH))   // North/Up for paper selection
    {
        choice = 'P';
    }

    if (navswitch_push_event_p(NAVSWITCH_WEST))    // West/Left for scissor selection
    {
        choice = 'S';
    }

    return choice;
}
