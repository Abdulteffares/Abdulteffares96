/*
 * DIO_Program.c
 *
 *  Created on: Apr 15, 2023
 *      Author: Abdulteffares
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/DIO/DIO_Private.h"
#include "../include/MCAL/DIO/DIO_Cfg.h"

void MDIO_voidinit(void)
{
	DDRA_REG=CONC_BIT(PORTA_PIN7_DIRECTION,PORTA_PIN6_DIRECTION,PORTA_PIN5_DIRECTION,PORTA_PIN4_DIRECTION,PORTA_PIN3_DIRECTION,PORTA_PIN2_DIRECTION,PORTA_PIN1_DIRECTION,PORTA_PIN0_DIRECTION);
	DDRB_REG=CONC_BIT(PORTB_PIN7_DIRECTION,PORTB_PIN6_DIRECTION,PORTB_PIN5_DIRECTION,PORTB_PIN4_DIRECTION,PORTB_PIN3_DIRECTION,PORTB_PIN2_DIRECTION,PORTB_PIN1_DIRECTION,PORTB_PIN0_DIRECTION);
	DDRC_REG=CONC_BIT(PORTC_PIN7_DIRECTION,PORTC_PIN6_DIRECTION,PORTC_PIN5_DIRECTION,PORTC_PIN4_DIRECTION,PORTC_PIN3_DIRECTION,PORTC_PIN2_DIRECTION,PORTC_PIN1_DIRECTION,PORTC_PIN0_DIRECTION);
	DDRD_REG=CONC_BIT(PORTD_PIN7_DIRECTION,PORTD_PIN6_DIRECTION,PORTD_PIN5_DIRECTION,PORTD_PIN4_DIRECTION,PORTD_PIN3_DIRECTION,PORTD_PIN2_DIRECTION,PORTD_PIN1_DIRECTION,PORTD_PIN0_DIRECTION);
	PORTA_REG=CONC_BIT(PORTA_PIN7_VALUE,PORTA_PIN6_VALUE,PORTA_PIN5_VALUE,PORTA_PIN4_VALUE,PORTA_PIN3_VALUE,PORTA_PIN2_VALUE,PORTA_PIN1_VALUE,PORTA_PIN0_VALUE);
	PORTB_REG=CONC_BIT(PORTB_PIN7_VALUE,PORTB_PIN6_VALUE,PORTB_PIN5_VALUE,PORTB_PIN4_VALUE,PORTB_PIN3_VALUE,PORTB_PIN2_VALUE,PORTB_PIN1_VALUE,PORTB_PIN0_VALUE);
	PORTC_REG=CONC_BIT(PORTC_PIN7_VALUE,PORTC_PIN6_VALUE,PORTC_PIN5_VALUE,PORTC_PIN4_VALUE,PORTC_PIN3_VALUE,PORTC_PIN2_VALUE,PORTC_PIN1_VALUE,PORTC_PIN0_VALUE);
	PORTD_REG=CONC_BIT(PORTD_PIN7_VALUE,PORTD_PIN6_VALUE,PORTD_PIN5_VALUE,PORTD_PIN4_VALUE,PORTD_PIN3_VALUE,PORTD_PIN2_VALUE,PORTD_PIN1_VALUE,PORTD_PIN0_VALUE);
}

void MDIO_SetPin_Direction(DIO_PORT PORT_NAME,DIO_PIN PIN_NUMBER ,Pin_Direction pin_Direction)
{
	if ((PORT_NAME<=PORTD) && (PIN_NUMBER<=PIN8) && (pin_Direction<=output))
	{
		switch(PORT_NAME)
		{
			case PORTA:
				switch(pin_Direction)
				{
					case(input):
									   CLR_BIT(DDRA_REG,PIN_NUMBER) ;
					break;
					case(output):
									   SET_BIT(DDRA_REG,PIN_NUMBER) ;
					break;

				}break;
			case PORTB:
					switch(pin_Direction)
					{
						case(input):
											   CLR_BIT(DDRB_REG,PIN_NUMBER) ;
						break;
						case(output):
											   SET_BIT(DDRB_REG,PIN_NUMBER) ;
						break;

					}break;

			case PORTC:
					switch(pin_Direction)
					 {
						case(input):
							  CLR_BIT(DDRC_REG,PIN_NUMBER) ;
							break;
						case(output):
							   SET_BIT(DDRC_REG,PIN_NUMBER) ;
							break;

					 }break;

			case PORTD:
						switch(pin_Direction)
						{
							case(input):
												   CLR_BIT(DDRD_REG,PIN_NUMBER) ;
							break;
							case(output):
												   SET_BIT(DDRD_REG,PIN_NUMBER) ;
							break;

						}break;
		}
	}
}
	void MDIO_SetPin_VALUE(DIO_PORT PORT_NAME,DIO_PIN PIN_NUMBER ,Pin_Value Pin_value)
	{
		if ((PORT_NAME<=PORTD) && (PIN_NUMBER<=PIN8) && (Pin_value<=HIGH))
		{
			switch(PORT_NAME)
			{
				case PORTA:
					switch(Pin_value)
					{
						case(LOW):
										   CLR_BIT(PORTA_REG,PIN_NUMBER) ;
						break;
						case(HIGH):
										   SET_BIT(PORTA_REG,PIN_NUMBER) ;
						break;

					}
					break;
				case PORTB:
						switch(Pin_value)
						{
							case(LOW):
												   CLR_BIT(PORTB_REG,PIN_NUMBER) ;
							break;
							case(HIGH):
												   SET_BIT(PORTB_REG,PIN_NUMBER) ;
							break;

						}
						break;

				case PORTC:
						switch(Pin_value)
						 {
							case(LOW):
								  CLR_BIT(PORTC_REG,PIN_NUMBER) ;
								break;
							case(HIGH):
								   SET_BIT(PORTC_REG,PIN_NUMBER) ;
								break;

						 }
						break;

				case PORTD:
							switch(Pin_value)
							{
								case(LOW):
													   CLR_BIT(PORTD_REG,PIN_NUMBER) ;
								break;
								case(HIGH):
													   SET_BIT(PORTD_REG,PIN_NUMBER) ;
								break;

							}
							break;
			}
		}
}
void MDIO_Toggle_PinValue(DIO_PORT PORT_NAME,DIO_PIN PIN_NUMBER)
{
	if ((PORT_NAME<=PORTD) && (PIN_NUMBER <=PIN7))
	{
		switch(PORT_NAME)
			{
				case PORTA:

					TOGGLE_BIT(PORTA_REG,PIN_NUMBER);

					break;
				case PORTB:

					TOGGLE_BIT(PORTB_REG,PIN_NUMBER);

					break;

				case PORTC:

					TOGGLE_BIT(PORTC_REG,PIN_NUMBER);

						break;
				case PORTD:
					TOGGLE_BIT(PORTD_REG,PIN_NUMBER);
						 break;
			}
	}
}
Pin_Value MDIO_DIO_VALUEGetPinValue(DIO_PORT PORT_NAME,DIO_PIN PIN_NUMBER)
{
	Pin_Value Pin_read =255;
	if ((PORT_NAME<=PORTD) && (PIN_NUMBER <=PIN7))
	{

		switch(PORT_NAME)
				{
					case PORTA:

						Pin_read=GET_BIT(PORTA_REG,PIN_NUMBER);

						break;
					case PORTB:

						Pin_read=GET_BIT(PORTB_REG,PIN_NUMBER);

						break;

					case PORTC:

						Pin_read=GET_BIT(PORTC_REG,PIN_NUMBER);

							break;
					case PORTD:
						Pin_read=GET_BIT(PORTD_REG,PIN_NUMBER);
							 break;
				}
	}
	return Pin_read ;
}
void MDIO_SetPort_Direction(DIO_PORT PORT_NAME,u8 portdirection)
{
	if(PORT_NAME<=PORTD)
	{
		switch(PORT_NAME)
						{
							case PORTA:

								DDRA_REG=portdirection;

								break;
							case PORTB:

								DDRB_REG=portdirection;
								break;

							case PORTC:

								DDRC_REG=portdirection;

									break;
							case PORTD:
								DDRD_REG=portdirection;

									 break;
						}
	}

}
void MDIO_SetPort_VALUE(DIO_PORT PORT_NAME,u8 portvalue)
{
	if(PORT_NAME<=PORTD)
	{
		switch(PORT_NAME)
						{
							case PORTA:

							PORTA_REG=portvalue;

								break;
							case PORTB:

								PORTB_REG=portvalue;
								break;

							case PORTC:

								PORTC_REG=portvalue;

									break;
							case PORTD:
								PORTD_REG=portvalue;

									 break;
						}
	}

}
