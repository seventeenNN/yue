#include "stm32f4xx.h"



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
RCC_CFGR |= APB1_PRESCALER ;//84

// ����APB2��Ƶ��
RCC_CFGR |= APB2_PRESCALER ;//42
	
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


