/*
 * distance.h
 *
 *  Created on: 10.06.2018
 *      Author: Rafa³
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_

#include "stm32l4xx_hal.h"
#include "dwt_stm32_delay.h"

float HCSR04READ1(void);
float HCSR04READ2(void);
float HCSR04READ3(void);

uint8_t HCSR04_Init(void);


#endif /* DISTANCE_H_ */
