// Se incluyen las librerias necesarias
#include <OrbitoMochilaCalidadAire.h>
#include <Orbito.h>

// Se declara el objeto Mochila
OrbitoMochilaCalidadAire Mochila;

// Se declaran las variables necesarias
float temperature;
float humidity;

void setup(){
  // Se inicializa el bus serial
  Serial.begin(9600);
  Serial.println("Iniciando test SHT40");
  // Se inicializa el robot
  Orbito.begin();
  // Se inicializa la mochila
  Mochila.begin();
  delay(2000);
}

void loop(){
  // Se lee el valor de la temperatura y se imprime en el monitor serial
  temperature = Mochila.SHT40.temperatura();
  Serial.println("Valor de la temperatura: " + String(temperature) + " ºC");
  // Se lee el valor de humedad relativa y se imprime en el monitor serial
  humidity = Mochila.SHT40.humedad();
  Serial.println("Valor de la humedad: " + String(humidity) + " %");
  // Retardo entre medidas
  delay(10000);
}