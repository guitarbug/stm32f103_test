#define USE_STDPERIPH_DRIVER
#define STM32F10X_MD

#include "stm32f10x_conf.h"
#include "stm32f10x.h"
#include "board.h"
#include "bsp_uart.h"
#include "stdio.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
    // 通过串口输出错误信息
    printf("\r\n[ERROR] Assert failed: file %s on line %ld\r\n", file, line);
    
    // 通过LED指示错误状态(PC13)
    GPIO_SetBits(GPIOC, GPIO_Pin_13);  // LED亮起表示错误
    
    while (1)
    {
        // LED闪烁指示错误状态
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay_ms(100);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay_ms(100);
    }
}
#endif

int main(void)
{
	
	board_init();
	
	uart1_init(115200);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);

    // 使用printf测试
    printf("Hello World!!!\r\n");

	while(1)
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		printf("LED ON!\r\n");
		delay_ms(1000);
		
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		printf("LED OFF!\r\n");
		delay_ms(1000);
		
		uint8_t *t = uart1_get_data();
		if(t != NULL)
		{
			printf("data = %s\r\n",t);
		}
	}
	
}
