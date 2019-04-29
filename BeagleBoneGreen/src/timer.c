/*********************************************************************************************
 *                      FILENAME: timer.c
 * *****************************************************************************************/
/*
 * @Title:timer.c

 * @Author: Vikrant Waje
 * @Date: 27 April 2019
 * @Tools: vim,gcc
 */

/*********************************************************************************
 *                        HEADER FILE SECTION
 * **********************************************************************************/

#include"timer.h"
/*********************************************************************************
 *                        GLOBAL VARIABLES SECTION
 * **********************************************************************************/

//timespec struct for giving interval values
struct itimerspec timer_setting;
struct sigevent signal_specification;
timer_t heartbeat_timer_id;
uint8_t heartbeat_flag;
FILE *fptr;
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
void heartbeat_timer_handler(int num){

	/*	heartbeat_flag.heartbeat_temp_sensor_flag = 1;
		heartbeat_flag.heartbeat_light_sensor_flag = 1;
		heartbeat_flag.heartbeat_logger_flag =1;
		heartbeat_flag.heartbeat_server_flag =1;
	 */
	printf("\n\rFlag =%d",heartbeat_flag);
	if(heartbeat_flag == 1){

		log_value(fptr,0,6,"UART RX LINK WORKING");
		printf("\n\rUART RX LINK WORKING");
	}
	else if(heartbeat_flag == 0){
		log_value(fptr,0,6,"UART RX LINK DOWN");
		printf("\n\rUART RX LINK DOWN");

	}
	heartbeat_flag = 0;
}

/***********************************************************************************************
 * @brief Create heartbeat timer
 *
 * Responsible for generating heartbeat for each of the four thread
 * @param null
 *
 * @return bool: Indicates whether intiialisation was successfull or not
 *********************************************************************************************/
bool create_heartbeat_timer(){

	signal_specification.sigev_notify = SIGEV_THREAD;
	signal_specification.sigev_notify_function = &heartbeat_timer_handler;
	signal_specification.sigev_value.sival_ptr = "Heartbeat timer";
	timer_create(CLOCK_REALTIME,&signal_specification,&heartbeat_timer_id);
	timer_setting.it_value.tv_sec =1;
	timer_setting.it_value.tv_nsec = 0;
	timer_setting.it_interval.tv_sec =6 ;
	timer_setting.it_interval.tv_nsec = 0;
	timer_settime(heartbeat_timer_id,0,&timer_setting,NULL);
	return 0;
}
