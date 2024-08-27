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
	//RED红
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*6));
	GPIOF->ODR &=~(1<<6);
}

void led_green(void)
{
	//GREEN绿
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*7));
	GPIOF->ODR &=~(1<<7);
}
void led_blue(void)
{
	//BLUE蓝
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*8));
	GPIOF->ODR &=~(1<<8);
}

void led_config(void)
{
/* ---------点亮LED---------（成功）*/	
/*	步骤
	1.开gpio端口时钟
	RCC_AHB1ENR  |=(1<<5);
	  |是为了保证其他位不受影响，但是使第5位为1	
	2.配置MODER
	  这里的moder有两位控制，首先要进行清零，再进行设置
	GPIO_MODER &=~(3<<(2*6));
	  &之前的操作，使目标的两个位为1，其他位为0，然后取反，目标位为0，其他位为1，
	  与原来的与操作后，目标位为0,其他位1
	GPIO_MODER |=(1<<(2*6));
	3.让gpio输出0或1，ODR寄存器或者BSRR寄存器
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

