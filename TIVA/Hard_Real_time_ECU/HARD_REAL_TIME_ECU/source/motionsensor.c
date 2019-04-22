/*
 * mymotion_sensor.c
 *
 *  Created on: 14 Apr 2019
 *      Author: TanmayC
 */



#include "motionsensor.h"




void motion_sensor_init(void)
{
    GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_1);
}

bool motion_sensor(void)

{
    uint32_t val = 0;

    val = GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_1);
    if(val!=0){
        return 1;
    }
    else
        return 0;
    UARTprintf("val = %d\n", val);
}
