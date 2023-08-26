
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_priivate.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../include/HAL/LCD/LCD_configurations.h"

#include <util/delay.h>
#define F_CPU 8000000UL

void HLCD_voidSendCommand(u8 A_u8Command)
{
    //    RS --> 0 , RW --> 0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, PIN_LOW);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);
    // Send command to LCD
    MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);
    // Set pulse on Enable Pin with 2 ms delay
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
}

void HLCD_voidSendData(u8 A_u8Data)
{
    //    RS --> 1 , RW --> 0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, PIN_HIGH);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);
    // Send command to LCD
    MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);
    // Set pulse on Enable Pin with 2 ms delay
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
}

void HLCD_voidInit(void)
{
    // Wait for more than 30ms after VDD rises to 4.5V.
    _delay_ms(30);
    // Function Set
    HLCD_voidSendCommand(FUNCTION_SET);
    // Wait for more than 39 us
    _delay_ms(1);
    // Display ON/OFF Control
    HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
    // Wait for more than 39 us
    _delay_ms(1);
    // Display Clear
    HLCD_voidSendCommand(DISPLAY_CLEAR);
    // Wait for more than 1.53 ms
    _delay_ms(2);
    // Entry Mode Set
    HLCD_voidSendCommand(ENTRY_MODE_SET);
    // End of Initialization
}

void HLCD_voidClearDisplay(void)
{
    HLCD_voidSendCommand(DISPLAY_CLEAR);
    // Wait for more than 1.53 ms
    _delay_ms(2);
}

void HLCD_voidSendString(u8 *A_Pu8String)
{
    while (*A_Pu8String > 0)
    {
        HLCD_voidSendData(*A_Pu8String++);
    }
}

void HLCD_voidGoToPos(u8 A_u8RowNum, u8 A_u8ColNum)
{
    switch (A_u8RowNum)
    {
    case LCD_ROW_ONE:
        HLCD_voidSendCommand(LCD_ROW1_ADDRESS + A_u8ColNum);
        break;
    case LCD_ROW_TWO:
        HLCD_voidSendCommand(LCD_ROW2_ADDRESS + A_u8ColNum);
        break;
    default:
        break;
    }
    _delay_ms(1);
}

HLCD_voidDisplayNumber(u32 A_u32Number)
{
    u32 local_u32Number = 1;
    if (A_u32Number == 0)
    {
        HLCD_voidSendData('0');
    }
    while (A_u32Number != 0)
    {
        local_u32Number = ((local_u32Number * 10) + (A_u32Number % 10));
        A_u32Number = A_u32Number / 10;
    }
    while (local_u32Number != 1)
    {
        HLCD_voidSendData((local_u32Number % 10) + 48);
        local_u32Number = local_u32Number / 10;
    }
}