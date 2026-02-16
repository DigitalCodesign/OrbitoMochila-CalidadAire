// Se incluyen las librerias necesarias
#include <OrbitoMochilaCalidadAire.h>
#include <Orbito.h>

// Se declara el objeto Mochila
OrbitoMochilaCalidadAire Mochila;

// Se declaran las variables necesarias
float mass_concentration_1p0;
float mass_concentration_2p5;
float mass_concentration_4p0;
float mass_concentration_10p0;
float number_concentration_1p0;
float number_concentration_2p5;
float number_concentration_4p0;
float number_concentration_10p0;
float typical_detected_size;

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
  // Se lee el valor de concentracion de masa de particulas de menos de 1 micrometro
  mass_concentration_1p0 = Mochila.SPS30.ConcentracionMasa.mc1p0();
  // Se lee el valor de concentracion de masa de particulas de menos de 2.5 micrometros
  mass_concentration_2p5 = Mochila.SPS30.ConcentracionMasa.mc2p5();
  // Se lee el valor de concentracion de masa de particulas de menos de 4 micrometros
  mass_concentration_4p0 = Mochila.SPS30.ConcentracionMasa.mc4p0();
  // Se lee el valor de concentracion de masa de particulas de menos de 10 micrometros
  mass_concentration_10p0 = Mochila.SPS30.ConcentracionMasa.mc10p0();
  // Se lee el valor de concentracion numerica de particulas de menos de 1 micrometro
  number_concentration_1p0 = Mochila.SPS30.ConcentracionParticulas.nc1p0();
  // Se lee el valor de concentracion numerica de particulas de menos de 2.5 micrometros
  number_concentration_2p5 = Mochila.SPS30.ConcentracionParticulas.nc2p5();
  // Se lee el valor de concentracion numerica de particulas de menos de 4 micrometros
  number_concentration_4p0 = Mochila.SPS30.ConcentracionParticulas.nc4p0();
  // Se lee el valor de concentracion numerica de particulas de menos de 10 micrometros
  number_concentration_10p0 = Mochila.SPS30.ConcentracionParticulas.nc10p0();
  // Se lee el valor tipico de la particula más detctada por el sensor
  typical_detected_size = Mochila.SPS30.tipicalSize();
  // Se imprimen en el moniotor serial todos los valores medidos previamente
  Serial.println("Valor de concentracion de masa de particulas de menos de 1 micrometro: " + String(mass_concentration_1p0) + " ug/m3");
  Serial.println("Valor de concentracion de masa de particulas de menos de 2.5 micrometro: " + String(mass_concentration_2p5) + " ug/m3");
  Serial.println("Valor de concentracion de masa de particulas de menos de 4 micrometro: " + String(mass_concentration_4p0) + " ug/m3");
  Serial.println("Valor de concentracion de masa de particulas de menos de 10 micrometro: " + String(mass_concentration_10p0) + " ug/m3");
  Serial.println("Valor de concentracion numerica de particulas de menos de 1 micrometro: " + String(number_concentration_1p0) + " unidades/m3");
  Serial.println("Valor de concentracion numerica de particulas de menos de 2.5 micrometro: " + String(number_concentration_2p5) + " unidades/m3");
  Serial.println("Valor de concentracion numerica de particulas de menos de 4 micrometro: " + String(number_concentration_4p0) + " unidades/m3");
  Serial.println("Valor de concentracion numerica de particulas de menos de 10 micrometro: " + String(number_concentration_10p0) + " unidades/m3");
  Serial.println("Valor tipico de paticula detectado: " + String(typical_detected_size) + " um");
  // Retardo entre medidas
  delay(10000);
}