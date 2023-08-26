################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIO_Program.c \
../src/GI_program.c \
../src/LED_Program.c \
../src/SSD_Program.c \
../src/TIMERS_Program.c \
../src/WDT_Program.c \
../src/app.c 

OBJS += \
./src/DIO_Program.o \
./src/GI_program.o \
./src/LED_Program.o \
./src/SSD_Program.o \
./src/TIMERS_Program.o \
./src/WDT_Program.o \
./src/app.o 

C_DEPS += \
./src/DIO_Program.d \
./src/GI_program.d \
./src/LED_Program.d \
./src/SSD_Program.d \
./src/TIMERS_Program.d \
./src/WDT_Program.d \
./src/app.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


