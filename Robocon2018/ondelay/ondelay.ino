#define pwm1 3
#define dir1 2
#define pwm2 5
#define dir2 4
#define pwm3 7
#define dir3 6
#define pwm4 9
#define dir4 8
#define sensor1 analogRead(A15)
#define sensor2 analogRead(A14)
#define sensor3 analogRead(A13)
#define sensor4 analogRead(A12)
#define sensor1J digitalRead(53)
#define sensor2J digitalRead(51)
#define sensor3J digitalRead(49)
#define sensor4J digitalRead(47)
#define relay1 23
#define relay2 25
#define relay3 27
#define switchtask1 A0
#define switchtask2 A1
#define switchtask3 A2
#define ledtask1 13
#define ledtask2 12
#define ledtask3 11
#define lval 180
#define uval 230
#define flag 0
int pos1,pos2,pos3,pos4;
int readVal,fl;
void forward(int x,int y,int z,int w)
{
  analogWrite(pwm1,x);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,y);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm3,z);
  digitalWrite(dir3,LOW);
  analogWrite(pwm4,w);
  digitalWrite(dir4,LOW);
}
void reverse(int x,int y,int z,int w)
{
  analogWrite(pwm1,x);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,y);
  digitalWrite(dir2,LOW);
  analogWrite(pwm3,z);
  digitalWrite(dir3,HIGH);
  analogWrite(pwm4,w);
  digitalWrite(dir4,HIGH);
}
void left(int x,int y,int z,int w)
{
  analogWrite(pwm1,x);
  digitalWrite(dir1,LOW);
  analogWrite(pwm2,y);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm3,z);
  digitalWrite(dir3,HIGH);
  analogWrite(pwm4,w);
  digitalWrite(dir4,LOW);
}
void right(int x,int y,int z,int w)
{
  analogWrite(pwm1,x);
  digitalWrite(dir1,HIGH);
  analogWrite(pwm2,y);
  digitalWrite(dir2,LOW);
  analogWrite(pwm3,z);
  digitalWrite(dir3,LOW);
  analogWrite(pwm4,w);
  digitalWrite(dir4,HIGH);
}
void stopM()
{
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
}
void setup() {
 pinMode(relay1,OUTPUT);
 pinMode(relay2,OUTPUT);
 pinMode(relay3,OUTPUT);
 pinMode(ledtask1,OUTPUT);
 pinMode(ledtask2,OUTPUT);
 pinMode(ledtask3,OUTPUT);
 pinMode(53,INPUT);
 pinMode(51,INPUT);
 pinMode(47,INPUT);
 pinMode(49,INPUT);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 for(int i=2;i<=9;i++)
 {
  pinMode(i,OUTPUT);
 }
 digitalWrite(relay1,HIGH);
 digitalWrite(relay2,HIGH);
 digitalWrite(relay3,HIGH);
}

void loop() {
  if(digitalRead(switchtask1))
  {
    left(uval,uval,uval,uval);
 delay(1660);
 stopM();
 digitalWrite(relay1,LOW);
 delay(1000);
 digitalWrite(relay1,HIGH);
 delay(500);
 right(uval,uval,uval,uval);
 delay(1660);
 stopM();
 fl=flag;
  }
  else if(digitalRead(switchtask2))
  {
    if(fl==0)
    {
      analogWrite(pwm1,180);
      digitalWrite(dir1,HIGH);
      analogWrite(pwm3,180);
      digitalWrite(dir3,LOW);
      delay(1000);
      stopM();
      forward(uval,uval,uval,uval);
      delay(1000);
      stopM();
      fl=100;
    }
    left(uval,uval,uval,uval);
 delay(1660);
 stopM();
 digitalWrite(relay2,LOW);
 delay(1000);
 digitalWrite(relay2,HIGH);
 delay(500);
 right(uval,uval,uval,uval);
 delay(1660);
 stopM();
  }
  else if(digitalRead(switchtask3))
  {
    left(uval,uval,uval,uval);
 delay(3320);
 stopM();
 digitalWrite(relay2,LOW);
 delay(1000);
 digitalWrite(relay2,HIGH);
 delay(500);
 right(uval,uval,uval,uval);
 delay(3320);
 stopM();
  }
  else
  {
    stopM();
  }
}
