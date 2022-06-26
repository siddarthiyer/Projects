################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../printf/printf.c 

OBJS += \
./printf/printf.o 

C_DEPS += \
./printf/printf.d 


# Each subdirectory must supply rules for building sources it contributes
printf/%.o printf/%.su: ../printf/%.c printf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"/Users/sidiyer27/Desktop/STM32_Projects/Webserver Test/GPIO" -I"/Users/sidiyer27/Desktop/STM32_Projects/Webserver Test/printf" -I"/Users/sidiyer27/Desktop/STM32_Projects/Webserver Test/UART" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-printf

clean-printf:
	-$(RM) ./printf/printf.d ./printf/printf.o ./printf/printf.su

.PHONY: clean-printf

