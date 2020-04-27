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
#define relay2 27
#define relay3 25
#define switchtask1 A0
#define switchtask2 A1
#define switchtask3 A2
#define ledtask1 13
#define ledtask2 12
#define ledtask3 11
#define lval 160
#define uval 200
const int flag=0;
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
void forwardJ()
{
  while(!(sensor1J))
  {
  readVal=sensor1;
  pos1=((float)readVal/921)*70;
  readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor3;
  pos3=((float)readVal/921)*70;
  
  if(pos1<=27 && pos3<=27)
  {
    forward(uval-10,uval-10,lval-10,lval-10);
  }
  else if(pos1<=27 && pos3<=43)
  {
    forward(lval-10,uval-10,lval-10,lval-10);
  }
  else if(pos1<=27 && pos3<=70)
  {
   forward(lval-10,uval-10,lval-10,uval-10);
  }
  else if(pos1<=43 && pos3<=27)
  {
    forward(uval-10,lval-10,lval-10,lval-10);
  }
  else if(pos1<=43 && pos3<=43)
  {
    forward(lval-10,lval-10,lval-10,lval-10);
  }
  else if(pos1<=43 && pos3<=70)
  {
    forward(lval-10,lval-10,lval-10,uval-10);
  }
  else if(pos1<=70 && pos3<=27)
  {
    forward(uval-10,lval-10,uval-10,lval-10);
  }
  else if(pos1<=70 && pos3<=43)
  {
    forward(lval-10,lval-10,uval-10,lval-10);
  }
  else if(pos1<=70 && pos3<=70)
  {
    forward(lval-10,lval-10,uval-10,uval-10);
  }
  else
  {
    stopM();
  }
  }
}
void forwardposition()
{
  while(!(pos2>27&&pos2<70))
 {
  readVal=sensor1;
  pos1=((float)readVal/921)*70;
  readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor3;
  pos3=((float)readVal/921)*70;
  
  if(pos1<=27 && pos3<=27)
  {
    forward(uval,uval,lval,lval);
  }
  else if(pos1<=27 && pos3<=43)
  {
    forward(lval,uval,lval,lval);
  }
  else if(pos1<=27 && pos3<=70)
  {
   forward(lval,uval,lval,uval);
  }
  else if(pos1<=43 && pos3<=27)
  {
    forward(uval,lval,lval,lval);
  }
  else if(pos1<=43 && pos3<=43)
  {
    forward(lval,lval,lval,lval);
  }
  else if(pos1<=43 && pos3<=70)
  {
    forward(lval,lval,lval,uval);
  }
  else if(pos1<=70 && pos3<=27)
  {
    forward(uval,lval,uval,lval);
  }
  else if(pos1<=70 && pos3<=43)
  {
    forward(lval,lval,uval,lval);
  }
  else if(pos1<=70 && pos3<=70)
  {
    forward(lval,lval,uval,uval);
  }
  else
  {
    stopM();
  }
 }
 stopM();
 reverse(lval,lval,lval,lval);
 delay(500);
 stopM();
 while(!(sensor4J))
 {
     readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(lval,uval,uval,lval);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(lval,lval,uval,lval);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(uval,lval,uval,lval);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(lval,uval,lval,lval);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(lval,lval,lval,lval);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(uval,lval,lval,lval);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(lval,uval,lval,uval);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(lval,lval,lval,uval);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(uval,lval,lval,uval);
  }
  else
  {
    stopM();
  }
 }
 stopM();
}
void left2J()
{
   while(!(sensor4J))
 {
     readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(lval,uval,uval,lval);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(lval,lval,uval,lval);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(uval,lval,uval,lval);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(lval,uval,lval,lval);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(lval,lval,lval,lval);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(uval,lval,lval,lval);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(lval,uval,lval,uval);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(lval,lval,lval,uval);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(uval,lval,lval,uval);
  }
  else
  {
    stopM();
  }
 }
}
void task()
{
    while(!(sensor2J))
    {
         readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(lval,uval,uval,lval);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(lval,lval,uval,lval);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(uval,lval,uval,lval);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(lval,uval,lval,lval);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(lval,lval,lval,lval);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(uval,lval,lval,lval);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(lval,uval,lval,uval);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(lval,lval,lval,uval);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(uval,lval,lval,uval);
  }
  else
  {
    stopM();
  }   
  }
}
void taskslow(int u,int l)
{
    while(!(sensor2J))
    {
         readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(l,u,u,l);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(l,l,u,l);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(u,l,u,l);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(l,u,l,l);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(l,l,l,l);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(u,l,l,l);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(l,u,l,u);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(l,l,l,u);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(u,l,l,u);
  }
  else
  {
    stopM();
  }   
  }
}
void task1()
{
   while(!(sensor2J))
    {
         readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(lval,uval,uval,lval);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(lval,lval,uval,lval);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(uval,lval,uval,lval);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(lval,uval,lval,lval);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(lval,lval,lval,lval);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(uval,lval,lval,lval);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(lval,uval,lval,uval);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(lval,lval,lval,uval);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(uval,lval,lval,uval);
  }
  else
  {
    stopM();
  }   
  }
  
  delay(500);
     
   while(!(sensor2J))
    {
      readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(lval,uval,uval,lval);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(lval,lval,uval,lval);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(uval,lval,uval,lval);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(lval,uval,lval,lval);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(lval,lval,lval,lval);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(uval,lval,lval,lval);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(lval,uval,lval,uval);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(lval,lval,lval,uval);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(uval,lval,lval,uval);
  }
  else
  {
    stopM();
  }   
  }
  stopM();
}
void taskspeed(int u,int l)
{
   while(!(sensor2J))
    {
         readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(l,u,u,l);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(l,l,u,l);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(u,l,u,l);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(l,u,l,l);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(l,l,l,l);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(u,l,l,l);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(l,u,l,u);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(l,l,l,u);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(u,l,l,u);
  }
  else
  {
    stopM();
  }   
  }
  
  delay(500);
     
   while(!(sensor2J))
    {
         readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(l,u,u,l);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(l,l,u,l);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(u,l,u,l);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(l,u,l,l);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(l,l,l,l);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(u,l,l,l);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(l,u,l,u);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(l,l,l,u);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(u,l,l,u);
  }
  else
  {
    stopM();
  }   
  }
  stopM();
}
void task2()
{
   while(!(sensor2J))
    {
         readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(lval,uval,uval,lval);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(lval,lval,uval,lval);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(uval,lval,uval,lval);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(lval,uval,lval,lval);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(lval,lval,lval,lval);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(uval,lval,lval,lval);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(lval,uval,lval,uval);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(lval,lval,lval,uval);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(uval,lval,lval,uval);
  }
  else
  {
    stopM();
  }   
  }
  
  delay(500);
     
   while(!(sensor2J))
    {
      readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos2<=27&&pos4<=27)
  {
    left(lval,uval,uval,lval);
  }
  else if(pos2<=27&&pos4<=43)
  {
    left(lval,lval,uval,lval);
  }
  else if(pos2<=27&&pos4<=70)
  {
    left(uval,lval,uval,lval);
  }

  
  else if(pos2<=43&&pos4<=27)
  {
    left(lval,uval,lval,lval);
  }
  else if(pos2<=43&&pos4<=43)
  {
    left(lval,lval,lval,lval);
  }
  else if(pos2<=43&&pos4<=70)
  {
    left(uval,lval,lval,lval);
  }

  
  else if(pos2<=70&&pos4<=27)
  {
     left(lval,uval,lval,uval);
  }
  else if(pos2<=70&&pos4<=43)
  {
     left(lval,lval,lval,uval);
  }
  else if(pos2<=70&&pos4<=70)
  {
     left(uval,lval,lval,uval);
  }
  else
  {
    stopM();
  }   
  }
}
void go()
{
  while(!(sensor4J))
    {
      readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos4<=27&&pos2<=27)
  {
    right(uval,lval,lval,uval);
  }
  else if(pos4<=27&&pos2<=43)
  {
    right(uval,lval,lval,lval);
  }
  else if(pos4<=27&&pos2<=70)
  {
    right(uval,lval,uval,lval);
  }

  
  else if(pos4<=43&&pos2<=27)
  {
    right(lval,lval,lval,uval);
  }
  else if(pos4<=43&&pos2<=43)
  {
    right(lval,lval,lval,lval);
  }
  else if(pos4<=43&&pos2<=70)
  {
    right(lval,lval,uval,lval);
  }

  
  else if(pos4<=70&&pos2<=27)
  {
     right(lval,uval,lval,uval);
  }
  else if(pos4<=70&&pos2<=43)
  {
     right(lval,uval,lval,lval);
  }
  else if(pos4<=70&&pos2<=70)
  {
     right(lval,uval,uval,lval);
  }
  else
  {
    stopM();
  }
  }
}
void goout()
{
  while(!(sensor4J))
    {
      readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos4<=27&&pos2<=27)
  {
    right(uval+10,lval+10,lval+10,uval+10);
  }
  else if(pos4<=27&&pos2<=43)
  {
    right(uval+10,lval+10,lval+10,lval+10);
  }
  else if(pos4<=27&&pos2<=70)
  {
    right(uval+10,lval+10,uval+10,lval+10);
  }

  
  else if(pos4<=43&&pos2<=27)
  {
    right(lval+10,lval+10,lval+10,uval+10);
  }
  else if(pos4<=43&&pos2<=43)
  {
    right(lval+10,lval+10,lval+10,lval+10);
  }
  else if(pos4<=43&&pos2<=70)
  {
    right(lval+10,lval+10,uval+10,lval+10);
  }

  
  else if(pos4<=70&&pos2<=27)
  {
     right(lval+10,uval+10,lval+10,uval+10);
  }
  else if(pos4<=70&&pos2<=43)
  {
     right(lval+10,uval+10,lval+10,lval+10);
  }
  else if(pos4<=70&&pos2<=70)
  {
     right(lval+10,uval+10,uval+10,lval+10);
  }
  else
  {
    stopM();
  }
  }
  delay(500);
  /*while(!(sensor4J))
    {
      readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;

  readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos4<=27&&pos2<=27)
  {
    right(uval,lval,lval,uval);
  }
  else if(pos4<=27&&pos2<=43)
  {
    right(uval,lval,lval,lval);
  }
  else if(pos4<=27&&pos2<=70)
  {
    right(uval,lval,uval,lval);
  }

  
  else if(pos4<=43&&pos2<=27)
  {
    right(lval,lval,lval,uval);
  }
  else if(pos4<=43&&pos2<=43)
  {
    right(lval,lval,lval,lval);
  }
  else if(pos4<=43&&pos2<=70)
  {
    right(lval,lval,uval,lval);
  }

  
  else if(pos4<=70&&pos2<=27)
  {
     right(lval,uval,lval,uval);
  }
  else if(pos4<=70&&pos2<=43)
  {
     right(lval,uval,lval,lval);
  }
  else if(pos4<=70&&pos2<=70)
  {
     right(lval,uval,uval,lval);
  }
  else
  {
    stopM();
  }   
  }
  */
  while(!(sensor4J))
    {
      readVal=sensor2;
  pos2=((float)readVal/921)*70;
  readVal=sensor4;
  pos4=((float)readVal/921)*70;
  if(pos4<=27&&pos2<=27)
  {
    right(uval+10,lval+10,lval+10,uval+10);
  }
  else if(pos4<=27&&pos2<=43)
  {
    right(uval+10,lval+10,lval+10,lval+10);
  }
  else if(pos4<=27&&pos2<=70)
  {
    right(uval+10,lval+10,uval+10,lval+10);
  }

  
  else if(pos4<=43&&pos2<=27)
  {
    right(lval+10,lval+10,lval+10,uval+10);
  }
  else if(pos4<=43&&pos2<=43)
  {
    right(lval+10,lval+10,lval+10,lval+10);
  }
  else if(pos4<=43&&pos2<=70)
  {
    right(lval+10,lval+10,uval+10,lval+10);
  }

  
  else if(pos4<=70&&pos2<=27)
  {
     right(lval+10,uval+10,lval+10,uval+10);
  }
  else if(pos4<=70&&pos2<=43)
  {
     right(lval+10,uval+10,lval+10,lval+10);
  }
  else if(pos4<=70&&pos2<=70)
  {
     right(lval+10,uval+10,uval+10,lval+10);
  }
  else
  {
    stopM();
  }
  }
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
 /*while(!(pos1>=27&&pos1<=40))
 {
  readVal=sensor1;
  pos1 = ((float)readVal/921)*70;
  analogWrite(pwm2,120);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm4,120);
  digitalWrite(dir4,LOW);
 }
 forward(127,127,127,127);
 delay(500);*/
 left(127,127,127,127);
 delay(500);
 forward(120,120,120,120);
 delay(250);
 stopM();
 while(!((pos1>=5 && pos1<=65)||(pos3>=5 && pos3<=65)))
    {
      readVal=sensor1;
      pos1 = ((float)readVal/921)*70;
      readVal=sensor3;
      pos3 = ((float)readVal/921)*70;
      analogWrite(pwm2,120);
      digitalWrite(dir2,HIGH);
      analogWrite(pwm4,120);
      digitalWrite(dir4,LOW);
    }
    stopM();
    forward(uval,uval,uval,uval);
    delay(500);
    right(127,127,127,127);
    delay(50);
    forwardJ();
    forward(lval,lval,lval,lval);
 forwardposition();
}
void loop()
{
  if(digitalRead(switchtask1))
  {
    digitalWrite(ledtask1,HIGH);
    delay(3000);
   task1();
   
   
   left(230,230,230,230);
   delay(180);
   stopM();
   
   
   delay(4000);
   digitalWrite(relay1,LOW);
   delay(1000);
   digitalWrite(relay1,HIGH);
   delay(100);
   goout();
   stopM();
   delay(200);
   left2J();
   stopM();
   fl=flag;
  }
  else if(digitalRead(switchtask2))
  {
    digitalWrite(ledtask3,HIGH);
    delay(4000);
    if(fl==0)
    {
      readVal=sensor1;
      pos1 = ((float)readVal/921)*70;
      readVal=sensor3;
      pos3 = ((float)readVal/921)*70;
    while(!(pos1>=25 && pos1<=55))
    {
      readVal=sensor1;
      pos1 = ((float)readVal/921)*70;
      readVal=sensor3;
      pos3 = ((float)readVal/921)*70;
      analogWrite(pwm1,120);
      digitalWrite(dir1,HIGH);
      analogWrite(pwm3,120);
      digitalWrite(dir3,LOW);
    }
    forwardJ();
    forward(150,150,150,150);
    delay(140);
    fl=10;
  }
  stopM();
  delay(600);
    taskslow(200,150);
    delay(100);
    stopM();
    delay(500);
    taskslow(200,150);
    delay(100);
    taskslow(200,150);
    
    stopM();
    left(127,127,127,127);
    delay(50);
    stopM();
    
    delay(4000);
    digitalWrite(relay2,LOW);
    delay(1000);
    digitalWrite(relay2,HIGH);
    delay(100);
    go();
    stopM();
    delay(200);
    go();
    stopM();
    delay(200);
    left2J();
    stopM();
  }
  else if(digitalRead(switchtask3))
  {
    digitalWrite(ledtask2,HIGH);
    if(fl==0)
    {
      delay(5000);
      readVal=sensor1;
      pos1 = ((float)readVal/921)*70;
      readVal=sensor3;
      pos3 = ((float)readVal/921)*70;
    while(!(pos1>=25 && pos1<=55))
    {
      readVal=sensor1;
      pos1 = ((float)readVal/921)*70;
      readVal=sensor3;
      pos3 = ((float)readVal/921)*70;
      analogWrite(pwm1,120);
      digitalWrite(dir1,HIGH);
      analogWrite(pwm3,120);
      digitalWrite(dir3,LOW);
    }
    forwardJ();
    forward(150,150,150,150);
    delay(140);
    fl=10;
  }
  stopM();
    delay(1250);
    task2();
    delay(30);
    task1();
    delay(30);
    task1();
    delay(30);
    task1();
    left(127,127,127,127);
    delay(275);
    stopM();    
    delay(4000);
    digitalWrite(relay3,LOW);
   delay(1000);
   digitalWrite(relay3,HIGH);
   delay(100);
   go();
   delay(50);
   go();
   delay(100);
   go();
   delay(50);
   go();
   delay(50);
   go();
   delay(50);
   go();
   delay(50);
   stopM();
   goout();
   stopM();
   delay(50);
   goout();
   stopM();
   delay(200);
   left2J();
   stopM();
  }
  else
  {
    stopM();
    digitalWrite(ledtask1,LOW);
    digitalWrite(ledtask2,LOW);
    digitalWrite(ledtask3,LOW);
  }
}
