/***********************************************************************************
 * @file ultrasonic.h
 * @brief Contains ultrasonic initialisation functions
 * @author Vikrant Waje and Tanmay Chaturvedi
 * @date April 7, 2019
 *@ Reference: https://github.com/LuisAfonso95/TM4C123-Launchpad-Examples/blob/master/srf04/main.c
 *****************************************************************************/
#ifndef INCLUDES_ULTRASONIC_H_
#define INCLUDES_ULTRASONIC_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include<stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "timer.h"



//***********************************************************************************
//                                  Macros
//***********************************************************************************



//***********************************************************************************
//                              Global variables
//***********************************************************************************
//Stores the pulse length
extern volatile uint32_t pulse_length;

//Tells the main code if the a pulse is being read at the moment
extern volatile uint8_t echowait;

//***********************************************************************************
//                              Function Prototype
//***********************************************************************************

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: GPIO interrupt for ultrasonic sensor


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void measure_echo();
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the ultrasonic sensor.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void ultrasonic_init();
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Send trigger from ultrasonic sensor


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void ultrasonic_send_trigger();



#endif /* INCLUDES_ULTRASONIC_H_ */
