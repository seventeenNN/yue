#include "bsp_exti.h"

void key_exti(void)	
{
//��ʱ��
	RCC_APB2ENR |= RCC_APB1ENR_PWREN;
	RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	
	GPIOA->MODER |=0;//����ģʽ
	GPIOA->PUPDR |=0;
//ѡ��������
	SYSCFG_EXTICR1 |= SYSCFG_EXTICR1_PA0;
	
//����EXTI
	EXTI_IMR |= EXTI_IMR_0;//�ж����μĴ���
	//EXTI_EMR |= EXTI_EMR_0;//�¼����μĴ���
  EXTI_RTSR |= EXTI_RTSR_0;//ѡ�������ش���
	
	
	//NVIC
	
	NVIC_ISER0 |=(1UL<<6);//ʹ��
	
	

}





