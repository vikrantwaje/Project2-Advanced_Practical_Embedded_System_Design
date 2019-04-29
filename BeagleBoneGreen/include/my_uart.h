#ifndef MY_UART_H_
#define MY_UART_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include "timer.h"
#define	BONEPATH	"/dev/ttyO1"

typedef enum
{
	WRONG_FILEDES = -3,
	UART_SEND_FAILED,
	UART_RECEIVE_FAILED,
	UART_INIT_FAILED,
	UART_STATUS_SUCCESS,
	UART_READ_SUCCESS
}uart_status_t;

typedef enum
{
	NULL_PTR = -2,
	TERMIOS_INIT_FAILED,
	TERMIOS_INIT_SUCCESS
}termios_status_t;

uart_status_t uart_init(void);
// termios_status_t termios_init(struct termios *my_terminal, int filedes);
termios_status_t termios_init(void);

//loopback testing
uart_status_t write_to_uart(char *);
uart_status_t read_from_uart(char *);




#endif
