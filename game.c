/* PAPER SCISSORS ROCK
 * Nic Page 41124128, Chris Tichborne 65767344
 * 16 October 2019
 * Main game file for game.c
 *
 * SEE README FOR INSTRUCTIONS ON HOW TO PLAY
 *
 * This game first scrolls "Paper Scissors Rock" upon first loadup. Once a navswitch is pressed,
 * the game enters character selection mode. Once a character is sent, it is locked into this choice.
 * Once both boards recieve a signal, the game decides a winner or loser on each screen.
 * Both boards may then be reset with the press of the R13 button, to return to idle character select screen. */

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

#define MESSAGE_RATE 20
#define PACER_RATE 500


int main (void)
{
    /* Initialises all modules*/
    system_init ();
    button_init ();
    navswitch_init ();
    ir_uart_init ();
    led_init ();
    led_set(LED1, 0);

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_NORMAL);
    tinygl_text ("ROCK PAPER SCISSORS "); /* Scrolling text at the beginning of the game*/

    pacer_init (PACER_RATE);

    /* Initialises all useful constants, comparison variables and strings*/
    char localCharacter = '-';
    char rivalCharacter = '-';
    int localSent = 0;
    int rivalRecieved = 0;
    int gameOver = 0; /*Game won/lost check*/
    int gameStatus = 0; /*Game status Check*/
    int bannerScroll = 1; /*Checks if banner should display*/

    /*Banner scrolling code*/
    while (bannerScroll == 1) {
        pacer_wait();
        tinygl_update ();
        navswitch_update ();

        if (navswitch_push_event_p (NAVSWITCH_EAST)) {
            bannerScroll = 0;
        }
        if (navswitch_push_event_p (NAVSWITCH_WEST)) {
            bannerScroll = 0;
        }
        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            bannerScroll = 0;
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            bannerScroll = 0;
        } else {
            tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
        }
    }

    /* Main game code */
    while (1) {
        pacer_wait ();
        navswitch_update ();
        tinygl_update ();

        if (gameOver == 0) {
            if (localSent == 0) {
                localCharacter = character_choice(localCharacter); /*character_choice module*/
                localSent = send_character(localCharacter); /*IR sending and recieving module*/
                if (localSent == 1) {
                    led_set(LED1, 1);
                }
            }
            if (rivalRecieved == 0) {
                rivalCharacter = recieve_character(); /*IR sending and recieving module*/
                if (rivalCharacter == 'R' || rivalCharacter == 'P' || rivalCharacter == 'S') {
                    rivalRecieved = 1;
                }
            }
            if (localSent == 1 && rivalRecieved == 1) { /*Once both characters have been recieved*/
                gameStatus = check_winner(localCharacter, rivalCharacter); /*check_winner module*/
                led_set(LED1, 0);
                gameOver = 1;
            }
        }
        if (gameOver == 0) {
            display_local(localCharacter); /*Character Display module*/
        } else if (gameOver == 1) {
            display_win_status(gameStatus); /*Character Display module*/
        }

        /*Resets state of the game with button press*/
        if (button_pressed_p()) {
            localCharacter = '-';
            rivalCharacter = '-';
            localSent = 0;
            rivalRecieved = 0;
            gameOver = 0;
            gameStatus = 0;
            led_set(LED1, 0);
        }
    }
}
