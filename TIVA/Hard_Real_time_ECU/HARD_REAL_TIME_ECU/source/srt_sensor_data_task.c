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
//extern QueueHandle_t myqueuehandle;

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/***********************************************************************************
/*
 @brief:Soft real-time sensor data communication task

 @param: None
 @param: None

 @return: None
 **************************************************************************************/
void srt_sensor_data_task(void *pvParameters)
{
    double *temperature_value = malloc(sizeof(double));
    uint32_t data = 0;
    int16_t gyro = 0;
    uint32_t gyro_val[2];
    //char a = 'a';
    LCD_send_string("Vikrant Waje");
    for (;;)
    {

        get_temperature(REQUEST_CELSIUS, temperature_value);
        /*Read data from ultrasonic sensor and print values on debug console*/
        ultrasonic_send_trigger();
       // UARTprintf("\n\rPulse length = %d",pulse_length);

       /* Read data from PIR sensor and print values on debug console*/
//        UARTprintf("\n\rMotion detected = %d",motion_sensor());
        SysCtlDelay(100);                                       //Insert delay of atleast 10us

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

//        char data_buff[7];
//        sprintf(data_buff, "|%d|\n\r", motion_sensor());
//        strcpy(data_txrx.motion_val, data_buff);

        strcpy(data_txrx.motion_val, "1\n\r");
        strcpy(data_txrx.gyroscope_val, "Gyro\n\r");
        strcpy(data_txrx.temperature_val, "temp_val\n\r");

//        char data_buff[7];
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

        UART_create_packet_and_transmit(data_txrx);
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

