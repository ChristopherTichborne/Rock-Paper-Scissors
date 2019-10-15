#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "../fonts/font5x7_1.h"
#include "tinygl.h"
#include "navswitch.h"
#include "button.h"

#define MESSAGE_RATE 10
#define PACER_RATE 500


int main (void)
{
    /* Initialises all modules*/
    system_init ();
    button_init ();
    navswitch_init ();
    ir_uart_init ();

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);

    pacer_init (PACER_RATE);




    while (1) {
        pacer_wait ();
        navswitch_update ();
        tinygl_update ();

    }
}
