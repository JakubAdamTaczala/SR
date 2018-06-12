/*
 * acc.c
 *
 *  Created on: 12.06.2018
 *      Author: Rafa³
 */

#include "acc.h"

#define __SPI_DIRECTION_2LINES(__HANDLE__)   do{\
                                             CLEAR_BIT((__HANDLE__)->Instance->CR1, SPI_CR1_RXONLY | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE);\
                                             }while(0);

#define __SPI_DIRECTION_2LINES_RXONLY(__HANDLE__)   do{\
                                                   CLEAR_BIT((__HANDLE__)->Instance->CR1, SPI_CR1_RXONLY | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE);\
                                                   SET_BIT((__HANDLE__)->Instance->CR1, SPI_CR1_RXONLY);\
                                                   }while(0);

#define __SPI_DIRECTION_1LINE_TX(__HANDLE__) do{\
                                             CLEAR_BIT((__HANDLE__)->Instance->CR1, SPI_CR1_RXONLY | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE);\
                                             SET_BIT((__HANDLE__)->Instance->CR1, SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE);\
                                             }while(0);

#define __SPI_DIRECTION_1LINE_RX(__HANDLE__) do {\
                                             CLEAR_BIT((__HANDLE__)->Instance->CR1, SPI_CR1_RXONLY | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE);\
                                             SET_BIT((__HANDLE__)->Instance->CR1, SPI_CR1_BIDIMODE);\
                                             } while(0);

void ACC_Transmit(uint8_t addr, uint8_t data) {
	HAL_GPIO_WritePin(ACC_CS_GPIO_Port, ACC_CS_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	__SPI_DIRECTION_1LINE_TX(&hspi2);
	HAL_SPI_Transmit(&hspi2, &addr, 1, 100);
//	__SPI_DIRECTION_1LINE_RX(&hspi2);
	HAL_SPI_Transmit(&hspi2, &data, 1, 100);
	HAL_Delay(10);
	HAL_GPIO_WritePin(ACC_CS_GPIO_Port, ACC_CS_Pin, GPIO_PIN_SET);
}

uint8_t ACC_Receive(uint8_t addr) {
	uint8_t dataout = 0;
	addr = 0x80 | addr;
	HAL_GPIO_WritePin(ACC_CS_GPIO_Port, ACC_CS_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	__SPI_DIRECTION_1LINE_TX(&hspi2);
	HAL_SPI_Transmit(&hspi2, &addr, 1, 100);
	__SPI_DIRECTION_1LINE_RX(&hspi2);
	HAL_SPI_Receive(&hspi2, &dataout, 1, 100);
	HAL_Delay(10);
	HAL_GPIO_WritePin(ACC_CS_GPIO_Port, ACC_CS_Pin, GPIO_PIN_SET);
	return dataout;
}

void ACC_Init() {

	HAL_GPIO_WritePin(ACC_CS_GPIO_Port, ACC_CS_Pin, GPIO_PIN_SET);
	HAL_Delay(100);
	ACC_Transmit(0x24, 1 << 6);

	ACC_Transmit(0x23, 1 << 2 | 1 << 1 | 1);

	ACC_Transmit(0x20, 0x27);
	HAL_Delay(100);
}

void ACC_ReadValues(int16_t* data) {
	data[0] = ACC_Receive(0x28)|(ACC_Receive(0x29)<<8);
	data[1] = ACC_Receive(0x2A)|(ACC_Receive(0x2B)<<8);
	data[2] = ACC_Receive(0x2C)|(ACC_Receive(0x2D)<<8);
}
