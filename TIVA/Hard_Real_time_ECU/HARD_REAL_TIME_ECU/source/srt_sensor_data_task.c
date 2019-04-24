/*
 * srt_sensor_data_task.c
 *
 *  Created on: 22 Apr 2019
 *      Author: Tanmay Chaturvedi & Vikrant Waje
 */

#include "main.h"


sensor_data_acq_t data_txrx;
extern QueueHandle_t myqueuehandle;

/*
 @brief: Soft real-time sensor data communication task

 @param: None

 @return: None
 */
void srt_sensor_data_task(void *pvParameters)
{
    float converted_val;
    uint32_t data = 0;
    int16_t gyro = 0;
    uint32_t gyro_val[2];
    spi_status_t status;
    for (;;)
    {


        /*Activating buzzer*/
        buzzer_on();


        /*Read data from gyro and print values on debug console*/
        readFloatGyroX( &gyro,gyro_val);
        //UARTprintf("\n\rGyro val = %d",gyro);

        //UARTprintf("\n\r%d %d",gyro_val[0],gyro_val[1]);
        //SysCtlDelay(100);
        //accelerometer_read_axis(&x, &y, &z);
        //UARTprintf("\n\rx = %d, y =%d, z =%d",x,y,z);
        //spi_write(0x55,0x37);

        /*Read data from ultrasonic sensor and print values on debug console*/
        ultrasonic_send_trigger();
       // UARTprintf("\n\rPulse length = %d",pulse_length);

       /* Read data from PIR sensor and print values on debug console*/
//        UARTprintf("\n\rMotion detected = %d",motion_sensor());
        SysCtlDelay(100);                                       //Insert delay of atleast 10us

        //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, PWMGenPeriodGet(PWM0_BASE, PWM_GEN_2)/3); // Set Duty cycle
        //
        //if(a=='z'){a='a';}
        //LCD_send_string(&a);
        //a++;

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

