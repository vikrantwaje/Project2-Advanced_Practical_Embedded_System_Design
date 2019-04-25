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
sensor_data_acq_t data_txrx;
hrt_send_data_t hrt_data;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/***********************************************************************************

 @brief:Initialise identification of different sensors
 @param: None
 @param: None
 @return: None
 **************************************************************************************/
void hrt_sensor_id_init(){
    hrt_data.gyroscope_sensor.sensor_id = GYROSCOPE_ID;


}
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
    while(1);
    //{
/*        readFloatGyroX( &gyro,gyro_val);
        if(gyro > THRESHOLD_ACCIDENT_MAX || gyro < THRESHOLD_ACCIDENT_MIN){
            //stop the motor
            threshold_exceed = 1;
            //snprintf(data_txrx.gyroscope_val, 10, "|%u|\n\r", threshold_exceed );
           // UART_create_packet_and_transmit(&data_txrx);
        }
        else{

            threshold_exceed = 0;
            //snprintf(data_txrx.gyroscope_val, 10, "|%u|\n\r", threshold_exceed );
            //UART_create_packet_and_transmit(&data_txrx);

        }*/

    //}


}

