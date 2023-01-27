#include <avr/io.h>
#include "ESC.h"
#include "USART.h"
#include <util/delay.h>

void main(void){
    USART_Init();
    ESC_Init();
    while(1);
}
