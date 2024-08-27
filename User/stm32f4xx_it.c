#include "stm32f4xx_it.h"
#include "bsp_led.h"




void NMI_Handler(void){}
void HardFault_Handler(void){/* 在发生硬故障异常时进入无限循环 */
     while (1){}}
void MemManage_Handler(void){/* Go to infinite loop when Memory Manage exception occurs */
     while (1){}}
void BusFault_Handler(void){ /* Go to infinite loop when Bus Fault exception occurs */
     while (1){}}
void UsageFault_Handler(void){/* Go to infinite loop when Usage Fault exception occurs */
     while (1){}}
void DebugMon_Handler(void){}
void SVC_Handler(void){}
void PendSV_Handler(void){}
void SysTick_Handler(void){}


void EXTI0_IRQHandler(void)
{
	//如果有中断挂起请求
if((EXTI_PR & EXTI_PR_TEST)==EXTI_PR_0)//如果有挂起请求
{
	
  led_blue ();

  int temp=0xfffff;
	for(temp=0xfffff ;temp  !=0;temp --);
	
	GPIOF->ODR |=(1UL<<8);
	//led_green ();	
	
	EXTI_PR |=EXTI_PR_0 ;//清除标记?????居然是写入1清除

/**
	*PRx：挂起位 (Pending bit)
  *0：没有发生触发请求 
  *1：发生了选择的触发请求 
  *当在外部中断线上发生了选择的边沿事件，该位被置“1”。在此位中写入“1”可以清除它，
  *也可以通过改变边沿检测的极性清除。
	*/

}	

}
