#include "stm32f4xx.h"
#include "LED.h"




void delay( unsigned int count)
{
	for(;count !=0;count--);


}
void LED_config(void)//����led
{
	
	

	//1.��gpio�˿�ʱ��
   RCC_AHB1ENR  |=(1<<5);
	//|��Ϊ�˱�֤����λ����Ӱ�죬����ʹ��5λΪ1
	
	//2.����MODER
	
	/*�����moder����λ���ƣ�����Ҫ�������㣬�ٽ�������*/
	//GPIO_MODER &=~(3<<(2*6));
	//&֮ǰ�Ĳ�����ʹĿ�������λΪ1������λΪ0��Ȼ��ȡ����Ŀ��λΪ0������λΪ1��
	//��ԭ�����������Ŀ��λΪ0,����λ1
	GPIO_MODER |=(1<<(2*6));


	//3.��gpio���0��1��ODR�Ĵ�������BSRR�Ĵ���
	
	GPIO_ODR |=(1<<6);
	
	
	//��˸
	while (1)
	{
		GPIO_ODR &=~(1<<6);
		
		delay(0x0fffff);
		
		GPIO_ODR |=(1<<6);
 
		delay(0x0fffff);

	}		
}




