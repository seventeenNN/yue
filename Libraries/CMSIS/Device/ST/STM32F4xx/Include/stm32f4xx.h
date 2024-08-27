#ifndef _STM32F4XX_H
#define _STM32F4XX_H



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
#define GPIOI_BASE 0x40022000


// ����GPIO�˿�ָ��
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)
#define GPIOI ((GPIO_TypeDef *)GPIOI_BASE)


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
#define PLL_N               336<<6 //  84<<6

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

#define RCC_BDCR_LSEON        (1UL<<0)
#define RCC_BDCR_LSERDY       (1UL<<1)       
#define RCC_CSR_LSION         (1UL<<0)
#define RCC_CSR_LSIRDY        (1UL<<1)       


#define RCC_APB2_SYSCFG       (1UL<<14)


#define AHB_PRESCALER       0x00000000
#define APB1_PRESCALER      (1<<12)
#define APB2_PRESCALER      0x00001400

#define RCC_APB1ENR_PWREN    (1<<28)



/* DMA */




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
#define DMA_SxCR_CIRC   (1UL<<8)


#define DMA_SxCR_MSIZE_B (0<<13)
#define DMA_SxCR_MSIZE_HWORD  (1<<13)
#define DMA_SxCR_MSIZE_WORD  (2<<13)
#define DMA_SxCR_MSIZE_received  (3<<13)

#define DMA_SxCR_PSIZE_B (0<<11)
#define DMA_SxCR_PSIZE_HWORD  (1<<11)
#define DMA_SxCR_PSIZE_WORD  (2<<11)
#define DMA_SxCR_PSIZE_received  (3<<11)

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



/************* ------*EXTI*------ ***************/


#define EXTI_BASE            (0x40013C00)
#define EXTI_IMR             (*(volatile uint32_t *)(EXTI_BASE + 0x00))
#define EXTI_EMR             (*(volatile uint32_t *)(EXTI_BASE + 0x04))
#define EXTI_RTSR            (*(volatile uint32_t *)(EXTI_BASE + 0x08))
#define EXTI_FTSR            (*(volatile uint32_t *)(EXTI_BASE + 0x0C))
#define EXTI_SWIER           (*(volatile uint32_t *)(EXTI_BASE + 0x10))
#define EXTI_PR              (*(volatile uint32_t *)(EXTI_BASE + 0x14))

#define EXTI_IMR_0           (1UL<<0)
//0-23
#define EXTI_EMR_0           (1UL<<0)
#define EXTI_RTSR_0           (1UL<<0)
#define EXTI_FTSR_0           (1UL<<0)
#define EXTI_PR_0             (1UL<<0)

#define EXTI_PR_TEST          0X007FFFFF


/************* ------*SYSCFG*------ ***************/

// ����SYSCFG�Ĵ�������ַ
#define SYSCFG_BASE          (0x40013800)

// SYSCFG�Ĵ���ӳ��
#define SYSCFG_MEMRMP        (*(volatile uint32_t *)(SYSCFG_BASE + 0x00))
#define SYSCFG_PMC           (*(volatile uint32_t *)(SYSCFG_BASE + 0x04))
#define SYSCFG_EXTICR1       (*(volatile uint32_t *)(SYSCFG_BASE + 0x08))
#define SYSCFG_EXTICR2       (*(volatile uint32_t *)(SYSCFG_BASE + 0x0C))
#define SYSCFG_EXTICR3       (*(volatile uint32_t *)(SYSCFG_BASE + 0x10))
#define SYSCFG_EXTICR4       (*(volatile uint32_t *)(SYSCFG_BASE + 0x14))
#define SYSCFG_CMPCR         (*(volatile uint32_t *)(SYSCFG_BASE + 0x20))

#define SYSCFG_EXTICR1_PA0   0x00000000  
//�ܶ�



/************* ------*NVIC*------ ***************/


typedef enum IRQn
{
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
  Reset_IRQn                  = -12,      /*! ��λ*/
	NonMaskableInt_IRQn         = -11,    /*!< 2 Non Maskable Interrupt                                          */
	HardFault_IRQn              = -10,
	MemoryManagement_IRQn       = -9,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
  BusFault_IRQn               = -8,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
  UsageFault_IRQn             = -7,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
  DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
  DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
  DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
  DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
  DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
  DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
  ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
  CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                                 */
  CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                                */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
  TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
  TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
  TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                    */
  DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
  FSMC_IRQn                   = 48,     /*!< FSMC global Interrupt                                             */
  SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                             */
  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
  TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
  DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
  DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
  DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
  DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
  DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
  ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                                         */
  ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
  CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                                 */
  CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                                */
  CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                                */
  CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                                */
  OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
  DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
  DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
  DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
  USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
  I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
  I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
  OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global interrupt                       */
  OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global interrupt                        */
  OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
  OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global interrupt                                       */
  DCMI_IRQn                   = 78,     /*!< DCMI global interrupt                                             */
  CRYP_IRQn                   = 79,     /*!< CRYP crypto global interrupt                                      */
  HASH_RNG_IRQn               = 80,     /*!< Hash and Rng global interrupt                                     */
  FPU_IRQn                    = 81      /*!< FPU global interrupt                                              */

} IRQn_Type;


#define NVIC_ISER0           *(unsigned int *)(0xE000E100)
#define NVIC_ICER0           *(unsigned int *)(0xE000E180)
#define NVIC_ISPR0           *(unsigned int *)(0xE000E200)
#define NVIC_ICPR0           *(unsigned int *)(0xE000E280)
#define NVIC_IABR0           *(unsigned int *)(0xE000E300)
#define NVIC_IPR0            *(unsigned int *)(0xE000E400)
#define NVIC_STIR0           *(unsigned int *)(0xE000EF00)










/************* ------*IWDG*------ ***************/
#define IWDG_BASE   0x40003000


typedef struct {
    volatile uint32_t KR;    // �ؼ��ּĴ���
    volatile uint32_t PR;   // Ԥ��Ƶ�Ĵ���
    volatile uint32_t RLR;  // ���ؼĴ���
    volatile uint32_t SR;    // ״̬�Ĵ���

} IWDG_TypeDef;


#define IWDG ((IWDG_TypeDef *)IWDG_BASE)


/************* ------*USART*------ ***************/


#define USART1_BASE   0x40011000
//��������23456

typedef struct {
    volatile uint32_t SR;      // ״̬�Ĵ���
    volatile uint32_t DR;      // ���ݼĴ���
    volatile uint32_t BRR;     // �����ʼĴ���
    volatile uint32_t CR1;     // ���ƼĴ���1
    volatile uint32_t CR2;     // ���ƼĴ���2
    volatile uint32_t CR3;     // ���ƼĴ���3
	  volatile uint32_t GTPR;   // ����ʱ���Ԥ��Ƶ���Ĵ���
}USART_TypeDef;


#define   USART1      ((USART_TypeDef *)USART1_BASE)



#endif /* _STM32F4XX_H */

