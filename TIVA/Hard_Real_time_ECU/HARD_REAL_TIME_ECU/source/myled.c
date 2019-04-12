/***************************************************************************************
 * @file myled.c
 * @brief This file is to be used for controlling the leds.
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include"myled.h"


//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise the led.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void led_init(void){

             // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
             // enable the GPIO pin for digital function.
             //
             GPIOPinTypeGPIOOutput(D1_LED_PORT | D2_LED_PORT, D1_LED_PIN | D2_LED_PIN);

             // Enable the GPIO pin for the LED (PN1).  Set the direction as output, and
             // enable the GPIO pin for digital function.

            // GPIOPinTypeGPIOOutput(RED_LED_PORT, RED_LED_PIN);
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Turn ON led.


 @param: Port: Port number
 @param: Pins: Pin number
 @param: Val: ON

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void led_on(uint32_t ui32Port, uint8_t ui8Pins,uint8_t ui8Val){
    GPIOPinWrite(ui32Port, ui8Pins, ui8Val);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Turn OFF led.

@param: Port: Port number
 @param: Pins: Pin number
 @param: Val: OFF

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void led_off(uint32_t ui32Port, uint8_t ui8Pins,uint8_t ui8Val){
    GPIOPinWrite(ui32Port, ui8Pins, ui8Val);

}
