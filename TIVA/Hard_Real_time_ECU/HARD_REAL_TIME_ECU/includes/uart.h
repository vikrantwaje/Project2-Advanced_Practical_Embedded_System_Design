/***********************************************************************************
 * @file uart.h
 * @brief Header file for UART peripheral of TM4C129XL.
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_
//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include<stdbool.h>
#include "clock.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "inc/hw_memmap.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "inc/hw_ints.h"
#include "synchronization.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************

//***********************************************************************************
//                              Global variables
//***********************************************************************************


//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the UART peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void UART_init(void);

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
void UART7_handler();


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Send a serial string via UART7

 @param: *data: string to be sent

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void UART_send_string(char *data);

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Create a UART data packet and send as as a string via UART7

 @param: *sensor_data_acq_t: pointer to sensor data acquisition global structure

 @return: None
 Reference: https://www.quora.com/How-do-I-pass-a-structure-through-UART-using-microcontroller-and-embedded-C
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
void UART_create_packet_and_transmit(uint8_t * );

#endif /* INCLUDES_UART_H_ */
