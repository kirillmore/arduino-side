float wet=250;
float dry=612;

void setup() {
  Serial.begin(9600);
}
void loop() {
  float val;
  int moisture;
  val = analogRead(0);
  moisture=round(100-(((val-wet)*100)/(dry-wet)));
  Serial.println(moisture);
  delay(1000);
}
