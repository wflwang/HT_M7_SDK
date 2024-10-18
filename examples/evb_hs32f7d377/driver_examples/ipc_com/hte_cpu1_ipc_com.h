#ifndef __CPU1_IPC_COM_INT_H__
#define __CPU1_IPC_COM_INT_H__

#define IPC_COM_READ  0x000055AA
#define IPC_COM_WRITE 0x000055BB
#define IPC_COM_CLK_PARAM 0x000055CC

#define IPC_COM_DONE  0x5A5A5B5B

extern void IPC_comInit(void);

#endif
