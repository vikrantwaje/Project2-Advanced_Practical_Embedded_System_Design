// Reference [1]: https://class.ece.uw.edu/474/peckol/code/BeagleBone/ForestExamples/Example_6_UART/uart1.c
// Reference [2]: https://en.wikibooks.org/wiki/Serial_Programming/termios

#include "../include/my_uart.h"
#include"timer.h"
struct termios my_terminal;

const char *uart_device = BONEPATH;
uint8_t heartbeat_flag;

int filedes; //might need to make it extern while scaling
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
   @brief: Setup the UART peripheral based on /dev/ttyO1.
   UART1_TXD - pin 24
   UART1_RXD - pin 25
   @param:None

   @return: None
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
uart_status_t uart_init()
{
	filedes = open(uart_device, O_RDWR,O_SYNC,O_NOCTTY );
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

	fcntl(filedes, F_SETFL, 0);
	return UART_STATUS_SUCCESS;
}


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
   @brief: Configure UART related parameters on the UART peripheral based on /dev/ttyO1 using termios UNIX API
   UART1_TXD - pin 24
   UART1_RXD - pin 25
   @param:None

   @return: None
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
termios_status_t termios_init()
{
	//get the current configuration of the serial interface
	tcgetattr(filedes, &my_terminal);
	//Input flags - Turn off input processing
	my_terminal.c_iflag = 0;

	//Output flags - Turn off output procesing
	my_terminal.c_oflag &= ~OPOST;

	//No line processing
	my_terminal.c_lflag &= ~(ECHO | ECHONL | ICANON | ECHOK | ECHOE | ISIG);	

	//Turn off character processing
	my_terminal.c_cflag = (CS8 | CLOCAL | CREAD | B9600);

	my_terminal.c_cc[VMIN] = 1;

	my_terminal.c_cc[VTIME] = 0;

	tcflush(filedes, TCIFLUSH);

	//Set the configuration attributes
	tcsetattr(filedes, TCSANOW, &my_terminal);

	return TERMIOS_INIT_SUCCESS;
}


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
   @brief: UART Loopback testing - serial write function
   UART1_TXD - pin 24
   UART1_RXD - pin 25
   @param:None

   @return: None
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
uart_status_t write_to_uart(char * ptr) 
{

	int ret_val;
	//char data[10] = 0xA;	//1010
	//char data[20] = "TANMAY\n\r";	//1010
	if (ret_val = write(filedes, ptr,3) <1)
	{
		perror("Error writing data\n");
		return UART_SEND_FAILED;
	}
	else
	{
		//	printf("data sent success\n");
		//	printf("ret_val write = %d\n", ret_val);
		return UART_STATUS_SUCCESS;
	}
	return 5;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
   @brief: UART Loopback testing - serial read function
   UART1_TXD - pin 24
   UART1_RXD - pin 25
   @param:None

   @return: None
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
uart_status_t read_from_uart(char *ptr)
{
	int ret_val;
	int filedes1;
	memset(ptr,0,10);	//Clear the buffer before receiving data
//	heartbeat_flag = 0;
	if(ret_val = read(filedes, ptr, 10) <1)
	{
		perror("Error Reading data\n");
		return UART_RECEIVE_FAILED;
	}
	else
	{

		//	printf("\n\r%c",*(ptr + 1));
		/*	if(*(rx_data + 0)=='|' &&  *(rx_data +1) == 'g'){
			printf("\n\rGyroscope");
			}
			else if(*(rx_data + 0)=='|' && *(rx_data +1) == 't'){
			printf("\n\rTemperature");
			}
			else if(*(rx_data + 1)=='|' && *(rx_data +2) == 'u'){
			printf("\n\rUltrasonic");
			}
			else if(*(rx_data + 1)=='|' && *(rx_data +2) == 'm'){
			printf("\n\rmotion");
			}
		 */

		//	printf("data Reading success\n");
//				printf("%s", ptr);

	heartbeat_flag = 1;
	
	return UART_STATUS_SUCCESS;
	}
	//return UART_READ_SUCCESS;
}


// Main function
/*void main()
{
	char *ptr = malloc(sizeof(char) * 40);
	char *tempptr = malloc(sizeof(char) * 40);
	char output[6];
	char temp_buffer[2];
	int temperature = 0;
	char ultrasonic_buffer[5];
	int ultrasonic = 0;
	char gyro_buffer[1];
	char motion_buffer[1];
	uint16_t i =0;
	int ret_val = uart_init();

	printf("ret_val for uart_init = %d", ret_val);

	ret_val = termios_init();
	printf("ret_val for terminos_init = %d", ret_val);

	while(1)
	{
			
		do{

		read_from_uart(ptr);
		if(*(ptr + 0)!='|'){
	//		printf("\n\rNot synchronised");
	//	sleep(1.3);
		}

		}while(*(ptr + 0)!='|');

		read_from_uart(ptr);

		switch(*(ptr )){

			case 'g':
				read_from_uart(&gyro_buffer[0]);
				if(gyro_buffer[0]=='1') 
				output[0] ='G';
				else
				output[0]='g';
				printf("\n\rGyro =%c",output[0]);
				break;
			case 't':
				read_from_uart(&temp_buffer[0]);
				read_from_uart(&temp_buffer[1]);
				temperature=atoi(temp_buffer);
				if(temperature>=28)
				output[0] ='T';
				else
				output[0]='t';
				printf("\n\rTemperature=%d",temperature);
				break;
			case 'u':
				read_from_uart(&ultrasonic_buffer[0]);
				read_from_uart(&ultrasonic_buffer[1]);
				read_from_uart(&ultrasonic_buffer[2]);
				read_from_uart(&ultrasonic_buffer[3]);
				read_from_uart(&ultrasonic_buffer[4]);
				ultrasonic=atoi(ultrasonic_buffer);
				
				if(ultrasonic>10000)
				output[0] ='U';
				else
				output[0] = 'u';
				printf("\n\rultrasonic =%d",ultrasonic);
				break;
			case 'm':
				
				read_from_uart(&motion_buffer[0]);
				if(motion_buffer[0]=='1') 
				output[0] ='M';
				else
				output[0]='m';
				printf("\n\rmotion =%c",output[0]);
				break;
			default:
				memset(output,0,6);
		}
		output[1]='\n';
		output[2]='\r';
		write_to_uart(output);

	}
}*/



