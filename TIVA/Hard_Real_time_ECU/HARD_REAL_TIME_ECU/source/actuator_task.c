/***********************************************************************************
 * @file actuator_task.c
 * @brief Contains callback function for actuator task
 * @author Tanmay C
 * @date April 23, 2019
 * @Reference: None
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "actuator_task.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/***********************************************************************************
/*
 @brief:For running actuators based on commands from controller node (BBG)

 @param: None
 @param: None

 @return: None
 **************************************************************************************/
void actuator_task(void *pvParameters)
{
    uint8_t receive_data = 0;
    uint8_t last_receive_data =0;
    while(1){
       // LCD_clear();
        xQueueReceive(xactuator_Queue, &(receive_data),(TickType_t ) portMAX_DELAY);

        if(receive_data == 'G' && last_receive_data!=receive_data){
          //  LCD_clear();
            SysCtlDelay(50000);
            //LCD_send_string("Accident!");
            last_receive_data = receive_data;

        }
 /*       else if(receive_data == 'M' && last_receive_data!=receive_data){
            LCD_clear();
             SysCtlDelay(50000);
             LCD_send_string("Motion detect");
             last_receive_data = receive_data;


        }*/
        else if(receive_data == 'U' && last_receive_data!=receive_data){
            SysCtlDelay(1000);
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_5, 0x20);    //Turn Watch distance on
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_4, 0x00);    //Turn Failure OFF
            SysCtlDelay(1000);

/*            LCD_clear();
            SysCtlDelay(50000);
            LCD_move_cursor(0x00);
            LCD_send_string("Watch Distance");
            last_receive_data = receive_data;
            SysCtlDelay(50000);*/
        }

        else if(receive_data == 'T' && last_receive_data!=receive_data){
   //        LCD_clear();
             SysCtlDelay(1000);
            PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, PWMGenPeriodGet(PWM0_BASE,PWM_GEN_2)/6/*6*/);
            PWMGenEnable(PWM0_BASE, PWM_GEN_2); // Enable PWM module
            PWMOutputInvert(PWM0_BASE, PWM_OUT_5_BIT, true);

            // PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true); // Enable PWM output channel 5
             SysCtlDelay(10000);
             PWMOutputInvert(PWM0_BASE, PWM_OUT_5_BIT, false);

          //  PWMOutputInvert(PWM0_BASE, PWM_OUT_5_BIT, false);
            // PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, false); // Enable PWM output channel 5


        }
        else if(receive_data == 'u' && last_receive_data!=receive_data){
            SysCtlDelay(1000);
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_5, 0x00);    //Turn Watch distance off
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_4, 0x00);    //Turn Failure OFF
            SysCtlDelay(1000);

               }

        else if(receive_data == 'h' && last_receive_data!=receive_data){
            SysCtlDelay(1000);
            PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, PWMGenPeriodGet(PWM0_BASE,PWM_GEN_2)/36);
        PWMGenEnable(PWM0_BASE, PWM_GEN_2); // Enable PWM module
           PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);

           // PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true); // Enable PWM output channel 5
            SysCtlDelay(10000);
            PWMOutputState(PWM0_BASE,PWM_OUT_5_BIT,false);

          // PWMOutputInvert(PWM0_BASE, PWM_OUT_5_BIT, false);

               }

        else if(receive_data == 'A' && last_receive_data!=receive_data){
            xSemaphoreTake( lcd_mutex, ( TickType_t )portMAX_DELAY );   //Mutex lock for LCD
            LCD_clear();
            SysCtlDelay(50000);
            //LCD_move_cursor(0x40);
             LCD_send_string("Drunk");
             last_receive_data = receive_data;
             xSemaphoreGive( lcd_mutex); //Mutex unlock for LCD

            // SysCtlDelay(50000);
        }
        else if(receive_data == 'S' && last_receive_data!=receive_data){
            SysCtlDelay(1000);
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_5, 0x00);    //Turn Watch distance off
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_4, 0x10);    //Turn Failure ON
            SysCtlDelay(1000);


          }

        else if(receive_data == 'D' && last_receive_data!=receive_data){
            xSemaphoreTake( lcd_mutex, ( TickType_t )portMAX_DELAY );   //Mutex lock for LCD
            LCD_clear();
             SysCtlDelay(50000);
             LCD_move_cursor(0x14);
             LCD_send_string("Degraded");
             last_receive_data = receive_data;
             xSemaphoreGive( lcd_mutex); //Mutex unlock for LCD

             //SysCtlDelay(50000);


        }
/*        else if(receive_data == 'B' && last_receive_data!=receive_data){
             LCD_clear();
             SysCtlDelay(50000);
             LCD_send_string("TX BROKEN");
             last_receive_data = receive_data;

        }
        else if(receive_data == 'X' && last_receive_data!=receive_data){
             LCD_clear();
             SysCtlDelay(50000);
             LCD_send_string("RX BROKEN");
             last_receive_data = receive_data;

        }*/

 /*       else{
            LCD_clear();
            SysCtlDelay(50000);
            //LCD_send_string("Engine activated");
        }*/
        receive_data = 0;

    }

}


