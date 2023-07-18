#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // Pin yang digunakan pada arduino
int SensorPin = A5; // Untuk sensor kelembapan tanah
int data;
int motorPin = 5; // Pin untuk motor 

void setup() {
lcd.begin(20, 4); // LCD 20 baris ke kanan 4 baris ke bawah
lcd.setCursor(1, 1);
lcd.print("KELEMBABAN");

pinMode(motorPin, OUTPUT);
}

void loop() {
data = analogRead(SensorPin);
float Kelembaban = analogRead(SensorPin) * 0.0981354269; // Sinyal analog sensor 1019 dirubah ke persen (100:1019) 

lcd.setCursor(13, 1);
lcd.print(Kelembaban);
lcd.print("%");

if (Kelembaban < 30) { // Mengaktifkan fan dan motor jika kelembaban kurang dari sama dengan 30% 
lcd.setCursor(1, 2);
lcd.print("TANAH KERING");
digitalWrite(motorPin, HIGH); // Menghidupkan motor
} else {
lcd.setCursor(1, 2);
lcd.print("TANAH LEMBAB");
digitalWrite(motorPin, LOW); // Mematikan motor 
}
}