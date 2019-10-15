/*
    Module to send choice selected to other board via IR & to recieve
*/

#include "system.h"
#include "ir_uart.h"

int send_character(char choice)
{
    if (((choice == 'P' || choice == 'S' || choice == 'R') && ir_uart_write_ready_p()
            && navswitch_push_event_p(NAVSWITCH_PUSH))) {
        ir_uart_putc(character);
        return 1;
    }
    return 0;
}

char recieve_character(void)
{
    char recievedChar = '_';

    while (recievedChar != 'R' || recievedChar != 'P' || recievedChar != 'S') {
        if (ir_uart_read_ready_p ()) {
            recievedChar = ir_uart_getc ();
        }
    }

    return recievedChar;
}
