
#define PWMA 3 
#define DIRA 2 
#define PWMB 5 
#define DIRB 4 
#define PWMC 6 
#define DIRC 7 
#define PWMD 9 
#define DIRD 8 
int i=2;
void ANTICLOCKWISE_ROTATION()
{
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRB,HIGH);
  digitalWrite(DIRC,HIGH);
  digitalWrite(DIRD,HIGH);

  analogWrite(PWMA,150);
  analogWrite(PWMB,150);
  analogWrite(PWMC,150);
  analogWrite(PWMD,150);
}
void DRIFT_LEFT()
{
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRC,HIGH);
  
  analogWrite(PWMA,150);
  analogWrite(PWMC,150);

  analogWrite(PWMB,0);
  analogWrite(PWMD,0);
}
void RIGHT()
{
  i=2;
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRB,HIGH);
  digitalWrite(DIRC,LOW);
  digitalWrite(DIRD,LOW);
  while(i<=128)
  {
  analogWrite(PWMA,i);
  analogWrite(PWMB,i);
  analogWrite(PWMC,i);
  analogWrite(PWMD,i);
  i=i*2;
  delay(25);
  }
  analogWrite(PWMA,150);
  analogWrite(PWMB,150);
  analogWrite(PWMC,150);
  analogWrite(PWMD,150);
}
void FORWARD()
{
  i=2;
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRB,LOW);
  digitalWrite(DIRC,HIGH);
  digitalWrite(DIRD,LOW);
  while(i<=128)
  {
  analogWrite(PWMA,i);
  analogWrite(PWMB,i);
  analogWrite(PWMC,i);
  analogWrite(PWMD,i);
  i=i*2;
  delay(25);
  }
  analogWrite(PWMA,150);
  analogWrite(PWMB,150);
  analogWrite(PWMC,150);
  analogWrite(PWMD,150);
}
void DRIFT_FRONT()
{
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRB,HIGH);
  
  analogWrite(PWMA,150);
  analogWrite(PWMB,150);

  analogWrite(PWMC,0);
  analogWrite(PWMD,0);
}
void LEFT()
{
  i=2;
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,LOW);
  digitalWrite(DIRC,HIGH);
  digitalWrite(DIRD,HIGH);
  while(i<=128)
  {
  analogWrite(PWMA,i);
  analogWrite(PWMB,i);
  analogWrite(PWMC,i);
  analogWrite(PWMD,i);
  i=i*2;
  delay(25);
  }
  analogWrite(PWMA,150);
  analogWrite(PWMB,150);
  analogWrite(PWMC,150);
  analogWrite(PWMD,150);
}
void FORWARD_LEFT()
{
  i=2;
  digitalWrite(DIRB,LOW);
  digitalWrite(DIRC,HIGH);
  while(i<=128)
  {
  analogWrite(PWMB,i);
  analogWrite(PWMC,i);
  i=i*2;
  delay(25);
  }
  analogWrite(PWMA,0);
  analogWrite(PWMD,0);
  analogWrite(PWMB,150);
  analogWrite(PWMC,150);
}
void FORWARD_RIGHT()
{
  i=2;
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRD,LOW);
  while(i<=128)
  {
  analogWrite(PWMA,i);
  analogWrite(PWMD,i);
  i=i*2;
  delay(25);
  }
  analogWrite(PWMB,0);
  analogWrite(PWMC,0);
  analogWrite(PWMA,150);
  analogWrite(PWMD,150);
}
void BACKWARD()
{
  i=2;
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,HIGH);
  digitalWrite(DIRC,LOW);
  digitalWrite(DIRD,HIGH);
  while(i<=128)
  {
  analogWrite(PWMA,i);
  analogWrite(PWMB,i);
  analogWrite(PWMC,i);
  analogWrite(PWMD,i);
  i=i*2;
  delay(25);
  }
  analogWrite(PWMA,150);
  analogWrite(PWMB,150);
  analogWrite(PWMC,150);
  analogWrite(PWMD,150);
}
void STOP()
{
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,LOW);
  digitalWrite(DIRC,LOW);
  digitalWrite(DIRD,LOW);
  
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
  analogWrite(PWMC,0);
  analogWrite(PWMD,0);
}
void UART_Control()
{
  char Uart_Date=0;
  if(Serial.available())
  {
    Uart_Date = Serial.read();
  }
  if(Uart_Date=='A')
  {
    ANTICLOCKWISE_ROTATION();
  }
  if(Uart_Date=='R')
  {
    RIGHT();
  }
  if(Uart_Date=='F')
  {
    FORWARD();
  }
  if(Uart_Date=='T')
  {
    DRIFT_FRONT();
  }
  if(Uart_Date=='B')
  {
    BACKWARD();
  }
  if(Uart_Date=='U')
  {
    FORWARD_LEFT();
  }
  if(Uart_Date=='V')
  {
    FORWARD_RIGHT();
  }
  if(Uart_Date=='L')
  {
    LEFT();
  }
  if(Uart_Date=='C')
  {
    DRIFT_LEFT();
  }
  if(Uart_Date=='S')
  {
    STOP();
  }
}
void IO_init()
{
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(DIRC, OUTPUT);
  pinMode(PWMD, OUTPUT);
  pinMode(DIRD, OUTPUT);
  STOP();
}
void setup()
{
  Serial.begin(9600);
  IO_init();
}

void loop()
{ 
  UART_Control();
}
