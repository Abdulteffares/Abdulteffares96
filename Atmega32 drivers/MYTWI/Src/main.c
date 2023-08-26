/*
 * main.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Abdulteffares
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include<stdio.h>
#include <util/delay.h>
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_priivate.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"

#include "../Include/MCAL/TWI/TWI_Interface.h"
#include "../Include/MCAL/TWI/TWI_private.h"
#include"../Include/HAL/EEPROM/EEPROM_PRIVATE.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../include/HAL/LCD/LCD_configurations.h"

#define F_CPU 8000000UL



void main(void)
{
	// local variable to return data in
	u8 local_u8Data=0;

	// Initialize DIO --> PORTD LCD Data, PORTB LCD Control, PORTC TWI
	MDIO_voidInit();

	// Initialize LCD
	HLCD_voidInit();

	// Initialize TWI in Master Mode
	TWI_voidMasterInit();

	// Send byte to EEPROM
	//EEPROM_u8WriteByte(5, 1)==TWI_OK;
	// Read Byte from EEPROM
	//EEPROM_u8ReadByte(5, &local_u8Data);

	// Display Results
	HLCD_voidSendString("Expected Value: ");//HLCD_voidSendString("Expected Value: ");
	//HLCD_voidSendString("Expected Value: ");
	//HLCD_voidDisplayNumber(5);
	//HLCD_voidGoToPos(2, 1);
	//HLCD_voidSendString("Returned Value: ");
	//HLCD_voidDisplayNumber(local_u8Data);

	// Super Loop
	while (1);

}

