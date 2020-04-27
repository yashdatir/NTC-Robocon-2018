#define Motor1PWM 3
#define Motor1DIR 23

#define Motor2PWM 5
#define Motor2DIR 27

#define Motor3PWM 4
#define Motor3DIR 25

#define Motor4PWM 6
#define Motor4DIR 29

#define frx1 analogRead(A3)
#define fry1 analogRead(A1)
#define frx2 analogRead(A4)

void forward(int j)
{
    analogWrite(Motor1PWM,j);
    digitalWrite(Motor1DIR,LOW);
    analogWrite(Motor3PWM,j);
    digitalWrite(Motor3DIR,HIGH);
}
void reverse(int j)
{
    digitalWrite(Motor1DIR,HIGH);
    analogWrite(Motor1PWM,j);
    digitalWrite(Motor3DIR,LOW);
    analogWrite(Motor3PWM,j);
}
void left(int j)
{
    digitalWrite(Motor2DIR,HIGH);
    analogWrite(Motor2PWM,j);   
    digitalWrite(Motor4DIR,LOW);
    analogWrite(Motor4PWM,j);   
}
void right(int j)
{
    analogWrite(Motor2PWM,j);
    digitalWrite(Motor2DIR,LOW);
    analogWrite(Motor4PWM,j);
    digitalWrite(Motor4DIR,HIGH); 
}
void stopM()
{
  analogWrite(Motor1PWM,0);
  analogWrite(Motor2PWM,0);
  analogWrite(Motor3PWM,0);
  analogWrite(Motor4PWM,0);
}
void all(int j)         //acl
{
    analogWrite(Motor1PWM,j);
    digitalWrite(Motor1DIR,LOW);
    analogWrite(Motor3PWM,j);
    digitalWrite(Motor3DIR,LOW);
    analogWrite(Motor2PWM,j);
    digitalWrite(Motor2DIR,LOW);
    analogWrite(Motor4PWM,j);
    digitalWrite(Motor4DIR,LOW);
}
void rev(int j)       //cw
{
    analogWrite(Motor1PWM,j);
    digitalWrite(Motor1DIR,HIGH);
    analogWrite(Motor3PWM,j);
    digitalWrite(Motor3DIR,HIGH);
    analogWrite(Motor2PWM,j);
    digitalWrite(Motor2DIR,HIGH);
    analogWrite(Motor4PWM,j);
    digitalWrite(Motor4DIR,HIGH);
}
void setup()
{
  Serial.begin(9600);
  pinMode(51,INPUT);
  pinMode(53,INPUT);
  pinMode(Motor1PWM,OUTPUT);
  pinMode(Motor1DIR,OUTPUT);
  pinMode(Motor2PWM,OUTPUT);
  pinMode(Motor2DIR,OUTPUT);
  pinMode(Motor3PWM,OUTPUT);
  pinMode(Motor3DIR,OUTPUT);
  pinMode(Motor4PWM,OUTPUT);
  pinMode(Motor4DIR,OUTPUT);
}

void loop() {
  int a=frx1;
  int b=fry1;
  int c=frx2;
  if(a>=520)
  {
    right(a/2);
    Serial.println(a/2);
  }
  else if(a<=500)
  {
    a-=512;
    a*=-2;
    a-=1;
    left(a/4);
    Serial.println(a/4);
    }
  else if(b>=520)
  {
    reverse(b/2);
    Serial.println(b/2);
  }
  else if(b<=500)
  {
    b-=512;
    b*=-2;
    b-=1;
    forward(b/4);
    Serial.println(b/4);
    }
  else if(c>=520)
  {
    rev(40);
  }
  else if(c<=500)
  {
    all(40);
  }
  else
  {
    stopM();
  }
}
