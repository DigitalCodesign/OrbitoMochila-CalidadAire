// Se incluyen las librerias necesarias
#include <OrbitoMochilaCalidadAire.h>
#include <Orbito.h>

// Se declara el objeto Mochila
OrbitoMochilaCalidadAire Mochila;

// Se declaran las variables necesarias
float nox;
float vox;

void setup(){
  // Se inicializa el bus serial
  Serial.begin(9600);
  Serial.println("Iniciando test SGP41");
  // Se inicializa el robot
  Orbito.begin();
  // Se inicializa la mochila
  Mochila.begin();
  delay(2000);
}

void loop(){
  // Se lee el indice Voc dado por el sensor
  Voc = Mochila.SGP41.Voc();
  // Se lee el indice Nox dado por el sensor
  Nox = Mochila.SGP41.Nox();
  // Se imprimen en el monitopr serial los valores medidos previamente
  Serial.println("Valor de Voc: " + String(Voc));
  Serial.println("Valor de Nox: " + String(Nox));
  // Retardo entre medidas
  delay(10000);
}