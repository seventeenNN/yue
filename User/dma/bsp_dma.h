#ifndef _BSP_DMA_H
#define _BSP_DMA_H


#include "stm32f4xx.h"
#include "stm32f4xx_qy_dma.h"


	// ����Դ��Ŀ���ڴ�����
#define SOURCE_ADDRESS        ((uint32_t)source_buffer)
#define DESTINATION_ADDRESS   ((uint32_t)destination_buffer)
#define DATA_SIZE             100  // �������ݵĴ�С


// ʹ�� extern ����ȫ�ֱ���
extern uint32_t source_buffer[DATA_SIZE];
extern uint32_t destination_buffer[DATA_SIZE];






void DMA_Init(void);



#endif /*  _BSP_DMA_H  */
