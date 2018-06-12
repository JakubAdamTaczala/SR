/*
 * acc.h
 *
 *  Created on: 12.06.2018
 *      Author: Rafa³
 */

#ifndef ACC_H_
#define ACC_H_

#include "stm32l4xx_hal.h"
#include "spi.h"

void ACC_Transmit(uint8_t addr, uint8_t data);
uint8_t ACC_Receive(uint8_t addr);
void ACC_Init();
void ACC_ReadValues(int16_t* data);

#endif /* ACC_H_ */
