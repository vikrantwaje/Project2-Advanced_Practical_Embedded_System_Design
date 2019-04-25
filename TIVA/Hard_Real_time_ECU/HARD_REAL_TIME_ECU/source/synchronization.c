/***************************************************************************************
 * @file mysynchronization.c
 * @brief This file is to be used for creating , closing and functions related to queue.
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include <synchronization.h>


//***********************************************************************************
//                                  Global variables
//***********************************************************************************
QueueHandle_t xcommunication_Queue; //Communication Queue
QueueHandle_t xhrt_Queue;   //Hard real time task queue

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Create a communication queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void create_communication_queue(){
    xcommunication_Queue = xQueueCreate( 30, sizeof( sensor_data_acq_t ) );
    if( xcommunication_Queue == NULL )
       {
           /* Queue was not created and must not be used. */
       }

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  brief:Delete the logger queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void delete_logger_queue(){
    vQueueDelete( xcommunication_Queue);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Create a hard real time task queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void create_hrt_queue(){
    xhrt_Queue = xQueueCreate( 20, (sizeof(char)*10) );
    if( xhrt_Queue == NULL )
       {
           /* Queue was not created and must not be used. */
       }

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  brief:Delete the hard real time task queue


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void delete_hrt_queue(){
    vQueueDelete( xhrt_Queue);

}
