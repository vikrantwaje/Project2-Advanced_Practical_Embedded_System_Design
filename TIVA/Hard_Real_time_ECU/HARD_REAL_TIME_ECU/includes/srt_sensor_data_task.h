/***********************************************************************************
 * @file srt_sensor_data_task.h
 * @brief Contains callback function for srt_sensor_data task
 * @author Tanmay C
 * @date April 23, 2019
 *
 *****************************************************************************/

#ifndef INCLUDES_SRT_SENSOR_DATA_TASK_H_
#define INCLUDES_SRT_SENSOR_DATA_TASK_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include <stdio.h>
#include "synchronization.h"
#include "ultrasonic.h"
#include "temperature.h"
#include "motionsensor.h"
#include<string.h>
#include<uart.h>


//***********************************************************************************
//                                  Macros
//***********************************************************************************


//***********************************************************************************
//                              Global variables
//***********************************************************************************

//Sensor identification
typedef enum{
    TEMPERATURE_ID = 0,
    ULTRASONIC_ID = 1,
    MOTION_ID = 2
}sensor_id_t;


    //The structure is supposed to be used when passing the data to beaglebone
    // sensor id is unique and reserved for each of the sensor
    //Beaglebone green will read sensor id and depending on
    // the value of sensor id will extract the number of data bytes
    //Sensor id is used just to identify the source of data(sensor)

typedef struct{
    //Structure for temperature sensor
     struct {
        sensor_id_t sensor_id ;
        double temperature_value;
    }temperature_sensor;

    //Structure for ultrasonic sensor
     struct {
        sensor_id_t sensor_id;
        uint32_t ultrasonic_value;
    }ultrasonic_sensor;

    //Structure for motion sensor
     struct {
        sensor_id_t sensor_id;
        bool motion_value;
    }motion_sensor;

}srt_send_data_t;

//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/***********************************************************************************

 @brief:Initialise identification of different sensors
 @param: None
 @param: None
 @return: None
 **************************************************************************************/
void srt_sensor_id_init();

/***********************************************************************************

 @brief:Convert into string
 @param: None
 @param: None
 @return: None
 **************************************************************************************/
void srt_convert_to_string();

/***********************************************************************************

 @brief:Collect data from different sensors(soft real time)
 @param: None
 @param: None
 @return: None
 **************************************************************************************/
void srt_collect_data();

/***********************************************************************************

 @brief:Soft real-time sensor data communication task

 @param: None
 @param: None

 @return: None
 **************************************************************************************/

void srt_sensor_data_task(void *pvParameters);




#endif /* INCLUDES_SRT_SENSOR_DATA_TASK_H_ */
