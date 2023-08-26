/*
 * TWI_program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Abdulteffares
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/TWI/TWI_Interface.h"
#include "../Include/MCAL/TWI/TWI_private.h"


void TWI_voidMasterInit(void)
{
	// Set Prescalers Value
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	// Set TWBR with the value => 200KHz
	TWBR=12;
	// Enable ACK
	SET_BIT(TWCR,6);
	// Enable I2C
	SET_BIT(TWCR,2);
}


void TWI_voidSlaveInit(u8 A_u8Address)
{
	// Set Slave Address in TWAR
	TWAR=A_u8Address<<1;
	// Enable ACK
	SET_BIT(TWCR,6);
	// Enable I2C
	SET_BIT(TWCR,2);
}


TWI_ErrorStatus TWI_u8SendStartCondition (void)
{
	TWI_ErrorStatus local_enuErrorStatus = TWI_OK;
	/* Clear INT Flag + Start Condition */
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,5);
	/* Wait for the flag to be 1 (polling on flag)*/
	while (GET_BIT(TWCR,7)==0);
	/* Check TWI Status Register */
	if ((TWSR & 0xF8)!=0x08)
	{
		local_enuErrorStatus = TWI_SC_ERROR;
	}
	/* Clear Start Condition Bit */
	CLR_BIT(TWCR,5);
	/* Return Status of TWI */
	return local_enuErrorStatus;
}

TWI_ErrorStatus TWI_u8SendReStartCondition (void)
{
	TWI_ErrorStatus local_enuErrorStatus = TWI_OK;
	/* Clear INT Flag + Start Condition */
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,5);
	/* Wait for the flag to be 1 (polling in flag)*/
	while (GET_BIT(TWCR,7)==0);
	/* Check TWI Status Register */
	if ((TWSR & 0xF8)!=0x10)
	{
		local_enuErrorStatus = TWI_RSC_ERROR;
	}
	/* Clear Start Condition Bit */
	CLR_BIT(TWCR,5);
	/* Return Status of TWI */
	return local_enuErrorStatus;
}


TWI_ErrorStatus TWI_u8SendStopCondition (void)
{
	TWI_ErrorStatus local_enuErrorStatus = TWI_OK;
	/* Clear INT Flag + Stop Condition */
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,4);
	/* Return Status of TWI */
	return local_enuErrorStatus;
}


TWI_ErrorStatus TWI_u8SendSlaveAddressWithWrite(u8 A_u8SlaveAddress)
{
	TWI_ErrorStatus local_enuErrorStatus = TWI_OK;
	/* Set Slave Address */
	u8 local_u8Byte = A_u8SlaveAddress << 1;
	/* Set Operation to Write */
	CLR_BIT(local_u8Byte,0);
	/* Set Slave Address to be Sent with the write request */
	TWDR = local_u8Byte;
	/* Clear INT Flag */
	SET_BIT(TWCR,7);
	/* Wait for the flag to be 1 (polling on flag)*/
	while (GET_BIT(TWCR,7)==0);
	/* Check TWI Status Register */
	if ((TWSR & 0xF8)!=0x18)
	{
		local_enuErrorStatus = TWI_SLA_W_ERROR;
	}
	/* Return Status of TWI */
	return local_enuErrorStatus;
}


TWI_ErrorStatus TWI_u8SendSlaveAddressWithRead(u8 A_u8SlaveAddress)
{
	TWI_ErrorStatus local_enuErrorStatus = TWI_OK;
	/* Set Slave Address */
	u8 local_u8Byte = A_u8SlaveAddress << 1;
	/* Set Operation to Read */
	SET_BIT(local_u8Byte,0);
	/* Set Slave Address to be Sent with the Read request */
	TWDR = local_u8Byte;
	/* Clear INT Flag */
	SET_BIT(TWCR,7);
	/* Wait for the flag to be 1 (polling in flag)*/
	while (GET_BIT(TWCR,7)==0);
	/* Check TWI Status Register */
	if ((TWSR & 0xF8)!=0x40)
	{
		local_enuErrorStatus = TWI_SLA_R_ERROR;
	}
	/* Return Status of TWI */
	return local_enuErrorStatus;
}


TWI_ErrorStatus TWI_u8SendDataByte(u8 A_u8Data)
{
	TWI_ErrorStatus local_enuErrorStatus = TWI_OK;
	/* Set Byte Data */
	TWDR = A_u8Data;
	/* Clear INT Flag */
	SET_BIT(TWCR,7);
	/* Wait for the flag to be 1 (polling in flag)*/
	while (GET_BIT(TWCR,7)==0);
	/* Check TWI Status Register */
	if ((TWSR & 0xF8)!=0x28)
	{
		local_enuErrorStatus = TWI_MT_DATA_ERROR;
	}
	/* Return Status of TWI */
	return local_enuErrorStatus;
}


TWI_ErrorStatus TWI_u8ReadDataByte(u8 *A_ReturnDataByte)
{
	TWI_ErrorStatus local_enuErrorStatus = TWI_OK;
	if (A_ReturnDataByte != NULL)
	{
		/* Clear INT Flag */
		SET_BIT(TWCR,7);
		/* Wait for the flag to be 1 (polling in flag)*/
		while (GET_BIT(TWCR,7)==0);
		/* Check TWI Status Register */
		if ((TWSR & 0xF8)!=0x50)
		{
			local_enuErrorStatus = TWI_MR_DATA_ERROR;
		}
		else
		{
			*A_ReturnDataByte = TWDR;
		}
	}
	else
	{
		local_enuErrorStatus = TWI_NULL_POINTER;
	}
	/* Return Status of TWI */
	return local_enuErrorStatus;
}












