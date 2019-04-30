
/*********************************************************************************************
 *                      FILENAME: logger.h
 * *****************************************************************************************/
/*
 * @Title: logger.h
 * @brief: Responsible for logging
 * @Author: Vikrant Waje
 * @Date: 27 April 2019
 * @Tools: vim,gcc
 */

/*********************************************************************************
 *                        HEADER FILE SECTION
 * **********************************************************************************/
#include<stdio.h>
#include<time.h>
#include<stdint.h>
#include<stdlib.h>

/*********************************************************************************
 *                        GLOBAL VARIABLES SECTION
 * **********************************************************************************/
extern FILE *fptr;
#define LOG(fptr,time,log_level,source_id,sensor_value) fprintf(fptr,"\n %c%lf%c [%s]:		LOGLEVEL:%d SENSOR VALUE: %u ",'[',time,']',source_id,log_level,sensor_value); //Log into the file

/*********************************************************************************
 *                        FUNCTION PROTOTYPE SECTION
 * **********************************************************************************/

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
   @brief: Log the values into file.
   @param:fptr: File in which data is to be logged
          value: sensor data value
   	  log_level: Level of logging
   	   source_id: Identification of each sensor

   @return: None
 */
/*------------------------------------------------------------------------------------------------------------------------------------*/
void log_value(FILE *fptr, uint32_t value,uint8_t log_level,uint8_t *source_id);

