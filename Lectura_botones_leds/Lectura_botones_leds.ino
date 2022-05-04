/*
 * Lectura de botones - Encendido de Leds
 * Por: Hugo Vargas
 * Fecha: 28 de junio de 2021
 * 
 * Este programa muestra las instrucciones básicas para la lectura
 * de botones y el encendido de leds
 */

// Bibliotecas
#include "DHT.h"

// Constantes
#define DHTPIN 12
#define DHTTYPE DHT11

const int BOTON1 = 4;
const int LED1 = 2;

// Variables
int dato1;

// Definición de objetos
DHT dht(DHTPIN, DHTTYPE);

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código

  Serial.begin(9600);
  Serial.println(F("DHTxx Text!"));

  dht.begin();
  
  pinMode (BOTON1, INPUT_PULLUP); // Configurar el pin donde se conecta el boton como entrada
  pinMode (LED1, OUTPUT); //Cofigurar el pin donde se conecta el led como salida de voltaje
  digitalWrite (LED1, LOW); //0, false, LOW, 1, true, HIGH
  
}// Fin de void setup

// Cuerpo del programa - Se ejecuta constamente
void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:
  
  delay(2000); // es un sensor lento, lee cada 2 segundos, restricciones del tiempo
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Faildes to read from DHT sensor!"));
    return;
  }
  Serial.println(F("Humedad :"));
  Serial.print(h);
  Serial.print(F("% Temperatura: "));
  Serial.print(t);
  Serial.println(F("oC "));

  
  dato1 = digitalRead (BOTON1); // Leer el boton
  digitalWrite (LED1, dato1);


}// Fin de void loop

// Funcioes del usuario
