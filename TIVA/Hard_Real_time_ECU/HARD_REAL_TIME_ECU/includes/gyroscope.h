/***********************************************************************************
 * @file gyrometer.h
 * @brief Contains function for gyrometer initialisation and read, write functions
 * @author Vikrant Waje
 * @date April 18, 2018
 * @Reference: https://github.com/sparkfun/SparkFun_LSM6DS3_Arduino_Library/blob/master/src/SparkFunLSM6DS3.h
 *****************************************************************************/
#ifndef INCLUDES_GYROSCOPE_H_
#define INCLUDES_GYROSCOPE_H_

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
#include "uart.h"
#include "srt_sensor_data_task.h"
#include "synchronization.h"

//***********************************************************************************
//                                  Macros
//***********************************************************************************

#define LSM6DS3_ACC_GYRO_CTRL2_G            0X11
#define LSM6DS3_ACC_GYRO_OUTX_L_G           0X22
#define LSM6DS3_ACC_GYRO_OUTX_H_G           0X23
#define LSM6DS3_ACC_GYRO_OUTY_L_G           0X24
#define LSM6DS3_ACC_GYRO_OUTY_H_G           0X25
#define LSM6DS3_ACC_GYRO_OUTZ_L_G           0X26
#define LSM6DS3_ACC_GYRO_OUTZ_H_G           0X27
#define LSM6DS3_ACC_GYRO_ID                 0X0F

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
void gyroscope_init();

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Read Raw Gyrovalue for x axis


 @param: input : Pointer to input data in which two bytes are to be stored
 @param:output_raw; Pointer to data in hwich two's complement data is to be stored

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void readRawGyroX( uint8_t *input, int16_t *output_raw );

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Read Float Gyrovalue for x axis


 @param: output : Pointer to variable in which converted value is to be stored
 @param: input: Pointer to data in raw data is provided

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void readFloatGyroX(  int16_t *output,uint32_t *input );

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Calculate gyro


 @param: input: variable in which float data is provided
 @param: output: Pointer to variable in which calculated Gyro is stored

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void calcGyro( int16_t input, float *output );




#endif /* INCLUDES_GYROSCOPE_H_ */
