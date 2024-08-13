#define pin1 3
#define pin2 5
#define bp 4

int count = 0;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(bp, INPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(bp)){
    count++;
    Serial.println(count);
    analogWrite(pin1, count);
    analogWrite(pin2, count);
  }
  delay(100);
}
