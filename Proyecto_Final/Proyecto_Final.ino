/* 
 lcd conecciones:
pin 1 ground
pin 2 5v 
pin 3 ground 
pin 4 pin 12
pin 5 ground
pin 6 pin 11
pin 11 pin 5 
pin 12 pin 4
pin 13 pin 3
pin 14 pin 2
pin 15 5v
pin 16 ground
*/

#include <TimerOne.h>
#include <Password.h> //Incluimos la libreria Password
#include <Keypad.h> //Incluimos la libreria Keypad
#include <LiquidCrystal.h>  //Incluimos la libreria LiquidCrystal
#include <SPI.h>
#include <MFRC522.h>

#define 0digito 0
#define 1digito 1
#define 2digito 2
#define 3digito 3
#define 4digito 4
#define 5digito 5
#define 6digito 6
#define 7digito 7
#define 8digito 8

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  53   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

Password password = Password("CACA");  //Definimos el Password
int dlugosc = 4;                        //Largo del Password
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Definimos los pines del LCD

void maquina (void);
char estado= 0;
int ms;
int contador;
 
int buzzer = 6; //Creamos las Variables de salida
int ledRed =7; 
int ledGreen = 8;
 
int ilosc; //Numero de Clicks
 
const byte ROWS = 4; // Cuatro Filas
const byte COLS = 4; // Cuatro Columnas

// Definimos el Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 23,24,25,26 };// Conectar los keypads ROW1, ROW2, ROW3 y ROW4 a esos Pines de Arduino.
byte colPins[COLS] = { 27,28,29,30, };// Conectar los keypads COL1, COL2, COL3 y COL4 a esos Pines de Arduino.
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup()
{
   ms=0;
      Timer1.initialize(1000); 
   Timer1.attachInterrupt(Timer);
   DDRA=0XFF;
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent);  
  pinMode(ledRed, OUTPUT);  
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
 
  lcd.begin(20, 4);
 
  lcd.setCursor(0,0);
  lcd.print("    *Bienvenido*");
  lcd.setCursor(0,2);
  lcd.print("- INGRESE SU PIN");
  lcd.setCursor(0,3);
  lcd.print("- ACERQUE SU TARJETA");

   SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos  el MFRC522
  Serial.println("Control de acceso");
}

 byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuario1[4]= {0x0C, 0xDA, 0xF1, 0xC5} ; //código del usuario 1
byte Usuario2[4]= {0xE6, 0x5A, 0x2B, 0x12} ; //código del usuario 2


void loop()
{
  keypad.getKey();
   maquina();

   // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print("Card UID:");
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX); 
                          ActualUID[i]=mfrc522.uid.uidByte[i];  
                  } 
                  Serial.println();
                  //comparamos los UID para determinar si es uno de nuestros usuarios  
                  if(compareArray(ActualUID,Usuario1))
                  {
                    Serial.println("Acceso concedido...");
                  
                    
                     digitalWrite(buzzer, HIGH);  
                      delay(120);            
                      digitalWrite(buzzer, LOW);  
                      delay(70);  
                      
                      digitalWrite(ledRed, LOW);
                      digitalWrite(ledGreen, HIGH);
                   
                      lcd.clear();
                      lcd.setCursor(0,1);
                      lcd.print("<<Acceso concedido>>");    
                          lcd.setCursor(0,2);
    lcd.print("   Abra la puerta.");
                   
                      delay(6000);
                      digitalWrite(ledGreen, LOW);
                      digitalWrite(ledRed, HIGH);
                         
                       lcd.clear();
                        lcd.setCursor(0,0);
                        lcd.print("    *Bienvenido*");
                        lcd.setCursor(0,2);
                        lcd.print("- INGRESE SU PIN");
                        lcd.setCursor(0,3);
                        lcd.print("- ACERQUE SU TARJETA");   
            } 
            
                  else if(compareArray(ActualUID,Usuario2))
                     {
                    Serial.println("Acceso concedido...");
                    
                     digitalWrite(buzzer, HIGH);  
                      delay(120);            
                      digitalWrite(buzzer, LOW);  
                      delay(70);  
                      
                      digitalWrite(ledRed, LOW);
                      digitalWrite(ledGreen, HIGH);
                   
                      lcd.clear();
                      lcd.setCursor(0,1);
                      lcd.print("<<Acceso concedido>>");    
                          lcd.setCursor(0,2);
    lcd.print("   Abra la puerta.");
                   
                      delay(6000);
                      digitalWrite(ledGreen, LOW);
                      digitalWrite(ledRed, HIGH);
                         
                      

                       lcd.clear();
                        lcd.setCursor(0,0);
                        lcd.print("    *Bienvenido*");
  lcd.setCursor(0,2);
  lcd.print("- INGRESE SU PIN");
  lcd.setCursor(0,3);
  lcd.print("- ACERQUE SU TARJETA");  
            } 

                    
                  else

                   
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("    *Bienvenido*");
  lcd.setCursor(0,2);
  lcd.print("- INGRESE SU PIN");
  lcd.setCursor(0,3);
  lcd.print("- ACERQUE SU TARJETA");
                  // Terminamos la lectura de la tarjeta  actual
                  mfrc522.PICC_HaltA();         
            }      
  } 
}

//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}


void keypadEvent(KeypadEvent eKey)
{
  switch (keypad.getState())
  {
    case PRESSED:
   
int i;
for( i = 1; i <= 1; i++ )
{
  digitalWrite(buzzer, HIGH);  
  delay(200);            
  digitalWrite(buzzer, LOW);  
  delay(100);      
}    
 
Serial.print("Pressed: ");
Serial.println(eKey);
 
switch (eKey)
{
/*
case '#':
break;
 
case '*':
break;
*/
 
default:
ilosc=ilosc+1;
password.append(eKey);
}
//Serial.println(ilosc);

void maquina()
 {
   
  
   switch(estado)
    {
     case 0digito: 

        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("     < PIN >");
        lcd.setCursor(0,1);
        lcd.print("*_");




 
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("     < PIN >");
        lcd.setCursor(0,1);
        lcd.print("*_");
        

}
if(ilosc == 2)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("     < PIN >");
lcd.setCursor(0,1);
lcd.print("**_");
}
if(ilosc == 3)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("     < PIN >");
lcd.setCursor(0,1);
lcd.print("***_");
}
if(ilosc == 4)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("     < PIN >");
lcd.setCursor(0,1);
lcd.print("****_");
}
if(ilosc == 5)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("     < PIN >");
lcd.setCursor(0,1);
lcd.print("*****_");
}
if(ilosc == 6)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("     < PIN >");
lcd.setCursor(0,1);
lcd.print("******_");
}
if(ilosc == 7)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("     < PIN >");
lcd.setCursor(0,1);
lcd.print("*******_");
}
if(ilosc == 8)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("     < PIN >");
lcd.setCursor(0,1);
lcd.print("********");
}
 
if(ilosc == dlugosc)
{
delay(250);
checkPassword();
ilosc = 0;
}
}
}
 
void checkPassword()
{
  if (password.evaluate())
  {
int i;
for( i = 1; i <= 3; i++ )
{
  digitalWrite(buzzer, HIGH);  
  delay(120);            
  digitalWrite(buzzer, LOW);  
  delay(70);      
}    
    ilosc = 0;
    password.reset();
    
    Serial.println("Pin correcto");    
 
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("<<Acceso concedido>>");    
    lcd.setCursor(0,2);
    lcd.print("   Abra la puerta.");
 
    delay(6000);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
       
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    *Bienvenido*");
  lcd.setCursor(0,2);
  lcd.print("- INGRESE SU PIN");
  lcd.setCursor(0,3);
  lcd.print("- ACERQUE SU TARJETA"); 
 
  }  
  else  
  {
int i;
for( i = 1; i <= 1; i++ )
{
  digitalWrite(buzzer, HIGH);  
  delay(300);            
  digitalWrite(buzzer, LOW);  
  delay(100);      
}  
    ilosc = 0;  
    password.reset();
 
    Serial.println("Error");
 
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);    
             
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("<<PIN ERRONEO>>");
    delay(2000);
   
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    *Bienvenido*");
  lcd.setCursor(0,2);
  lcd.print("- INGRESE SU PIN");
  lcd.setCursor(0,3);
  lcd.print("- ACERQUE SU TARJETA");
  }
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
   

