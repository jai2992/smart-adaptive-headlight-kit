#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LDR_PIN = A0; 
const int LED_PIN = D0; 

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  lcd.init();                     
  lcd.backlight();                
  lcd.setCursor(0, 0);            
  lcd.print("LDR Value: ");       
}

void loop() {
  int sensorValue = analogRead(LDR_PIN);

  lcd.setCursor(11, 0);          
  lcd.print(sensorValue);       
  if (sensorValue > 500) {  
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
