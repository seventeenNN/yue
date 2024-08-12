/*用来存放寄存器映射相关的代码*/

#define       uint32_t unsigned int
#define       uint16_t unsigned int
#define       __IO     volatile

	//先找到原理图中所用到的哪个gpio，找到对应的基地址
#define GPIO_BASE (( unsigned int )  0x40021400)

//根据偏移地址，得出相应的地址
#define GPIO_MODER  *(unsigned int *)( GPIO_BASE+0X00)
#define GPIO_OTYPER *(unsigned int *)( GPIO_BASE+0X04)
#define GPIO_ODR    *(unsigned int *)( GPIO_BASE+0X14)

//(unsigned int *)强制类型转换为对地址的操作，计算机不会自动的认为是地址

//还要找出时钟，根据外设挂载的总线，找出对应的时钟使能寄存器
//同样上述过程



	




/* 时钟 */
#define RCC_BASE             ((unsigned int ) 0x40023800)
#define PWR_CR               *(unsigned int *)(0x40007000)
#define PWR_CR_VOS           0x00004000

#define FLASH_ACR             *(unsigned int *)0x40023C00

#define FLASH_ACR_PRFTEN       0x00000100
#define FLASH_ACR_ICEN         0x00000200
#define FLASH_ACR_DCEN         0x00000400
#define FLASH_ACR_LATENCY_5WS  0x00000005


//得到的是该地址寄存器内的数值
#define RCC_CR               *(unsigned int *)(RCC_BASE+0X00)
#define RCC_PLLCFGR          *(unsigned int *)(RCC_BASE+0X04)
#define RCC_CFGR             *(unsigned int *)(RCC_BASE+0X08)
#define RCC_CIR              *(unsigned int *)(RCC_BASE+0X0C)//RCC时钟中断寄存器
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

//选择
#define RCC_CR_HSERDY        0x00020000     //或者（1UL << 17）
#define RCC_CR_HSEON         (1<<16)        //0x00010000
#define RCC_CR_PLLON         (1<<24)
#define RCC_CR_PLLRDY        (1<<25)
#define RCC_CR_HSIRDY        (1<<1)    
#define RCC_CR_HSION         (1<<0)       
#define RCC_CFGR_SW_HSE      0x00000001
#define RCC_CFGR_SW_PLL      0x00000002
#define RCC_CFGR_SW_HSI      0x00000000
#define RCC_CFGR_SWS         0x0000000C     //用于检测
#define RCC_CFGR_SWS_HSE     0x00000004
#define RCC_CFGR_SWS_PLL     (1<<3)
#define RCC_CFGR_SWS_HSI     0x00000000



//配置PLL

#define PLL_M_HSE           25<<0
#define PLL_M_HIE           16<<0
#define PLL_P               2<<16
#define PLL_Q               7<<24
#define PLL_N               336<<6  //84<<6

#define RCC_PLLCFGR_PLLSRC   (1<<22)

#define AHB_PRESCALER       0x00000000
#define APB1_PRESCALER      (1<<12)
#define APB2_PRESCALER      0x00001400



#define RCC_APB1ENR_PWREN    (1<<28)

