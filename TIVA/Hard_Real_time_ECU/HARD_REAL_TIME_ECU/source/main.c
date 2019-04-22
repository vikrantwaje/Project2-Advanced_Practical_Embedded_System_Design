/************************************************************************************
 * @file main.c
 * @brief Contains main function
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 ************************************************************************************/

//***********************************************************************************
//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include"main.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************
xSemaphoreHandle logger_mutex;
TaskHandle_t Alert_taskhandler ;
SemaphoreHandle_t xSemaphore_led;
SemaphoreHandle_t xSemaphore_temperature;

volatile uint32_t pulse_length;
//***********************************************************************************
//                              Function implementation
//***********************************************************************************

int main(void)
{
    float converted_val ;
    uint32_t data = 0;
    system_init();
    int16_t gyro = 0;
    uint32_t gyro_val[2];
    spi_status_t status;


    //LCD_send_string("Vikrant  Waje");   //Test string to check LCD is working correctly


    int16_t x =0;
    int16_t y =0;
    int16_t z =0;

    while(1){
        buzzer_on();

       readFloatGyroX( &gyro,gyro_val);
       UARTprintf("\n\rGyro val = %d",gyro);

       //UARTprintf("\n\r%d %d",gyro_val[0],gyro_val[1]);
       // SysCtlDelay(100);
       /* accelerometer_read_axis(&x, &y, &z);
        UARTprintf("\n\rx = %d, y =%d, z =%d",x,y,z);*/
        //spi_write(0x55,0x37);

        ultrasonic_send_trigger();

        UARTprintf("\n\rPulse length = %d",pulse_length);

        UARTprintf("\n\rMotion detected = %d",motion_sensor());
        SysCtlDelay(1000);                                       //Insert delay of atleast 10us

       // PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, PWMGenPeriodGet(PWM0_BASE, PWM_GEN_2)/3); // Set Duty cycle

      /*  if(a=='z'){a='a';}
        LCD_send_string(&a);
        a++;*/

      //  read_adc(&converted_val);
     //   buzzer_on();
       // buzzer_off();

       // SysCtlDelay(10000);
       // PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 300);



    }

}
