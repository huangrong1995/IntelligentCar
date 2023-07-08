#ifndef __DEBUG_H
#define	__DEBUG_H

#include "stdio.h"

#define DEBUG_ON

#ifdef DEBUG_ON
#define LOG(format, ...) printf("\r[%s][%d]"format, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define LOG(format, ...) 
#endif


#endif /* __DEBUG_H */
