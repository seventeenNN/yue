#include "stm32f4xx.h"

//记得打开options for target里面的use ，microLTB才能执行.c文件
void delay( unsigned int count)
{
	for(;count !=0;count--);
}

int main()
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
	RCC_AHB1ENR  |=(1<<5);
	GPIO_MODER |=(1<<(2*6));
	GPIO_ODR &=~(1<<6);
	
/*-----------闪烁-----------（成功）*/

while (1)
	{
		GPIO_ODR &=~(1<<6);
		
		delay(0x0fffff);
		
		GPIO_ODR |=(1<<6);
 
		delay(0x0fffff);

	}		

}



void SystemInit (void )
{
	
/* ----------HSE----------（成功） */
/* 步骤
//1.开HSE	    
			//	RCC_CR  |= RCC_CR_HSEON;
//2.等待HSE稳定，并且检查
			//	while(!(RCC_CR & RCC_CR_HSERDY ));
	// 想要对照某一位是否已经完成硬件置1，定义一个该位为1的宏，并将想要对照的地址，相与 
//1.1.SW选择为hse
			//	RCC_CFGR |= RCC_CFGR_SW_HSE;
//1.2.等待硬件配置选择好HSE
			//while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
*/
	
/* 代码
		
	
	
	RCC_CR  |= RCC_CR_HSEON;
	while(!(RCC_CR & RCC_CR_HSERDY ));
	RCC_CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
*/



/* ----------HSI----------（成功）*/	
/* 步骤
//1.开HSI	    
				RCC_CR  |= RCC_CR_HSION;
//2.等待HSI稳定，并且检查
				while(!(RCC_CR & RCC_CR_HSIRDY ));
//1.1.SW选择为HSI
				RCC_CFGR |= RCC_CFGR_SW_HSI;
//1.2.等待硬件配置选择好HSI
				while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);	
*/
/* 代码

RCC_CR  |= RCC_CR_HSION;
while(!(RCC_CR & RCC_CR_HSIRDY ));
RCC_CFGR |= RCC_CFGR_SW_HSI;
while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);	

*/





/* ----------PLL---------- (成功) */	
/* 步骤
	
2.0 打开HSE/HSI并稳定运行，并选择	
  选择HSE作为时钟输入	
	RCC_PLLCFGR |=RCC_PLLCFGR_PLLSRC;  （HSE）
	选择HSI作为时钟输入
	RCC_PLLCFGR &=~RCC_PLLCFGR_PLLSRC; （HSI）
2.1	配置PLL参数		
		RCC_PLLCFGR |=PLL_M_HSE ;
		RCC_PLLCFGR |=PLL_N ;
		RCC_PLLCFGR |=PLL_P ;
		RCC_PLLCFGR |=PLL_Q ;	
		RCC_PLLCFGR |=RCC_PLLCFGR_PLLSRC;		
RCC_PLLCFGR = (PLL_M_HSE << 0) | (PLL_N << 6) | (PLL_P << 16) | (PLL_Q << 24) | (RCC_PLLCFGR_PLLSRC);
2.2 使能PLL ，并等待完成
		RCC_CR |=RCC_CR_PLLON ;
		while(!(RCC_CR & RCC_CR_PLLRDY ))	;	
2.3 SW选择PLL
		RCC_CFGR |=RCC_CFGR_SW_PLL;
2.4 等待硬件选择完成	 	
		while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
*/
  RCC_CR  |= RCC_CR_HSEON;
	while((RCC_CR & RCC_CR_HSERDY )==0); 
	
	
	//使能电源接口时钟
RCC_APB1ENR |= RCC_APB1ENR_PWREN;


PWR_CR |= PWR_CR_VOS;

	
// 配置AHB分频器
RCC_CFGR |= AHB_PRESCALER ;

// 配置APB1分频器
RCC_CFGR |= APB1_PRESCALER ;

// 配置APB2分频器
RCC_CFGR |= APB2_PRESCALER ;
	
	RCC_PLLCFGR |=PLL_M_HSE ;
		RCC_PLLCFGR |=PLL_N ;
		RCC_PLLCFGR |=PLL_P ;
		RCC_PLLCFGR |=PLL_Q ;	
		RCC_PLLCFGR |=RCC_PLLCFGR_PLLSRC;		
 // RCC_PLLCFGR = (PLL_M_HSE << 0) | (PLL_N << 6) | (PLL_P << 16) | (PLL_Q << 24) | (RCC_PLLCFGR_PLLSRC);
 
 
  RCC_CR |=RCC_CR_PLLON ;
  while((RCC_CR & RCC_CR_PLLRDY ) == 0)	;
	
	/*为什么一定要加上这一行!!!!!!!!!!!!!!!!!!!!*/
	//Flash预取、指令缓存、数据缓存和等待状态
	FLASH_ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;

  RCC_CFGR |=RCC_CFGR_SW_PLL;
	while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);



}

