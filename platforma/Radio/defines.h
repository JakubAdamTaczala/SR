
#ifndef DEFINES_H_
#define DEFINES_H_

#include "stm32l4xx_hal.h"
#include "main.h"

#define Bit_RESET 		0

extern SPI_HandleTypeDef hspi1;

#define NRF24L01_SPI				&hspi1

#define NRF24L01_CSN_PORT			SPI1_CS_GPIO_Port
#define NRF24L01_CSN_PIN			SPI1_CS_Pin

#define NRF24L01_CE_PORT			SPI1_CE_GPIO_Port
#define NRF24L01_CE_PIN				SPI1_CE_Pin

#define NRF24L01_CE_LOW				HAL_GPIO_WritePin(NRF24L01_CE_PORT, NRF24L01_CE_PIN, GPIO_PIN_RESET)
#define NRF24L01_CE_HIGH			HAL_GPIO_WritePin(NRF24L01_CE_PORT, NRF24L01_CE_PIN, GPIO_PIN_SET)
#define NRF24L01_CSN_LOW			HAL_GPIO_WritePin(NRF24L01_CSN_PORT, NRF24L01_CSN_PIN, GPIO_PIN_RESET)
#define NRF24L01_CSN_HIGH			HAL_GPIO_WritePin(NRF24L01_CSN_PORT, NRF24L01_CSN_PIN, GPIO_PIN_SET)


uint8_t TM_SPI_Send(SPI_HandleTypeDef* SPIx, uint8_t data);

void TM_SPI_ReadMulti(SPI_HandleTypeDef* SPIx, uint8_t *dataIn, uint8_t dummy, uint32_t count);

void TM_SPI_SendMulti(SPI_HandleTypeDef* SPIx, uint8_t* dataOut, uint8_t* dataIn, uint32_t count);

void TM_SPI_WriteMulti(SPI_HandleTypeDef* SPIx, uint8_t* dataOut, uint32_t count);


#endif /* DEFINES_H_ */
