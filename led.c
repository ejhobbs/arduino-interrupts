#include <avr/io.h>
#include <util/delay.h>

#define RED 0x01
#define REDAMBER 0x03
#define GREEN 0x04
#define AMBER 0x02
int main (void) {
  DDRB = 0x07;

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
