//v1.0
//Вычисление с помощью двух резисторов времени мигания светодиода и паузы между миганиями.

int led=5;
int calcDelay;
int calcPowerOn;

void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);

  int sensorValue2 = analogRead(A1);
  float voltage2 = sensorValue2 * (5.0 / 1023.0);
  
  //Serial.println(voltage);
  digitalWrite(led, HIGH);
  calcPowerOn=1000*voltage2;
  delay(calcPowerOn);
  digitalWrite(led, LOW);
  calcDelay=1000*voltage;
  Serial.println(calcDelay);
  delay(calcDelay);
}
