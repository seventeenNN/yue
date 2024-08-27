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
    while (!(USART1->SR & USART_SR_TXE)); // �ȴ����ͻ�����Ϊ��
    USART1->DR = c; // �����ַ�
}


char USART1_ReceiveChar(void) 
{
    while (!(USART1->SR & USART_SR_RXNE)); // �ȴ����ջ������ǿ�
    return USART1->DR; // ��ȡ���յ����ַ�
}


void USART1_SendString(const char *str)
{
    while (*str) {
        USART1_SendChar(*str++);
    }
}
