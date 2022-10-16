#include <Wire.h>
#include <Rtc_Pcf8563.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

//init the real time clock
Rtc_Pcf8563 rtc;



int minButton = 42;

void setup()
{
  lcd.backlight();
  lcd.begin(16, 2);
  pinMode (minButton,INPUT);
  //clear out all the registers
  rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century, year
  byte day = 1;
  byte weekday= 1;
  byte month = 1;
  byte century =0;
  byte year = 13;

  day =20;
  weekday =7;
  month =1;
  century =20;
  year =13;
  rtc.setDate(day,weekday, month, century, year);
}

void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print(rtc.formatTime());
  lcd.setCursor(0, 1);
  lcd.print(rtc.formatDate());
  delay(1000);

  if(digitalRead(minButton) == HIGH)
    changeTime();
}

void changeTime(){

  byte hour = 5;
  byte min = 30;
  byte sec = 14;

  hour = 18;
  min = 20;
  sec = 00;
  rtc.setTime(hour, min,sec);

  if(digitalRead(minButton) == HIGH)
  {
    min += 1;  
  }
}
