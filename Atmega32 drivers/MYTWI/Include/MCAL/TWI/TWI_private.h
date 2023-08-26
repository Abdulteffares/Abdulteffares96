/*
 * TWI_private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Abdulteffares
 */

#ifndef INCLUDE_MCAL_TWI_TWI_PRIVATE_H_
#define INCLUDE_MCAL_TWI_TWI_PRIVATE_H_

#define TWDR (*(volatile u8 *)0x23)
#define TWAR (*(volatile u8 *)0x22)
#define TWSR (*(volatile u8 *)0x21)
#define TWBR (*(volatile u8 *)0x20)
#define TWCR (*(volatile u8 *)0x56)



#endif /* INCLUDE_MCAL_TWI_TWI_PRIVATE_H_ */
