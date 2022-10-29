#include <SPI.h>
#include <SD.h>

const int PIN_CHIP_SELECT = 4;

float wet=250;
float dry=612;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
 // Этот пин обязательно должен быть определен как OUTPUT
  pinMode(10, OUTPUT);

  // Пытаемся проинициализировать модуль
  if (!SD.begin(PIN_CHIP_SELECT)) {
    Serial.println("Card failed, or not present");
    // Если что-то пошло не так, завершаем работу:
    return;
  }
  Serial.println("card initialized.");
}

void loop() {
  float val;
  int moisture;
  val = analogRead(0);
  moisture=round(100-(((val-wet)*100)/(dry-wet)));

  File dataFile = SD.open("moisture.csv", FILE_WRITE);

  // Если все хорошо, то записываем строку:
  if (dataFile) {
    dataFile.println(moisture);
    dataFile.close();
    // Публикуем в мониторе порта для отладки
    Serial.println(moisture+";");
  }
  else {
  // Сообщаем об ошибке, если все плохо
    Serial.println("error opening moisture.csv");
  }

  delay(5000);
}