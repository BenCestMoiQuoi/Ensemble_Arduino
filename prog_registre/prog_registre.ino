    //  Clignottement d'un pin 

// Avec les fonctions d'Arduino

const byte outPin = 10;

void setup() {
  pinMode(outPin, OUTPUT);
  while(1) {
    digitalWrite(outPin, HIGH);
    digitalWrite(outPin, LOW);
  }
}

// Avec les fonctions Adruino, le clignottement est de 112.6 kHz

// Sans les fonctions d'Arduino

const byte outPin = B00000100;

void setup() {
  DDRB |= outPin;
  while (1) {
    PORTB |= B00000100;
    PORTB &= B11111011;
  }
}

// Sans les fonctions Arduino, le clignottement est de 2.6 MHz