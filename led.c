#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define RED 0x01
#define REDAMBER 0x03
#define GREEN 0x04
#define AMBER 0x02
#define WHITE 0x08
int main (void) {
  DDRB = 0x0F;
  PORTB |= (1<<PORTB4);
  PCICR |= (1<<PCIE0);
  PCMSK0 |= (1<<PCINT4); //enable interrupt listening on PB4 (arduino pin 12)

  sei(); //enable interrupts

  while(1){
    PORTB = RED;
    _delay_ms(500);
    PORTB = REDAMBER;
    _delay_ms(500);
    PORTB = GREEN;
    _delay_ms(500);
    PORTB = AMBER;
    _delay_ms(500);
  }
}

ISR (PCINT0_vect){
  if (PINB & (1 << PINB4)){ //check if PB4 high
    PORTB = WHITE;
  }
}
