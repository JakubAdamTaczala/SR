
#include "main_module_radio.h"

/* My address */
uint8_t MyAddress[] = { 0xE7, 0xE7, 0xE7, 0xE7, 0xE7 };
/* Receiver address */
uint8_t Address[] = { 0x7E, 0x7E, 0x7E, 0x7E, 0x7E };

void mainModuleRadioInit() {
	TM_NRF24L01_Init(15, 32);

	/* Set RF settings, Data rate to 2Mbps, Output power to -18dBm */
	TM_NRF24L01_SetRF(TM_NRF24L01_DataRate_2M, TM_NRF24L01_OutputPower_M18dBm);

	/* Set my address, 5 bytes */
	TM_NRF24L01_SetMyAddress(MyAddress);
	/* Set TX address, 5 bytes */
	TM_NRF24L01_SetTxAddress(Address);
}
