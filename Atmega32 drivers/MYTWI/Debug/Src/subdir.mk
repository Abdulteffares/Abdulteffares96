################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_program.c \
../Src/EEPROM_program.c \
../Src/GI_program.c \
../Src/LCD_program.c \
../Src/TWI_program.c \
../Src/main.c 

OBJS += \
./Src/DIO_program.o \
./Src/EEPROM_program.o \
./Src/GI_program.o \
./Src/LCD_program.o \
./Src/TWI_program.o \
./Src/main.o 

C_DEPS += \
./Src/DIO_program.d \
./Src/EEPROM_program.d \
./Src/GI_program.d \
./Src/LCD_program.d \
./Src/TWI_program.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


