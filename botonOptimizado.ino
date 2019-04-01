// Definicion de Pines
int Led = LED_BUILTIN;
int Botn = 8 ;
// Definicion de variables globales
int contador ;
long t0;
void setup() {
  // inicializacion de variables 
  contador= 0;  // asiigno valor inicial al contador
  // put your setup code here, to run once:
  t0 = 0;
  // configuracion de pines
  pinMode(Led, OUTPUT);
  pinMode(Botn, INPUT);
  Serial.begin(9600);
  //Mensaje de inicio
  Serial.println("iicio de programa");
}

void loop() {
  // Mostrar contador
  Serial.println(contador);

  if( botonPresionado() && tiempoCumplido())
   
  {
   contar();
  }
  if(esPar()){
    encenderLed();
   
  }
  else {
     apagarLed();
    
  }

}
 bool botonPresionado()
 {if( digitalRead(Botn)== 1)
 { return true;
  }
  else 
  { return false;
  }
 }
 

bool tiempoCumplido()

{if (millis () > t0 + 400)
{
  return true;
}
else
{
  return false;
}
  }

bool esPar()
{ if( (contador % 2) == 0)
{return true;
}
{return false;
}
}

void encenderLed(){
   Serial.println("Led encendido");
    digitalWrite(Led , HIGH);
}

void apagarLed(){
Serial.println("Led apagado");
digitalWrite(Led, LOW);
}

void contar(){
   t0 = millis();
    Serial.println("Boton presiona");
   contador++;
   Serial.println(contador);
  }
