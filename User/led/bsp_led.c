#include "bsp_led.h"

/*

//void gpio_led (void);

//void gpio_led (void)
//{

//GPIO_InitTypeDef  GPIO_InitStruct;

//GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
//	
//GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//	
//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP ;
//	
//GPIO_InitStruct.GPIO_Speed = GPIO_25MHz_Speed ;
//	


//}


*/
void led_red(void)
{
	//RED��
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*6));
	GPIOF->ODR &=~(1<<6);
}

void led_green(void)
{
	//GREEN��
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*7));
	GPIOF->ODR &=~(1<<7);
}
void led_blue(void)
{
	//BLUE��
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*8));
	GPIOF->ODR &=~(1<<8);
}

void led_config(void)
{
/* ---------����LED---------���ɹ���*/	
/*	����
	1.��gpio�˿�ʱ��
	RCC_AHB1ENR  |=(1<<5);
	  |��Ϊ�˱�֤����λ����Ӱ�죬����ʹ��5λΪ1	
	2.����MODER
	  �����moder����λ���ƣ�����Ҫ�������㣬�ٽ�������
	GPIO_MODER &=~(3<<(2*6));
	  &֮ǰ�Ĳ�����ʹĿ�������λΪ1������λΪ0��Ȼ��ȡ����Ŀ��λΪ0������λΪ1��
	  ��ԭ�����������Ŀ��λΪ0,����λ1
	GPIO_MODER |=(1<<(2*6));
	3.��gpio���0��1��ODR�Ĵ�������BSRR�Ĵ���
	GPIO_ODR |=(1<<6);
*/
	led_red();
	led_green();
  led_blue();
	
	GPIOF->ODR |=(1<<6);
	GPIOF->ODR |=(1<<7);
	GPIOF->ODR |=(1<<8);
}	
void turn_red(void)
{
  RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*6));
	
	GPIOF->ODR ^=(1<<6);
}

void turn_green(void)
{
  RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*7));
	GPIOF->ODR ^=(1<<7);
}

void turn_blue(void)
{
  RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*8));


	GPIOF->ODR ^=(1<<8);
	
}

