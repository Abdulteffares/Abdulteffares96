/*
 * SPI_PROGRAME.c
 *
 *  Created on: Jun 9, 2023
 *      Author: Abdulteffares
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/SPI/SPI_INTERFACE.h"
#include "../include/MCAL/SPI/SPI_PRIVATE.h"
#include "../include/MCAL/SPI/SPI_CFG.h"


void MSPI_voidinit(void)
{
	CLR_BIT(SPDCR,DORD);
	SET_BIT(SPDCR,3);
	SET_BIT(SPDCR,2);
#if(master_mode==1)
	//select master mode
	SET_BIT(SPDCR,4);
	//SELECT CLOCK CYCLE
    CLR_BIT(SPDCR,0);
    SET_BIT(SPDCR,1);
#elif(master_mode==0)
    //select master mode
    CLR_BIT(SPDCR,4);
   	//SELECT CLOCK CYCLE
#endif
     SET_BIT(SPDCR,SPE);

}
 u8 MSPI_u8send_recive(u8 copy_data)
 {

	 SPDR=copy_data;
	 while(GET_BIT(SPDSR ,7)==0);
	 return SPDR;
 }


