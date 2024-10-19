/**
**********************************************************
  @file decodeCan.h -- head file
  @author Maxwell Wang
  @version v1.0.0
  @date 2024-10-17
  @brief decode can for customer
***********************************************************
**/
#ifndef __DECODECAN_H
#define __DECODECAN_H
#include "hte_common.h"

extern uint32_t backCanStandID(uint32_t srcID);
extern void GetRpm(uint16_t *data);
extern void GetInputVol(uint16_t *data);
extern void SetDuty(uint16_t* dr);
extern void SetDutyClr(void);
extern void SetI(uint16_t* dr);
extern void SetRPM(uint16_t* dr);
extern void decodeInst(uint16_t *data);
extern void GetMotorValue(uint16_t *data);

#endif