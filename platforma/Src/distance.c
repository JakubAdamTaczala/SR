/*
 * distance.c
 *
 *  Created on: 10.06.2018
 *      Author: Rafa³
 */

#include "distance.h"


float HCSR04READ1(void)
{
 uint32_t time;
 uint32_t timeout;
 //float dystans = 0;
 //Sygnal niski na trigger
 HAL_GPIO_WritePin(Trig_1_GPIO_Port,Trig_1_Pin,GPIO_PIN_RESET);
 //Opóznienie 2us
 DWT_Delay_us(10000);
 //Sygnal wysoki na trigger
 HAL_GPIO_WritePin(Trig_1_GPIO_Port,Trig_1_Pin,GPIO_PIN_SET);
 //Opóznienie 10 us
 DWT_Delay_us(15);
 //Sygnal niski na trigger
 HAL_GPIO_WritePin(Trig_1_GPIO_Port,Trig_1_Pin,GPIO_PIN_RESET);

 //Po takiej inicjalizacji nastepuje dokonanie pomiarow

 //Troche czasu na odpowiedz
 timeout = 30000;
 while (HAL_GPIO_ReadPin(Echo_1_GPIO_Port,Echo_1_Pin) == GPIO_PIN_RESET)
 {
 DWT_Delay_us(1);
 timeout--;
  if (timeout <= 0x00)
  {
   return -1;
  }
 }

 //Rozpoczecie pomiaru czasu impulsu
 //time = HAL_GetTick();
 time=0;
 //Wpisanie tekstu
 //Petla while czeka do momentu kiedy sygnal bedzie 0
 while (HAL_GPIO_ReadPin(Echo_1_GPIO_Port,Echo_1_Pin) == GPIO_PIN_SET){
	 time++;
	 DWT_Delay_us(1);
 }
 //Pobranie czasu trwania stanu wysokiego
 //time = HAL_GetTick() - time;
 //Obliczenie odleglosci
 //dystans = (float)time / 58.0;
 //Zwrócenie odleglosci
 return time;
}



float HCSR04READ2(void)
{ uint32_t time;
uint32_t timeout;
//float dystans = 0;
//Sygnal niski na trigger
HAL_GPIO_WritePin(Trig_2_GPIO_Port,Trig_2_Pin,GPIO_PIN_RESET);
//Opóznienie 2us
DWT_Delay_us(10000);
//Sygnal wysoki na trigger
HAL_GPIO_WritePin(Trig_2_GPIO_Port,Trig_2_Pin,GPIO_PIN_SET);
//Opóznienie 10 us
DWT_Delay_us(15);
//Sygnal niski na trigger
HAL_GPIO_WritePin(Trig_2_GPIO_Port,Trig_2_Pin,GPIO_PIN_RESET);

//Po takiej inicjalizacji nastepuje dokonanie pomiarow

//Troche czasu na odpowiedz
timeout = 30000;
while (HAL_GPIO_ReadPin(Echo_2_GPIO_Port,Echo_2_Pin) == GPIO_PIN_RESET)
{
DWT_Delay_us(1);
timeout--;
 if (timeout <= 0x00)
 {
  return -1;
 }
}

time=0;
//Petla while czeka do momentu kiedy sygnal bedzie 1
while (HAL_GPIO_ReadPin(Echo_2_GPIO_Port,Echo_2_Pin) == GPIO_PIN_SET){
	 time++;
	 DWT_Delay_us(1);
}

return time;
}


float HCSR04READ3(void)
{
 uint32_t time;
 uint32_t timeout;
 //float dystans = 0;
 //Sygnal niski na trigger
 HAL_GPIO_WritePin(Trig_3_GPIO_Port,Trig_3_Pin,GPIO_PIN_RESET);
 //Opóznienie 2us
 DWT_Delay_us(10000);
 //Sygnal wysoki na trigger
 HAL_GPIO_WritePin(Trig_3_GPIO_Port,Trig_3_Pin,GPIO_PIN_SET);
 //Opóznienie 10 us
 DWT_Delay_us(15);
 //Sygnal niski na trigger
 HAL_GPIO_WritePin(Trig_3_GPIO_Port,Trig_3_Pin,GPIO_PIN_RESET);

 //Po takiej inicjalizacji nastepuje dokonanie pomiarow

 //Troche czasu na odpowiedz
 timeout = 30000;
 while (HAL_GPIO_ReadPin(Echo_3_GPIO_Port,Echo_3_Pin) == GPIO_PIN_RESET)
 {
 DWT_Delay_us(1);
 timeout--;
  if (timeout <= 0x00)
  {
   return 0;
  }
 }

 time=0;

 while (HAL_GPIO_ReadPin(Echo_3_GPIO_Port,Echo_3_Pin) == GPIO_PIN_SET){
	 time++;
	 DWT_Delay_us(1);
 }

 return time;
}


uint8_t HCSR04_Init(void)
{
 HAL_GPIO_WritePin(Trig_1_GPIO_Port,Trig_1_Pin,GPIO_PIN_RESET);
 HAL_GPIO_WritePin(Trig_2_GPIO_Port,Trig_2_Pin,GPIO_PIN_RESET);
 HAL_GPIO_WritePin(Trig_3_GPIO_Port,Trig_3_Pin,GPIO_PIN_RESET);

}
