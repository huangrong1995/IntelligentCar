#ifndef __USART_H
#define	__USART_H

#include "stm32f10x.h"
#include <stdio.h>

void USART_Config(void);
int fputc(int ch, FILE *f);
void USART_printf(USART_TypeDef* USARTx, uint8_t *Data,...);

#endif /* __USART_H */
