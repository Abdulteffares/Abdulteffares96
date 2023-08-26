################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TIMERS_Driver_Parallel.lss \

FLASH_IMAGE += \
TIMERS_Driver_Parallel.hex \

EEPROM_IMAGE += \
TIMERS_Driver_Parallel.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: TIMERS_Driver_Parallel.elf secondary-outputs

# Tool invocations
TIMERS_Driver_Parallel.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TIMERS_Driver_Parallel.map -mmcu=atmega32 -o "TIMERS_Driver_Parallel.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TIMERS_Driver_Parallel.lss: TIMERS_Driver_Parallel.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TIMERS_Driver_Parallel.elf  >"TIMERS_Driver_Parallel.lss"
	@echo 'Finished building: $@'
	@echo ' '

TIMERS_Driver_Parallel.hex: TIMERS_Driver_Parallel.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TIMERS_Driver_Parallel.elf  "TIMERS_Driver_Parallel.hex"
	@echo 'Finished building: $@'
	@echo ' '

TIMERS_Driver_Parallel.eep: TIMERS_Driver_Parallel.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex TIMERS_Driver_Parallel.elf  "TIMERS_Driver_Parallel.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TIMERS_Driver_Parallel.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TIMERS_Driver_Parallel.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TIMERS_Driver_Parallel.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
