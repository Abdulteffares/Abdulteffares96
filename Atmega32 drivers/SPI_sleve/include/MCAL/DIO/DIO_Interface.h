/*
 * DIO_Interface.h
 *
 *  Created on: Apr 15, 2023
 *      Author: Abdulteffares
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

typedef enum{
	input=0,
	output
}Pin_Direction;
typedef enum{
	LOW=0,
	HIGH,
	ERROR=255
}Pin_Value;

typedef enum{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD

}DIO_PORT;

typedef enum{
	PIN1=0,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8

}DIO_PIN;
void MDIO_voidinit(void);
void MDIO_SetPin_Direction(DIO_PORT PORT_NAME,DIO_PIN PIN_NUMBER ,Pin_Direction pin_Direction);
void MDIO_SetPin_VALUE(DIO_PORT PORT_NAME,DIO_PIN PIN_NUMBER ,Pin_Value Pin_value);
void MDIO_Toggle_PinValue(DIO_PORT PORT_NAME,DIO_PIN PIN_NUMBER);
Pin_Value  MDIO_DIO_VALUEGetPinValue(DIO_PORT PORT_NAME,DIO_PIN PIN_NUMBER);
void MDIO_SetPort_Direction(DIO_PORT PORT_NAME,u8 portdirection);
void MDIO_SetPort_Direction(DIO_PORT PORT_NAME,u8 portvalue);

#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
