#define pin_resistor A0
#define nb_led 8


int pin_led[nb_led] = {6, 7, 8, 9, 10, 11, 3, 13};

int val_res;
bool val_led;
int k;


void setup() {
  for (k=0; k<nb_led;k++){
    pinMode(pin_led[k], OUTPUT);
    digitalWrite(pin_led[k], LOW);
  }
  pinMode(pin_resistor, INPUT);
  Serial.begin(9600);

}

void loop() {
  val_res = analogRead(pin_resistor);
  Serial.println(val_res);
  for (k=0; k<8; k++){
    if (val_res > k*128){
      digitalWrite(pin_led[k], HIGH);
    }
    else if (val_res <= k*128){
      digitalWrite(pin_led[k], LOW);
    }
  }
}
