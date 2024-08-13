const int SensorPin = A0;
const float cte = 20.0;
void setup() {
 Serial.begin(9600);
 pinMode(4,OUTPUT); 
}
void loop() {
int SensorVal = analogRead(SensorPin);
Serial.print("valeur capteur :");
Serial.print(SensorVal);
float voltage = (SensorVal/1024.0)*5;
Serial.print(" , Volts : ");
Serial.print(voltage);
Serial.print(" , degres C : ");
float temperature = (voltage - .5)*100;
Serial.println(temperature);
if (temperature > cte){
  digitalWrite(4, HIGH);
}
else {
  digitalWrite(4, LOW);
}
delay(1000);
}
