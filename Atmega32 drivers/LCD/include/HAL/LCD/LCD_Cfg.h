/*
 * LCD_Cfg.h
 *
 *  Created on: Apr 20, 2023
 *      Author: Abdulteffares
 */

#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_

#define LCD_DATA_PORT     PORTD
#define LCD_CONTROL_PORT  PORTC

#define LCD_RS_PIN  PIN0
#define LCD_RW_PIN  PIN1
#define LCD_E_PIN   PIN2

// 8-bit mode  --> 1
// 4-bit mode  --> 0
#define LCD_DL 1

// 1 line --> 0
// 2 line --> 1
#define NO_OF_LINES 1


// 5 * 7  --> 0
// 5 * 10 --> 1
#define CHAR_FONT 0

// off --> 0
// on  --> 1
#define DISPLAY_ON 1

// off --> 0
// on  --> 1
#define CURSOR_DISPLAY 1

// off --> 0
// on  --> 1
#define CURSOR_BLINK 1

// right to left --> 0
// left to right --> 1
#define DATA_DIRECTION 1
#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
