/***********************************************************************************
 * @file synchronization.h
 * @brief Contains queue and synchronization structures
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_SYNCHRONIZATION_H_
#define INCLUDES_SYNCHRONIZATION_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include "FreeRTOS.h"
#include "queue.h"
#include"semphr.h"
#include "threads.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************
typedef struct{
    TickType_t timestamp;
    uint8_t custom_message[30];
    double thread_specific_data;
    task_id id;
}log_msg_t;



typedef struct sensor_data_acq
{
    char temperature_val[10];
    char ultrasonic_val[10];
    char motion_val[10];

}sensor_data_acq_t;

//***********************************************************************************
//                              Global variables
//***********************************************************************************
extern xSemaphoreHandle lcd_mutex; //mutex for lcd protection

extern QueueHandle_t myqueuehandle;

//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Create a logger queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void create_logger_queue();


#endif /* INCLUDES_SYNCHRONIZATION_H_ */
