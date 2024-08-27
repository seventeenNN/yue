#include "bsp_key.h"
#include "bsp_led.h"

void key(void)
{
 //1.��ʱ��,���üĴ���
RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOAEN;
RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOCEN;	
 // ����GPIOA��PIN0Ϊ����
GPIOA->MODER &= ~(3UL << (0  * 2));
 //����GPIOC��PIN13Ϊ����
GPIOC->MODER &= ~(3UL << (13  * 2));

led_config();

//�����������Ĵ���״̬	
/*	PA0       (�ɹ�) */

while(1)
	{// ��ⰴ������
		if( (GPIOA->IDR & PIN0 )==KEY_ON )	
			{   		
   				//GPIOF->ODR |=(1<<6); 
				   //GPIOF->ODR |=(1<<7);
  				//	GPIOF->ODR |=(1<<8);
					//GPIOF->ODR &=~(1<<6);
				  //GPIOF->ODR &=~(1<<7);
					GPIOF->ODR &=~(1<<8);
				
		   }      
    else {
   				//GPIOF->ODR |=(1<<6); 
					//GPIOF->ODR |=(1<<7);
					GPIOF->ODR |=(1<<8);
					//GPIOF->ODR &=~(1<<6);
					//GPIOF->ODR &=~(1<<7);
					//GPIOF->ODR &=~(1<<8);
			
          }
	}

/*  PC13      (�ɹ�)
while(1)	
{// ��ⰴ������
		if( (GPIOC->IDR & PIN13 )==(KEY_ON<<13)  )	
			{   			
				
// ??Ϊʲô�������ִ�� 
// !!ע������Ľ������1������1<<13!!!		
				
					GPIOF->ODR |=(1<<6);// ��������,����
		//		GPIOF->ODR &=~(1<<6);// ��������,��
		   }      
    else {
					GPIOF->ODR &=~(1<<6); // �����ͷ�,��
			//	GPIOF->ODR |=(1<<6);// �����ͷ�,����
          }
}

*/
	
/*  PA0+PC13	(�ɹ�)
	while(1)
	
	{// ��ⰴ������
		if(((GPIOA->IDR & PIN0 )==KEY_ON) &((GPIOC->IDR & PIN13 )==(KEY_ON<<13)) )	//����һ����ȥ
	//if(((GPIOA->IDR & PIN0 )==KEY_ON) |((GPIOC->IDR & PIN13 )==(KEY_ON<<13)) )
			{   			
					GPIOF->ODR |=(1<<6);// ��������,����
		//		GPIOF->ODR &=~(1<<6);// ��������,��
		   }      
    else {
					GPIOF->ODR &=~(1<<6); // �����ͷ�,��
		//		GPIOF->ODR |=(1<<6);// �����ͷ�,����
          }
	}
*/	
	
	
}


void buzzer(void)//(�ɹ�)
{

RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOGEN;
GPIOG->MODER |=(1<<(2*7));
GPIOG->OTYPER &=~(1<<7);//��λ״̬
GPIOG->OSPEEDR |=(3<<(2*7));
GPIOG->PUPDR  &=~(3<<(2*7));//��λ״̬
//GPIOG->ODR &=~(1<<7);
//GPIOG->ODR |=(1<<7);//��������һ��
while(1)
		{
			delay(0xfffff);
			GPIOG->ODR |=(1<<7);//��������һ��
			delay(0xfffff);
			GPIOG->ODR &=~(1<<7);//ֹͣ
		}
}


