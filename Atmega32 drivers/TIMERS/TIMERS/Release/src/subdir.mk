################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADC_Program.c \
../src/DIO_Program.c \
../src/GI_program.c \
../src/LCD_Program.c \
../src/LED_Program.c \
../src/SSD_Program.c \
../src/TIMERS_Program.c \
../src/WDT_Program.c \
../src/app.c \
../src/servo_prgrame.c 

OBJS += \
./src/ADC_Program.o \
./src/DIO_Program.o \
./src/GI_program.o \
./src/LCD_Program.o \
./src/LED_Program.o \
./src/SSD_Program.o \
./src/TIMERS_Program.o \
./src/WDT_Program.o \
./src/app.o \
./src/servo_prgrame.o 

C_DEPS += \
./src/ADC_Program.d \
./src/DIO_Program.d \
./src/GI_program.d \
./src/LCD_Program.d \
./src/LED_Program.d \
./src/SSD_Program.d \
./src/TIMERS_Program.d \
./src/WDT_Program.d \
./src/app.d \
./src/servo_prgrame.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


