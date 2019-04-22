/***********************************************************************************
 * @file accelerometer.h
 * @brief Contains function for accelerometer initialisation and read, write functions
 * @author Vikrant Waje
 * @date April 18, 2018
 * @Reference: https://github.com/sparkfun/SparkFun_LIS331_Arduino_Library/blob/master/src/SparkFun_LIS331.h
 *****************************************************************************/

#ifndef INCLUDES_ACCELEROMETER_H_
#define INCLUDES_ACCELEROMETER_H_

//***********************************************************************************
//                              Include files
//***********************************************************************************
#include<stdint.h>
#include<stdbool.h>
#include "driverlib/sysctl.h"
#include "inc/hw_ssi.h"
#include "driverlib/ssi.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "clock.h"
#include "gpio.h"
#include "spi.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************
#define CTRL_REG1        0x20
#define CTRL_REG2        0x21
#define CTRL_REG3        0x22
#define CTRL_REG4        0x23
#define CTRL_REG5        0x24
#define HP_FILTER_RESET  0x25
#define REFERENCE        0x26
#define STATUS_REG       0x27
#define OUT_X_L          0x28
#define OUT_X_H          0x29
#define OUT_Y_L          0x2A
#define OUT_Y_H          0x2B
#define OUT_Z_L          0x2C
#define OUT_Z_H          0x2D

#define NORMAL_MODE      0x01

#define DR_50HZ          0x00
#define DR_100HZ         0x01
#define DR_400HZ         0x02
#define DR_1000HZ        0x03

#define HPC_8            0x00
#define HPC_16           0x01
#define HPC_32           0x02
#define HPC_64           0x03

#define LOW_RANGE        0x00
#define MED_RANGE        0x01
#define NO_RANGE         0x02
#define HIGH_RANGE       0x03





//***********************************************************************************
//                              Global variables
//***********************************************************************************

//***********************************************************************************
//                              Function Prototype
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Initialise the accelerometer


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_init();

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Set the power mode of accelerometer


 @param: power_mode: power mode of accelerometer
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_setpowermode(uint8_t power_mode);
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Enable the axis of accelerometer


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_enableaxis();
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Set the ODR of accelerometer


 @param: data_rate: Output data rate of the accelerometer
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_setODR(uint8_t data_rate);

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Read x,y and z axis of accelerometer


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_read_axis(int16_t *x, int16_t *y, int16_t *z);

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Convert to G


 @param: None
 @param:None

 @return: float: G value
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
float accelerometer_convert_to_G(int maxscale, int reading);
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief:Set High pass coefficient


 @param: coefficient: coefficient of High pass filter
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_set_highpass_coefficient(uint8_t coefficient);

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief:Enable High pass Filter


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_enable_highpassfilter(uint8_t coefficient);

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief:Set fullscale range


 @param: range: fullscale range of accelerometer
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_set_fullscalerange(uint8_t range);

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Checks whether accelerometer has new data for X axis


 @param: None
 @param:None

 @return: Returns true if accelerometer has new value for X axis
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool accelerometer_new_Xdata();

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Checks whether accelerometer has new data for Y axis


 @param: None
 @param:None

 @return: Returns true if accelerometer has new value for Y axis
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool accelerometer_new_Ydata();
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Checks whether accelerometer has new data for Z axis


 @param: None
 @param:None

 @return: Returns true if accelerometer has new value for Z axis
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool accelerometer_new_Zdata();






#endif /* INCLUDES_ACCELEROMETER_H_ */
