#include "stm32f4xx.h"
void delay( unsigned int count)
{
	for(;count !=0;count--);
}



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
	
/*-----------闪烁-----------（成功）*/
/*
while (1)
	{
		GPIO_ODR &=~(1<<6);
		
		delay(0x0fffff);
		
		GPIO_ODR |=(1<<6);
 
		delay(0x0fffff);

	}		

*/


}




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


	// 定义源和目标内存区域
#define SOURCE_ADDRESS     ((uint32_t)source_buffer)
#define DESTINATION_ADDRESS ((uint32_t)destination_buffer)
#define DATA_SIZE          100  // 传输数据的大小

// 定义缓冲区
uint32_t source_buffer[DATA_SIZE];
uint32_t destination_buffer[DATA_SIZE];

void DMA_Init(void) 
{
	 // 填充源缓冲区
    for (uint32_t i = 0; i < DATA_SIZE; i++) 
	{
        source_buffer[i] = i;
    }
	
	  // 初始化DMA
    // 使能DMA2时钟
    RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;

 
    // 配置数据大小和传输数量
    DMA_SxNDTR(2, 0) = DATA_SIZE;

    // 配置源和目标地址
    DMA_SxPAR(2, 0) = SOURCE_ADDRESS;
    DMA_SxM0AR(2, 0) = DESTINATION_ADDRESS;
		

		// 配置DMA流
		//  DMA_SxCR(2, 0) =0; // 清除
    DMA_SxCR(2, 0) &=~ DMA_SxCR_EN;
		DMA_SxCR(2, 0) |= (0 << 25); // 选择通道
    DMA_SxCR(2, 0) |= DMA_SxCR_DIR_MM; // 设置数据传输方向为内存到内存
    DMA_SxCR(2, 0) |= DMA_SxCR_MINC ;
	  DMA_SxCR(2, 0) |= DMA_SxCR_PINC; // 使能内存和外设地址自增
    DMA_SxCR(2, 0) |= DMA_SxCR_PL_VH; // 设置优先级为非常高
		
		
		//错误原因：这两行，传输数据的大小有要求的
    DMA_SxCR(2, 0) |= DMA_SxCR_MSIZE_WORD ;
    DMA_SxCR(2, 0) |= DMA_SxCR_PSIZE_WORD ;

    // 使能DMA流
    DMA_SxCR(2, 0) |= DMA_SxCR_EN;
		

}


#define RGB_SIZE   1

uint16_t RGB_ADD[RGB_SIZE]={
//	0xFFFFFFBF,//red
//	0xFFFFFF7F,//green
//	0x0,0x0,
	0xFEFF,//blue
};

void DMA_RGB_Init(void) 
{
	 
    // 使能DMA2时钟
    RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;

 
    // 配置数据大小和传输数量
    DMA_SxNDTR(2, 1) = RGB_SIZE;

    // 配置源和目标地址
    DMA_SxM0AR(2, 1) = (uint16_t )RGB_ADD;
    DMA_SxPAR(2, 1) = (uint16_t )&(GPIOF->ODR);
		

		// 配置DMA流
		//  DMA_SxCR(2, 0) =0; // 清除
    DMA_SxCR(2, 1) &=~ DMA_SxCR_EN;
		DMA_SxCR(2, 1) |= (0 << 25); // 选择通道
    DMA_SxCR(2, 1) |= DMA_SxCR_DIR_MP; // 设置数据传输方向为内存到外设
    DMA_SxCR(2, 1) |= DMA_SxCR_MINC ;
	  DMA_SxCR(2, 1) |= DMA_SxCR_PINC; // 使能内存和外设地址自增
    DMA_SxCR(2, 1) |= DMA_SxCR_PL_VH; // 设置优先级为非常高
		//DMA_SxCR(2, 0) |= DMA_SxCR_CIRC ;//循环模式

    DMA_SxCR(2, 1) |= DMA_SxCR_MSIZE_HWORD ;
    DMA_SxCR(2, 1) |= DMA_SxCR_PSIZE_HWORD ;

    // 使能DMA流
    DMA_SxCR(2, 1) |= DMA_SxCR_EN;
		
		    if (DMA_SxCR(2, 1) & DMA_LISR_TCIF1) // 检查传输完成标志
    {
        DMA_SxCR(2, 1) &= ~DMA_LISR_TCIF1; // 清除标志
			
			if((GPIOF->ODR &(1UL<<8))==0)
			{
			led_red ();
			
			}


    }
		
		
		
		
		
		
	}
int main(void) 
{ 	
//	
//	led_config ();
//	
//	DMA_RGB_Init();


	 //key();
	 //buzzer ();
/**/
	
	
    // 初始化DMA
DMA_Init();
    // 等待DMA传输完成
while (!(DMA2_LISR & DMA_LISR_TCIF0));
    // 清除传输完成标志
DMA2_LISR &= ~DMA_LISR_TCIF0;

    // 检查目标缓冲区
for (uint32_t i = 0; i < DATA_SIZE; i++)
		{
        if (destination_buffer[i] != source_buffer[i])
					{
            // 传输错误处理
            while (1)
						{
							led_red(); 
							
						}
	
					}
		}
    // 传输成功
while (1)
		{
		  led_green ();
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
//RCC_APB1ENR |= RCC_APB1ENR_PWREN;


//PWR_CR |= PWR_CR_VOS;

	
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


