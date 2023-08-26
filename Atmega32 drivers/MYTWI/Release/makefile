################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/subdir.mk
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
MYTWI.lss \

FLASH_IMAGE += \
MYTWI.hex \

EEPROM_IMAGE += \
MYTWI.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: MYTWI.elf secondary-outputs

# Tool invocations
MYTWI.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MYTWI.map -mmcu=atmega32 -o "MYTWI.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MYTWI.lss: MYTWI.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MYTWI.elf  >"MYTWI.lss"
	@echo 'Finished building: $@'
	@echo ' '

MYTWI.hex: MYTWI.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MYTWI.elf  "MYTWI.hex"
	@echo 'Finished building: $@'
	@echo ' '

MYTWI.eep: MYTWI.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex MYTWI.elf  "MYTWI.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MYTWI.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MYTWI.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MYTWI.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
