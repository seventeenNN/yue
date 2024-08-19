#include "stm32f4xx.h"
void delay( unsigned int count)
{
	for(;count !=0;count--);
}



void led_red(void)
{
	//RED��
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*6));
	GPIOF->ODR &=~(1<<6);
}

void led_green(void)
{
	//GREEN��
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*7));
	GPIOF->ODR &=~(1<<7);
}
void led_blue(void)
{
	//BLUE��
	RCC_AHB1ENR  |=RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER |=(1<<(2*8));
	GPIOF->ODR &=~(1<<8);
}

void led_config(void)
{
/* ---------����LED---------���ɹ���*/	
/*	����
	1.��gpio�˿�ʱ��
	RCC_AHB1ENR  |=(1<<5);
	  |��Ϊ�˱�֤����λ����Ӱ�죬����ʹ��5λΪ1	
	2.����MODER
	  �����moder����λ���ƣ�����Ҫ�������㣬�ٽ�������
	GPIO_MODER &=~(3<<(2*6));
	  &֮ǰ�Ĳ�����ʹĿ�������λΪ1������λΪ0��Ȼ��ȡ����Ŀ��λΪ0������λΪ1��
	  ��ԭ�����������Ŀ��λΪ0,����λ1
	GPIO_MODER |=(1<<(2*6));
	3.��gpio���0��1��ODR�Ĵ�������BSRR�Ĵ���
	GPIO_ODR |=(1<<6);
*/
	led_red();
	led_green();
  led_blue();
	
	GPIOF->ODR |=(1<<6);
	GPIOF->ODR |=(1<<7);
	GPIOF->ODR |=(1<<8);
	
/*-----------��˸-----------���ɹ���*/
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
/*	PA0       (�ɹ�) 

while(1)
	{// ��ⰴ������
		if( (GPIOA->IDR & PIN0 )==KEY_ON )	
			{   		
   				//GPIOF->ODR |=(1<<6); 
				   //GPIOF->ODR |=(1<<7);
  				//	GPIOF->ODR |=(1<<8);
					GPIOF->ODR &=~(1<<6);
				  //GPIOF->ODR &=~(1<<7);
					//GPIOF->ODR &=~(1<<8);
				
		   }      
    else {
   				GPIOF->ODR |=(1<<6); 
					//GPIOF->ODR |=(1<<7);
					//GPIOF->ODR |=(1<<8);
					//GPIOF->ODR &=~(1<<6);
					//GPIOF->ODR &=~(1<<7);
					//GPIOF->ODR &=~(1<<8);
			
          }
	}
*/
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

void DMA_Init(void) 
{// ��ʼ��DMA
    // ʹ��DMA2ʱ��
    RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;

    // ����DMA��
    DMA_SxCR(2, 0) &= ~DMA_SxCR_CHSEL; // ���ͨ��ѡ��λ
    DMA_SxCR(2, 0) |= (0 << 25); // ѡ��ͨ��
    DMA_SxCR(2, 0) |= DMA_SxCR_DIR_MM; // �������ݴ��䷽��Ϊ�ڴ浽�ڴ�
    DMA_SxCR(2, 0) |= DMA_SxCR_MINC ;
	  DMA_SxCR(2, 0) |= DMA_SxCR_PINC; // ʹ���ڴ�������ַ����
    DMA_SxCR(2, 0) |= DMA_SxCR_PL_VH; // �������ȼ�Ϊ�ǳ���

    // �������ݴ�С�ʹ�������
    DMA_SxNDTR(2, 0) = DATA_SIZE;

    // ����Դ��Ŀ���ַ
    DMA_SxPAR(2, 0) = SOURCE_ADDRESS;
    DMA_SxM0AR(2, 0) = DESTINATION_ADDRESS;

    // ʹ��DMA��
    DMA_SxCR(2, 0) |= DMA_SxCR_EN;
}

void DMA_RGB(void)
{
		// ʹ��DMA2ʱ��
    RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;

    // ����DMA��
    DMA_SxCR(2, 0) &= ~DMA_SxCR_CHSEL; // ���ͨ��ѡ��λ
    DMA_SxCR(2, 0) |= (0 << 25); // ѡ��ͨ��
    DMA_SxCR(2, 0) |= DMA_SxCR_DIR_MM; // �������ݴ��䷽��Ϊ�ڴ浽�ڴ�
    DMA_SxCR(2, 0) |= DMA_SxCR_MINC ;
	  DMA_SxCR(2, 0) |= DMA_SxCR_PINC; // ʹ���ڴ�������ַ����
    DMA_SxCR(2, 0) |= DMA_SxCR_PL_VH; // �������ȼ�Ϊ�ǳ���

    // �������ݴ�С�ʹ�������
    DMA_SxNDTR(2, 0) = DATA_SIZE;

    // ����Դ��Ŀ���ַ
    DMA_SxPAR(2, 0) = SOURCE_ADDRESS;
    DMA_SxM0AR(2, 0) = DESTINATION_ADDRESS;

    // ʹ��DMA��
    DMA_SxCR(2, 0) |= DMA_SxCR_EN;
}


int main(void) 
{ 	
#if 0
    // ���Դ������
    for (uint32_t i = 0; i < DATA_SIZE; i++) 
	{
        source_buffer[i] = 100;

		
    }
 
    // ��ʼ��DMA
    DMA_Init();
    // �ȴ�DMA�������
//��ɵ��Ǵ���
        while (!(DMA2_LISR & DMA_LISR_TCIF0))
//					{
//								//led_red ();
//		}
//		    while (!(DMA2_LISR & DMA_LISR_HTIF0))	{
//					    	led_green ();
//		}
//		    while (!(DMA2_LISR & DMA_LISR_TEIF0)){
//								led_blue ();
//		}
		
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
	/*
											
//						int j=i;
//						for(j=i;j>=0;j--)
//						{
//								led_blue ();
//								delay (0xfff0ff);
//								GPIOF->ODR |=(1UL<<8);
//								delay (0xfffff);
//						}
//					   	  led_red();
//								delay (0xffffff);
//								GPIOF->ODR |=(1UL<<6);
//								delay (0xfffff);
//						if(i==99)
//						{
//								led_green ();
//						}
						
	*/
         }
			}

    // ����ɹ�
    while (1)
		{
		   led_green ();
		}
		

#endif	

	
	
	
	
	
	
	}
void SystemInit (void )
{
	
/* ----------HSE----------���ɹ��� */
/* ����
//1.��HSE	    
			//	RCC_CR  |= RCC_CR_HSEON;
//2.�ȴ�HSE�ȶ������Ҽ��
			//	while(!(RCC_CR & RCC_CR_HSERDY ));
	// ��Ҫ����ĳһλ�Ƿ��Ѿ����Ӳ����1������һ����λΪ1�ĺ꣬������Ҫ���յĵ�ַ������ 
//1.1.SWѡ��Ϊhse
			//	RCC_CFGR |= RCC_CFGR_SW_HSE;
//1.2.�ȴ�Ӳ������ѡ���HSE
			//while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
*/
	
/* ����
		
	
	
	RCC_CR  |= RCC_CR_HSEON;
	while(!(RCC_CR & RCC_CR_HSERDY ));
	RCC_CFGR |= RCC_CFGR_SW_HSE;
	while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
*/



/* ----------HSI----------���ɹ���*/	
/* ����
//1.��HSI	    
				RCC_CR  |= RCC_CR_HSION;
//2.�ȴ�HSI�ȶ������Ҽ��
				while(!(RCC_CR & RCC_CR_HSIRDY ));
//1.1.SWѡ��ΪHSI
				RCC_CFGR |= RCC_CFGR_SW_HSI;
//1.2.�ȴ�Ӳ������ѡ���HSI
				while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);	
*/
/* ����

RCC_CR  |= RCC_CR_HSION;
while(!(RCC_CR & RCC_CR_HSIRDY ));
RCC_CFGR |= RCC_CFGR_SW_HSI;
while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);	

*/





/* ----------PLL---------- (�ɹ�) */	
/* ����
	
2.0 ��HSE/HSI���ȶ����У���ѡ��	
  ѡ��HSE��Ϊʱ������	
	RCC_PLLCFGR |=RCC_PLLCFGR_PLLSRC;  ��HSE��
	ѡ��HSI��Ϊʱ������
	RCC_PLLCFGR &=~RCC_PLLCFGR_PLLSRC; ��HSI��
2.1	����PLL����		
		RCC_PLLCFGR |=PLL_M_HSE ;
		RCC_PLLCFGR |=PLL_N ;
		RCC_PLLCFGR |=PLL_P ;
		RCC_PLLCFGR |=PLL_Q ;	
		RCC_PLLCFGR |=RCC_PLLCFGR_PLLSRC;		
RCC_PLLCFGR = (PLL_M_HSE << 0) | (PLL_N << 6) | (PLL_P << 16) | (PLL_Q << 24) | (RCC_PLLCFGR_PLLSRC);
2.2 ʹ��PLL �����ȴ����
		RCC_CR |=RCC_CR_PLLON ;
		while(!(RCC_CR & RCC_CR_PLLRDY ))	;	
2.3 SWѡ��PLL
		RCC_CFGR |=RCC_CFGR_SW_PLL;
2.4 �ȴ�Ӳ��ѡ�����	 	
		while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

*/


  RCC_CR  |= RCC_CR_HSEON;
	while((RCC_CR & RCC_CR_HSERDY )==0); 
	
	
	//ʹ�ܵ�Դ�ӿ�ʱ��
//RCC_APB1ENR |= RCC_APB1ENR_PWREN;


//PWR_CR |= PWR_CR_VOS;

	
// ����AHB��Ƶ��
RCC_CFGR |= AHB_PRESCALER ;

// ����APB1��Ƶ��
RCC_CFGR |= APB1_PRESCALER ;

// ����APB2��Ƶ��
RCC_CFGR |= APB2_PRESCALER ;
	
		RCC_PLLCFGR |=PLL_M_HSE ;
		RCC_PLLCFGR |=PLL_N ;
		RCC_PLLCFGR |=PLL_P ;
		RCC_PLLCFGR |=PLL_Q ;	
		RCC_PLLCFGR |=RCC_PLLCFGR_PLLSRC;		
 // RCC_PLLCFGR = (PLL_M_HSE << 0) | (PLL_N << 6) | (PLL_P << 16) | (PLL_Q << 24) | (RCC_PLLCFGR_PLLSRC);
 
 
  RCC_CR |=RCC_CR_PLLON ;
  while((RCC_CR & RCC_CR_PLLRDY ) == 0)	;
	
	/*Ϊʲôһ��Ҫ������һ��!!!!!!!!!!!!!!!!!!!!*/
	//FlashԤȡ��ָ��桢���ݻ���͵ȴ�״̬
	FLASH_ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;

  RCC_CFGR |=RCC_CFGR_SW_PLL;
	while ((RCC_CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

}


