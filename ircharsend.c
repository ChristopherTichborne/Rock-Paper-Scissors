/*
    Module to send choice selected to other board via IR
*/

#include "system.h"
#include "ir_uart.h"

if (((choice == 'P' || choice == 'S' || choice == 'R') && ir_uart_write_ready_p()
            && navswitch_push_event_p(NAVSWITCH_PUSH)))
        {
            ir_uart_putc(character);
        }
