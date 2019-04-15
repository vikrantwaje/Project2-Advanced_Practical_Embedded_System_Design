#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define	BONEPATH	"/dev/tty04"

uart_status_t uart_init(void);
termios_status_t termios_init(struct termios *my_terminal, int filedes);
int filedes; //might need to make it extern while scaling

typedef enum
{
	WRONG_FILEDES = -2,
	UART_INIT_FAILED,
	UART_STATUS_SUCCESS
}uart_status_t;

typedef enum
{
	NULL_PTR = -2,
	TERMIOS_INIT_FAILED,
	TERMIOS_INIT_SUCCESS
}termios_status_t;
