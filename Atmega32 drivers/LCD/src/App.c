/*
 * App.c
 *
 *  Created on: Apr 15, 2023
 *      Author: Abdulteffares
 */



#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#define F_CPU 8000000UL


int main ()
{
	// Set PORT D as O/P Low
	// Set PORT C from C0 to C2 to O/P Low
	MDIO_voidInit();

	HLCD_voidInit();
	HLCD_voidSendString("Abdelrahman");
	while(1)
	{

	}
}
