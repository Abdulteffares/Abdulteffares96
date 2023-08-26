/*
 * EEPROM_PRIVATE.h
 *
 *  Created on: Jul 10, 2023
 *      Author: abdulteffares
 */

#ifndef INCLUDE_HAL_EEPROM_EEPROM_PRIVATE_H_
#define INCLUDE_HAL_EEPROM_EEPROM_PRIVATE_H_
u8 EEPROM_u8WriteByte (u16 A_u16ByteAddress, u8 A_u8ByteData);
u8 EEPROM_u8ReadByte (u16 A_u16ByteAddress, u8 *A_pu8ReturnedData);

#endif /* INCLUDE_HAL_EEPROM_EEPROM_PRIVATE_H_ */
