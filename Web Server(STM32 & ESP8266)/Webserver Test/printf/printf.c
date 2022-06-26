/*
 * printf1.c
 *
 *  Created on: Jun 2, 2022
 *      Author: sidiyer27
 */

#include "printf.h"

void serialPrint(char *msg, ...){
	char buff[800];
	va_list args;
	va_start(args,msg);
	vsprintf(buff,msg,args);
	for(int i = 0; i < strlen(buff); i++)
	{
	USART1->DR = buff[i];
	while(!(USART1->SR & USART_SR_TXE)){;}
	}

}

void serialPrintInit(int baud){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_USART1EN;
	GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_MODE9_1;
	GPIOA->CRH &= ~(GPIO_CRH_CNF9_0);
	USART1->BRR = 72000000/baud;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_UE;
}
