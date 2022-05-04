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
  
 
  boton1_dato = digitalRead (BOTON1); // Leer el boton1
  if (boton1_dato == 1){
    digitalWrite (LED1,LOW);
  }else {
    digitalWrite (LED1,HIGH);
  }

// ** Automatico por temperatura 
if (t > TEMP_H){
  digitalWrite(LED2, HIGH);
}else{
  digitalWrite(LED2, LOW);
}
  
}// Fin de void loop

// Funciones del usuario
