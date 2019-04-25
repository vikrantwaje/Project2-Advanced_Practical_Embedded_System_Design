/***********************************************************************************
 * @file hrt_sensor_data_task.c
 * @brief Contains callback function for Hard real time sensor task
 * @author Tanmay C
 * @date April 23, 2019
 *
 *****************************************************************************/
//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "hrt_sensor_data_task.h"
//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/***********************************************************************************

 @brief:Hard real-time sensor data communication task for detecting accident condition using gyroscope

 @param: None
 @param: None

 @return: None
 **************************************************************************************/
void hrt_sensor_data_task(void *pvParameters)
{

    int16_t gyro = 0;
    uint32_t gyro_val[2];
    bool threshold_exceed = 0;
    while(1)
    {
        readFloatGyroX( &gyro,gyro_val);
        if(gyro > THRESHOLD_ACCIDENT_MAX || gyro < THRESHOLD_ACCIDENT_MIN){

            threshold_exceed = 0;
        }
        else{

            threshold_exceed =1;
        }

    }


}

