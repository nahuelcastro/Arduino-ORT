#include <TimerOne.h>


#define avanzado3      0
#define avanzado1      1
#define llenado1chico  2
#define llenado1grande 3
#define avanzado2      4
#define llenado2chico  5
#define llenado2grande 6 



char sensor1;
char sensor2;
char sensor3;
char sensor4;
char sensorf;
char motor;
char actuador1;
char actuador2;
int ms; 
int s;
void maquina (void)

void setup()
{
  pinMode (3, INPUT_PULLUP);
  pinMode (4, INPUT_PULLUP);
  pinMode (5, INPUT_PULLUP);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, INPUT_PULLUP);
  pinMode (10, INPUT_PULLUP);
   Timer1 initialize (1000)
   Timer1 atachinterrupt(timer1);
  
}

void loop()
{
  sensor1=digitalRead(3);
 sensor2=digitalRead(4);
 sensorf=digitalRead(5);
 sensor3=digitalRead(9);
 sensor4=digitalRead(10);
  
  maquina();
  
 }

 void timer()
  { ms++;
    if(ms==1000)
    {
     s++;
     ms=0
     }
  }

   void maquina()
  {

    
   switch(estado)
    {
     case avanza3:
       
       if(sensorf==0)
          {
            digitalWrite(6,LOW);
            estado=avanza1
          }

        if(sensorf==1)
          {
            digitalWrite(6,HIGH);
            estado=avanza1
          }    
      break;
    }
    
     

   
     case avanza1:
      
       if( (sensor1==0) && (sensor2==1) //  llenado chico
       {
           s=0;
          digitalWrite(6,LOW);
          digitalWrite(7,HIGH);
         estado=llenado1chico
       }

         if( (sensor1==0) && (sensor2==0) // llenado grande
       {
           s=0;
          digitalWrite(6,LOW);
          digitalWrite(7,HIGH);
         estado=llenado1grande
      }
      break;      
    }

   
   
    case llenado1chico:
        if(s==3)
        {
          digitalWrite(7,LOW);
          digitalWrite(6,HIGH);
           s=0;
           estado=avanza2
          }
       break;      
    }

   
    
    case llenado1grande:
      if(s==5)
        {
          digitalWrite(7,LOW);
          digitalWrite(6,HIGH);
           s=0;
           estado=avanza2
          }
           break;      
    }
     
    
     
     
     case avanza2;

     if( (sensor3==0) && (sensor4==1) //  llenado chico
       {
           s=0;
          digitalWrite(6,LOW);
          digitalWrite(8,HIGH);
         estado=llenado2chico
       }

         if( (sensor3==0) && (sensor4==0) // llenado grande
       {
           s=0;
          digitalWrite(6,LOW);
          digitalWrite(8,HIGH);
         estado=llenado2grande
      }
      break;      


      case llenado2chico:
        if(s==3)
        {
          digitalWrite(8,LOW);
          digitalWrite(6,HIGH);
           s=0;
           estado=avanza3
          }
       break;      
    }

   
    
    case llenado2grande:
      if(s==5)
        {
          digitalWrite(8,LOW);
          digitalWrite(6,HIGH);
           s=0;
           estado=avanza3
          }
           break;      
    }

    // falta el contador de botellas chicas y grandes
     
       
    
      
    
      











      
  }

  
