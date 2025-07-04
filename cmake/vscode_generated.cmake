# This is converter generated file, and shall not be touched by user
#
# Use CMakeLists.txt to apply user changes
cmake_minimum_required(VERSION 3.22)

# Core MCU flags, CPU, instruction set and FPU setup
set(cpu_PARAMS ${cpu_PARAMS}
    -mthumb

    # Other parameters
    # -mcpu, -mfloat, -mfloat-abi, ...
    -mcpu=cortex-m3
	
)

# Linker script
set(linker_script_SRC ${linker_script_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f103c8tx_FLASH.ld
)

# Sources
set(sources_SRCS ${sources_SRCS}
    
	${CMAKE_CURRENT_SOURCE_DIR}/Src/main.c
	${CMAKE_CURRENT_SOURCE_DIR}/Src/syscall.c
	${CMAKE_CURRENT_SOURCE_DIR}/Src/sysmem.c
	${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_stm32f103c8tx.s
    ${CMAKE_CURRENT_SOURCE_DIR}/board/board.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/uart/bsp_uart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/STM32F10x_StdPeriph_Driver/src/misc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/croutine.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/event_groups.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/queue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/stream_buffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/tasks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/timers.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/portable/MemMang/heap_4.c
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/portable/GCC/ARM_CM3/port.c
)

# Include directories
set(include_c_DIRS ${include_c_DIRS}
    
	${CMAKE_CURRENT_SOURCE_DIR}/config
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/CMSIS/CM3/CoreSupport
    ${CMAKE_CURRENT_SOURCE_DIR}/libraries/STM32F10x_StdPeriph_Driver/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/board
    ${CMAKE_CURRENT_SOURCE_DIR}/bsp/uart
    ${CMAKE_CURRENT_SOURCE_DIR}/module
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/include
    ${CMAKE_CURRENT_SOURCE_DIR}/freertos/portable/GCC/ARM_CM3
)
set(include_cxx_DIRS ${include_cxx_DIRS}
    
)
set(include_asm_DIRS ${include_asm_DIRS}
    
)

# Symbols definition
set(symbols_c_SYMB ${symbols_c_SYMB}

)
set(symbols_cxx_SYMB ${symbols_cxx_SYMB}
    
)
set(symbols_asm_SYMB ${symbols_asm_SYMB}
    
)

# Link directories
set(link_DIRS ${link_DIRS}
    
)

# Link libraries
set(link_LIBS ${link_LIBS}
    
)

# Compiler options
set(compiler_OPTS ${compiler_OPTS})

# Linker options
set(linker_OPTS ${linker_OPTS})
