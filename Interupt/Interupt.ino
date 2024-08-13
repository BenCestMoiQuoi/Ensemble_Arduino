// More info on the data sheet 
//  Arduino Uno (to know the prossessor)
//  ATmega48A   Microchip

// Exemple for Timer 2 and Timer 0

#define Pin_a 5

int state = 0;

void setup() {
  pinMode(Pin_a, OUTPUT);

  cli();
  TCCR2A &= B00001100;
  TCCR2B &= B00110000;
  TCCR2B |= B00000100;
  TIMSK2 &= B11111000;
  TIMSK2 |= B00000100;
  OCR2B = 250;
  sei();

  int Timer = 0;
}

void loop() {
  // put your main code here, to run

}

ISR(TIMER2_COMPB_vect){
  TCNT2 = 0;
  state = !state;
  digitalWrite(Pin_a, state);
}
