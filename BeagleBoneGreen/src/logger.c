
/*********************************************************************************************
 *                      FILENAME: logger.c
 * *****************************************************************************************/
/*
 * @Title: logger.c
    
 * @Author: Vikrant Waje and Tanmay Chaturvedi
 * @Date: 27 April 2019
 * @Tools: vim,gcc
 */

/*********************************************************************************
 *                        HEADER FILE SECTION
 * **********************************************************************************/
#include"logger.h"

/*********************************************************************************
 *                        GLOBAL VARIABLE SECTION
 * **********************************************************************************/
struct timespec master_timestamp;




/*********************************************************************************
 *                        FUNCTION DEFINITION SECTION
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
void log_value(FILE *fptr, uint32_t value,uint8_t log_level,uint8_t *source_id){
	double time_master =0;
	clock_gettime(CLOCK_MONOTONIC,&master_timestamp);	//timestamp
	time_master =((master_timestamp.tv_sec*1000.0)+ (master_timestamp.tv_nsec/1000000.0)); //print into log file
	fptr = fopen("log.txt","a+");
	LOG(fptr,time_master,log_level,source_id,value);
	fclose(fptr);
}
