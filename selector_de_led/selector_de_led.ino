/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
#define l1 0
#define l2 1
#define l3 2
#define l4 3
#define l5 4
#define l6 5
#define l7 6
#define l8 7

void maquina (void);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int led1;
int led2;
int led3;
int led4;
int led5;
int led6;
int led7;
int led8;
char botonArriba;
char botonAbajo;
char enter;
char estado=0;

void setup()
{
  lcd.begin(20,4);
 // lcd.print("hello, world!");
  pinMode(22,OUTPUT); 
  pinMode(23,OUTPUT); 
  pinMode(24,OUTPUT); 
  pinMode(25,OUTPUT); 
  pinMode(26,OUTPUT); 
  pinMode(27,OUTPUT); 
  pinMode(28,OUTPUT); 
  pinMode(29,OUTPUT); 
 
  pinMode(31,INPUT_PULLUP); 
  pinMode(32,INPUT_PULLUP); 
  pinMode(33,INPUT_PULLUP); 

}

void loop() 
{
   // lcd.setCursor(0, 1);
   botonArriba=digitalRead(31);
   botonAbajo=digitalRead(32);
   enter=digitalRead(33);
   maquina();
  
}


 void maquina()
 {
   
  
   switch(estado)
    {
     case l1: ///////////////////////////////////////////////  L1 ///////////

        lcd.setCursor(0, 0); 
        lcd.print(" # LED 1");
        lcd.setCursor(0, 1); 
        lcd.print("   LED 2");
        lcd.setCursor(0, 2); 
        lcd.print("   LED 3");
        lcd.setCursor(0, 3); 
        lcd.print("   LED 4");
        
       

        if(botonArriba==0)
            {
              while(botonArriba==0)
                {
                  botonArriba=digitalRead(31);
                }

              estado=l8;
            }
            
        
        if(botonAbajo==0)
            {
              while(botonAbajo==0)
                {
                  botonAbajo=digitalRead(32);
                }

              estado=l2;
            }
            

         if(enter==0)
            {
              while(enter==0)
                {
                  enter=digitalRead(33);
                }
                digitalWrite (22,HIGH);
                digitalWrite (23,LOW);
                digitalWrite (24,LOW);
                digitalWrite (25,LOW);
                digitalWrite (26,LOW);
                digitalWrite (27,LOW);
                digitalWrite (28,LOW);
                digitalWrite (29,LOW);
           }
 
          break;

         
         case l2: ///////////////////////////////////////////////  L2 ///////////
            
        lcd.setCursor(0, 0); 
        lcd.print("   LED 1");
        lcd.setCursor(0, 1); 
        lcd.print(" # LED 2");
        lcd.setCursor(0, 2); 
        lcd.print("   LED 3");
        lcd.setCursor(0, 3); 
        lcd.print("   LED 4");
        
      

     if(botonArriba==0)
            {
              while(botonArriba==0)
                {
                  botonArriba=digitalRead(31);
                }

              estado=l1;
            }
            
       if(botonAbajo==0)
            {
              while(botonAbajo==0)
                {
                  botonAbajo=digitalRead(32);
                }

              estado=l3;
            }
            
     if(enter==0)
            {
              while(enter==0)
                {
                  enter=digitalRead(33);
                }
                digitalWrite (22,LOW);
                digitalWrite (23,HIGH);
                digitalWrite (24,LOW);
                digitalWrite (25,LOW);
                digitalWrite (26,LOW);
                digitalWrite (27,LOW);
                digitalWrite (28,LOW);
                digitalWrite (29,LOW);
           }

         break;

         
          
          case l3: ///////////////////////////////////////////////  L3 ///////////

        lcd.setCursor(0, 0); 
        lcd.print("   LED 1");
        lcd.setCursor(0, 1); 
        lcd.print("   LED 2");
        lcd.setCursor(0, 2); 
        lcd.print(" # LED 3");
        lcd.setCursor(0, 3); 
        lcd.print("   LED 4");
        
       

        if(botonArriba==0)
            {
              while(botonArriba==0)
                {
                  botonArriba=digitalRead(31);
                }
                
              estado=l2;
            }
            
       if(botonAbajo==0)
            {
              while(botonAbajo==0)
                {
                  botonAbajo=digitalRead(32);
                }

              estado=l4;
            }
            
     if(enter==0)
            {
              while(enter==0)
                {
                  enter=digitalRead(33);
                }
                digitalWrite (22,LOW);
                digitalWrite (23,LOW);
                digitalWrite (24,HIGH);
                digitalWrite (25,LOW);
                digitalWrite (26,LOW);
                digitalWrite (27,LOW);
                digitalWrite (28,LOW);
                digitalWrite (29,LOW);
           }
   
         break;

         
          case l4: ///////////////////////////////////////////////  L4 ///////////

        lcd.setCursor(0, 0); 
        lcd.print("   LED 1");
        lcd.setCursor(0, 1); 
        lcd.print("   LED 2");
        lcd.setCursor(0, 2); 
        lcd.print("   LED 3");
        lcd.setCursor(0, 3); 
        lcd.print(" # LED 4");
        
        
        

        if(botonArriba==0)
            {
              while(botonArriba==0)
                {
                  botonArriba=digitalRead(31);
                }

              estado=l3;
            }
            
       if(botonAbajo==0)
            {
              while(botonAbajo==0)
                {
                  botonAbajo=digitalRead(32);
                }

              estado=l5;
            }
            
     if(enter==0)
            {
              while(enter==0)
                {
                  enter=digitalRead(33);
                }
                digitalWrite (22,LOW);
                digitalWrite (23,LOW);
                digitalWrite (24,LOW);
                digitalWrite (25,HIGH);
                digitalWrite (26,LOW);
                digitalWrite (27,LOW);
                digitalWrite (28,LOW);
                digitalWrite (29,LOW);
                
           }
   
         break;
         

          case l5:  ///////////////////////////////////////////////  L5 ///////////

        lcd.setCursor(0, 0); 
        lcd.print(" # LED 5");
        lcd.setCursor(0, 1); 
        lcd.print("   LED 6");
        lcd.setCursor(0, 2); 
        lcd.print("   LED 7");
        lcd.setCursor(0, 3); 
        lcd.print("   LED 8");
        
       
        
        if(botonArriba==0)
            {
              while(botonArriba==0)
                {
                  botonArriba=digitalRead(31);
                }

              estado=l4;
            }
            
       if(botonAbajo==0)
            {
              while(botonAbajo==0)
                {
                  botonAbajo=digitalRead(32);
                }

              estado=l6;
            }
            
     if(enter==0)
            {
              while(enter==0)
                {
                  enter=digitalRead(33);
                }
                digitalWrite (22,LOW);
                digitalWrite (23,LOW);
                digitalWrite (24,LOW);
                digitalWrite (25,LOW);
                digitalWrite (26,HIGH);
                digitalWrite (27,LOW);
                digitalWrite (28,LOW);
                digitalWrite (29,LOW);
           }
   
   
         break;
         

         case l6: ///////////////////////////////////////////////  L6 ///////////

        lcd.setCursor(0, 0); 
        lcd.print("   LED 5");
        lcd.setCursor(0, 1); 
        lcd.print(" # LED 6");
        lcd.setCursor(0, 2); 
        lcd.print("   LED 7");
        lcd.setCursor(0, 3); 
        lcd.print("   LED 8");
        
       

        if(botonArriba==0)
            {
              while(botonArriba==0)
                {
                  botonArriba=digitalRead(31);
                }

              estado=l5;
            }
            
       if(botonAbajo==0)
            {
              while(botonAbajo==0)
                {
                  botonAbajo=digitalRead(32);
                }

              estado=l7;
            }
            
     if(enter==0)
            {
              while(enter==0)
                {
                  enter=digitalRead(33);
                }
                digitalWrite (22,LOW);
                digitalWrite (23,LOW);
                digitalWrite (24,LOW);
                digitalWrite (25,LOW);
                digitalWrite (26,LOW);
                digitalWrite (27,HIGH);
                digitalWrite (28,LOW);
                digitalWrite (29,LOW);
           }
   
         break;

         
         case l7:  ///////////////////////////////////////////////  L7 ///////////

            
        lcd.setCursor(0, 0); 
        lcd.print("   LED 5");
        lcd.setCursor(0, 1); 
        lcd.print("   LED 6");
        lcd.setCursor(0, 2); 
        lcd.print(" # LED 7");
        lcd.setCursor(0, 3); 
        lcd.print("   LED 8");

        
       
        
        if(botonArriba==0)
            {
              while(botonArriba==0)
                {
                  botonArriba=digitalRead(31);
                }

              estado=l6;
            }
            
       if(botonAbajo==0)
            {
              while(botonAbajo==0)
                {
                  botonAbajo=digitalRead(32);
                }

              estado=l8;
            }
            
     if(enter==0)
            {
              while(enter==0)
                {
                  enter=digitalRead(33);
                }
                digitalWrite (22,LOW);
                digitalWrite (23,LOW);
                digitalWrite (24,LOW);
                digitalWrite (25,LOW);
                digitalWrite (26,LOW);
                digitalWrite (27,LOW);
                digitalWrite (28,HIGH);
                digitalWrite (29,LOW);
           }
   
         break;

         
         case l8: ///////////////////////////////////////////////  L8 ///////////

           
        lcd.setCursor(0, 0); 
        lcd.print("   LED 5");
        lcd.setCursor(0, 1); 
        lcd.print("   LED 6");
        lcd.setCursor(0, 2); 
        lcd.print("   LED 7");
        lcd.setCursor(0, 3); 
        lcd.print(" # LED 8");
        
        
        
        if(botonArriba==0)
            {
              while(botonArriba==0)
                {
                  botonArriba=digitalRead(31);
                }

              estado=l7;
            }
            
       if(botonAbajo==0)
            {
              while(botonAbajo==0)
                {
                  botonAbajo=digitalRead(32);
                }

              estado=l1;
            }
            
     if(enter==0)
            {
              while(enter==0)
                {
                  enter=digitalRead(33);
                }
                digitalWrite (22,LOW);
                digitalWrite (23,LOW);
                digitalWrite (24,LOW);
                digitalWrite (25,LOW);
                digitalWrite (26,LOW);
                digitalWrite (27,LOW);
                digitalWrite (28,LOW);
                digitalWrite (29,HIGH);
           }
   
         break;

    
    } 
 }



