// v1.1
int firstRed=4;
int firstGreen=5;
int secondRed=6;
int secondGreen=7;

int phase=5000;

void blink(int l){
  int i;
  for(i=0;i<3;i++){
    delay(500);digitalWrite(l, HIGH);  
    delay(500);digitalWrite(l, LOW);
  }
}

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
  delay(phase);
  digitalWrite(secondGreen, LOW);
  blink(secondGreen);
  digitalWrite(firstRed, LOW);
  //phase2
  digitalWrite(secondRed, HIGH);
  digitalWrite(firstGreen, HIGH);
  delay(phase);
  digitalWrite(firstGreen, LOW);
  blink(firstGreen);
  digitalWrite(secondRed, LOW);
}