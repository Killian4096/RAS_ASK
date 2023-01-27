#include <avr/io.h>
#include <stdint.h>
#include <config.h>
#include <USART.h>


void USART_Init(void){
    //Set Baud Rate, put something here
    UBRR0H |= (uint8_t)(BAUD_FACTOR>>8);
    UBRR0L |= (uint8_t)(BAUD_FACTOR);

    //Enable Transmitter and Receiver
    UCSR0B |= (1<<TXEN0) | (1<<RXEN0);

    //Set frame format: 9data, 2 stop bit
    UCSR0C |= (1<<USBS0) | (1<<UCSZ02) | (1<<UCSZ01) | (1<<UCSZ00);

    //Look at UCSRnC datasheet
}

uint16_t USART_Receive(void){
    while(!(UCSR0A & (1<<RXC0)));
    status = USCR0A
    resh = UCSR0B;
    resl = UDR0;
    
    if (status & (1<<FE0)|(1<<DOR0)|(1<<UPE0))
        return -1
    
    resh = (resh >> 1) & 0x01;
    return ((resh << 8) | resl);
}

void USART_Transmit(uint16_t data){
    //Wait for transmit to finish
    while(!(UCSR0A & (1<<UDRE0)));

    //Copy 9th bit
    UCSR0B &= ~(1<<TXB8);
    if(data & 0x0100)
        USCR0B |= (1<<TXB8);

    //Put data into buffer
    UDR0 = data;
}
