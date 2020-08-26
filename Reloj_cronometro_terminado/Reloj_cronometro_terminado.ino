#include <TimerOne.h>
#define D1 0
#define D2 1
#define D3 2
#define D4 3


#define cencendido 0
#define cstop  1
#define creset  2




char estado= 0;
char estado1= 0;
char b1;
char b2;

int ms; 
int us; //unidad de segundos
int ds;// decenas de segundos 
int um;// unidad de minutos 
int dm;// unidad de minutos

void maquina (void);
void cronometro (void);

void setup()
{
  ms=0;
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);

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
    b1=digitalRead(3);
    b2=digitalRead(4);


  
 maquina();
  cronometro(); 
   
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
  
  //{
     //Serial.println("dm");
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
  
   //{
    // Serial.println("um");
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
    
   //{
    // Serial.println("ds");
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
    // Serial.println("us");
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




void cronometro()

 {
  
   switch(estado1)
    {
      case cencendido: 
      //Serial.println("cronometroON"); 
    
      if(b1==0)
        {
           while(b1==0)
          {
          b1=digitalRead(3);
         }
          Timer1.stop();
          estado1=cstop;
        }

       if(b2==0)
        {
           
          ms=0;
          us=0;
          ds=0;
          um=0;
          dm=0;
          estado1=cencendido;
        }
        
      break;
      
      
      case cstop:
       //Serial.println("cronometroOFFFFFFF");  
      if(b1==0)
        {
           while(b1==0)
          {
          b1=digitalRead(3);
          }
        
          Timer1.resume();
          estado1=cencendido;
        }

         if(b2==0)
        {
          
          ms=0;
          us=0;
          ds=0;
          um=0;
          dm=0;
          estado1=cencendido;
        }
        
      break;
      
      
      case creset:
       //Serial.println("cronometroRRRRRRRRRRRRRRRRR");  
      if(b2==0)
        {
          while(b2==0)
        {
          b2=digitalRead(4);
        }
          ms=0;
          us=0;
          ds=0;
          um=0;
          dm=0;
          estado1=cencendido;
        }
      break;
      
   }
      
      
 }
    
