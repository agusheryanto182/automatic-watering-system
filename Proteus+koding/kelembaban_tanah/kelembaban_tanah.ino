#include <LiquidCrystal.h> 

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
int SensorPin = A5; 
int data;
int motorPin = 5; 

void setup() {
lcd.begin(20, 4); 
lcd.setCursor(1, 1);
lcd.print("KELEMBABAN");

pinMode(motorPin, OUTPUT);
}

void loop() {
data = analogRead(SensorPin);
float Kelembaban = analogRead(SensorPin) * 0.098135426889107; 

lcd.setCursor(13, 1);
lcd.print(Kelembaban);
lcd.print("%");

if (Kelembaban < 30) { 
lcd.setCursor(1, 2);
lcd.print("TANAH KERING");
digitalWrite(motorPin, HIGH); 
} else {
lcd.setCursor(1, 2);
lcd.print("TANAH LEMBAB");
digitalWrite(motorPin, LOW); 
}
}