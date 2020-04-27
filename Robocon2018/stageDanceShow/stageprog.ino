#define pwm1 3
#define dir1 2
#define pwm2 5
#define dir2 4
#define pwm3 7
#define dir3 6
#define pwm4 9
#define dir4 8
#define relay1 23
#define relay2 25
#define relay3 27
#define ledtask1 13
#define ledtask2 12
#define ledtask3 11
void setup() {
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  digitalWrite(ledtask1,LOW);
  digitalWrite(ledtask2,LOW);
  digitalWrite(ledtask3,LOW);
  digitalWrite(ledtask1,HIGH);
  delay(500);
  digitalWrite(ledtask1,LOW);
  digitalWrite(ledtask2,HIGH);
  delay(500);
  digitalWrite(ledtask2,LOW);
  digitalWrite(ledtask3,HIGH);
  delay(500);
  digitalWrite(ledtask3,LOW);
  delay(2000);
digitalWrite(relay1,LOW);
delay(1000);
digitalWrite(relay1,HIGH);
delay(1000);
digitalWrite(relay2,LOW);
delay(1000);
digitalWrite(relay2,HIGH);
delay(1000);
digitalWrite(relay3,LOW);
delay(1000);
digitalWrite(relay3,HIGH);
delay(1000);
}

void loop() {
}
