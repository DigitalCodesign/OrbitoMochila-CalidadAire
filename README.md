# OrbitoMochilaCalidadAire
## Descripción
Esta libreria esta pensada para ser usadada junto con el modulo mochila de calidad del aire y el robot Orbito. Con esta se pueden controlar y obtener la información de todos los sensores disponibles en la mochila de calidad del aire
## Caracteristicas
Esta libreria permite obtener los datos medidos por los siguientes sensores:
+ **BME688:** Este sensor es capaz de medir la temperatura, la humedad relativa, la presión atmosférica, la resistencia del gas y a través de la presión, estimar la altura.
+ **SHT40** Este sensor es capaz de medir la temperatura y la humedad con mayor presición que todos los demas
+ **SCD40** Este sensor es capaz de medir la concentración de CO2 en ppm, la temperatura y la humedad relativa
+ **SGP41** Este sensor es capaz de dar los índices VOC (Compuestos Orgánicos Volátiles) y NOX (Óxidos de Nitrógeno)
+ **SPS30** Este sensor es capaz de medir la concentracion de masa de los diferentes tamaños de particulas en el aire(PM1.0, PM2.5, PM4.0, PM10.0), asi como la concentración numérica y el tamaño típico de partícula
## Modo de empleo
1. **Instalación**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "OrbitoMochilaCalidadAire" e instálala.
    * Asegurate de tener todas las dependencias:
      * `Orbito` en la versión **1.0.0** o superior
      * `Adafruit GFX Library` en la versión **1.12.4** o superior
      * `Adafruit BusIO` en la versión **1.17.4** o superior
      * `Adafruit ST7735 and ST7789 Library` en la versión **1.10.3** o superior
2. **Ejemplo Básico**
```c++
// Se incluyen las librerias necesarias
#include <OrbitoMochilaCalidadAire.h>
#include <Orbito.h>

// Se declara el objeto Mochila
OrbitoMochilaCalidadAire Mochila;

// Se declaran las variables para almacenar el valor del sensor
float temperature;

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
  // Se imprimen en el monitor serial el valor de la temperatura
  Serial.println("Valor de temperatura:" + String(temperature) + " ºC");
  // Retardo entre mediciones
  delay(10000);
}
```
## Constructor y métodos básicos
### Constructor
* `OrbitoMochilaCalidadAire` crea un objeto de esta clase con el nombre indicado
### Structs
* `BME688` selecciona el sensor BME688
* `SHT40` selecciona el sensor SHT40
* `SCD40` selecciona el sensor SCD40 
* `SGP41` selecciona el sensor SGP41
* `SPS30` selecciona el sensor SPS30
### Métodos
* `temperatura()` devuelve el valor de temperatura en grados centígrados (ºC)
* `humedad()` devuelve el valor de humedad relativa (%)
* `presion()` devuelve el valor de presion medido en pascales (Pa)
* `resistencia_gas()` devuelve el valor de la resistencia del gas en ohms
* `altitud()` devuelve el valor de altitud estimado en metros (m)
* `CO2()` devuelve el valor de concentración de CO2 en particulas por millon (ppm)
* `Voc()` devuelve el valor del indice de VOC
* `Nox()` devuelve el valor del indice de Nox
* `mc1p0()` devuelve el valor de la concentración de masa de particulas de menos de 1 micrómetro (ug/cm3)
* `mc2p5()` devuelve el valor de la concentración de masa de particulas de menos de 2.5 micrómetro (ug/cm3)
* `mc4p0()` devuelve el valor de la concentración de masa de particulas de menos de 4 micrómetro (ug/cm3)
* `mc10p0()` devuelve el valor de la concentración de masa de particulas de menos de 10 micrómetro (ug/cm3)
* `nc1p0()` devuelve el valor de la concentración númerica de particulas de menos de 1 micrómetro (unidades/cm3)
* `nc2p5()` devuelve el valor de la concentración númerica de particulas de menos de 2.5 micrómetro (unidades/cm3)
* `nc4p0()` devuelve el valor de la concentración númerica de particulas de menos de 4 micrómetro (unidades/cm3)
* `nc10p0()` devuelve el valor de la concentración númerica de particulas de menos de 10 micrómetro (unidades/cm3)
* `tipicalSize()` devuelve el tamaño tipico de las particulas medidas por el sensor (um)