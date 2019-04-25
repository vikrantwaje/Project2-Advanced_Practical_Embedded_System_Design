/***********************************************************************************
 * @file srt_sensor_data_task.c
 * @brief Contains callback function for srt_sensor_data task
 * @author Tanmay C
 * @date April 23, 2019
 *
 *****************************************************************************/
//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "srt_sensor_data_task.h"
//***********************************************************************************
//                                  Global variables
//***********************************************************************************
sensor_data_acq_t data_txrx;
srt_send_data_t srt_data;
volatile uint32_t pulse_length;
QueueHandle_t xcommunication_Queue;  //Queue for communication task
SemaphoreHandle_t xSemaphore_srt;

//extern QueueHandle_t myqueuehandle;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/***********************************************************************************

 @brief:Collect data from different sensors(soft real time)
 @param: None
 @param: None
 @return: None
 **************************************************************************************/
void srt_collect_data(){
    double temperature_value = 0;
    get_temperature(REQUEST_CELSIUS, &temperature_value);
    srt_data.temperature_sensor.temperature_value = temperature_value;
    ultrasonic_send_trigger();
    srt_data.ultrasonic_sensor.ultrasonic_value =pulse_length;
    srt_data.motion_sensor.motion_value = motion_sensor();

}

/***********************************************************************************

 @brief:Convert into string
 @param: None
 @param: None
 @return: None
 **************************************************************************************/
void srt_convert_to_string(){
/*    int16_t gyro = 0;
    uint32_t gyro_val[2];*/
    snprintf(data_txrx.temperature_val, 10, "|%lu|",(uint32_t)srt_data.temperature_sensor.temperature_value );
    snprintf(data_txrx.ultrasonic_val, 10, "|%lu|", srt_data.ultrasonic_sensor.ultrasonic_value );
    snprintf(data_txrx.motion_val, 10, "|%u|\n\r", srt_data.motion_sensor.motion_value );
    //
    /*readFloatGyroX( &gyro,gyro_val);
    snprintf(data_txrx.motion_val, 10, "|%d|\n\r", gyro );*/



}
/***********************************************************************************

 @brief:Initialise identification of different sensors
 @param: None
 @param: None
 @return: None
 **************************************************************************************/
void srt_sensor_id_init(){
    srt_data.temperature_sensor.sensor_id = TEMPERATURE_ID;
    srt_data.ultrasonic_sensor.sensor_id = ULTRASONIC_ID;
    srt_data.motion_sensor.sensor_id = MOTION_ID;

}
/***********************************************************************************

 @brief:Soft real-time sensor data communication task

 @param: None
 @param: None

 @return: None
 **************************************************************************************/
void srt_sensor_data_task(void *pvParameters)
{
    double temperature_value;
    uint32_t data = 0;
    int16_t gyro = 0;
    //uint32_t gyro_val[2];
    //char a = 'a';
    while(1)
    {
       // LCD_send_string("Vikrant Waje");

        if (xSemaphoreTake(xSemaphore_srt, (TickType_t )portMAX_DELAY) == pdTRUE){

        //Get sensor values
        srt_collect_data();

        //convert to string
        srt_convert_to_string();

        //Send the data converted into string format through the communication queue

        xQueueSend(xcommunication_Queue, (void * ) &data_txrx,(TickType_t )portMAX_DELAY);  //Send data through communication queue

        //Create packet and send it to UART on beaglebone
        //UART_create_packet_and_transmit(&data_txrx);

        //UART_send_string("Vikrant");

        //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, PWMGenPeriodGet(PWM0_BASE, PWM_GEN_2)/3); // Set Duty cycle
        //
       /* if(a=='z'){a='a';}
        LCD_send_string(&a);
        a++;*/

        //read_adc(&converted_val);
        //buzzer_on();
        //buzzer_off();


        //SysCtlDelay(10000);
        //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 300);

//        if( xSemaphoreTake( xSemaphore, ( TickType_t ) 10 ) == pdTRUE )
//        {
//        char data_buff[10];
//        snprintf(data_buff, 9, "|%d|", gyro);
//        strcpy(data_txrx.gyroscope_val, data_buff);
//

//
//        char data_buff2[20];
//        snprintf(data_buff2, 18, "|%lf|", *temperature_value);
//        strcpy(data_txrx.temperature_val, data_buff2);

/*
        char data_buff3[50];
        snprintf(data_buff3, 9, "|%d|",50srt_data.ultrasonic_sensor.ultrasonic_value);
        strcpy(data_txrx.ultrasonic_val, data_buff3);


        char data_buff1[50];
        snprintf(data_buff1, 9, "|%d|\n\r", (uint32_t)srt_data.temperature_sensor.temperature_value);
        strcpy(data_txrx.temperature_val, data_buff1);
        //
*/
        //int motion_val = motion_sensor();
//        char data_buff2[10];
//        snprintf(data_buff2, 9, "|%d|\n\r", gyro);
//        strcpy(data_txrx.gyroscope_val, data_buff2);

//        char data_buff1[6];
//    //    snprintf(data_buff1, 5,"|%d|", gyro);
//        strcpy(data_txrx.gyroscope_val, "|kota|\n\r");
//
////        char data_buff2[10];
////   //     snprintf(data_buff2, 11, "|%lf|", *temperature_value );
//        strcpy(data_txrx.temperature_val, "|Chaturvedi|\n\r");
////
////        char data_buff3[6];
////   //     snprintf(data_buff3, 6,"|%d|\n\r", pulse_length );
//        strcpy(data_txrx.ultrasonic_val, "|Tanmay|\n\r");
//

//        //        char data_buff[7];
//        sprintf(data_buff, "|%d|", motion_sensor());
//        strcpy(data_txrx.motion_val, data_buff);


//        char data_buff1[30];
//        sprintf(data_buff1, "|%d|", gyro);
//        strcpy(data_txrx.temperature_val, data_buff1);

//        char data_buff2[30];
//        sprintf(data_buff2, "|%d|\n\r", pulse_length);
//        strcpy(data_txrx.gyroscope_val, data_buff2);

//        char buffer[sizeof(sensor_data_acq_t)+1];
//        memcpy(buffer, &data_txrx, sizeof(sensor_data_acq_t));
//        UART_send_string(buffer);

/*        vTaskDelay(100);
        UART_create_packet_and_transmit(data_txrx);*/
//        xSemaphoreGive( xSemaphore );
//        }

    //
//        if(xQueueSend(myqueuehandle, &data_txrx , 20))
//        {
//            //UARTprintf("Data sent = %d\n\r", data_txrx.led_toggle_count);
//        }
//        else
//            UARTprintf("Not able to send");
//        }


    }
    }
}

