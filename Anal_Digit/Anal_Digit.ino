// analog to digital converter

// map(val, fromLOW, fromHIGH, toLOW, toHIGH)
//  map(395, 0, 1023, 0, 255)

// default frequency --> 100000 samples/s
// we can change this frequency
//  CK = clock of micro
// ADPS   [2, 1, 0] 0bxxx
//  1   1   1 | CK/128
//  1   1   0 | CK/64
//  1   0   1 | CK/32
//  1   0   0 | CK/16
//  0   1   1 | CK/8
//  0   1   0 | CK/4
//  0   0   1 | CK/2
//  0   0   0 | 1000000 samples/s (default)


#define led_pin 5
#define _BV(n) (1<<n)

int status = 0;
int val;

void ADC_Init() {
  DIDR0 |= _BV(ADC0D); // Desible digital pin
  DDRC=0x0; // Make ADC port as input
  ADCSRA = ADCSRA | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); //  ADPS = 0b111
  ADMUX |= _BV(REFS0); // Verf: Avcc, ADC Channel: 0
}

int ADC_Read(char channel) {
  ADMUX = ADMUX|(channel & 0x0f); // Set input channel to read
  ADCSRA |= _BV(ADSC); // Start conversion
  while(bit_is_set(ADCSRA, ADSC)); // Monitor and of conversion interrupt
  //delayMicroseconds(10);
  return ADCW; // Return digital value
}

void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
  ADC_Init();
}

void loop() {
  while(1){
    cli();
    val = ADC_Read(0);
    if (status) {
      digitalWrite(led_pin, HIGH);
    }
    else{
      digitalWrite(led_pin, LOW);
    }
    status = !status;
    sei();
  }
}
