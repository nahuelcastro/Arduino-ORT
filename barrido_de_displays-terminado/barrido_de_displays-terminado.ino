#include <TimerOne.h>
#define D1 0
#define D2 1
#define D3 2
#define D4 3

char estado= 0;
int ms; 
void maquina (void);
void setup()
{
  ms=0;
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
   Timer1.initialize(1000); 
   Timer1.attachInterrupt(Timer);
   DDRA=0XFF;
   Serial.begin(9600);
}



void loop ()
{

 maquina(); 
    //PORTA=3;
    //digitalWrite (29,HIGH);     
    //digitalWrite (28,LOW);
    //digitalWrite (27,LOW);
    //digitalWrite (26,LOW);
     //Serial.println("3");
}




void Timer()
  {
    ms++;
  }



 void maquina()
 {
   
  
   switch(estado)
    {
     case D1: 
  if(ms>=0)
  {
     Serial.println("3a");
    PORTA=1;
    digitalWrite (29,HIGH);
    digitalWrite (28,LOW);
    digitalWrite (27,LOW);
    digitalWrite (26,LOW);
    estado=D2;
    ms=0;
  }
   break;

    case D2:
   if(ms>=3)
   {
     Serial.println("2");
    PORTA=2;
    digitalWrite (29,LOW);
    digitalWrite (28,HIGH);
    digitalWrite (27,LOW);
    digitalWrite (26,LOW);
    estado=D3;
    ms=0;
   }
    break;

    case D3:
     if(ms>=3)
   {
     Serial.println("1");
    PORTA=3;
    digitalWrite (29,LOW);
    digitalWrite (28,LOW);
    digitalWrite (27,HIGH);
    digitalWrite (26,LOW);
    estado=D4;
    ms=0;
   }
    break;

    case D4:
     if(ms>=3)
   { 
     Serial.println("4");
    PORTA=4;
    digitalWrite (29,LOW);
    digitalWrite (28,LOW);
    digitalWrite (27,LOW);
    digitalWrite (26,HIGH);
    ms=0;
    estado=D1;
   }
    
    break;
 }
      
      
    }

    
 
