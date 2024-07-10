
/*
 *
 * Operating System Design / Diseño de Sistemas Operativos
 * (c) ARCOS.INF.UC3M.ES
 *
 * PLEASE DO NOT MODIFY THIS FILE!
 *
 * @file 	crc.h
 * @brief 	Headers for the CRC functionality.
 * @date	Last revision 01/04/2020
 *
 */


#ifndef _CRC_H_
#define _CRC_H_

#include <stdint.h>

/*
 * @brief	CRC16 implementation.
 *
 * @param	<buffer> to compute the CRC on.
 * @param	<length> of the buffer, in bytes.
 * @return	A 16-bit unsigned integer containing the resulting CRC.
 */
uint16_t CRC16(const unsigned char* buffer, unsigned int length);

/*
 * @brief	CRC32 implementation.
 *
 * @param	<buffer> to compute the CRC on.
 * @param	<length> of the buffer, in bytes.
 * @return	A 32-bit unsigned integer containing the resulting CRC.
 */

uint32_t CRC32(const unsigned char* buffer, unsigned int length);
/*
 * @brief	CRC64 implementation.
 *
 * @param	<buffer> to compute the CRC on.
 * @param	<length> of the buffer, in bytes.
 * @return	A 64-bit unsigned integer containing the resulting CRC.
 */
uint64_t CRC64(const unsigned char * buffer, unsigned int length);

#endif
