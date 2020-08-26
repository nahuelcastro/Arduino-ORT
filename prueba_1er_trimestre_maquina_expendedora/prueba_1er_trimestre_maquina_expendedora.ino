#define moneda1 25
#define moneda2 50
#define moneda3 100
int sensor25c;
int sensor50c;
int sensor1p;
char boton1;
char boton2;
char boton3;
char boton4;
int temperatura;
char numBCD;
char valoringresado;
int grados;

void setup() 
  {
    pinMode( 3, INPUT_PULLUP);
    pinMode( 4, INPUT_PULLUP);
    pinMode( 5, INPUT_PULLUP);
    pinMode( 6, INPUT_PULLUP);
    pinMode( 7, INPUT_PULLUP);
    pinMode( 8, INPUT_PULLUP);
    pinMode( 9, INPUT_PULLUP);
    pinMode( 10, OUTPUT);
    
  }

void loop() 
  {
    sensor25c=digitalRead(3);
    sensor50c=digitalRead(4);
    sensor1p=digitalRead(5);
    temperatura=analogRead(A0);
    grados=(voltimetro*50)/1024;
    boton1=digitalRead(3);
    boton2=digitalRead(4);
    boton3=digitalRead(5);
    boton4=digitalRead(6); 
    numBCD=convBCD(grados);
    PORTA=numBCD
  if(sensor25c==1)
    {
        while(sensor25c==1)
        {
          sensor25c=digitalRead(3);
        }
    
       valoringresado=valor ingresado+moneda1;
    }
  if(sensor50c==1)
    {
        while(sensor50c==1)
        {
          sensor50c=digitalRead(4);
        }
    
       valoringresado += moneda2;
    }

  if(sensor1p==1)
    {
        while(sensor1p==1)
        {
          sensor1p=digitalRead(4);
        }
    
       valoringresado += moneda3;
    }

  if(valoringresado >= valortotal)
    {
      digitalWrite(10,HIGH); //led verde
      digitalWrite(11,LOW); //led rojo
      if((boton1==0)||(boton2==0)||(boton3==0)||(boton4==1))
        while((boton1==0)||(boton2==0)||(boton3==0)||(boton4==1))
        {
          boton1=digitalRead(3);
          boton2=digitalRead(4);
          boton3=digitalRead(5);
          boton4=digitalRead(6);
        }
      digitalWrite(10,LOW); //led verde
      digitalWrite(11,HIGH); //led rojo
      digitalWrite(12,HIGH); //prender actuador
       valoringresado = 0;
    }  

  }
