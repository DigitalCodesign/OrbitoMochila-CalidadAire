// Se incluyen las librerias necesarias
#include <OrbitoMochilaCalidadAire.h>
#include <Orbito.h>

// Se declara el objeto Mochila
OrbitoMochilaCalidadAire Mochila;

// Se declaran las variables necesarias
float temperature;
float humedad;
float presion;
float altitud;
float nox;
float vox;
float mass_concentration_1p0;
float mass_concentration_2p5;
float mass_concentration_4p0;
float mass_concentration_10p0;
uint32_t resistencia_gas;
uint16_t CO2_value;


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
  // Se lee el valor de la temperatura
  temperature = Mochila.BME688.temperatura();
  // Se lee el valor de la humedad
  humedad = Mochila.BME688.humedad();
  // Se lee el valor de la presion
  presion = Mochila.BME688.presion();
  // Se lee el valor estimado de la altitud
  altitud = Mochila.BME688.altitud();
  // Se lee el valor de la resistencia del aire
  resistencia_gas = Mochila.BME688.resistencia_gas();
  // Se lee el valor de la concentracion de CO2
  CO2_value = Mochila.SCD40.CO2();
  // Se lee el valor del indice NOX
  nox = Mochila.SGP41.Nox();
  // Se lee el valor del indice VOX
  vox = Mochila.SGP41.Voc();
  // Se lee el valor de concentracion de masa de particulas de menos de 1 micrometro
  mass_concentration_1p0 = Mochila.SPS30.ConcentracionMasa.mc1p0();
  // Se lee el valor de concentracion de masa de particulas de menos de 2.5 micrometros
  mass_concentration_2p5 = Mochila.SPS30.ConcentracionMasa.mc2p5();
  // Se lee el valor de concentracion de masa de particulas de menos de 4 micrometros
  mass_concentration_4p0 = Mochila.SPS30.ConcentracionMasa.mc4p0();
  // Se lee el valor de concentracion de masa de particulas de menos de 10 micrometros
  mass_concentration_10p0 = Mochila.SPS30.ConcentracionMasa.mc10p0();
  // Se imprimen por el monitor serial todos los datos medidos
  Serial.println("Valor de temperatura:" + String(temperature) + " ºC");
  Serial.println("Valor de humedad: " + String(humedad) + " %");
  Serial.println("Valor de presion: " + String(presion) + " Pa");
  Serial.println("Valor de resistencia del gas: " + String(resistencia_gas/1000) + " KOhms");
  Serial.println("Valor de altitud: " + String(altitud) + " m");
  Serial.println("Valor de C02: " + String(CO2_value) + " ppm");
  Serial.println("Valor de Voc: " + String(vox));
  Serial.println("Valor de Nox: " + String(nox));
  Serial.println("Valor de concentracion de masa de particulas de menos de 1 micrometro: " + String(mass_concentration_1p0) + " ug/m3");
  Serial.println("Valor de concentracion de masa de particulas de menos de 2.5 micrometro: " + String(mass_concentration_2p5) + " ug/m3");
  Serial.println("Valor de concentracion de masa de particulas de menos de 4 micrometro: " + String(mass_concentration_4p0) + " ug/m3");
  Serial.println("Valor de concentracion de masa de particulas de menos de 10 micrometro: " + String(mass_concentration_10p0) + " ug/m3");
  // Retardo entre medidas
  delay(10000);
}