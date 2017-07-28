String direccion = "";
char a;


void setup() 
{
  //INICIALIZAMOS LA COMUNICACION SERIAL
  Serial1.begin(38400); //PUERTO DE INTERFAZ
  Serial.begin(38400); //COMUNICACION SERIAL DEL MODULO
  delay(2000);

  
  //Serial.println("Comenzando...");
  //RESETEAMOS AT
  Serial1.println("AT+RESET");
  delay(2000);
  
  //INICIAMOS AT
  Serial1.println("AT");
  delay(2000);
  
  //INICIAMOS LA BUSQUEDA DE LA CONEXION
  Serial1.println("AT+INIT");
  //Serial.println("AHORA");
  delay(2000);

  //VACIAMOS EL BUFFER
  while(Serial1.available())
  Serial1.read();
}

void loop() 
{
  //AT+INQ PREGUNTA SI HAY ALGUN DISPOSITIVO CERCA
  delay(3000);
  Serial1.println("AT+INQ"); 

  delay(300);
  while(Serial1.available())
  {
      a=Serial1.read();
      
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

