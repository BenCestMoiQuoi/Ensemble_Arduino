#include "LCD_I2C.h"
#include "DHT.h"

#define DHTPIN 3
#define DHTTYPE DHT11

LCD_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

double humidity;
double temperature;

void setup() {
  dht.begin();

  lcd.begin();
  lcd.backlight();

  Serial.begin(9600);
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  
  lcd.setCursor(0, 0);
  lcd.print("Humi : ");
  lcd.print(humidity, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp : ");
  lcd.print(temperature, 2);
  lcd.print("°C");
}
