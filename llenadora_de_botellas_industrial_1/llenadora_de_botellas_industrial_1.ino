#include <TimerOne.h>


#define avanza3        0
#define avanza1        1
#define llenado1chico  2
#define llenado1grande 3
#define avanza2        4
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
char estado= 0;
int ms; 
int s;
int contadorbotellasgrandes;
int contadorbotellaschicas;

void maquina (void);


void setup()
{
  pinMode (3, INPUT_PULLUP); //sensor1( primera instancia sensor de abajo)
  pinMode (4, INPUT_PULLUP); //sensor2 ( primera instancia sensor de arriba)
  pinMode (5, INPUT_PULLUP); //sensor final 
  pinMode (6, OUTPUT);// motor de cinta transportadora
  pinMode (7, OUTPUT); //actuador1 (llenador primera instancia)
  pinMode (8, OUTPUT);//actuador2 (llenador segunda instancia)
  pinMode (9, INPUT_PULLUP); //sensor3( segunda instancia sensor de abajo)
  pinMode (10, INPUT_PULLUP); //sensor4( segunda instancia sensor de arriba)
  //pinMode (A0,INPUT);
  //pinMode (A1,INPUT);
  Serial.begin(9600);
   Timer1.initialize(1000); 
   Timer1.attachInterrupt(Timer);
    contadorbotellasgrandes=0 ;
    contadorbotellaschicas=0 ;
    //DDRA=0xFF;
  
}

void loop()
{
 sensor1=digitalRead(3);
 sensor2=digitalRead(4);
 sensorf=digitalRead(5);
 sensor3=digitalRead(9);
 sensor4=digitalRead(10);


  //if( (sensor4==0) && (sensor3==1) ) //  detecta botella chica
  // {
          // while((sensor3==0) && (sensor4==1))
          //   {
        //      sensor3=digitalRead(9);
      //        sensor4=digitalRead(10);
    //         }
  //     contadorbotellaschicas++;      
           
//       }

 //if((sensor3==0) && (sensor4==0)) // detecta botella grande
      // {
        //   while((sensor3==0) && (sensor4==0))
          //   {
            // sensor3=digitalRead(9);
              //sensor4=digitalRead(10);
            // }
       //contadorbotellasgrandes++;      
           
       //}


       
  maquina();
 }

 void Timer()
  { ms++;
    if(ms>=1000)
    {
     s++;
     ms=0;
     }
  }

   void maquina()
  {

    
   switch(estado)
    {
     case avanza3:
       Serial.print("avanza3");
       if(sensorf==0) // sensorfinal detecta botella
          {
            digitalWrite(6,LOW); //para el motor 
            
          }

        if(sensorf==1) // sensorfinal NO detecta botella
          {
            digitalWrite(6,HIGH); //motor encendido 
            estado=avanza1;
            Serial.print("avanza1");
          }    
      break;
    
    
     


     case avanza1:

       if( (sensor1==0) && (sensor2==1)) //  llenado chico
       {
           s=0;
          digitalWrite(6,LOW); // para motor de cinta transportadora
          digitalWrite(7,HIGH); // enciende actuador 1
          estado=llenado1chico;
          Serial.print("llenado1chico");
       }

         if( (sensor1==0) && (sensor2==0)) // llenado grande
       {
           s=0;
          digitalWrite(6,LOW); // para motor de cinta transportadora
          digitalWrite(7,HIGH);// enciende actuador 1
         estado=llenado1grande;
         Serial.print("llenado1grande");
      }
      break;      
    
  
   
   
    case llenado1chico:
        if(s==3)
        {
          digitalWrite(7,LOW); //apaga actuador 1
          digitalWrite(6,HIGH);//enciende motor de cinta transportadora
           s=0;
           estado=avanza2;
           Serial.print("avanza2");
          }
       break;      
    

   
    
    case llenado1grande:

      if(s==5)
        {
          digitalWrite(7,LOW); //apaga actuador 1
          digitalWrite(6,HIGH);//enciende motor de cinta transportadora
           s=0;
           estado=avanza2;
           Serial.print("avanza2");
          }
           break;      
    
     
    
     
     
     case avanza2:
     if( (sensor3==0) && (sensor4==1) ) //  llenado chico
       {
           s=0;
          digitalWrite(6,LOW);//apaga motor de cinta transportadora
          digitalWrite(8,HIGH);//enciende actuador 2
         estado=llenado2chico;
         Serial.print("llenado2chico");
       }

         if( (sensor3==0) && (sensor4==0) ) // llenado grande
       {
           s=0;
          digitalWrite(6,LOW);//apaga motor de cinta transportadora
          digitalWrite(8,HIGH);//enciende actuador 2
          estado=llenado2grande;
          Serial.print("llenado2grande");
      }
      break;      


      case llenado2chico:
        if(s==3)
        {
          digitalWrite(8,LOW);//apaga actuador 2
          digitalWrite(6,HIGH);
           s=0;
           estado=avanza3;
          }
       break;      
    

   
    
    case llenado2grande:
      if(s==5)
        {
          digitalWrite(8,LOW);
          digitalWrite(6,HIGH);
           s=0;
           estado=avanza3;
          }
           break;    
    }  
    
//contadorbotellaschicas= analogRead(A0);
//contadorbotellasgrandes= analogRead(A1);
//contadorfinalbotellasgrandes=(contadorbotellasgrandes*5)/1024;
//contadorfinalbotellaschicas=(contadorbotellaschicas*5)/1024;
//PORTA=decimalBCD(contadorfinalbotellaschicas);
//PORTA=decimalBCD(contadorfinalbotellasgrandes);

     
    }
    

    // falta el contador de botellas chicas y grandes
     
       
    
      
    
      











      
  

  
