String direccion = "";
char a;


void setup() 
{
  //INICIALIZAMOS LA COMUNICACION SERIAL
  Serial.begin(38400); //COMUNICACION SERIAL DEL MODULO
  //Serial.begin(38400); //PUERTO DE INTERFAZ
  delay(2000);

  
  //Serial.println("Comenzando...");
  //RESETEAMOS AT
  Serial.println("AT+RESET");
  delay(2000);
  
  //INICIAMOS AT
  Serial.println("AT");
  delay(2000);
  
  //INICIAMOS LA BUSQUEDA DE LA CONEXION
  Serial.println("AT+INIT");
  //Serial.println("AHORA");
  delay(2000);

  //VACIAMOS EL BUFFER
  //while(Serial.available())
  //Serial1.read();
}

void loop() 
{
  //AT+INQ PREGUNTA SI HAY ALGUN DISPOSITIVO CERCA
  delay(3000);
  Serial.println("AT+INQ"); 

  delay(500);
  while(Serial.available())
  {
      a=Serial.read();
      
      if(a != '\n')
      {
        direccion += a;
      }
      else if(a == '\n')
      {
        Imprimir();
        direccion = "";
      }
      delay(10);
   }
   delay(500);
   direccion = "";
   
  /*if(Serial1.available())
  {
    char a=Serial1.read();
    Serial.write(a);
  }
  
  if(Serial.available())
  {
    char a=Serial.read();
    Serial1.write(a);
  }*/
}

//AQUI SE ENVIARAN LOS DATOS AL SERVIDOR
void Imprimir()
{
  if(direccion[1] != 'K')
  {
    Serial.println(direccion);
  }
  delay(50);
  direccion == "";
}

