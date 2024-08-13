#include <Servo.h>
Servo servomoteur;
#include <Servo.h>
Servo servomoteur2;
int positionservo;
int positionservo2;
int analogPin=A1;
int analogValue=0;
int analogPin2=A2;
int analogValue2=0;
int analogPin3=A3;
int analogValue3=0;
int analogPin4=A4;
int analogValue4=0;


void setup() {
 servomoteur.attach(6);
 servomoteur.write(positionservo);
 servomoteur2.attach(9);
 servomoteur2.write(positionservo2);
  Serial.begin(9600);
}

void loop() {
analogValue=analogRead(analogPin);
analogValue2=analogRead(analogPin2);
analogValue3=analogRead(analogPin3);
analogValue4=analogRead(analogPin4);
Serial.println(analogValue);
Serial.println(analogValue2);
Serial.println(analogValue3);
Serial.println(analogValue4);
delay(10);
if (analogValue > analogValue2)
{
servomoteur.write(positionservo);
positionservo = positionservo+1;
}
else if (analogValue < analogValue2)
{
 servomoteur.write(positionservo);
 positionservo = positionservo-1;
}
else
{
}
if (analogValue3 > analogValue4)
{
servomoteur2.write(positionservo2);
positionservo2 = positionservo2 + 1;
}
else if (analogValue3 < analogValue4)
{
 servomoteur2.write(positionservo2);
 positionservo2 = positionservo2 - 1;
}
else
{
servomoteur2.write(positionservo2);
positionservo2 = positionservo2;
}
}
