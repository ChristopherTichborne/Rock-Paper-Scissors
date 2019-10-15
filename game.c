#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "../fonts/font5x7_1.h"
#include "tinygl.h"
#include "navswitch.h"
#include "button.h"
#include "../drivers/led.h"

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

    pacer_init (PACER_RATE);

    /* Initialises all useful constants, comparison variables and strings*/
    char localCharacter = '_';
    char rivalCharacter = '_';
    int localSent = 0;
    int rivalRecieved = 0;
    int gameOver = 0; /*Game Over check*/
    int gameStatus = 0; /*Game status Check*/



    while (1) {
        pacer_wait ();
        navswitch_update ();
        tinygl_update ();

        if (gameWon == 0) {
            localCharacter = character_choice();

            if (localSent == 0) {
                send_character(localCharacter);
                led_set(LED1, 1);
                localSent = 1;
            }

            if (rivalRecieved == 0) {
                rivalCharacter = recieve_character();
                rivalRecieved = 1;
            }

            if (localSent == 1 && rivalCharacter == 1) {
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
            char localCharacter = '_';
            char rivalCharacter = '_';
            int localSent = 0;
            int rivalRecieved = 0;
            int gameOver = 0;
            int gameStatus = 0;
            led_set(LED1, 0);
        }

    }
}
