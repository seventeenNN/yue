#ifndef __STM32F4xx_QY_GPIO_H
#define __STM32F4xx_QY_GPIO_H


#ifdef __cplusplus
 extern "C" {
#endif
//条件编译指令，用于在C++编译器中编译C语言代码时，确保C语言的函数声明和定义能够被正确地处理。

#include "stm32f4xx.h"

   
typedef enum
{ 
  GPIO_Mode_IN   = 0x00, /* 输入 */
  GPIO_Mode_OUT  = 0x01, /* 输出 */
  GPIO_Mode_AF   = 0x02, /* 复用 */
  GPIO_Mode_AN   = 0x03  /* 模拟 */
}GPIOMode_TypeDef;

 
typedef enum
{ 
  GPIO_OType_PP = 0x00,/* 推挽 */
  GPIO_OType_OD = 0x01 /* 开漏 */
}GPIOOType_TypeDef;

typedef enum
{ 
  GPIO_2MHz_Speed     = 0x00, /*   2 MHz（低速）   */
  GPIO_25MHz_Speed    = 0x01, /*  25 MHz（中速）  */
  GPIO_50Mhz_Speed    = 0x02, /*  50 MHz（快速）  */
  GPIO_100MHz_Speed   = 0x03  /*  30 pF 时为 100 MHz（高速）（15 pF 时为 80 MHz 输出（最大速度））   */
}GPIOSpeed_TypeDef;


typedef enum
{ 
  GPIO_PuPd_NOPULL = 0x00,/* 无上拉下拉 */
  GPIO_PuPd_UP     = 0x01,/*   上拉    */
  GPIO_PuPd_DOWN   = 0x02 /*   上拉    */
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
