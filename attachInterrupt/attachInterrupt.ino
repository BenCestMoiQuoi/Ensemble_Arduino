#define ENCODER_SIA 2
#define ENCODER_SIB 4
#define ENCODER_SW 3

volatile int count;
int last_count;

void setup() {
  pinMode(ENCODER_SIA, INPUT);
  pinMode(ENCODER_SIB, INPUT);
  pinMode(ENCODER_SW, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_SIA), readEncoder, FALLING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_SW), clearCount, FALLING);

  count = 0;
  Serial.begin(9600);
  Serial.println(count);
}

void readEncoder() {
  if (digitalRead(ENCODER_SIB))  count++;
  else count--;
}

void clearCount(){
  count = 0;
}

void loop() {
  if (last_count != count){
    Serial.println(count);
    last_count = count;
  }
}