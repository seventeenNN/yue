#include "stm32f4xx_it.h"
#include "bsp_led.h"




void NMI_Handler(void){}
void HardFault_Handler(void){/* �ڷ���Ӳ�����쳣ʱ��������ѭ�� */
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
	//������жϹ�������
if((EXTI_PR & EXTI_PR_TEST)==EXTI_PR_0)//����й�������
{
	
  led_blue ();

  int temp=0xfffff;
	for(temp=0xfffff ;temp  !=0;temp --);
	
	GPIOF->ODR |=(1UL<<8);
	//led_green ();	
	
	EXTI_PR |=EXTI_PR_0 ;//������?????��Ȼ��д��1���

/**
	*PRx������λ (Pending bit)
  *0��û�з����������� 
  *1��������ѡ��Ĵ������� 
  *�����ⲿ�ж����Ϸ�����ѡ��ı����¼�����λ���á�1�����ڴ�λ��д�롰1�������������
  *Ҳ����ͨ���ı���ؼ��ļ��������
	*/

}	

}
