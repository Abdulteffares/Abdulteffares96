/*
 * App.c
 *
 *  Created on: Apr 15, 2023
 *      Author: Abdulteffares
 */
#include<stdio.h>
#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/SPI/SPI_INTERFACE.h"
#include "../include/MCAL/SPI/SPI_CFG.h"
#include "../include/MCAL/SPI/SPI_PRIVATE.h"
#define F_CPU 8000000UL


int main ()
{
   MDIO_voidinit();
   MSPI_voidinit();
   u8 x=0;
   while(1)
   {
	   x=MSPI_u8send_recive('5');
	   if(x=='1')
	   {
		   MDIO_Toggle_PinValue(PORTA,PIN1);

	   }
	   _delay_ms(2000);
   }
}
