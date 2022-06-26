#include "UART.h"
#include "GPIO.h"


/***********************************************************************************************************************/
//                                                         UART
/***********************************************************************************************************************/

/**********************************************************************************************************************
 * @brief: This function sets up basic functions of UART (without clock)
 * @parameters:
 *              USART        ->       USART1
 *                                    USART2
 *                                    USART3
 *              baudrate     ->       2400
 *                                    9600
 *                                    19200
 *                                    57600
 *                                    115200
 *                                    230400
 *                                    460800
 *                                    921600
 *                                    2250000
 *                                    450000
 *              frame_length ->   0:  1 Start bit, 8 Data bits, n Stop bit
 *                                1:  1 Start bit, 9 Data bits, n Stop bit
 *              stop_bits    ->   0:  1 Stop bit
 *                                1:  0.5 Stop bit
 *                                2:  2 Stop bits
 *                                3:  1.5 Stop bit
 *
 **********************************************************************************************************************/


void UART_Setup(USART_TypeDef *USART,int baudrate, uint8_t frame_length, uint8_t stop_bits)
{
	if (USART == USART1)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
		GPIO_Pin_Init(GPIOA,9,ALT_PUSH_PULL_OUTPUT);
		GPIO_Pin_Init(GPIOA,8,FLOATING_INPUT);
		if(frame_length)
		{
			USART ->CR1 |= USART_CR1_M;
		}
		else
		{
			USART ->CR1 &= ~USART_CR1_M;
		}




		USART -> CR1 |= stop_bits << 12;
		USART ->BRR = (int)(72000000 /baudrate);

		USART ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
		USART ->CR1 |= USART_CR1_UE;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////
	if (USART == USART2)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
		RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
		GPIO_Pin_Init(GPIOA,2,ALT_PUSH_PULL_OUTPUT);
		GPIO_Pin_Init(GPIOA,3,FLOATING_INPUT);
		if(frame_length)
		{
			USART ->CR1 |= USART_CR1_M;
		}
		else
		{
			USART ->CR1 &= ~USART_CR1_M;
		}

		USART ->BRR = (int)(36000000 /baudrate);
		USART ->CR1 |= stop_bits << 12;
		USART ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
		USART ->CR1 |= USART_CR1_UE;
	}
}





/***********************************************************************************************************************
 * @brief: This function receives incoming data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *@return: UART 8 bit data
 ***********************************************************************************************************************/

uint8_t UART_Get_Data(USART_TypeDef *uart)
{
	while((uart->SR & USART_SR_RXNE) == 0);
	return uart -> DR;
}



/***********************************************************************************************************************
 * @brief: This function sends out data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *             data  -> 8 bit data
 ***********************************************************************************************************************/

int UART_Send_Data(USART_TypeDef *uart,uint8_t data)
{
	uart -> DR = data;
	while((uart->SR & USART_SR_TC) == 0);
	return data;
}
