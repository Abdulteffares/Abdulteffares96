/*
 * LCD_configurations.h
 *
 *  Created on: Aug 4, 2022
 *      Author: abdulteffares
 */

#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_

#define LCD_DATA_PORT    PORTD
#define LCD_CONTROL_PORT PORTB

#define RS_PIN PIN0
#define RW_PIN PIN1
#define E_PIN  PIN2

#define FUNCTION_SET 		   0b00111000
#define DISPLAY_ON_OFF_CONTROL 0b00001111
#define DISPLAY_CLEAR 		   0b00000001
#define ENTRY_MODE_SET         0b00000110

#endif /* INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_ */
