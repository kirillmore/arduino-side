#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);


void setup(){
  lcd.init();
//  lcd.noBacklight();
  lcd.setCursor(0, 0);
  lcd.print("Current time:");
}

void loop(){
  delay(1000);
  lcd.setCursor(0, 1);
  unsigned long tstamp = millis()+1000;
  int h = tstamp / 1000 / 60 / 60;
  int m = (tstamp / 1000 / 60) % 60;
  int s = (tstamp / 1000) % 60;

  String line = String(h) + "h " +
    String(m) + "m " +
    String(s) + "s";

  int len = line.length();
  while(len < 16){
    line += " ";
    len++;
  }
  lcd.print(line);
}
