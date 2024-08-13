const byte pin_button = 2;
const byte leds[4] = {6, 7, 8, 9};

byte state_pb = 1;
int count = 0;
bool state_led = 0;
int timer = 0;


void setup() {
  pinMode(pin_button, INPUT);
  for(int k=0; k<4; k++){
    pinMode(leds[k], OUTPUT);
    digitalWrite(leds[k], LOW);
  }
  
  Serial.begin(9600);

/* Prise en charge et configuration du clignotement */
  TCCR0A=(1<<WGM01);    //Set the CTC mode   
  OCR0A=0xF9; //Value for ORC0A for 1ms 
  
  TIMSK0|=(1<<OCIE0A);   //Set  the interrupt request
  sei(); //Enable interrupt
  
  TCCR0B|=(1<<CS01);    //Set the prescale 1/64 clock
  TCCR0B|=(1<<CS00);
  
}

void loop() {
  if (!digitalRead(pin_button) && state_pb == 1){
    delay(100);
    if (!digitalRead(pin_button)){
      count++;
      state_pb = 0;
      
      Serial.println(count);
    }
  } 

  else if(digitalRead(pin_button) && state_pb == 0){
    delay(100);
    if (digitalRead(pin_button)){
      state_pb = 1;
    } 
  }

  if (timer >= 1000){
    state_led = !state_led;
    timer = 0;
  }

  for (int k=0; k<4; k++){
    digitalWrite(leds[k], bitRead(count, k) && state_led);
  }
}

ISR(TIMER0_COMPA_vect){    //This  is the interrupt request
  timer++;
}
