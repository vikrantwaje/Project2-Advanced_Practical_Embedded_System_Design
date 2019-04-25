/************************************************************************************
 * @file main.c
 * @brief Contains main function
 * @author Vikrant Waje & Tanmay Chaturvedi
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


QueueHandle_t myqueuehandle ;
SemaphoreHandle_t xSemaphore ;
volatile uint32_t pulse_length;



//***********************************************************************************
//                              Function implementation
//***********************************************************************************

return_type_t main(void)
{
    int16_t gyro = 0;
    uint32_t gyro_val[2];
    double temperature_value ;
    uint32_t test_pulse_length = 0;
    system_init();
    BaseType_t  xReturned;
    xSemaphore = xSemaphoreCreateMutex();
    LCD_send_string("LCD initialised properly");
    //UART_send_string("UART initialised properly\n\r");

 /*   while(1){
        readFloatGyroX( &gyro,gyro_val);
    }*/
/*    while(1)
        {
        ultrasonic_send_trigger();
        test_pulse_length = pulse_length;
        }*/
    /*
//    UARTprintf("Out of System\n");
    UART_send_string("Tanmay\n\r");
   // UARTCharPut(UART7_BASE, 'c');
     */
    /*    while(1)
    {
       // UARTCharPut(UART0_BASE, "Inside");
        uart_val = UARTCharGet(UART7_BASE);
        UARTCharPut(UART0_BASE, uart_val);

    }*/


    //for Soft Real Time sensing
    xReturned = xTaskCreate(srt_sensor_data_task, (const portCHAR *)"SRT Sensor Acquisition Task", \
                            2000, NULL, 1, NULL);

    if(xReturned != pdPASS)
    {
        UART_send_string("SOFT REAL TIME SENSOR DATA TASK FAILED");
        return SRT_SENSOR_TASK_CREATE_FAILED;
    }

    //for Hard Real Time sensing
    xReturned = xTaskCreate(hrt_sensor_data_task, (const portCHAR *)"HRT Sensor Acquisition Task", \
                            2000, NULL, 1, NULL);

    if(xReturned != pdPASS)
    {
        UART_send_string("HARD REAL TIME SENSOR DATA TASK FAILED");
        return HRT_SENSOR_TASK_CREATE_FAILED;
    }

/*    //for Data communication via UART
    xReturned = xTaskCreate(data_communication_task, (const portCHAR *)"Data Communication Task", \
                            200, NULL, 1, NULL);

    if(xReturned != pdPASS)
    {
        UART_send_string("DATA COMMUNICATION TASK FAILED");
        return COMMUNICATION_TASK_CREATE_FAILED;
    }

    //for Actuator
    xReturned = xTaskCreate(actuator_task, (const portCHAR *)"Actuator Task", \
                            200, NULL, 1, NULL);

    if(xReturned != pdPASS)
    {
        UART_send_string("ACTUATOR TASK FAILED");
        return ACTUATOR_TASK_CREATE_FAILED;
    }*/

    vTaskStartScheduler();
    return PROGRAM_SUCCESS;

/*
    while(1){
        buzzer_on();

       readFloatGyroX( &gyro,gyro_val);
       UARTprintf("\n\rGyro val = %d",gyro);

       //UARTprintf("\n\r%d %d",gyro_val[0],gyro_val[1]);
       // SysCtlDelay(100);
//        accelerometer_read_axis(&x, &y, &z);
//        UARTprintf("\n\rx = %d, y =%d, z =%d",x,y,z);
        //spi_write(0x55,0x37);

        ultrasonic_send_trigger();

        UARTprintf("\n\rPulse length = %d",pulse_length);

        UARTprintf("\n\rMotion detected = %d",motion_sensor());
        SysCtlDelay(1000);                                       //Insert delay of atleast 10us

       // PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, PWMGenPeriodGet(PWM0_BASE, PWM_GEN_2)/3); // Set Duty cycle
//
//        if(a=='z'){a='a';}
//        LCD_send_string(&a);
//        a++;

      //  read_adc(&converted_val);
     //   buzzer_on();
       // buzzer_off();

       // SysCtlDelay(10000);
       // PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 300);

    }
*/


}
