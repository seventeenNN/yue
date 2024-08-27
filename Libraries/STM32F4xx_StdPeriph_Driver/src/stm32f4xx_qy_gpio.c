#include "stm32f4xx_qy_gpio.h"

//GPIO��ʼ������	
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
	
	//��ʱ��
		if (GPIOx == GPIOA)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
else if (GPIOx == GPIOB)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
else if (GPIOx == GPIOC)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
else if (GPIOx == GPIOD)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIODEN;
else if (GPIOx == GPIOE)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
else if (GPIOx == GPIOF)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
else if (GPIOx == GPIOG)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
else if (GPIOx == GPIOH)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
else if (GPIOx == GPIOI)
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOIEN;

//����ģʽ
//�����������ģʽʱ����Ҫ����
if((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT)||(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
{
}


}	

void gpio_usart_PA9PA10(void)
{
	
RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
GPIOA->MODER |= (GPIO_Mode_AF<<2*9);
GPIOA->MODER |= (GPIO_Mode_AF<<2*10);
GPIOA->AFRH  |=0x00000070;//PA9����
GPIOA->AFRH  |=0x00000700;//PA10���ù���


}
	