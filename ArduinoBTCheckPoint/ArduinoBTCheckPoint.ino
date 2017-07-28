#include <Arduino.h>

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>


const char* ssid     = "HUAWEIP8";
const char* password = "focobol555";

String direccion = "";
char a;


ESP8266WiFiMulti WiFiMulti;

void setup() 
{ 
  //INICIALIZAMOS LA COMUNICACION SERIAL
  Serial.begin(38400); //COMUNICACION SERIAL DEL MODULO
  //Serial.begin(38400); //PUERTO DE INTERFAZ
  delay(2000);

  //WiFi.begin(ssid,password);
  WiFiMulti.addAP("HUAWEIP8", "focobol555");
  delay(500);

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
  if((WiFiMulti.run() == WL_CONNECTED))
  {
    HTTPClient http;
    
    if(direccion[1] != 'K')
    {
      //Serial.println(direccion);
      if(direccion[5] == '9')
      {
        http.begin("http://checkpointhackbo.azurewebsites.net/api/RegistroPuntosApi/1"); //HTTP
        delay(100);
        int httpCode = http.GET();
        //Serial.println("ENVIO1");
      }

      if(direccion[5] == '2')
      {
        http.begin("http://checkpointhackbo.azurewebsites.net/api/RegistroPuntosApi/2"); //HTTP
        int httpCode = http.GET();
        //Serial.println("ENVIO2");
      }
      //direccion = "1@" + direccion;
      //Serial.println(direccion);
      //client.println(direccion);
    }
      http.end();
      delay(10000);
      direccion == ""; 
    }
}

