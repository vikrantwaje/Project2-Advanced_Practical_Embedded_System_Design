// Reference [1]: https://class.ece.uw.edu/474/peckol/code/BeagleBone/ForestExamples/Example_6_UART/uart1.c
// Reference [2]: https://en.wikibooks.org/wiki/Serial_Programming/termios

#include "../include/my_uart.h"

struct termios my_terminal;

const char *uart_device = BONEPATH;

int filedes; //might need to make it extern while scaling

void main()
{
	int ret_val = uart_init();
	printf("ret_val for uart_init = %d", ret_val);

	ret_val = termios_init();
	printf("ret_val for terminos_init = %d", ret_val);

	while(1)
	{
	write_to_uart();

	sleep(1);
	// }
	//ret_val = 
	read_from_uart();
	//printf("\nreading ret status = %d\n", ret_val);
	 }
}

uart_status_t uart_init()
{
	filedes = open(uart_device, O_RDWR | O_NOCTTY | O_NDELAY);
	/*
	O_RDWR: Opens the port for reading and writing
	O_NOCTTY: The port never becomes the controlling terminal of the process
	O_NDELAY: Use non-blocking I/O.
	*/

	if (filedes < 0)
	{
		perror("failed to open port, uart init failed! \n");
		return	UART_INIT_FAILED;
	}

	//check if the file descriptor is pointing to a TTY device or not
	if (!isatty(filedes))
	{
		perror("File descriptor not pointing to a tty device \n");
		return	WRONG_FILEDES;	
	}

	fcntl(filedes, F_SETFL, FNDELAY);
	return UART_STATUS_SUCCESS;
}


termios_status_t termios_init()
{
	// my_terminal = (struct termios *)malloc(sizeof(struct termios));
	// if( my_terminal == NULL )
	// {
	// 	perror("Null: Pointer to struct termios\n");
	// 	return NULL_PTR;
	// }

	//get the current configuration of the serial interface
	tcgetattr(filedes, &my_terminal);
	// if(tcgetattr(filedes, &my_terminal) < 0)
	// {
	// 	printf("Error: TCGETATTR()\n");
	// 	return TERMIOS_INIT_FAILED;
	// }

	//Input flags - Turn off input processing
	// my_terminal.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);
	my_terminal.c_iflag = 0;

	//Output flags - Turn off output procesing
	my_terminal.c_oflag &= ~OPOST;

	//No line processing
	my_terminal.c_lflag &= ~(ECHO | ECHONL | ICANON | ECHOK | ECHOE | ISIG);	

	//Turn off character processing
	my_terminal.c_cflag = (CS8 | CLOCAL | CREAD | B115200);

	my_terminal.c_cc[VMIN] = 1;

	my_terminal.c_cc[VTIME] = 5;

	// if( (cfsetispeed(&my_terminal, B115200)  ) || ( cfsetospeed(&my_terminal, B115200) ) ) 
	// {
 //    	printf("Error: Communication Speed Config Failed\n");
 //    	return TERMIOS_INIT_FAILED;
 // 	}
	tcflush(filedes, TCIFLUSH);
 	//Set the configuration attributes
 	tcsetattr(filedes, TCSANOW, &my_terminal);
 	// if(tcsetattr(filedes, TCSANOW, &my_terminal) < 0)
 	// {
 	// 	perror("Error: TCSETATTR\n");
 	// 	return TERMIOS_INIT_FAILED;
 	// }
 	return 5;
}

//Loopback Testing function
uart_status_t write_to_uart(void) 
{

	int ret_val;
	//char data[10] = 0xA;	//1010
	char data = 'A';	//1010
	if (ret_val = write(filedes, "TANMAY\r", 7) <1)
	{
		perror("Error writing data\n");
		return UART_SEND_FAILED;
	}
	else
	{
		printf("data sent success\n");
		printf("ret_val write = %d\n", ret_val);
		return UART_STATUS_SUCCESS;
	}
	return 5;
}

//Loopback Testing function
uart_status_t read_from_uart(void)
{
	int ret_val;
	char rx_data[7];
	int filedes1;
	if(ret_val = read(filedes, &rx_data, 7) <1)
	{
		perror("Error Reading data\n");
		return UART_RECEIVE_FAILED;
	}
	else
	{
		printf("data Reading success\n");
		printf("Received data = %s\n", rx_data);
		return UART_STATUS_SUCCESS;
	}
	return 5;
}
