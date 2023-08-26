################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/App.c \
../src/DIO_Program.c 

OBJS += \
./src/App.o \
./src/DIO_Program.o 

C_DEPS += \
./src/App.d \
./src/DIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	C:\01- Embedded Systems AVR Tools-20230217T165646Z-001\01- Embedded Systems AVR Tools\01- IMT SDK\IMT_SDK_Win_64\IMT_SDK_Win_64\WinAVR\bin\avr-gcc.exe -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


