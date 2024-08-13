// More info on the data sheet 
//  Arduino Uno (to know the prossessor)
//  ATmega48A   Microchip

// Exemple for Timer 2 "Fast PWM"


#define _BV(n) (1<<n)

void setup() {
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);

  //              TCCR2A
  //  |COM2A1|COM2A0|COM2B1|COM2B0| - | - |WGM21|WGM20|
  //  |   1  |   0  |   1  |  0   | - | - |  1  |  1  |

  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);

  //              TCCR2B
  //  |FOC2A|FOC0B| - | - |WGM22|CS22|CS21|CS20|
  //  |  0  |  0  | - | - |  0  |  1 | 1  | 1  |

  // Frrquency --> clk = f_micro/(n*256)
  // n = 1 -> 001
  // n = 8 -> 010
  // n = 32 -> 011
  // n = 64 -> 100
  // n = 128 -> 101
  // n = 256 -> 110
  // n = 1024 -> 111

  TCCR2B = _BV(CS22) |_BV(CS21) | _BV(CS20);

  // dA=(180+1)/256 = 70.7%
  // dB=(50+1)/256 = 19.9%
  OCR2A = 180;
  OCR2B = 50;

}

void loop() {
  

}
