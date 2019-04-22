/***********************************************************************************
 * @file main.h
 * @brief Contains all header files for all peripheral. This is the only file to be included in main.c
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_MAIN_H_
#define INCLUDES_MAIN_H_
//***********************************************************************************
//                              Include files
//***********************************************************************************
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "inc/hw_types.h"
#include<stdlib.h>
#include<string.h>
#include "clock.h"
#include "myuart.h"
#include "mystack.h"
#include "myerror.h"
#include "myled.h"
#include "mythreads.h"
#include "myi2c.h"
#include "mysynchronization.h"
#include "mytemperature_sensor.h"
#include "spi.h"
#include "pwm.h"
#include "adc.h"
#include "buzzer.h"
#include "shiftregister.h"
#include "lcd.h"
#include "dcmotor.h"
#include "timer.h"
#include "ultrasonic.h"
#include "accelerometer.h"
#include "gpio.h"
#include "gyroscope.h"
#include "system.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************

//***********************************************************************************
//                              Global variables
//***********************************************************************************


//***********************************************************************************
//                              Function Prototype
//***********************************************************************************



#endif /* INCLUDES_MAIN_H_ */
