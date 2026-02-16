// Se incluyen las librerias necesarias
#include <OrbitoMochilaCalidadAire.h>
#include <Orbito.h>

// Se declara el objeto Mochila
OrbitoMochilaCalidadAire Mochila;

// Se declaran las variables donde almacenar los valores medidos por el sensor
float temperature;
float humedad;
float presion;
uint32_t resistencia_gas;
float altitud;

void setup(){
  // Se iniciliza el monitor serial
  Serial.begin(9600);
  Serial.println("Iniciando test");
  // Se inicializa el robot
  Orbito.begin();
  // Se inicializa la mochila
  Mochila.begin();
  delay(1000);
}

void loop(){
  // Se lee el valor de temperatura
  temperature = Mochila.BME688.temperatura();
  // Se lee el valor de la humedad relativa
  humedad = Mochila.BME688.humedad();
  // Se lee el valor de la presion
  presion = Mochila.BME688.presion();
  // Se lee el valor de la resistencia del gas en ohms
  resistencia_gas = Mochila.BME688.resistencia_gas();
  // Se lee el valor de altura calculado por el sensor
  altitud = Mochila.BME688.altitud();
  // Se imprimen en el monitor serial todas las medidas tomadas previamente
  Serial.println("Valor de temperatura:" + String(temperature) + " ºC");
  Serial.println("Valor de humedad: " + String(humedad) + " %");
  Serial.println("Valor de presion: " + String(presion) + " Pa");
  Serial.println("Valor de resistencia del gas: " + String(resistencia_gas/1000) + " KOhms");
  Serial.println("Valor de altitud: " + String(altitud) + " m");
  // Retardo entre mediciones
  delay(10000);
}