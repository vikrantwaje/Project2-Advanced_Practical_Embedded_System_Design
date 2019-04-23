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
// Task includes
#include "srt_sensor_data_task.h"
#include "hrt_sensor_data_task.h"
#include "actuator_task.h"
#include "data_communication_task.h"

// FreeRTOS includes
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
//***********************************************************************************
//                                  Macros
//***********************************************************************************

//***********************************************************************************
//                              Global variables
//***********************************************************************************


//***********************************************************************************
//                              Function Prototype
//***********************************************************************************


//***********************************************************************************
//                              Return type Enums
//***********************************************************************************

typedef enum
{
    HRT_SENSOR_TASK_CREATE_FAILED,      //Gyro sensor used for Hard Real-Time Sensing-Actuation Purposes
    SRT_SENSOR_TASK_CREATE_FAILED,      //Soft Real-Time
    COMMUNICATION_TASK_CREATE_FAILED,
    ACTUATOR_TASK_CREATE_FAILED,
    PROGRAM_SUCCESS
}return_type_t;

#endif /* INCLUDES_MAIN_H_ */
