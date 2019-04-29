/***********************************************************************************
 * @file mysynchronization.h
 * @brief Contains queue and synchronization structures
 * @author Vikrant Waje
 * @date April 7, 2018
 *
 *****************************************************************************/

#ifndef INCLUDES_MYSYNCHRONIZATION_H_
#define INCLUDES_MYSYNCHRONIZATION_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include "FreeRTOS.h"
#include "queue.h"
#include"semphr.h"
#include "mythreads.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************
typedef struct{
    TickType_t timestamp;
    uint8_t custom_message[30];
    double thread_specific_data;
    task_id id;
}log_msg_t;


//***********************************************************************************
//                              Global variables
//***********************************************************************************
extern QueueHandle_t xLogger_Queue;
extern xSemaphoreHandle logger_mutex; // The mutex that protects concurrent access of UART from multiple tasks.
extern SemaphoreHandle_t xSemaphore_led;
extern SemaphoreHandle_t xSemaphore_temperature;
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


#endif /* INCLUDES_MYSYNCHRONIZATION_H_ */
