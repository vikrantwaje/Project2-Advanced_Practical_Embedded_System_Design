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
xSemaphoreHandle lcd_mutex; //Mutex for lcd
xSemaphoreHandle communication_queue_mutex; //mutex for protection of communication queue
SemaphoreHandle_t xSemaphore_hrt;
SemaphoreHandle_t xSemaphore_srt;
uint8_t auth;

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

    //Initialise I2C for temperature sensor
    i2c_init();

    //Initialise the UART
    UART_init();

    //Initialise motor
    // dcmotor_init();

    //For motor, servo motor and buzzer
    pwm_init();
    set_pwm_duty_cycle_freq(SPEAKER_RESONANT_FREQ);   // For speaker
    //PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6,SPEAKER_RESONANT_FREQ/2 );    //For motor

    adc_init();

    //Initialise SPI
    spi_init();
    gyroscope_init();

    //PIR sensor initialise
    motion_sensor_init();

    //Initialise shift register
    shift_reg_setup();

    //LCD setup and initialisation

    LCD_setup();
    LCD_init();

    //Initialise Timer
    timer_capture_init();

    //Initialise the sensor id
    srt_sensor_id_init();
    hrt_sensor_id_init();

    //Create queues
    create_hrt_queue();
    create_communication_queue();
    create_actuator_queue();


    //Mutex creation
    lcd_mutex = xSemaphoreCreateMutex();   //Create Mutex for lcd protection

    //Semaphore initialisation
    xSemaphore_srt = xSemaphoreCreateBinary();  //Sempahore for soft real time task
    xSemaphore_hrt = xSemaphoreCreateBinary();  //Semaphore for hard real time task

    SysCtlDelay(255000);
     timer_init();



}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Authentication state.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void authenticate(){
    int32_t password = 0;
        do{
            password = GPIOPinRead(GPIO_PORTM_BASE, GPIO_PIN_5);
            if(password == 0X20){
                UARTCharPut(UART7_BASE,'1');
                while(auth!='1'){
                    UARTCharPut(UART7_BASE,'1');

                }
            }
            else if(password == 0){
                  if(motion_sensor()==1){
                      while(auth!='0'){
                          UARTCharPut(UART7_BASE,'0');
                      }
                      //Turn buzzer on
                      PWMGenEnable(PWM0_BASE, PWM_GEN_2); // Enable PWM module
                      PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true); // Enable PWM output channel 4

                  }
                  else{

                  }
            }
                    }while(auth!='1');
        //motor on
      //  PWMGenEnable(PWM0_BASE, PWM_GEN_2); // Enable PWM module
        PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, false); // Enable PWM output channel 4

}
