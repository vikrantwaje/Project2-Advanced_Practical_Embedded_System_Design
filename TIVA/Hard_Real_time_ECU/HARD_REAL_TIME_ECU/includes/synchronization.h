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
   // char gyroscope_val[10];


}sensor_data_acq_t;



//***********************************************************************************
//                              Global variables
//***********************************************************************************
extern xSemaphoreHandle lcd_mutex; //mutex for lcd protection
extern QueueHandle_t xcommunication_Queue;  //Queue for communication task
extern QueueHandle_t xhrt_Queue;  //Queue for hard real time task
extern QueueHandle_t xactuator_Queue;  //Queue for hard real time task

extern QueueHandle_t myqueuehandle;

extern SemaphoreHandle_t xSemaphore_srt;
extern SemaphoreHandle_t xSemaphore_hrt;

//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Create a communication queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void create_communication_queue();

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Create a hard real time task queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void create_hrt_queue();


/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  brief:Delete the hard real time task queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void delete_hrt_queue();
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Create a actuator task queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void create_actuator_queue();
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  brief:Delete the actuator task queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void delete_actuator_queue();

#endif /* INCLUDES_SYNCHRONIZATION_H_ */
