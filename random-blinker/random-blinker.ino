// v1.1
int led1=5;
int led2=6;
int led3=7;
int led4=8;
int led5=9;
int led6=10;
int led7=11;

void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
}
 
void loop(){
  int n;
  n=random(5, 12);
  Serial.print(n);
  digitalWrite(n,HIGH);
  delay(1000);
  digitalWrite(n,LOW);
}
