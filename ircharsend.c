/* ircharsend.c
 * Nic page 41124128, Chris Tichborne 65767344
 * 16 October 2019
 * Module that handles IR communications
*/

#include "system.h"
#include "ir_uart.h"
#include "navswitch.h"

/* Function for sending characters*/
int send_character(char choice)
{
    if (((choice == 'P' || choice == 'S' || choice == 'R') && ir_uart_write_ready_p()
            && navswitch_push_event_p(NAVSWITCH_PUSH))) {
        ir_uart_putc(choice);
        return 1;
    }

    return 0;
}

/* Fucntion for recieving characters*/
char recieve_character(void)
{
    char recievedChar = '-';

    if (recievedChar != 'R' || recievedChar != 'P' || recievedChar != 'S') {
        if (ir_uart_read_ready_p ()) {
            recievedChar = ir_uart_getc ();
        }
    }

    return recievedChar;
}
