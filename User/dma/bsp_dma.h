#ifndef _BSP_DMA_H
#define _BSP_DMA_H


#include "stm32f4xx.h"
#include "stm32f4xx_qy_dma.h"


	// 定义源和目标内存区域
#define SOURCE_ADDRESS        ((uint32_t)source_buffer)
#define DESTINATION_ADDRESS   ((uint32_t)destination_buffer)
#define DATA_SIZE             100  // 传输数据的大小


// 使用 extern 声明全局变量
extern uint32_t source_buffer[DATA_SIZE];
extern uint32_t destination_buffer[DATA_SIZE];






void DMA_Init(void);



#endif /*  _BSP_DMA_H  */
