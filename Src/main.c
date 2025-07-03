#define USE_STDPERIPH_DRIVER
#define STM32F10X_MD

#include "stm32f10x_conf.h"
#include "stm32f10x.h"
#include "board.h"
#include "bsp_uart.h"
#include "stdio.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#include "FreeRTOS.h"
#include "task.h"

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

// FreeRTOS断言回调函数
void vAssertCalled(const char *pcFile, unsigned long ulLine) {
    printf("\r\n[ERROR] Assert failed: file %s on line %ld\r\n", pcFile, ulLine);
    while(1) {
        // LED闪烁指示错误
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay_ms(100);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay_ms(100);
    }
}

// FreeRTOS栈溢出钩子函数
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    printf("\r\n[ERROR] Stack overflow in task: %s\r\n", pcTaskName);
    while(1) {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay_ms(200);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay_ms(200);
    }
}

// FreeRTOS内存分配失败钩子函数
void vApplicationMallocFailedHook(void) {
    printf("\r\n[ERROR] Memory allocation failed!\r\n");
    while(1) {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay_ms(300);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay_ms(300);
    }
}

// LED任务实现
void LedTask(void *argument) {
    for (;;) {
        //HAL_GPIO_TogglePin(GPIOC, GPIO_Pin_13); // 翻转LED
        //vTaskDelay(pdMS_TO_TICKS(500));         // 延迟500ms

        GPIO_SetBits(GPIOC, GPIO_Pin_13);
		printf("freertos LedTask: LED ON!\r\n");
		delay_ms(100);
		
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		printf("freertos LedTask: LED OFF!\r\n");
		delay_ms(100);
    }
}

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

    // 创建LED任务
    xTaskCreate(
        LedTask,                   // 任务函数
        "LED Task",                // 任务名称
        configMINIMAL_STACK_SIZE * 4, // 栈大小（单位：字）
        NULL,                      // 参数
        tskIDLE_PRIORITY + 1,      // 优先级
        NULL            // 任务句柄
    );

    // 启动FreeRTOS调度器
    vTaskStartScheduler();

    // 如果调度器启动成功，以下代码不会运行
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
