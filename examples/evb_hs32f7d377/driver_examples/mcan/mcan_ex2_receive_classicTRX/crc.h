/*
**********************************************************
  @file crc.h
  @author Maxwell Wang
  @version v1.0.0
  @date 2024-10-17
  @brief decode can for customer
***********************************************************
    */

#ifndef CRC_H_
#define CRC_H_

#include <stdint.h>

/*
 * Functions
 */
unsigned short crc16(unsigned char *buf, unsigned int len);

#endif /* CRC_H_ */
