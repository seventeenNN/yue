/*   
	������żĴ���ӳ����صĴ���
*/

#define       uint32_t      unsigned int
#define       uint16_t      unsigned int
#define       __IO     			volatile
#define KEY_ON      			  1
#define KEY_OFF    			    0

//ͨ������,��������ѡ��һλ��������
//uint16_t
#define PIN0                (1UL<<0)
#define PIN1        				(1UL<<1)
#define PIN2         				(1UL<<2)
#define PIN3         				(1UL<<3)
#define PIN4         				(1UL<<4)
#define PIN5         				(1UL<<5)
#define PIN6         				(1UL<<6)
#define PIN7         				(1UL<<7)
#define PIN8         				(1UL<<8)
#define PIN9         				(1UL<<9)
#define PIN10         			(1UL<<10)
#define PIN11        				(1UL<<11)
#define PIN12        				(1UL<<12)
#define PIN13        				(1UL<<13)
#define PIN14         			(1UL<<14)
#define PIN15       				(1UL<<15)

//

// ����GPIO�Ĵ����ṹ��
typedef struct {
    volatile uint32_t MODER;    // ģʽ�Ĵ���
    volatile uint32_t OTYPER;   // ������ͼĴ���
    volatile uint32_t OSPEEDR;  // ����ٶȼĴ���
    volatile uint32_t PUPDR;    // ����/�����Ĵ���
    volatile uint32_t IDR;      // �������ݼĴ���
    volatile uint32_t ODR;      // ������ݼĴ���
    volatile uint32_t BSRR;     // ��λ/��λ�Ĵ���
    volatile uint32_t LCKR;     // �����Ĵ���
    volatile uint16_t AFRL;   // ���ù��ܵ�λ�Ĵ���
	  volatile uint16_t AFRH;   // ���ù��ܸ�λ�Ĵ���

} GPIO_TypeDef;

// ����GPIO�˿ڻ���ַ
#define GPIOA_BASE 0x40020000
#define GPIOB_BASE 0x40020400
#define GPIOC_BASE 0x40020800
#define GPIOD_BASE 0x40020C00
#define GPIOE_BASE 0x40021000
#define GPIOF_BASE 0x40021400
#define GPIOG_BASE 0x40021800
#define GPIOH_BASE 0x40021C00


// ����GPIO�˿�ָ��
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)


//(unsigned int *)ǿ������ת��Ϊ�Ե�ַ�Ĳ���������������Զ�����Ϊ�ǵ�ַ

//��Ҫ�ҳ�ʱ�ӣ�����������ص����ߣ��ҳ���Ӧ��ʱ��ʹ�ܼĴ���





/* ʱ�� */
#define RCC_BASE             ((unsigned int ) 0x40023800)
#define PWR_CR               *(unsigned int *)(0x40007000)
#define PWR_CR_VOS           0x00004000

#define FLASH_ACR             *(unsigned int *)0x40023C00

#define FLASH_ACR_PRFTEN       0x00000100
#define FLASH_ACR_ICEN         0x00000200
#define FLASH_ACR_DCEN         0x00000400
#define FLASH_ACR_LATENCY_5WS  0x00000005


//�õ����Ǹõ�ַ�Ĵ����ڵ���ֵ
#define RCC_CR               *(unsigned int *)(RCC_BASE+0X00)
#define RCC_PLLCFGR          *(unsigned int *)(RCC_BASE+0X04)
#define RCC_CFGR             *(unsigned int *)(RCC_BASE+0X08)
#define RCC_CIR              *(unsigned int *)(RCC_BASE+0X0C)//RCCʱ���жϼĴ���
#define RCC_AHB1RSTR         *(unsigned int *)(RCC_BASE+0X10)
#define RCC_AHB2RSTR         *(unsigned int *)(RCC_BASE+0X14)
#define RCC_AHB3RSTR         *(unsigned int *)(RCC_BASE+0X18)
#define Reserved_1           *(unsigned int *)(RCC_BASE+0X1C)
#define RCC_APB1RSTR         *(unsigned int *)(RCC_BASE+0X20)
#define RCC_APB2RSTR         *(unsigned int *)(RCC_BASE+0X24)
#define Reserved_2           *(unsigned int *)(RCC_BASE+0X28)
#define Reserved_3           *(unsigned int *)(RCC_BASE+0X2C)
#define RCC_AHB1ENR          *(unsigned int *)(RCC_BASE+0X30)
#define RCC_AHB2ENR          *(unsigned int *)(RCC_BASE+0X34)
#define RCC_AHB3ENR          *(unsigned int *)(RCC_BASE+0X38)
#define Reserved_4           *(unsigned int *)(RCC_BASE+0X3C)
#define RCC_APB1ENR          *(unsigned int *)(RCC_BASE+0X40)
#define RCC_APB2ENR          *(unsigned int *)(RCC_BASE+0X44)
#define Reserved_5           *(unsigned int *)(RCC_BASE+0X48)
#define Reserved_6           *(unsigned int *)(RCC_BASE+0X4C)
#define RCC_AHB1LPENR        *(unsigned int *)(RCC_BASE+0X50)
#define RCC_AHB2LPENR        *(unsigned int *)(RCC_BASE+0X54)
#define RCC_AHB3LPENR        *(unsigned int *)(RCC_BASE+0X58)
#define Reserved_7           *(unsigned int *)(RCC_BASE+0X5C)
#define RCC_APB1LPENR        *(unsigned int *)(RCC_BASE+0X60)
#define RCC_APB2LPENR        *(unsigned int *)(RCC_BASE+0X64)
#define Reserved_8           *(unsigned int *)(RCC_BASE+0X68)
#define Reserved_9           *(unsigned int *)(RCC_BASE+0X6C)
#define RCC_BDCR             *(unsigned int *)(RCC_BASE+0X70)
#define RCC_CSR              *(unsigned int *)(RCC_BASE+0X74)	
#define Reserved_10          *(unsigned int *)(RCC_BASE+0X78)
#define Reserved_11          *(unsigned int *)(RCC_BASE+0X7C)
#define RCC_SSCGR            *(unsigned int *)(RCC_BASE+0X80)
#define RCC_PLLI2SCFGR       *(unsigned int *)(RCC_BASE+0X84)
//#define RCC_DCKCFGR          *(unsigned int *)(RCC_BASE+0X88)

//ѡ��
#define RCC_CR_HSERDY        0x00020000     //���ߣ�1UL << 17��
#define RCC_CR_HSEON         (1<<16)        //0x00010000
#define RCC_CR_PLLON         (1<<24)
#define RCC_CR_PLLRDY        (1<<25)
#define RCC_CR_HSIRDY        (1<<1)    
#define RCC_CR_HSION         (1<<0)       
#define RCC_CFGR_SW_HSE      0x00000001
#define RCC_CFGR_SW_PLL      0x00000002
#define RCC_CFGR_SW_HSI      0x00000000
#define RCC_CFGR_SWS         0x0000000C     //���ڼ��
#define RCC_CFGR_SWS_HSE     0x00000004
#define RCC_CFGR_SWS_PLL     (1<<3)
#define RCC_CFGR_SWS_HSI     0x00000000



//����PLL

#define PLL_M_HSE           25<<0
#define PLL_M_HIE           16<<0
#define PLL_P               2<<16
#define PLL_Q               7<<24
#define PLL_N               336<<6  //84<<6

#define RCC_PLLCFGR_PLLSRC   (1<<22)


//AHB1ʹ��
#define RCC_AHB1ENR_GPIOAEN    0x00000001
#define RCC_AHB1ENR_GPIOBEN    0x00000002
#define RCC_AHB1ENR_GPIOCEN    0x00000004
#define RCC_AHB1ENR_GPIODEN    0x00000008
#define RCC_AHB1ENR_GPIOEEN    0x00000010
#define RCC_AHB1ENR_GPIOFEN    0x00000020
#define RCC_AHB1ENR_GPIOGEN    0x00000040
#define RCC_AHB1ENR_GPIOHEN    0x00000080
#define RCC_AHB1ENR_GPIOIEN    0x00000100


#define RCC_AHB1ENR_DMA1EN    (1UL<<21)
#define RCC_AHB1ENR_DMA2EN    (1UL<<22)



#define AHB_PRESCALER       0x00000000
#define APB1_PRESCALER      (1<<12)
#define APB2_PRESCALER      0x00001400

#define RCC_APB1ENR_PWREN    (1<<28)



/* DMA */

// ����Դ��Ŀ���ڴ�����
#define SOURCE_ADDRESS     ((uint32_t)source_buffer)
#define DESTINATION_ADDRESS ((uint32_t)destination_buffer)
#define DATA_SIZE          100  // �������ݵĴ�С

// ���建����
uint32_t source_buffer[DATA_SIZE];
uint32_t destination_buffer[DATA_SIZE];




#define DMA1_Stream0_BASE            0x40026000
#define DMA2_Stream0_BASE            0x40026400

// ����DMA����������ַ�ĺ�
#define DMA1_BASE DMA1_Stream0_BASE
#define DMA2_BASE DMA2_Stream0_BASE

// ����DMA�������Ĵ����ĺ꣨����Ҫ����ƫ������
#define DMA1_LISR (*(__IO uint32_t *)(DMA1_BASE + 0x00)) // DMA1���ж�״̬�Ĵ���
#define DMA1_HISR (*(__IO uint32_t *)(DMA1_BASE + 0x04)) // DMA1���ж�״̬�Ĵ���
#define DMA1_LIFCR (*(__IO uint32_t *)(DMA1_BASE + 0x08)) // DMA1���жϱ�־����Ĵ���
#define DMA1_HIFCR (*(__IO uint32_t *)(DMA1_BASE + 0x0C)) // DMA1���жϱ�־����Ĵ���

#define DMA2_LISR (*(__IO uint32_t *)(DMA2_BASE + 0x00)) // DMA2���ж�״̬�Ĵ���
#define DMA2_HISR (*(__IO uint32_t *)(DMA2_BASE + 0x04)) // DMA2���ж�״̬�Ĵ���
#define DMA2_LIFCR (*(__IO uint32_t *)(DMA2_BASE + 0x08)) // DMA2���жϱ�־����Ĵ���
#define DMA2_HIFCR (*(__IO uint32_t *)(DMA2_BASE + 0x0C)) // DMA2���жϱ�־����Ĵ���

// ����DMA������ַ�ĺ꣨��Ҫ����ƫ������
#define DMA_STREAM_BASE(dma, stream) (dma == 1 ? DMA1_Stream0_BASE : DMA2_Stream0_BASE + 0x18 * (stream))

// ����DMA��x���üĴ�����DMA_SxCR��
#define DMA_SxCR(dma, stream) (*(__IO uint32_t *)(DMA_STREAM_BASE(dma, stream) + 0x10))

// ����DMA��x������ݼĴ�����DMA_SxNDTR��
#define DMA_SxNDTR(dma, stream) (*(__IO uint32_t *)(DMA_STREAM_BASE(dma, stream) + 0x14))

// ����DMA��x�����ַ�Ĵ�����DMA_SxPAR��
#define DMA_SxPAR(dma, stream) (*(__IO uint32_t *)(DMA_STREAM_BASE(dma, stream) + 0x18))

// ����DMA��x�ڴ�0��ַ�Ĵ�����DMA_SxM0AR��
#define DMA_SxM0AR(dma, stream) (*(__IO uint32_t *)(DMA_STREAM_BASE(dma, stream) + 0x1C))

// ����DMA��x�ڴ�1��ַ�Ĵ�����DMA_SxM1AR��
#define DMA_SxM1AR(dma, stream) (*(__IO uint32_t *)(DMA_STREAM_BASE(dma, stream) + 0x20))

// ����DMA��x FIFO���ƼĴ�����DMA_SxFCR��
#define DMA_SxFCR(dma, stream) (*(__IO uint32_t *)(DMA_STREAM_BASE(dma, stream) + 0x24))





// ����DMA����������

#define DMA_SxCR_CHSEL    (7<<25)
#define DMA_SxCR_EN   (1UL<<0)

#define DMA_SxCR_MSIZE_bite  (0<<13)
#define DMA_SxCR_MSIZE_halfword  (1<<13)
#define DMA_SxCR_MSIZE_word  (2<<13)
#define DMA_SxCR_MSIZE_received  (3<<13)

#define DMA_SxCR_MINC    (1UL<<10)
#define DMA_SxCR_PINC    (1UL<<9)


#define DMA_SxCR_DIR_PM      (0UL<<6)
#define DMA_SxCR_DIR_MP      (1UL<<6)
#define DMA_SxCR_DIR_MM      (2UL<<6)
#define DMA_SxCR_DIR_received  (3UL<<6)

#define DMA_SxCR_PL_L   (0UL<<16)
#define DMA_SxCR_PL_M   (1UL<<16)
#define DMA_SxCR_PL_H   (2UL<<16)
#define DMA_SxCR_PL_VH   (3UL<<16)


#define DMA_LISR_TCIF0  (1UL<<5)
#define DMA_LISR_TCIF1  (1UL<<11)
#define DMA_LISR_TCIF2  (1UL<<21)
#define DMA_LISR_TCIF3  (1UL<<27)

#define DMA_LISR_HTIF0  (1UL<<4)
#define DMA_LISR_TEIF0  (1UL<<3)
#define DMA_LISR_DMEIF0  (1UL<<2)
#define DMA_LISR_FEIF0  (1UL<<0)




