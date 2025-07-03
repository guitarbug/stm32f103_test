#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* 添加 CMSIS 头文件 */
#include "stm32f10x.h"

// 基础配置
#define configUSE_PREEMPTION             1
#define configUSE_IDLE_HOOK              0
#define configUSE_TICK_HOOK              0
#define configCPU_CLOCK_HZ               (SystemCoreClock)
#define configTICK_RATE_HZ               ((TickType_t)1000)
#define configMAX_PRIORITIES             (5)
#define configMINIMAL_STACK_SIZE         ((uint16_t)128)
#define configTOTAL_HEAP_SIZE            ((size_t)10240) // 10KB
#define configMAX_TASK_NAME_LEN          (16)
#define configUSE_TRACE_FACILITY         1
#define configUSE_16_BIT_TICKS           0
#define configIDLE_SHOULD_YIELD          1
#define configUSE_MUTEXES                1
#define configQUEUE_REGISTRY_SIZE        8
#define configCHECK_FOR_STACK_OVERFLOW   2
#define configUSE_RECURSIVE_MUTEXES      1
#define configUSE_MALLOC_FAILED_HOOK     1
#define configUSE_APPLICATION_TASK_TAG   0
#define configUSE_COUNTING_SEMAPHORES    1

// 内存管理
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configSUPPORT_STATIC_ALLOCATION  0

// 钩子函数
#define configUSE_TICKLESS_IDLE          0

// 中断优先级配置
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         0xf
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5
#define configKERNEL_INTERRUPT_PRIORITY         (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << 4)
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << 4)

// 断言函数
extern void vAssertCalled(const char *pcFile, unsigned long ulLine);
#define configASSERT(x) if((x) == 0) vAssertCalled(__FILE__, __LINE__)

#endif /* FREERTOS_CONFIG_H */