/*********************************************************************************************
 *                      FILENAME: timer.h
 * *****************************************************************************************/
/*
 * @Title: timer.h
    
 * @Author: Vikrant Waje and Tanmay Chaturvedi
 * @Date: 27 April 2019
 * @Tools: vim,gcc
 */

/*********************************************************************************
 *                        HEADER FILE SECTION
 * **********************************************************************************/
#include<time.h>
#include<stdint.h>
#include<signal.h>
#include<stdbool.h>
#include "logger.h"
#include"my_uart.h"
/*********************************************************************************
 *                        	GLOBAL VARIABLE SECTION
 * **********************************************************************************/
extern uint8_t heartbeat_flag;

/******************************************************************************        
  FUNCTION DEFINITION SECTION
 * **********************************************************************************/

/***********************************************************************************************
 * @brief heartbeat timer handler
 *
 * Handler that executes periodically to generate heartbeat interval
 * @param null
 *
 * @return null
 *********************************************************************************************/
void heartbeat_timer_handler(int num);

/***********************************************************************************************
 * @brief Create heartbeat timer
 *
 * Responsible for generating heartbeat for each of the four thread
 * @param null
 *
 * @return bool: Indicates whether intiialisation was successfull or not
 *********************************************************************************************/
bool create_heartbeat_timer();


