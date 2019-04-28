/***************************************************************************************
 * @file uart.c
 * @brief This file is to be used for the setting the  UART peripheral of the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include <uart.h>
#include"main.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************
uint32_t sys_clock;
char uart_val;
uint8_t auth;
//***********************************************************************************
//                                 Function implementation
//***********************************************************************************


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: UART7 Interrrupt handler
    Pin PC4- UART7 Rx
    Pin PC5- UART7 Tx

 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/

void UART7_handler(){

    if(auth == '1'){
    uart_val = UARTCharGet(UART7_BASE);
    if(uart_val=='G' || uart_val =='U' || uart_val=='M' || uart_val=='T'|| uart_val =='A'){
    xQueueSend(xactuator_Queue, (void * ) &uart_val,(TickType_t )portMAX_DELAY);  //Send data through actuator queue
    }
    UARTCharPut(UART0_BASE, uart_val);
    }
    else{
        auth = UARTCharGet(UART7_BASE);
    }
}


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the UART peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void UART_init(void)
{
    //
    // Enable the GPIO Peripheral used by the UART.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //
    // Enable the GPIO Peripheral for inter-board communication with BBG
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);

    //
    // Enable UART0, UART(7) for BBG Communication
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);


    //
    // Configure GPIO Pins for UART mode.
    //
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinConfigure(GPIO_PC4_U7RX);
    GPIOPinConfigure(GPIO_PC5_U7TX);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);

     UARTConfigSetExpClk(UART0_BASE, sys_clock, 9600,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));
     UARTConfigSetExpClk(UART7_BASE, sys_clock, 9600,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));

    IntMasterEnable();
    IntEnable(INT_UART7);
    UARTIntEnable(UART7_BASE,UART_INT_RX | UART_INT_RT);
/*
    //
    // Use the internal 16MHz oscillator as the UART clock source.
    //
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    UARTClockSourceSet(UART7_BASE, UART_CLOCK_PIOSC);
*/
/*

    //
    // Initialize the UART for console I/O.
    //
    UARTStdioConfig(0, 9600, 16000000);

    //
    // Initialize the UART for Inter-board communication with BBG.
    //
    UARTStdioConfig(0, 9600, 16000000);
*/
}


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Send a serial string via UART7

 @param: *data: string to be sent

 @return: None
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
void UART_send_string(char *data)
{
    uint8_t i = 0;
    while(*(data + i) != '\0')
    {
        UARTCharPut(UART7_BASE, *(data + i));
        i++;
    }
}


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Receive a serial string via UART7

 @param: none

 @return: None
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
void UART_receive_data(void);



/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Create a UART data packet and send as as a string via UART7

 @param: *sensor_data_acq_t: pointer to sensor data acquisition global structure

 @return: None
 Reference: https://www.quora.com/How-do-I-pass-a-structure-through-UART-using-microcontroller-and-embedded-C
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
void UART_create_packet_and_transmit(uint8_t *struct_obj,size_t length)
{
    uint8_t * ptr = (uint8_t *)(struct_obj);
    size_t numberOfBytes = length;
    size_t i = 0;
    for(i=0;i<numberOfBytes;i++)
    {
        UARTCharPut(UART7_BASE,*(ptr + i));
        // Wait for Transmission Complete .
    }

}

