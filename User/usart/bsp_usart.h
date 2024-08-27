#ifndef _BSP_USART_H
#define _BSP_USART_H

#include "stm32f4xx.h"
#include "stm32f4xx_qy_gpio.h"


#define USART_EN      (1UL<<13)
#define TE_EN         (1UL<<3)
#define RE_EN         (1UL<<2)
#define CLK_EN        (1UL<<11)
#define TC_IT_EN      (1UL<<6)

#define M_8           (0UL<<12)
#define M_9           (1UL<<12)
#define BRR_9600      0x1117
#define BRR_115200    0x016C


#define USART_SR_TXE  (1UL<<7)
#define USART_SR_RXNE (1UL<<5)


#define RCC_APB2ENR_USART1   (1UL<<4)

void usart_PA9PA10_init(void);
void USART1_SendChar(char c);
char USART1_ReceiveChar(void);
void USART1_SendString(const char *str);




#endif /* _BSP_USART_H */

