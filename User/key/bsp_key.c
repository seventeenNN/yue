#include "bsp_key.h"
#include "bsp_led.h"

void key(void)
{
 //1.开时钟,配置寄存器
RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOAEN;
RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOCEN;	
 // 配置GPIOA的PIN0为输入
GPIOA->MODER &= ~(3UL << (0  * 2));
 //配置GPIOC的PIN13为输入
GPIOC->MODER &= ~(3UL << (13  * 2));

led_config();

//持续监测输入寄存器状态	
/*	PA0       (成功) */

while(1)
	{// 检测按键按下
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

/*  PC13      (成功)
while(1)	
{// 检测按键按下
		if( (GPIOC->IDR & PIN13 )==(KEY_ON<<13)  )	
			{   			
				
// ??为什么这个不会执行 
// !!注意这里的结果不是1，而是1<<13!!!		
				
					GPIOF->ODR |=(1<<6);// 按键按下,不亮
		//		GPIOF->ODR &=~(1<<6);// 按键按下,亮
		   }      
    else {
					GPIOF->ODR &=~(1<<6); // 按键释放,亮
			//	GPIOF->ODR |=(1<<6);// 按键释放,不亮
          }
}

*/
	
/*  PA0+PC13	(成功)
	while(1)
	
	{// 检测按键按下
		if(((GPIOA->IDR & PIN0 )==KEY_ON) &((GPIOC->IDR & PIN13 )==(KEY_ON<<13)) )	//两个一起按下去
	//if(((GPIOA->IDR & PIN0 )==KEY_ON) |((GPIOC->IDR & PIN13 )==(KEY_ON<<13)) )
			{   			
					GPIOF->ODR |=(1<<6);// 按键按下,不亮
		//		GPIOF->ODR &=~(1<<6);// 按键按下,亮
		   }      
    else {
					GPIOF->ODR &=~(1<<6); // 按键释放,亮
		//		GPIOF->ODR |=(1<<6);// 按键释放,不亮
          }
	}
*/	
	
	
}


void buzzer(void)//(成功)
{

RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOGEN;
GPIOG->MODER |=(1<<(2*7));
GPIOG->OTYPER &=~(1<<7);//复位状态
GPIOG->OSPEEDR |=(3<<(2*7));
GPIOG->PUPDR  &=~(3<<(2*7));//复位状态
//GPIOG->ODR &=~(1<<7);
//GPIOG->ODR |=(1<<7);//响亮的哔一声
while(1)
		{
			delay(0xfffff);
			GPIOG->ODR |=(1<<7);//响亮的哔一声
			delay(0xfffff);
			GPIOG->ODR &=~(1<<7);//停止
		}
}


