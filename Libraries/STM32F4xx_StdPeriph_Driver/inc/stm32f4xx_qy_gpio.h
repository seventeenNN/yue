#ifndef __STM32F4xx_QY_GPIO_H
#define __STM32F4xx_QY_GPIO_H


#ifdef __cplusplus
 extern "C" {
#endif
//��������ָ�������C++�������б���C���Դ���ʱ��ȷ��C���Եĺ��������Ͷ����ܹ�����ȷ�ش���

#include "stm32f4xx.h"

   
typedef enum
{ 
  GPIO_Mode_IN   = 0x00, /* ���� */
  GPIO_Mode_OUT  = 0x01, /* ��� */
  GPIO_Mode_AF   = 0x02, /* ���� */
  GPIO_Mode_AN   = 0x03  /* ģ�� */
}GPIOMode_TypeDef;

 
typedef enum
{ 
  GPIO_OType_PP = 0x00,/* ���� */
  GPIO_OType_OD = 0x01 /* ��© */
}GPIOOType_TypeDef;

typedef enum
{ 
  GPIO_2MHz_Speed     = 0x00, /*   2 MHz�����٣�   */
  GPIO_25MHz_Speed    = 0x01, /*  25 MHz�����٣�  */
  GPIO_50Mhz_Speed    = 0x02, /*  50 MHz�����٣�  */
  GPIO_100MHz_Speed   = 0x03  /*  30 pF ʱΪ 100 MHz�����٣���15 pF ʱΪ 80 MHz ���������ٶȣ���   */
}GPIOSpeed_TypeDef;


typedef enum
{ 
  GPIO_PuPd_NOPULL = 0x00,/* ���������� */
  GPIO_PuPd_UP     = 0x01,/*   ����    */
  GPIO_PuPd_DOWN   = 0x02 /*   ����    */
}GPIOPuPd_TypeDef;

 
typedef struct
{
  uint32_t GPIO_Pin;             

  GPIOMode_TypeDef GPIO_Mode;     

  GPIOSpeed_TypeDef GPIO_Speed;   

  GPIOOType_TypeDef GPIO_OType;  

  GPIOPuPd_TypeDef GPIO_PuPd;     
	
}GPIO_InitTypeDef;




void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void gpio_usart_PA9PA10(void);









#endif /*__STM32F4xx_QY_GPIO_H*/
