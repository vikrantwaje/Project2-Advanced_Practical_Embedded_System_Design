/***************************************************************************************
 * @file myuart.c
 * @brief This file is to be used for the setting the  UART peripheral of the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include"myuart.h"


//***********************************************************************************
//                                  Global variables
//***********************************************************************************
uint32_t sys_clock;


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
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

    //
    // Configure GPIO Pins for UART mode.
    //
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinConfigure(GPIO_PC4_U7RX);
    GPIOPinConfigure(GPIO_PC5_U7TX);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);


    //
    // Use the internal 16MHz oscillator as the UART clock source.
    //
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    UARTClockSourceSet(UART7_BASE, UART_CLOCK_PIOSC);

    //
    // Initialize the UART for console I/O.
    //
    UARTStdioConfig(0, 9600, 16000000);

    //
    // Initialize the UART for Inter-board communication with BBG.
    //
    UARTStdioConfig(0, 115200, 16000000);
}
