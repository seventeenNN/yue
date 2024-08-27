#include "bsp_exti.h"

void key_exti(void)	
{
//开时钟
	RCC_APB2ENR |= RCC_APB1ENR_PWREN;
	RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	
	GPIOA->MODER |=0;//输入模式
	GPIOA->PUPDR |=0;
//选择输入线
	SYSCFG_EXTICR1 |= SYSCFG_EXTICR1_PA0;
	
//配置EXTI
	EXTI_IMR |= EXTI_IMR_0;//中断屏蔽寄存器
	//EXTI_EMR |= EXTI_EMR_0;//事件屏蔽寄存器
  EXTI_RTSR |= EXTI_RTSR_0;//选择上升沿触发
	
	
	//NVIC
	
	NVIC_ISER0 |=(1UL<<6);//使能
	
	

}





