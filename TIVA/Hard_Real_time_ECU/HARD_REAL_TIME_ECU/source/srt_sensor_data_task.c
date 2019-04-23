/*
 * srt_sensor_data_task.c
 *
 *  Created on: 22 Apr 2019
 *      Author: Tanmay Chaturvedi & Vikrant Waje
 */

#include "main.h"

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
        UARTprintf("\n\rGyro val = %d",gyro);

        //UARTprintf("\n\r%d %d",gyro_val[0],gyro_val[1]);
        //SysCtlDelay(100);
        //accelerometer_read_axis(&x, &y, &z);
        //UARTprintf("\n\rx = %d, y =%d, z =%d",x,y,z);
        //spi_write(0x55,0x37);

        /*Read data from ultrasonic sensor and print values on debug console*/
        ultrasonic_send_trigger();
        UARTprintf("\n\rPulse length = %d",pulse_length);

       /* Read data from PIR sensor and print values on debug console*/
        UARTprintf("\n\rMotion detected = %d",motion_sensor());
        SysCtlDelay(1000);                                       //Insert delay of atleast 10us

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
    }
}
