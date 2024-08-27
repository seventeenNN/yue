#ifndef _BSP_IWDG_H
#define _BSP_IWDG_H


#include "stm32f4xx.h"


#define IWDR_PR_4       0x00000000;
#define IWDR_PR_8       0x00000001;
#define IWDR_PR_16      0x00000002;
#define IWDR_PR_32      0x00000003;
#define IWDR_PR_64      0x00000004;
#define IWDR_PR_128     0x00000005;
#define IWDR_PR_256     0x00000006;
#define IWDR_PR_256_    0x00000007;

#define IWDG_KR_FEED     0x0000AAAA;
#define IWDG_KR_WRITE    0x00005555;
#define IWDG_KR_EN       0x0000CCCC;


void LSI_OPEN(void);

void feed_iwdg(void);

void init_iwdg(unsigned int count);












#endif /* _BSP_IWDG_H */

