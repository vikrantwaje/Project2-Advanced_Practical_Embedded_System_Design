/***********************************************************************************
 * @file bist.c
 * @brief Contains BIST routine
 * @author Vikrant Waje
 * @date April 29, 2019
 * @Reference: None
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "bist.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: BIST routine.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool bist(void)
{
    bool flag =0;
    double temperature_value = 0;
    uint32_t converted_val = 0;
    uint16_t count =0;
    i2c_status_t status = READ_SUCCESS;
    uint8_t gyro_id = 0;
    uint32_t ultrasonic_val = 0;
    uint32_t previous_val =0;
    status = get_temperature(REQUEST_CELSIUS, &temperature_value);
   if(status == READ_FAILURE){

       flag =1;
    }
   else {

   }
    gyro_id = gyroscope_read_identification();
    if(gyro_id != 0x69){

        flag = 1;
        }
    else{

    }

/*    read_adc(&converted_val);
    if(converted_val ==0){
        GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_3, 0x08);    //Turn Failure ON
        GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_2, 0x00);    //Turn BIST SUCCESS OFF
        }
    else{
        GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_3, 0x00);    //Turn Failure OFF
        GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_2, 0x04);    //Turn BIST SUCCESS ON
    }*/
    while(count <1000){
    ultrasonic_send_trigger();
     ultrasonic_val=(pulse_length );
     if(previous_val == ultrasonic_val){
          count++;
          if(count == 999){
              //Failure

              flag = 1;
          }
     }
     else{

         //Success

         ///flag =0;
         break;


     }
     previous_val = ultrasonic_val;

    }
    if(flag == 1){
        GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_3, 0x08);    //Turn Failure ON
        GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_2, 0x00);    //Turn BIST SUCCESS OFF
    }
    else{
        GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_3, 0x00);    //Turn Failure OFF
        GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_2, 0x04);    //Turn BIST SUCCESS ON
    }
    return flag;
}


