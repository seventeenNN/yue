#include "bsp_dma.h"
	// ���建����
uint32_t source_buffer[DATA_SIZE];
uint32_t destination_buffer[DATA_SIZE];


void DMA_Init(void) 
{
	 // ���Դ������
    for (uint32_t i = 0; i < DATA_SIZE; i++) 
	{
        source_buffer[i] = i;
    }
	
	  // ��ʼ��DMA
    // ʹ��DMA2ʱ��
    RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;

    // �������ݴ�С�ʹ�������
    DMA_SxNDTR(2, 0) = DATA_SIZE;

    // ����Դ��Ŀ���ַ
    DMA_SxPAR(2, 0) = SOURCE_ADDRESS;
    DMA_SxM0AR(2, 0) = DESTINATION_ADDRESS;
	
		// ����DMA��
		//  DMA_SxCR(2, 0) =0; // ���
    DMA_SxCR(2, 0) &=~ DMA_SxCR_EN;
		DMA_SxCR(2, 0) |= (0 << 25); // ѡ��ͨ��
    DMA_SxCR(2, 0) |= DMA_SxCR_DIR_MM; // �������ݴ��䷽��Ϊ�ڴ浽�ڴ�
    DMA_SxCR(2, 0) |= DMA_SxCR_MINC ;
	  DMA_SxCR(2, 0) |= DMA_SxCR_PINC; // ʹ���ڴ�������ַ����
    DMA_SxCR(2, 0) |= DMA_SxCR_PL_VH; // �������ȼ�Ϊ�ǳ���
			
		//����ԭ�������У��������ݵĴ�С��Ҫ���
    DMA_SxCR(2, 0) |= DMA_SxCR_MSIZE_WORD ;
    DMA_SxCR(2, 0) |= DMA_SxCR_PSIZE_WORD ;

    // ʹ��DMA��
    DMA_SxCR(2, 0) |= DMA_SxCR_EN;
	
}

