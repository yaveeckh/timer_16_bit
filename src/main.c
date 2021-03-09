#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


ISR(TIMER1_COMPA_vect) {
    PORTA ^= 0xFF;
}

int main(void)
{
    // make the LED pin an output for PORTA
    DDRA |= 0xFF;
    PORTA |= 0b01010101;

    TCCR1A |= _BV(COM1A1);
    TCCR1A &= ~_BV(COM1A0);

    TCCR1B |= _BV(WGM12);
    TCCR1B &= ~_BV(WGM13);

    TCCR1B  |= _BV(CS12) | _BV(CS10);
    TCCR1B &= ~_BV(CS11);

    OCR1A = 15625;

    sei();
    TIMSK1 |= _BV(OCIE1A);

    
    
    while (1)
    {
        
    }

    return 0;
}

