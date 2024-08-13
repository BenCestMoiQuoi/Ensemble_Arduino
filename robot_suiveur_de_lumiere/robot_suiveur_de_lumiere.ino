int analogPin = A1;
int analogValue = 0;
int analogPin2 = A3;
int analogValue2 = 0;
const int motorPin = 9;
const int motorPin2 = 10;
void setup() {
 Serial.begin(9600);
 pinMode(motorPin,OUTPUT);
 pinMode(motorPin2,OUTPUT);
}

void loop() {
analogValue2=analogRead(analogPin2);
analogValue=analogRead(analogPin);
Serial.println(analogValue2);
Serial.println(analogValue);
delay(200);
if (analogValue > analogValue2)
{
digitalWrite(motorPin,LOW);
digitalWrite(motorPin2,HIGH);
}
else
{
digitalWrite(motorPin,HIGH);
digitalWrite(motorPin2,LOW);  
}
}
