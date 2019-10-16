#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "../fonts/font5x7_1.h"
#include "tinygl.h"
#include "navswitch.h"
#include "button.h"
#include "../drivers/led.h"
#include "character_choice.h"
#include "check_winner.h"
#include "displayResults.h"
#include "ircharsend.h"

#define MESSAGE_RATE 10
#define PACER_RATE 500


int main (void)
{
    /* Initialises all modules*/
    system_init ();
    button_init ();
    navswitch_init ();
    ir_uart_init ();
    led_init ();

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_NORMAL);
    tinygl_text ("ROCK PAPER SCISSORS ");

    pacer_init (PACER_RATE);

    /* Initialises all useful constants, comparison variables and strings*/
    char localCharacter = '_';
    char rivalCharacter = '_';
    int localSent = 0;
    int rivalRecieved = 0;
    int gameOver = 0; /*Game Over check*/
    int gameStatus = 0; /*Game status Check*/
    led_set(LED1, 0);
    int gameStart = 1;

    while (gameStart == 1) {
        pacer_wait();
        tinygl_update ();
        navswitch_update ();

        if (navswitch_push_event_p (NAVSWITCH_EAST)) {
            gameStart = 0;
        }
        if (navswitch_push_event_p (NAVSWITCH_WEST)) {
            gameStart = 0;
        }
        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            gameStart = 0;
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            gameStart = 0;
        } else {
            tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
        }
    }



    while (1) {
        pacer_wait ();
        navswitch_update ();
        tinygl_update ();

        if (gameOver == 0) {
            if (localSent == 0) {
                localCharacter = character_choice(localCharacter);
                localSent = send_character(localCharacter);
                if (localSent == 1) {
                    led_set(LED1, 1);
                }
            }

            if (rivalRecieved == 0) {
                rivalCharacter = recieve_character();
                if (rivalCharacter == 'R' || rivalCharacter == 'P' || rivalCharacter == 'S') {
                    rivalRecieved = 1;
                }
            }

            if (localSent == 1 && rivalRecieved == 1) {
                gameStatus = check_winner(localCharacter, rivalCharacter);
                led_set(LED1, 0);
                gameOver = 1;

            }
        }

        if (gameOver == 0) {
            display_local(localCharacter);
        } else if (gameOver == 1) {
            display_win_status(gameStatus);
        }

        if (button_pressed_p()) {
            localCharacter = '_';
            rivalCharacter = '_';
            localSent = 0;
            rivalRecieved = 0;
            gameOver = 0;
            gameStatus = 0;
            led_set(LED1, 0);
        }
    }
}
