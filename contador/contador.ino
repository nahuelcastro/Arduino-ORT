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
int contador; 

int u;  //unidad de segundos
int d;  // decenas de segundos 
int c;  // unidad de minutos 
int um; // unidad de minutos

void maquina (void);
void cronometro (void);
void separar_digitos (int num);
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
   {
    ms++;
    if(ms>=100)
     {
      contador++;
      ms=0;
     }
    
   }
   


void separar_digitos (int num)
{
  u=(num)%10;
  d=(num / 10 )%10;
  c=(num / 100 )%10;
  um=(num / 1000 )%10;
  return;
}
 void maquina()
 {
   separar_digitos (contador);
  
   switch(estado)
    {
     case D1: 
  
 
    PORTA=um;
    digitalWrite (29,HIGH);
    digitalWrite (28,LOW);
    digitalWrite (27,LOW);
    digitalWrite (26,LOW);
    estado=D2;
  
   break;

    case D2:
  
   
    PORTA=c;
    digitalWrite (29,LOW);
    digitalWrite (28,HIGH);
    digitalWrite (27,LOW);
    digitalWrite (26,LOW);
    estado=D3;
    
    break;

    case D3:
    
  
    PORTA=d;
    digitalWrite (29,LOW);
    digitalWrite (28,LOW);
    digitalWrite (27,HIGH);
    digitalWrite (26,LOW);
    estado=D4;
    
    break;

    case D4:
   
    PORTA=u;
    digitalWrite (29,LOW);
    digitalWrite (28,LOW);
    digitalWrite (27,LOW);
    digitalWrite (26,HIGH);
    
    estado=D1;
  
    
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
           
          contador=0;
          
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
          
         contador=0;
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
          contador=0;
          estado1=cencendido;
        }
      break;
      
   }
      
      
 }
