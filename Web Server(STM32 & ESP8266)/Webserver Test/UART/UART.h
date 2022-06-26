#ifndef _USART_H_
#define _USART_H_


#include <stdbool.h>
#include "main.h"


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
 *              DMA_TX       ->   0:  DMA mode is enabled for transmission
 *                                1:  DMA mode is disabled for transmission
 *              DMA_RX       ->   0:  DMA mode is enabled for reception
 *                                1:  DMA mode is disabled for reception
 **********************************************************************************************************************/

void UART_Setup(USART_TypeDef *USART,int baudrate, uint8_t frame_length, uint8_t stop_bits);






/***********************************************************************************************************************
 * @brief: This function receives incoming data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *@return: UART 8 bit data
 ***********************************************************************************************************************/

uint8_t UART_Get_Data(USART_TypeDef *uart);



/***********************************************************************************************************************
 * @brief: This function sends out data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *             data  -> 8 bit data
 ***********************************************************************************************************************/

int UART_Send_Data(USART_TypeDef *uart,uint8_t data);


/***********************************************************************************************************************/
//                                                         USART
/***********************************************************************************************************************/

/**********************************************************************************************************************
 * @brief: This function sets up basic functions of USART1 (with clock)
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
 *              CPOL              0:  Steady low value on CK pin outside transmission window
 *                                1:  Steady high value on CK pin outside transmission window
 *              CPHA              0:  The first clock transition is the first data capture edge
 *                                1:  The second clock transition is the first data capture edge
 *              DMA_TX       ->   0:  DMA mode is enabled for transmission
 *                                1:  DMA mode is disabled for transmission
 *              DMA_RX       ->   0:  DMA mode is enabled for reception
 *                                1:  DMA mode is disabled for reception
 **********************************************************************************************************************/







#endif
