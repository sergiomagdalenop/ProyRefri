// Bibliotecas

#include "DHT.h"


// Constantes
#define DHTPIN 12
#define DHTTYPE DHT11

// nivel de temperatura

// Variables


// Definición de objetos
DHT dht(DHTPIN, DHTTYPE);

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código
  Serial.begin(9600);
  Serial.println(F("DHTxx Text!"));

  dht.begin();

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

}// Fin de void loop

// Funciones del usuario
