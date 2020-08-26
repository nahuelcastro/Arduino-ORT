#define prendido
#define apagado
#define espera

void maquina (void)
char estado = 0;
int ms,s;
char boton

void setup()
  {
    pinMode (3, INPUT_PULLUP);
    pinMode (4, OUTPUT);
    Timer1 initialize (1000)
    timer1 atachinterrupt(timer1);
  }

void loop()
  {
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
      case prendido:
          if(s==1)
          {
            digitalWrite(4,LOW);
            s=0;
            estado=apagado; 
          }
      boton=digitalRead(3);
      if(boton==0);
        { while...
        digitalWrite(4,LOW)
        estado=espera
        }

        break;
  }
  


