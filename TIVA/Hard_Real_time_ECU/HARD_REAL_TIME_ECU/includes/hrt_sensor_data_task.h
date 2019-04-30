/***********************************************************************************
 * @file hrt_sensor_data_task.h
 * @brief Contains callback function for Hard real time sensor task
 * @author Tanmay C
 * @date April 23, 2019
 *
 *****************************************************************************/

#ifndef INCLUDES_HRT_SENSOR_DATA_TASK_H_
#define INCLUDES_HRT_SENSOR_DATA_TASK_H_
//***********************************************************************************
//                              Include files
//***********************************************************************************
#include "gyroscope.h"
#include "synchronization.h"
#include "srt_sensor_data_task.h"
//***********************************************************************************
//                                  Macros
//***********************************************************************************
#define THRESHOLD_ACCIDENT_MAX (500)
#define THRESHOLD_ACCIDENT_MIN (90)
#define  GYROSCOPE_ID           (3)

//***********************************************************************************
//                              Global variables
//***********************************************************************************


typedef struct{

    //Structure for gyro sensor
     struct {
        uint8_t sensor_id;
        bool gyroscope_val;
    }gyroscope_sensor;

}hrt_send_data_t;

extern char gyroscope_val[10];     //Buffer to store gyroscope string

//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/***********************************************************************************

 @brief:Initialise identification of different sensors
 @param: None
 @param: None
 @return: None
 **************************************************************************************/
void hrt_sensor_id_init();
/***********************************************************************************

 @brief:Hard real-time sensor data communication task for detecting accident condition using gyroscope

 @param: None
 @param: None

 @return: None
 **************************************************************************************/

void hrt_sensor_data_task(void *pvParameters);




#endif /* INCLUDES_HRT_SENSOR_DATA_TASK_H_ */
