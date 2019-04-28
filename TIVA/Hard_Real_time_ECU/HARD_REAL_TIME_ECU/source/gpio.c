/***************************************************************************************
 * @file mygpio.c
 * @brief This file is to be used for the setting the GPIO of the microcontroller.
 * @author Vikrant Waje
 * @date April 7, 2019
 *@Reference: http://www.ti.com/lit/an/spma073/spma073.pdf
 *****************************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include <gpio.h>


//***********************************************************************************
//                                  Global variables
//***********************************************************************************

//***********************************************************************************
//                                 Function implementation
//***********************************************************************************

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
  @brief: Setup the GPIO peripheral.


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void gpio_init(void)
{


    //Enable the GPIO that are used for I2C Interface Pins
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOL));

    //
    // Configure Pins for I2C2 Master Interface
    //
    GPIOPinConfigure(GPIO_PL1_I2C2SCL);
    GPIOPinConfigure(GPIO_PL0_I2C2SDA);
    GPIOPinTypeI2C(GPIO_PORTL_BASE, GPIO_PIN_0);
    GPIOPinTypeI2CSCL(GPIO_PORTL_BASE, GPIO_PIN_1);


    //Motor pin initialisation clock
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOM));

    //Switch pin
    GPIOPinTypeGPIOInput(GPIO_PORTM_BASE, GPIO_PIN_5);

    //Shift register pin initialisation clock
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK));



    //ADC initialisation
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));

    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);


    // PWM for servo motor
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);// Enable Port G
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOG));

    GPIOPinConfigure(GPIO_PG1_M0PWM5);
    GPIOPinTypePWM(GPIO_PORTG_BASE, GPIO_PIN_1);

    //PWM for speaker
    GPIOPinConfigure(GPIO_PG0_M0PWM4);
    GPIOPinTypePWM(GPIO_PORTG_BASE, GPIO_PIN_0);

    //PWM for motor
    GPIOPinConfigure(GPIO_PK4_M0PWM6);
    GPIOPinTypePWM(GPIO_PORTK_BASE, GPIO_PIN_4);

   SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
    //SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);



     //Enable the GPIO that are used for SPI Interface Pins

     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
     while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

    // SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);


     //while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));

     //

     // Configure Pins for SPI Interface
     //
     // Configure the muxing and GPIO settings to bring the SSI/SPI functions out to the pins
     //PA4: Tx,PA5:Rx,PA2:SCLK,PA3:FSS
     GPIOPinConfigure(GPIO_PA2_SSI0CLK);
     GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_3);   //Configure cs PIN

     //GPIOPinConfigure(GPIO_PA3_SSI0FSS);
     GPIOPinConfigure(GPIO_PA4_SSI0XDAT0);
     GPIOPinConfigure(GPIO_PA5_SSI0XDAT1);

      GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_4/*|GPIO_PIN_3*/|GPIO_PIN_2);

      //Ultrasonic pin initialisation
      GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_1);   //Configure Trigger pin

      //Configure Echo PIN
     GPIOPinTypeGPIOInput(GPIO_PORTM_BASE, GPIO_PIN_2);    //PM2 as echo pin
      GPIOIntEnable(GPIO_PORTM_BASE, GPIO_PIN_2);           //Enable interrupt on PM2
      GPIOIntTypeSet(GPIO_PORTM_BASE, GPIO_PIN_2,GPIO_BOTH_EDGES);  //Interrupt on both level
      GPIOIntRegister(GPIO_PORTM_BASE,measure_echo);

      //Enable clock to PIR sensor
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
      while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOH));



}
