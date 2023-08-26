/*
 * LCD_Interface.h
 *
 *  Created on: Apr 20, 2023
 *      Author: Abdulteffares
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

typedef enum{
	ROW1=1,
	ROW2
}LCD_ROWS;

typedef enum{
	COL1=1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7,
	COL8,
	COL9,
	COL10,
	COL11,
	COL12,
	COL13,
	COL14,
	COL15,
	COL16
}LCD_COLS;


void HLCD_voidGoToPos (LCD_ROWS A_RowNo, LCD_COLS A_ColNo);
void HLCD_voidSendString (u8 *A_u8PtrToString);
void HLCD_voidClearDisplay (void);
void HLCD_voidInit (void);
void HLCD_voidSendData (u8 A_u8Data);
void HLCD_voidSendCommand (u8 A_u8Command);

#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
