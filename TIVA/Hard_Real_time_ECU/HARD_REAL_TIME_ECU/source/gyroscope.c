/***********************************************************************************
 * @file gyroscope.c
 * @brief Contains functions to operate the gyroscope
 * @author Vikrant Waje
 * @date April 18, 2018
 * @Reference: Reference: https://github.com/sparkfun/SparkFun_LSM6DS3_Arduino_Library/blob/master/src/SparkFunLSM6DS3.h
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include "gyroscope.h"

//***********************************************************************************
//                                  Global variables
//***********************************************************************************


//***********************************************************************************
//                                 Function implementation
//***********************************************************************************
/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Initialise the accelerometer


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void gyroscope_init()
{
    spi_write(LSM6DS3_ACC_GYRO_CTRL2_G, 0x10); // write the new value to CTRL_REG1


}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Read Raw Gyrovalue for x axis


 @param: input : Pointer to input data in which two bytes are to be stored
 @param:output_raw; Pointer to data in hwich two's complement data is to be stored

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void readRawGyroX( uint8_t *input, int16_t *output_raw )
{
    spi_read_multibyte(LSM6DS3_ACC_GYRO_OUTX_L_G,input,2);
     *output_raw = (int16_t)*(input + 0) | (int16_t)(*(input + 1) << 8);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Read Float Gyrovalue for x axis


 @param: output : Pointer to variable in which converted value is to be stored
 @param: input: Pointer to data in raw data is provided

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void readFloatGyroX(  int16_t *output,uint32_t *input )
{
    //int16_t output_raw;
    spi_read_multibyte(LSM6DS3_ACC_GYRO_OUTX_L_G,input,2);
    *output = (int16_t)*(input + 0) | (int16_t)(*(input + 1) << 8);

    // UARTprintf("\n\r%d",output_raw);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Calculate gyro


 @param: input: variable in which float data is provided
 @param: output: Pointer to variable in which calculated Gyro is stored

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void calcGyro( int16_t input, float *output )
{
    //uint8_t gyroRangeDivisor = settings.gyroR / 125;
    *output = (float)input * 4.375 * (2) / 1000;

}

