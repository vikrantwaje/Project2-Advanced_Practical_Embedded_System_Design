/***************************************************************************************
 * @file system.c
 * @brief This file is to be used for initialising the whole system.
 * @author Vikrant Waje
 * @date April 7, 2019
 *
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include <system.h>


//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Initialise all the peripherals required for system operation.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void system_init(){
    //
    // Set the clocking to run at 50 MHz from the PLL.
    //
    clock_init();


    //Initialise the GPIO
    gpio_init();

    //Initialise the UART
    UART_init();

    //Initialise motor
    //dcmotor_init();

    //For motor, servo motor and buzzer
    pwm_init();
    set_pwm_duty_cycle_freq(SPEAKER_RESONANT_FREQ);   // For speaker
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6,SPEAKER_RESONANT_FREQ/2 );    //For motor

    //adc_init();

    //Initialise SPI
    spi_init();
    gyroscope_init();

    //PIR sensor initialise
    motion_sensor_init();

    //Initialise shift register
    //shift_reg_setup();

    //LCD setup and initialisation

    //LCD_setup();
    //LCD_init();

    //Initialise Timer
    timer_capture_init();
    // timer_init();



}
