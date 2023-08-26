/*
 * EEPROM_program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Abdulteffares
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/TWI/TWI_Interface.h"
#include "../Include/MCAL/TWI/TWI_private.h"

#include <util/delay.h>

#define EEPROM_FIXED_ADDRESS 0x50
#define EEPROM_HW_A2_ADDRESS 0
static u8 private_u8CheckError(TWI_ErrorStatus A_enuErorrStatus);
static u8 private_u8CheckError(TWI_ErrorStatus A_enuErorrStatus)
{
	u8 local_u8ErrorStatus=TWI_OK;
	if (A_enuErorrStatus != TWI_OK)
	{
		local_u8ErrorStatus = TWI_NOK;
	}
	return local_u8ErrorStatus;
}


u8 EEPROM_u8WriteByte (u16 A_u16ByteAddress, u8 A_u8ByteData)
{
	u8 local_ErrorStatus = TWI_OK;
	TWI_ErrorStatus local_enuErorrStatus= TWI_OK;

	// Send Start Condition
	local_enuErorrStatus=TWI_u8SendStartCondition();
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Send Slave Address with write operation
	local_enuErorrStatus=TWI_u8SendSlaveAddressWithWrite(EEPROM_FIXED_ADDRESS | (EEPROM_HW_A2_ADDRESS<<2)|(A_u16ByteAddress>>8));
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Send Byte Address
	local_enuErorrStatus=TWI_u8SendDataByte((u8)A_u16ByteAddress);
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Send Byte Data
	local_enuErorrStatus=TWI_u8SendDataByte(A_u8ByteData);
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Stop Condition
	TWI_u8SendStopCondition();

	// Delay
	_delay_ms (5);

	// Return Status
	return local_ErrorStatus;
}


u8 EEPROM_u8ReadByte (u16 A_u16ByteAddress, u8 *A_pu8ReturnedData)
{
	u8 local_ErrorStatus = TWI_OK;
	TWI_ErrorStatus local_enuErorrStatus= TWI_OK;

	// Send Start Condition
	local_enuErorrStatus=TWI_u8SendStartCondition();
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Send Slave Address with write operation
	local_enuErorrStatus=TWI_u8SendSlaveAddressWithWrite(EEPROM_FIXED_ADDRESS | (EEPROM_HW_A2_ADDRESS<<2)|(A_u16ByteAddress>>8));
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Send Byte Address
	local_enuErorrStatus=TWI_u8SendDataByte((u8)A_u16ByteAddress);
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Send Repeated Start Condition
	local_enuErorrStatus=TWI_u8SendReStartCondition();
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Send Slave Address with Read operation
	local_enuErorrStatus=TWI_u8SendSlaveAddressWithRead(EEPROM_FIXED_ADDRESS | (EEPROM_HW_A2_ADDRESS<<2)|(A_u16ByteAddress>>8));
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Read Data Byte
	local_enuErorrStatus=TWI_u8ReadDataByte(A_pu8ReturnedData);
	local_ErrorStatus = private_u8CheckError(local_enuErorrStatus);

	// Stop Condition
	TWI_u8SendStopCondition();

	// Delay
	_delay_ms (5);

	// Return Status
	return local_ErrorStatus;
}





