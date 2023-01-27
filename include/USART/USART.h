#ifndef USART_H_
#define USART_H_
#include <stdint.h>


void USART_Init(void);
uint16_t USART_Receive(void);
void USART_Transmit(uint16_t data);

#endif
