/***********************************************************************************
 * @file gyroscope.c
 * @brief Contains functions to operate the gyroscope
 * @author Vikrant Waje
 * @date April 18, 2018
 * @Reference: Reference: https://github.com/sparkfun/SparkFun_LIS331_Arduino_Library/blob/master/src/SparkFun_LIS331.cpp
 *
 *****************************************************************************/

//***********************************************************************************
//                                  Include files
//***********************************************************************************
#include <accelerometer.h>

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
void accelerometer_init()
{
    accelerometer_setpowermode(NORMAL_MODE);
    accelerometer_enableaxis();
    uint8_t data = 0;
    int i = 0;
    for ( i = 0x21; i < 0x25; i++)
        spi_write(i, data);
    for ( i = 0x30; i < 0x37; i++)
        spi_write(i,data);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Set the power mode of accelerometer


 @param: power_mode: power mode of accelerometer
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_setpowermode(uint8_t power_mode){
    uint8_t data;
    spi_read(CTRL_REG1, &data);

    // The power mode is the high three bits of CTRL_REG1. The mode
    //  constants are the appropriate bit values left shifted by five, so we
    //  need to right shift them to make them work. We also want to mask off the
    //  top three bits to zero, and leave the others untouched, so we *only*
    //  affect the power mode bits.
    data &= ~0xe0; // Clear the top three bits
    data |= power_mode<<5; // set the top three bits to our pmode value
    spi_write(CTRL_REG1, data); // write the new value to CTRL_REG1

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Enable the axis of accelerometer


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_enableaxis(){
    uint8_t data;
    spi_read(CTRL_REG1, &data);
    data |= 0x07;
    spi_write(CTRL_REG1, data);

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Set the ODR of accelerometer


 @param: data_rate: Output data rate of the accelerometer
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_setODR(uint8_t data_rate){
    uint8_t data;
    spi_read(CTRL_REG1, &data);

    // The data rate is bits 4:3 of CTRL_REG1. The data rate constants are the
    //  appropriate bit values; we need to right shift them by 3 to align them
    //  with the appropriate bits in the register. We also want to mask off the
    //  top three and bottom three bits, as those are unrelated to data rate and
    //  we want to only change the data rate.
    data &=~0x18;     // Clear the two data rate bits
    data |= data_rate<<3; // Set the two data rate bits appropriately.
    spi_write(CTRL_REG1,data); // write the new value to CTRL_REG1

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Read x,y and z axis of accelerometer


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_read_axis(int16_t *x, int16_t *y, int16_t *z){
    uint8_t data[6]; // create a buffer for our incoming data
    spi_read(OUT_X_L, &data[0]);
    spi_read(OUT_X_H, &data[1]);
    spi_read(OUT_Y_L, &data[2]);
    spi_read(OUT_Y_H, &data[3]);
    spi_read(OUT_Z_L, &data[4]);
    spi_read(OUT_Z_H, &data[5]);
    // The data that comes out is 12-bit data, left justified, so the lower
    //  four bits of the data are always zero. We need to right shift by four,
    //  then typecase the upper data to an integer type so it does a signed
    //  right shift.
    *x = data[0] | data[1] << 8;
    *y = data[2] | data[3] << 8;
    *z = data[4] | data[5] << 8;
    *x = *x >> 4;
    *y = *y >> 4;
    *z = *z >> 4;

}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Convert to G


 @param: None
 @param:None

 @return: float: G value
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
float accelerometer_convert_to_G(int maxscale, int reading){
    float result = 0.0;
    result =((float)(maxscale) * (float)(reading))/2047;
    return result;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief:Set High pass coefficient


 @param: coefficient: coefficient of High pass filter
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_set_highpass_coefficient(uint8_t coefficient){
    // The HPF coeff depends on the output data rate. The cutoff frequency is
    //  is approximately fs/(6*HPc) where HPc is 8, 16, 32 or 64, corresponding
    //  to the various constants available for this parameter.
    uint8_t data;
    spi_read(CTRL_REG2, &data);
    data &= ~0xfc;  // Clear the two low bits of the CTRL_REG2
    data |= coefficient;
    spi_write(CTRL_REG2, data);
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief:Enable High pass Filter


 @param: None
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_enable_highpassfilter(uint8_t coefficient){
    // Enable the high pass filter
    uint8_t data;
    spi_read(CTRL_REG2, &data);
    data |= 1<<5;
    spi_write(CTRL_REG2, data);
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief:Set fullscale range


 @param: range: fullscale range of accelerometer
 @param:None

 @return: None
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
void accelerometer_set_fullscalerange(uint8_t range){
    uint8_t data;
    spi_read(CTRL_REG4, &data);
    data &= ~0xcf;
    data |= range<<4;
    spi_write(CTRL_REG4, data);
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Checks whether accelerometer has new data for X axis


 @param: None
 @param:None

 @return: Returns true if accelerometer has new value for X axis
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool accelerometer_new_Xdata(){
    uint8_t data;
    spi_read(STATUS_REG, &data);
    if (data & 1<<0)
    {
      return true;
    }
    else
    {
      return false;
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Checks whether accelerometer has new data for Y axis


 @param: None
 @param:None

 @return: Returns true if accelerometer has new value for Y axis
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool accelerometer_new_Ydata(){
    uint8_t data;
    spi_read(STATUS_REG, &data);
    if (data & 1<<1)
    {
      return true;
    }
    else
    {
      return false;
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------*/
/*
 @brief: Checks whether accelerometer has new data for Z axis


 @param: None
 @param:None

 @return: Returns true if accelerometer has new value for Z axis
 */
/*-----------------------------------------------------------------------------------------------------------------------------*/
bool accelerometer_new_Zdata(){
    uint8_t data;
    spi_read(STATUS_REG, &data);
    if (data & 1<<2)
    {
      return true;
    }
    else
    {
      return false;
    }
}
