################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GPIO.c \
../Src/RCC.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart_driver.c 

OBJS += \
./Src/GPIO.o \
./Src/RCC.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart_driver.o 

C_DEPS += \
./Src/GPIO.d \
./Src/RCC.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/GPIO.d ./Src/GPIO.o ./Src/GPIO.su ./Src/RCC.d ./Src/RCC.o ./Src/RCC.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart_driver.d ./Src/uart_driver.o ./Src/uart_driver.su

.PHONY: clean-Src

