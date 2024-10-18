/**
**********************************************************
  @file decodeCan.c
  @author Maxwell Wang
  @version v1.0.0
  @date 2024-10-17
  @brief decode can for customer
***********************************************************
**/
//#include "hte_common.h"
#include "board.h"
#include "decodeCan.h"
#include "hte_uart.h"
#include "crc.h"
/************************************************************
//reback  stand  ID
// @return desID
************************************************************/
uint32_t backCanStandID(uint32_t srcID){
    //
		uint32_t tempid = srcID;
		//printf("id:%x",tempid);
		tempid = ((tempid)>>18);   //&>>18
		//printf("id1:0x%x",tempid);
    tempid = (tempid&0x700)|((tempid>>4)&0x0f)|((tempid<<4)&0xf0);
		//printf("id1:0x%x",tempid);
    return (tempid<<18)|((srcID)&0x3ffff);
}
/**
 * decode data inst
 * 
 * 
*/
void decodeInst(uint16_t *data){
    uint16_t dat = *data;
    switch(*data){
        case 0: //获取参数
        break;;
        case 1: //设置参数
        break;
        case 2: //参须运行状态
        switch (data[1]){
            case 5: //获取速度
            GetRpm(data);
            break;
            case 6: //读出输入电压
            GetInputVol(data);
            break;
        }
        break;
        case 3: //控制命令
        default:
        if(data[1]==0){
            switch((data[2]<<8)|data[3]){
                case 0: //standby
                    SetDutyClr();
                break;
                case 1: //servo
                break;
                case 2: //speed - 3,0,0,2,x,x,x,x
                    SetDuty(&data[4]);
                break;
                case 3: //I control
                    SetI(&data[4]);
                break;
                case 4: //check
                break;
            }
        }
        break;
    }
}
// 函数：将整数转换为二进制字符串（这里稍作修改以适应静态数组）  
//void intToBinary(int num, char binaryStr[33]) {  
//    binaryStr[32] = '\0'; // 字符串终止符  
//    for (int i = 31; i >= 0; i--) {  
//        binaryStr[31 - i] = (num & (1 << i)) ? '1' : '0';  
//    }  
//}  
/**
 * 获取当前转速
 * 
*/
void GetRpm(uint16_t *data){
    const uint8_t dataBuf[20]  = {0x02,0x05,0x32,0,0,0x00,0x80,0xd9,0xe5,0x03};  //获取电压
    (void)UART_writeDataBlocking(BOARD_DEBUG_CONSOLE_BASE, dataBuf, 10);
	(void)UART_readDataBlocking(BOARD_DEBUG_CONSOLE_BASE, dataBuf, 14);
    unsigned short crc = crc16(&dataBuf[2], dataBuf[1]);
    if(((crc>>8)==dataBuf[dataBuf[1]+2])&&((crc&0xff)==dataBuf[dataBuf[1]+3])){
        data[2] = dataBuf[7];
        data[3] = dataBuf[8];
        data[4] = dataBuf[9];
        data[5] = dataBuf[10];
    }
}
/**
 * 获取输入电压
 * 
*/
void GetInputVol(uint16_t *data){
    const uint8_t dataBuf[20]  = {0x02,0x05,50,0,0,0x01,0x00,0x7b,0x5c,0x03};  //获取电压
    (void)UART_writeDataBlocking(BOARD_DEBUG_CONSOLE_BASE, dataBuf, 10);
	(void)UART_readDataBlocking(BOARD_DEBUG_CONSOLE_BASE, dataBuf, 12);
    //while(1){
        //(void)UART_readDataBlocking(BOARD_DEBUG_CONSOLE_BASE, &dataBuf, 12);
        //(void)UART_writeDataBlocking(BOARD_DEBUG_CONSOLE_BASE, &dataBuf, 1);
    //}
    //(void)UART_readDataBlocking(BOARD_DEBUG_CONSOLE_BASE, dataBuf, 1);
    unsigned short crc = crc16(&dataBuf[2], dataBuf[1]);
    if(((crc>>8)==dataBuf[dataBuf[1]+2])&&((crc&0xff)==dataBuf[dataBuf[1]+3])){
        data[2] = dataBuf[7];
        data[3] = dataBuf[8];
    }
}
/**
 * 获取电调内部参数
 * 
*/
void GetMotorValue(){
    //查询命令表格
    const uint8_t dataBuf[20]  = {0x02,0x05,14,0xe1,0xce,0x03};  //获取电压
    (void)UART_writeDataBlocking(BOARD_DEBUG_CONSOLE_BASE, dataBuf, 6);
	(void)UART_readDataBlocking(BOARD_DEBUG_CONSOLE_BASE, dataBuf, 12);
    unsigned short crc = crc16(&dataBuf[2], dataBuf[1]);
    if(((crc>>8)==dataBuf[dataBuf[1]+2])&&((crc&0xff)==dataBuf[dataBuf[1]+3])){
        data[2] = dataBuf[7];
        data[3] = dataBuf[8];
    }
}
/**
 * set duty duty/100000
 * 
*/
void SetDutyClr(){
    //const uint8_t dataBuf[10]  = {0x02,0x05,0x05,0,0,0,0,0x23,0x57,0x03};
    const uint8_t dataBuf[10]  = {0x02,0x05,0x06,0,0,0,0,0xcd,0x85,0x03};
    (void)UART_writeDataBlocking(BOARD_DEBUG_CONSOLE_BASE, dataBuf, sizeof(dataBuf));
}
/**
 * set duty duty/100000
 * 
*/
void SetDuty(uint16_t *dr){
    //DEBUG_CONSOLE_HAL_uartTransmit();
    //printf(555555);
    //int num = 555555;  
    //char binaryStr[33]; 
    //intToBinary(num, binaryStr); 
    //printf("%s\n", binaryStr); 
    /* Send the example banner */
    unsigned char dataBuf[5]  = {0x05,(uint8_t)(*dr),(uint8_t)(*(dr+1)),(uint8_t)(*(dr+2)),(uint8_t)(*(dr+3))};
    unsigned short crc = crc16(dataBuf, 5);
    const uint8_t databuff1[] = {0x02,0x05,dataBuf[0],dataBuf[1],dataBuf[2],dataBuf[3],dataBuf[4],(uint8_t)(crc >> 8),(uint8_t)(crc & 0xFF),0x03};
    (void)UART_writeDataBlocking(BOARD_DEBUG_CONSOLE_BASE, databuff1, sizeof(databuff1));
    //printf("%02X%02X%02X%02X%02X",0x05,(uint8_t)(*dr),(uint8_t)(*dr+1),(uint8_t)(*dr+2),(uint8_t)(*dr+3));
}
/**
 * set I I/1000
 * 
*/
void SetI(uint16_t *dr){
    unsigned char dataBuf[5]  = {0x06,(uint8_t)(*dr),(uint8_t)(*(dr+1)),(uint8_t)(*(dr+2)),(uint8_t)(*(dr+3))};
    unsigned short crc = crc16(dataBuf, 5);
    const uint8_t databuff1[] = {0x02,0x05,dataBuf[0],dataBuf[1],dataBuf[2],dataBuf[3],dataBuf[4],(uint8_t)(crc >> 8),(uint8_t)(crc & 0xFF),0x03};
    (void)UART_writeDataBlocking(BOARD_DEBUG_CONSOLE_BASE, databuff1, sizeof(databuff1));
    //printf("%02X%02X%02X%02X%02X",0x06,(uint8_t)(dr3),(uint8_t)(dr2),(uint8_t)(dr1),(uint8_t)(dr0));
}
/**
 * set RPM PRM/1000000
 * 
*/
void SetRPM(uint16_t *dr){
    unsigned char dataBuf[5]  = {0x08,(uint8_t)(*dr),(uint8_t)(*(dr+1)),(uint8_t)(*(dr+2)),(uint8_t)(*(dr+3))};
    unsigned short crc = crc16(dataBuf, 5);
    const uint8_t databuff1[] = {0x02,0x05,dataBuf[0],dataBuf[1],dataBuf[2],dataBuf[3],dataBuf[4],(uint8_t)(crc >> 8),(uint8_t)(crc & 0xFF),0x03};
    (void)UART_writeDataBlocking(BOARD_DEBUG_CONSOLE_BASE, databuff1, sizeof(databuff1));
    //printf("%02X%02X%02X%02X%02X",0x08,(uint8_t)(dr3),(uint8_t)(dr2),(uint8_t)(dr1),(uint8_t)(dr0));
}
/**
 * get tord Kpd IqrComFPbs
 * 获取D轴参数
*/
void getTDConfif(){

}