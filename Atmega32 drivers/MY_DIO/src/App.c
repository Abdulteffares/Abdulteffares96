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

#define F_CPU 8000000UL


int main ()
{
	MDIO_SetPort_Direction(PORTA,0X0F);

	while(1)
	{
		//step no1
		MDIO_SetPin_VALUE(PORTA,PIN1,LOW);
		MDIO_SetPin_VALUE(PORTA,PIN2,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN3,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN4,HIGH);
		_delay_ms(10);
		//step no2
		MDIO_SetPin_VALUE(PORTA,PIN1,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN2,LOW);
		MDIO_SetPin_VALUE(PORTA,PIN3,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN4,HIGH);
		_delay_ms(10);
		//step no3
		MDIO_SetPin_VALUE(PORTA,PIN1,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN2,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN3,LOW);
		MDIO_SetPin_VALUE(PORTA,PIN4,HIGH);
		_delay_ms(10);
		//step no4
		MDIO_SetPin_VALUE(PORTA,PIN1,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN2,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN3,HIGH);
		MDIO_SetPin_VALUE(PORTA,PIN4,LOW);
		_delay_ms(10);
	}
}
