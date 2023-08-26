/*
 * UART_Prgoram.c
 *
 *  Created on: May 4, 2023
 *      Author: Abdulteffares
 */


#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/UART/UART_Interface.h"
#include "../include/MCAL/UART/UART_Private.h"
#include "../include/MCAL/UART/UART_Cfg.h"


#define F_CPU 8000000UL
#define NULL 0

static void (*FuncPtr[3]) (void) = {NULL,NULL,NULL};

void MUART_voidInit(void)
{
	u16 local_u16BaudRateValue = BAUD_RATE_EQUATION;
	// Set Baudrate
	UBRRL = (u8)local_u16BaudRateValue;
	UBRRH = (u8)(local_u16BaudRateValue >> 8);

	// Character Size 8-bit
	CLR_BIT(UCSRB,2);
	// Mode Asynchronous operation
	// Parity Disabled
	// 1 Stop Bit
	UCSRC = CONC_BIT(1,0,0,0,0,1,1,0);

	// Enable Receiver
	// Enable Transmitter
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
}


void MUART_voidSendByteSyncBlocking (u8 A_u8DataByte)
{
	// wait until UDRE is empty
	while (GET_BIT(UCSRA,5)==0);

	// Set Data into Tx Register and start Transmission
	UDR = A_u8DataByte;

	// wait until UDRE is empty
	while (GET_BIT(UCSRA,5)==0);

	// Clear transmit Interrupt flag
	SET_BIT(UCSRA,6);
}

void MUART_voidSendByteSyncNonBlocking (u8 A_u8DataByte)
{
	u32 local_u32TimeOut=0;

	// wait until UDRE is empty or time out
	while (GET_BIT(UCSRA,5)==0)
	{
		local_u32TimeOut++;
		if (local_u32TimeOut == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}

	if (local_u32TimeOut != NON_BLOCKING_TIME_OUT)
	{
		local_u32TimeOut=0;

		// Set Data into Tx Register and start Transmission
		UDR = A_u8DataByte;

		// wait until UDRE is empty or time out
		while (GET_BIT(UCSRA,5)==0)
		{
			local_u32TimeOut++;
			if (local_u32TimeOut == NON_BLOCKING_TIME_OUT)
			{
				break;
			}
		}
		// Clear transmit Interrupt flag
		SET_BIT(UCSRA,6);
	}
}



void MUART_voidSendStringSyncNonBlocking (u8 *A_pu8String)
{
	while (*A_pu8String > 0)
	{
		MUART_voidSendByteSyncNonBlocking(*A_pu8String++);
	}
}


void MUART_voidSendByteAsync (u8 A_u8DataByte)
{
	if (GET_BIT(UCSRA,5)==1)
	{
		UDR = A_u8DataByte;
	}
}


u8 MUART_u8ReadByteSyncBlocking (void)
{
	// wait for Rx Flag
	while (GET_BIT(UCSRA,7)==0);

	return UDR;
}

u8 MUART_u8ReadByteAsync (void)
{
	return UDR;
}

u8 MUART_u8ReadByteSyncNonBlocking (void)
{
	u8 local_u8value= NO_VALUE_RETURNED;

	// wait for Rx Flag
	u32 local_u32TimeOut=0;

	// wait until Rx flag is up
	while (GET_BIT(UCSRA,7)==0)
	{
		local_u32TimeOut++;
		if (local_u32TimeOut == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}

	if (local_u32TimeOut != NON_BLOCKING_TIME_OUT)
		local_u8value =  UDR;

	return local_u8value;
}

typedef enum{
	UART_RX_INTERRUPT = 0,
	UART_UDRE_INTERRUPT ,
	UART_TX_INTERRUPT
}UART_INTERRUPTS;

void MUART_voidSetCallBack (UART_INTERRUPTS A_InterruptSource , void (*A_PtoFunc)(void))
{
	if ((A_InterruptSource<=UART_TX_INTERRUPT)&&(A_PtoFunc != NULL))
	{
		FuncPtr [A_InterruptSource] = A_PtoFunc;
	}
}


void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if (FuncPtr[UART_RX_INTERRUPT] != NULL)
	{
		FuncPtr[UART_RX_INTERRUPT]();
	}
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if (FuncPtr[UART_UDRE_INTERRUPT] != NULL)
	{
		FuncPtr[UART_UDRE_INTERRUPT]();
	}
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if (FuncPtr[UART_TX_INTERRUPT] != NULL)
	{
		FuncPtr[UART_TX_INTERRUPT]();
	}
}
