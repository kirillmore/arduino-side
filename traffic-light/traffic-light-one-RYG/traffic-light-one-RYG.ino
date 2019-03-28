// v1.1
int Green=8;
int Yellow=9;
int Red=10;
int phase=5000;

void blink(int l){
  int i;
  for(i=0;i<3;i++){
    delay(500);digitalWrite(l, HIGH);  
    delay(500);digitalWrite(l, LOW);
  }
}

void setup(){
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
}
 
void loop(){
  digitalWrite(Red, HIGH);delay(phase);
  digitalWrite(Yellow, HIGH);delay(1000);
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, HIGH);delay(phase);
  digitalWrite(Green, LOW);
  blink(Green);
  digitalWrite(Yellow, HIGH);delay(1000);
  digitalWrite(Yellow, LOW);
}
