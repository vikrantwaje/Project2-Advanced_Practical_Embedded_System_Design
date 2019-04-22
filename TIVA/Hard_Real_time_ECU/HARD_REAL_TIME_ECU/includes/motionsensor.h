/*
 * mymotion_sensor.h
 *
 *  Created on: 14 Apr 2019
 *      Author: TanmayC
 */

#ifndef MYMOTION_SENSOR_H_
#define MYMOTION_SENSOR_H_

#include<stdint.h>
#include<stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include<stdbool.h>

void motion_sensor_init(void);
bool motion_sensor(void);


#endif /* MYMOTION_SENSOR_H_ */
