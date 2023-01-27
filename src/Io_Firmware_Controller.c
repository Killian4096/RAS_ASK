#include <avr/io.h>
#include "OSEPP_Motor_Shield.h"
#include <util/delay.h>
#include "USART.h"

void main(void){
    ESC_Init();
    USART_Init();
    while(1);
}
