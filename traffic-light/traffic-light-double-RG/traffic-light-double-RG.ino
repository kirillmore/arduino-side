// v1.0a
int firstRed=4;
int firstGreen=5;
int secondRed=6;
int secondGreen=7;

void setup(){
  pinMode(firstRed, OUTPUT);
  pinMode(firstGreen, OUTPUT);
  pinMode(secondRed, OUTPUT);
  pinMode(secondGreen, OUTPUT);
}
 
void loop(){
  //phase1
  digitalWrite(firstRed, HIGH);
  digitalWrite(secondGreen, HIGH);
  delay(5000);
  digitalWrite(firstRed, LOW);
  digitalWrite(secondGreen, LOW);
  //phase2
  digitalWrite(secondRed, HIGH);
  digitalWrite(firstGreen, HIGH);
  delay(5000);
  digitalWrite(secondRed, LOW);
  digitalWrite(firstGreen, LOW);
}