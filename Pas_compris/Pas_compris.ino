/* Mouving average */

#define _BV(n) (1<<n)

#define max_k 8

int data[max_k];
int k;
int val;
int cal;
int i;
float avg;

void setup() {
  Serial.begin(9600);
  k = 0;
  for (i=0; i!=max_k; i++){
    data[i] = 0;
  }
  ADC_Init();
}

void loop() {
  val = ADC_Read(0);
  data[k] = val;
  //Serial.println(data[k]);
  k = (k+1)%max_k;
  cal = 0;
  for (i=0; i!=max_k; i++) {
    cal = cal+data[i];
  }
  avg = cal/max_k;
  Serial.println(avg);
  delay(1000);
}


void ADC_Init() {
  DDRC=0x0; // Make ADC port as input
  ADCSRA = ADCSRA | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); //  ADPS = 0b111
  ADMUX |= _BV(REFS0); // Verf: Avcc, ADC Channel: 0
}

int ADC_Read(char channel) {
  ADMUX = ADMUX|(channel & 0x0f); // Set input channel to read
  ADCSRA |= _BV(ADSC); // Start conversion
  while(!(ADCSRA & _BV(ADIF))); // Monitor and of conversion interrupt
  ADCSRA |= _BV(ADIF);
  delayMicroseconds(10);
  return ADCW; // Return digital value
}