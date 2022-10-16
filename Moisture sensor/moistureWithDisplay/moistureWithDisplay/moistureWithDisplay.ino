float wet=250;
float dry=612;

//init display
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

//init dht11
#include <dht11.h>
dht11 DHT;
#define DHT11_PIN 4

void setup() {
  Serial.begin(9600);
  String version="groover v1.1";
  Serial.begin(9600);
  lcd.init();
  //lcd.backlight();
  lcd.noBacklight();
  lcd.print(version);
  delay(3000);
}

void loop() {
  int chk;
  chk = DHT.read(DHT11_PIN);
  Serial.print(DHT.humidity,1);
  Serial.print(",\t");
  Serial.println(DHT.temperature,1);
  
  float val;
  int moisture;
  val = analogRead(0);
  moisture=round(100-(((val-wet)*100)/(dry-wet)));
  lcd.setCursor(0,0);
  lcd.print("WET----------DRY");
  lcd.setCursor(0,1);
  lcd.print(moisture);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
