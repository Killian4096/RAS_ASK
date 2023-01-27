#include <avr/io.h>
#include <stdint.h>
#include <config.h>
#include <ESC.h>

void ESC_Init(void){
    //Enable pwm pins
    DDRD |= (1<<DDD5);
    
    //Set pwm mode to clear on compare and fast pwm mode 3, no prescale
    TCCR0A |= (1<<COM0A1) | (1<<COM0B1) | (1<<WGM01) | (1<<WGM00);
    TCCR0B |= (1<<CS00);
    
}

void ESC_Set_Speed(uint8_t value){
    //Send value to register
    OC0B = value;
}


