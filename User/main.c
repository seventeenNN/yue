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


 	
/*  DMA:M->M����
    // ��ʼ��DMA
DMA_Init();
    // �ȴ�DMA�������
while (!(DMA2_LISR & DMA_LISR_TCIF0));
    // ���������ɱ�־
DMA2_LISR &= ~DMA_LISR_TCIF0;

    // ���Ŀ�껺����
for (uint32_t i = 0; i < DATA_SIZE; i++)
		{
        if (destination_buffer[i] != source_buffer[i])
					{
            // ���������
            while (1)
						{
							led_red(); 
							
						}
	
					}
		}
    // ����ɹ�
while (1)
		{
		  led_green ();
			
		}
	*/		
	




/*  PA0ͨ��EXTI�����ж�����

	key_exti();
	
	while(1);

**/
	




/*  IWDGι���Լ�ģ�����λ 
1.��������ι����while�г��������
2.����ʱδ��ʱι�����Ḵλ�����½���main����

LSI_OPEN();
init_iwdg(0xfff);

while(1)
{
	turn_blue ();
  feed_iwdg();
 for (volatile int i = 0; i < 0xfffff; i++)
	{
		//ģ���������
	}

}
*/
int main(void) 
{gpio_usart_PA9PA10();
//gpio����Ϊ����ģʽ
 usart_PA9PA10_init();
    // �����ַ���
    USART1_SendString("Hello, USART1!\r\n");

while (1) 
{
	//printf("hello");

	// �����ַ������ͻ�ȥ
        char receivedChar = USART1_ReceiveChar();
	   USART1_SendChar('a');
	//���룿��������

	
     

}

}	
