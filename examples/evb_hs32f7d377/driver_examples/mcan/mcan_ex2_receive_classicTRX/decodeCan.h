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

typedef struct decodeCanData
{
  /* data */
  int vLastDuty;
  int vNowDuty;
}decodeCanData;
extern uint32_t backCanStandID(uint32_t srcID);
extern void GetUWI(uint16_t *data);
extern void Getidvd(uint16_t *data);
extern void Getiqvq(uint16_t *data);
extern void GetRpm(uint16_t *data);
extern void GetInputVol(uint16_t *data);
extern void SetDuty(uint16_t* dr);
extern void SetDutyClr(void);
extern void SetI(uint16_t* dr);
extern void SetRPM(uint16_t* dr);
extern void decodeInst(uint16_t *data,decodeCanData* dcd);
extern void GetMotorValue(uint16_t *data);


#endif