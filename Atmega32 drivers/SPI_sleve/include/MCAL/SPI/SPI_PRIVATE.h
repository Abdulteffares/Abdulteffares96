/*
 * SPI_PRIVATE.h
 *
 *  Created on: Jun 9, 2023
 *      Author: Abdultef fares
 */

#ifndef INCLUDE_SPI_SPI_PRIVATE_H_
#define INCLUDE_SPI_SPI_PRIVATE_H_
#define SPDR  (*(volatile u8*)0x2F)
#define SPDSR (*(volatile u8*)0x2E)
#define SPDCR (*(volatile u8*)0x2D)
#define SPIE 7 //SPI INTERRUPT ENABLE
#define SPE 6 //SPI ENABLE
#define DORD 5

#endif /* INCLUDE_SPI_SPI_PRIVATE_H_ */
