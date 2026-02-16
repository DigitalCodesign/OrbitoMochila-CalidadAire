// Se incluyen las librerias necesarias
#include <OrbitoMochilaCalidadAire.h>
#include <Orbito.h>

// Se declara el objeto Mochila
OrbitoMochilaCalidadAire Mochila;

// Se declaran las variables necesarias para almacenar los valores medidos por el sensor
float temperature;
float humidity;
uint16_t CO2_value;

void setup(){
  // Se inicializa el bus serial 
  Serial.begin(9600);
  Serial.println("Iniciando test SCD40");
  // Se inicializa el robot
  Orbito.begin();
  // Se inicializa la mochila de calidad del aire
  Mochila.begin();
  delay(2000);
}

void loop(){
  // Se lee y se imprime en el monitor serial el valor de la temperatura
  temperature = Mochila.SCD40.temperatura();
  Serial.println("Valor de la temperatura: " + String(temperature) + " ºC");
  // Se lee y se imprime en el monitor serial el valor de la humedad relativa
  humidity = Mochila.SCD40.humedad();
  Serial.println("Valor de la humedad: " + String(humidity) + " %");
  // Se lee y se imprime en el monitor serial el valor medido de CO2 en ppm
  CO2_value = Mochila.SCD40.CO2();
  Serial.println("Valor de C02: " + String(CO2_value) + " ppm");
  // Retardo entre medidas
  delay(10000);
}