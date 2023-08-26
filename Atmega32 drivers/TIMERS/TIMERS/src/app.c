#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/DIO/DIO_Cfg.h"
#include "../include/MCAL/GI/GI_interface.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LCD/LCD_CFG.h"
#include "../include/MCAL/ADC/ADC_Interface.h"
#include"../include/MCAL/ADC/ADC_Private.h"
#include "../include/HAL/LED/LED_Interface.h"
#include "../include/MCAL/servo/servo_interface.h"

#define F_CPU 8000000UL
void TIMER0_CTC_FUNC (void);
void TIMER0_OVF_FUNC (void)
{
	static u16 counter =0;
	counter++;
	if (counter == 3907)
	{
		MTIMER0_voidSetPreloadValue(192);
		counter=0;
		HLED_voidToggleLedStatus(PORTA, PIN0);
	}
}


// OVF Main
//int main (void)
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(TIMER0_OVF_FUNC);
//	MTIMER0_voidInit();
//	MTIMER0_voidSetPreloadValue(192);
//	MGI_voidEnable();
//	while(1)
//	{
//
//	}
//}


//// CTC Main
//int main (void)
//{
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(TIMER0_CTC_FUNC);
//	MTIMER0_voidInit();
//	MGI_voidEnable();
//	while(1)
//	{
//
//	}
//}


//// Fast PWM Main
//int main (void)
//{
//	MDIO_voidInit();
//	MTIMER0_voidInit();
//	while(1)
//	{
//		for (u8 i=0; i<250; i+=10)
//		{
//			MTIMER0_voidSetOCR0Value(i);
//			_delay_ms (300);
//		}
//		for (u8 i=250; i>0; i -=10)
//		{
//			MTIMER0_voidSetOCR0Value(i);
//			_delay_ms (300);
//		}
//	}
//}



// Fast PWM Main
int main (void)
{
	//MDIO_voidSetPinStatus (PORTA,PIN0,DIO_SET);
	MDIO_voidInit();
	MGI_voidEnable ();
	MTIMER0_voidInit ();
	MTIMER1_voidInit();
	//MTIMER0_voidSetOVFCallback(TIMER0_OVF_FUNC);
	MADC_voidInit ();
	HLCD_voidInit ();
	HLCD_voidSendString("temperature:");
	MTIMER0_voidSetCTCCallback (TIMER0_CTC_FUNC);



	MTIMER1_voidInit();
	//MTIMER1_voidSetOCR1AValue(19999);
	while(1)
	{


	}
}
void TIMER0_CTC_FUNC (void)
{
	    u32 static counter=0;
	    counter++;
	    if(counter==90000)
	    {
	    	u16 ADCdigital_value =MADC_u16GetDigitalvalue (ADC3);
	    	u16 Analog_value=ADCdigital_value*5000UL/1024;
	    	u16	temperature=Analog_value/10;
			MDIO_voidSetPinStatus (PORTA,PIN0,DIO_SET);
			HLCD_voidGoToPos (ROW1,COL13);
			//HLCD_voidClearDisplay();
			HLCD_voidDisplayNumber(temperature);
			if(1<temperature && temperature<=10)
				{
				  MTIMER1_voidSetOCR1AValue(18400);
				  HLCD_voidGoToPos (ROW2,COL1);
				  HLCD_voidSendString("fan is active ");
				}
			else if (10<temperature && temperature<=20)
				{

				  MTIMER1_voidSetOCR1AValue(19000);
				  HLCD_voidGoToPos (ROW2,COL1);
				  HLCD_voidSendString("fan is active ");
				}
			else if (20<temperature && temperature<=30)
				{
				  MTIMER1_voidSetOCR1AValue(19500);
				  HLCD_voidGoToPos (ROW2,COL1);
				  HLCD_voidSendString("fan is active ");
				}
			else if (temperature>30)
				{
				  MTIMER1_voidSetOCR1AValue(19999);
				  HLCD_voidGoToPos (ROW2,COL1);
				  HLCD_voidSendString("fan is active ");
				}
			else
			{
				MTIMER1_voidSetOCR1AValue(0);
				HLCD_voidGoToPos (ROW2,COL1);
				HLCD_voidSendString("fan not active");
			}

			counter=0;
	    }
}
