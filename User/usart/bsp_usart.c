#include "bsp_usart.h"

void usart_PA9PA10_init(void)
{
	
	
RCC_APB2ENR |=RCC_APB2ENR_USART1;
	
USART1->CR1 |= USART_EN;
USART1->CR1 |= TE_EN;
USART1->CR1 |= RE_EN;
USART1->CR1 |= M_8;
//USART1->CR1 |= TC_IT_EN;

USART1->BRR |=BRR_115200;

}


void USART1_SendChar(char c) 
	
{
    while (!(USART1->SR & USART_SR_TXE)); // 等待发送缓冲区为空
    USART1->DR = c; // 发送字符
}


char USART1_ReceiveChar(void) 
{
    while (!(USART1->SR & USART_SR_RXNE)); // 等待接收缓冲区非空
    return USART1->DR; // 读取接收到的字符
}


void USART1_SendString(const char *str)
{
    while (*str) {
        USART1_SendChar(*str++);
    }
}
