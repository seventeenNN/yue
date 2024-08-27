#include "bsp_dma.h"
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

