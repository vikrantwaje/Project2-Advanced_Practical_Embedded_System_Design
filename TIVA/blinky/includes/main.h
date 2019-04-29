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
//#include "driverlib/gpio.h"
//#include "driverlib/rom.h"
//#include "driverlib/sysctl.h"
//#include "driverlib/uart.h"
//#include "utils/uartstdio.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "inc/hw_types.h"
#include<stdlib.h>
#include<string.h>
#include "myuart.h"
#include "mystack.h"
#include "myerror.h"
#include "myclock.h"
#include "mygpio.h"
#include "myled.h"
#include "mysystem.h"
#include "mythreads.h"
#include "myi2c.h"
#include "mysynchronization.h"
#include "mytemperature_sensor.h"
#include "mytimer.h"

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
