/*
 * servo_prgrame.c\
 *
 *  Created on: Aug 4, 2023
 *      Author: Abdulteffares
 */
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/servo/servo_interface.h"
u32 Servo_16angle(u8 angle)
{
	return (angle*1000)/180+1000;
}

