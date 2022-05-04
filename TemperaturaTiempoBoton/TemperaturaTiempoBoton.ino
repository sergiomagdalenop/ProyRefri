// Bibliotecas

#include "DHT.h"


// Constantes
#define DHTPIN 12
#define DHTTYPE DHT11
const int BOTON1 = 14;
const int BOTON2 = 15;
const int BOTON3 = 13;
const int LED1 = 4;
const int LED2 = 2;
// nivel de temperatura
const int TEMP_H = 28;

// Variables
int   boton1_dato;
int   boton2_dato;
int   boton3_dato;

float h;
float t; 
float temp_vieja=0.0; //Cambios de temperaturas

// Definición de objetos
DHT dht(DHTPIN, DHTTYPE);

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código
  Serial.begin(9600);
  Serial.println(F("DHTxx Text!"));

   // configuracion de botrones
  pinMode (BOTON1, INPUT_PULLUP);
  pinMode (BOTON2, INPUT_PULLUP); // Configurar el pin donde se conecta el boton como entrada
  pinMode (BOTON3, INPUT_PULLUP);

  //configurar leds
  pinMode (LED1, OUTPUT); //Cofigurar el pin donde se conecta el led como salida de voltaje
  pinMode (LED2, OUTPUT); 
  digitalWrite (LED1, LOW); //0, false, LOW, 1, true, HIGH

  dht.begin();
  
}// Fin de void setup


// Cuerpo del programa - Se ejecuta constamente
void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:

  lectura();
  logica();

}// Fin de void loop

// Funciones del usuario

void lectura()
{
  delay(2000); // es un sensor lento, lee cada 2 segundos, restricciones del tiempo
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (temp_vieja!=t){
    temp_vieja=t; //actualizando valor de la temperatura
    
  }

  
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Faildes to read from DHT sensor!"));
    return;
  }
  Serial.print(F("% Temperatura: "));
  Serial.print(t); //mostrar temperatura actual
  Serial.println(F("oC "));
  
  Serial.println(F("Humedad :"));
  Serial.print(h);
 
}

void lecturaBotones()
{
  boton2_dato = digitalRead (BOTON2); // Leer el boton2
  boton3_dato = digitalRead (BOTON3); // Leer el boton3
}

void logica()
{
  if (t<=TEMP_H)
{ 
  boton1_dato = digitalRead (BOTON1); // Leer el boton1
  if (boton1_dato == 0){
    digitalWrite (LED1,LOW);
    lecturaBotones();
    boton3_dato = digitalRead (BOTON3); // Leer el boton3
    if (boton2_dato==0 && boton3_dato==0)
    {
      digitalWrite(LED2,LOW); // Led auto=0
    }
    else
    {
      digitalWrite(LED2,HIGH); // Led auto = 1
    }
  }else {
        digitalWrite (LED1,HIGH); //Led manual = 1
        lecturaBotones();
        if (boton1_dato==0 && boton3_dato==0)
        {
          digitalWrite(LED2, LOW); // Led automatico = 0
        }
       else
       {
        digitalWrite(LED2, HIGH); //Led autonmatico =1
       }
  }
}
else
 {
  digitalWrite(LED2,HIGH); //Led automatico = 1
  boton1_dato = digitalRead (BOTON1); // Leer el boton1
 
  if (boton1_dato==0 && boton2_dato==0 && boton3_dato==0)
  {
    digitalWrite(LED1, LOW); // Led manual = 0
  }
  else
  {
    digitalWrite(LED2,HIGH); //Led automatico = 1
  }
 }

}
