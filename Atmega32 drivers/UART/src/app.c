#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/DIO/DIO_Interface.h"


#include "../include/HAL/LED/LED_Interface.h"

#define F_CPU 8000000UL


int main (void)
{
	// Rx --> D0
	// Tx --> D1
	MDIO_voidInit();
	MUART_voidInit();

	u8 local_u8Value = 0;
	MUART_voidSendStringSyncNonBlocking("Hello From Microcontroller \r\n");
	MUART_voidSendStringSyncNonBlocking("To turn on the LED press A and to Turn the LED off press D\r\n");
	while(1)
	{
		local_u8Value = MUART_u8ReadByteSyncBlocking();
		if (local_u8Value == 'A' || local_u8Value == 'a')
		{
			HLED_voidSetLedStatus(PORTA, PIN0, ON);
		}
		else if (local_u8Value == 'D' || local_u8Value == 'd')
		{
			HLED_voidSetLedStatus(PORTA, PIN0, OFF);
		}
	}
}
