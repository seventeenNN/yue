#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_dma.h"
#include "./exti/bsp_exti.h"
#include "bsp_iwdg.h"
#include "bsp_usart.h"

void delay( unsigned int count)
{
	for(;count !=0;count--);
}


 	
/*  DMA:M->M传输
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
	*/		
	




/*  PA0通过EXTI发出中断请求

	key_exti();
	
	while(1);

**/
	




/*  IWDG喂狗以及模拟程序复位 
1.定期正常喂狗，while中程序会正常
2.当超时未及时喂狗，会复位，重新进入main函数

LSI_OPEN();
init_iwdg(0xfff);

while(1)
{
	turn_blue ();
  feed_iwdg();
 for (volatile int i = 0; i < 0xfffff; i++)
	{
		//模拟程序运行
	}

}
*/
int main(void) 
{gpio_usart_PA9PA10();
//gpio设置为复用模式
 usart_PA9PA10_init();
    // 发送字符串
    USART1_SendString("Hello, USART1!\r\n");

while (1) 
{
	//printf("hello");

	// 接收字符并发送回去
        char receivedChar = USART1_ReceiveChar();
	   USART1_SendChar('a');
	//乱码？？？？？

	
     

}

}	
