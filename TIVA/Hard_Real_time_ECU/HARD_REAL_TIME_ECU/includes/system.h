/***********************************************************************************
 * @file system.h
 * @brief Contains commonly implemented error routine
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_SYSTEM_H_
#define INCLUDES_SYSTEM_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include "clock.h"
#include "spi.h"
#include "shiftregister.h"
#include "lcd.h"
#include "dcmotor.h"
#include "timer.h"
#include "ultrasonic.h"
#include "accelerometer.h"
#include "gpio.h"
#include "gyroscope.h"
#include "i2c.h"
#include "led.h"
#include "uart.h"
#include "synchronization.h"

#include "srt_sensor_data_task.h"
#include "hrt_sensor_data_task.h"


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
  @brief: Initialise all the peripherals required for system operation.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void system_init();


#endif /* INCLUDES_SYSTEM_H_ */
