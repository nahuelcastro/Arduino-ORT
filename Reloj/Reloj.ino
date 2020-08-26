#include <TimerOne.h>
#define D1 0
#define D2 1
#define D3 2
#define D4 3

char estado= 0;
int ms; 
int us; //unidad de segundos
int ds;// decenas de segundos 
int um;// unidad de minutos 
int dm;// unidad de minutos
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
  { ms++;
    if(ms>=1000)
      {
        us++;
        ms=0;
      }

    if(us==10)
      {
        ds++;
        us=0;
      }
    if(ds==6)
      {
        um++;
        ds=0;
      }
    if(um==10)
      {
        dm++;
        um=0;
      }
      if(dm==6)
      {
        um++;
        dm=0;
      }

  }



 void maquina()
 {
   
  
   switch(estado)
    {
     case D1: 
  //if(ms>=0)
  //{
     Serial.println("dm");
    PORTA=dm;
    digitalWrite (29,HIGH);
    digitalWrite (28,LOW);
    digitalWrite (27,LOW);
    digitalWrite (26,LOW);
    estado=D2;
    //ms=0;
  //}
   break;

    case D2:
   //if(ms>=3)
   //{
     Serial.println("um");
    PORTA=um;
    digitalWrite (29,LOW);
    digitalWrite (28,HIGH);
    digitalWrite (27,LOW);
    digitalWrite (26,LOW);
    estado=D3;
    //ms=0;
   //}
    break;

    case D3:
     //if(ms>=3)
   //{
     Serial.println("ds");
    PORTA=ds;
    digitalWrite (29,LOW);
    digitalWrite (28,LOW);
    digitalWrite (27,HIGH);
    digitalWrite (26,LOW);
    estado=D4;
    //ms=0;
   //}
    break;

    case D4:
     //if(ms>=3)
   //{ 
     Serial.println("us");
    PORTA=us;
    digitalWrite (29,LOW);
    digitalWrite (28,LOW);
    digitalWrite (27,LOW);
    digitalWrite (26,HIGH);
    //ms=0;
    estado=D1;
   //}
    
    break;
 }
      
      
    }

