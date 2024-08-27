#include "bsp_iwdg.h"


//��LSEʱ�Ӳ��ȴ��ȶ�
void LSI_OPEN(void)
{
	RCC_CSR |= RCC_CSR_LSION;
	while(!(RCC_CSR & RCC_CSR_LSIRDY));
}


void init_iwdg(unsigned int count)
{ 
  IWDG->KR  |=IWDG_KR_EN;
	IWDG->KR  |=IWDG_KR_WRITE;
	IWDG->RLR |=count ;
  IWDG->KR  |=IWDG_KR_FEED;

}

void feed_iwdg(void)
{
	IWDG->KR |=IWDG_KR_FEED;
}