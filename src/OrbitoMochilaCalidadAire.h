#ifndef OrbitoMochilaCalidadAire_h
#define OrbitoMochilaCalidadAire_h

#include <Orbito.h>
#include "I2CInstructions.h"

class OrbitoMochilaCalidadAire
{

    public:
        
        OrbitoMochilaCalidadAire();
        void begin();

        struct BME688
        {

            float temperatura();
            float humedad();
            float presion();
            uint32_t resistencia_gas();
            float altitud();

        }BME688;

        struct SHT40
        {

            float temperatura();
            float humedad();

        }SHT40;

        struct SCD40
        {

            uint16_t CO2();
            float temperatura();
            float humedad();


        }SCD40;

        struct SGP41
        {

            uint16_t Voc();
            uint16_t Nox();

        }SGP41;

        struct SPS30
        {

            struct ConcentracionMasa{

                float mc1p0();
                float mc2p5();
                float mc4p0();
                float mc10p0();

            }ConcentracionMasa;
            struct ConcentracionParticulas{

                float nc1p0();
                float nc2p5();
                float nc4p0();
                float nc10p0();
                
            }ConcentracionParticulas;

            float tipicalSize();

        }SPS30;

    private:

        friend struct BME688;
        friend struct SHT40;
        friend struct SCD40;
        friend struct SGP41;
        friend struct SPS30;
        class I2CInstructions I2CInstructions;

        union _floatConversion{
            float float_value;
            uint8_t float_bytes[4];
        };

        union _uint32_tConversion{
            uint32_t uint32_t_value;
            uint8_t uint8_t_bytes[4];
        };

        union _uint16_tConversion{
            uint16_t uint16_t_value;
            uint8_t bytes[2];
        };
        
};

#endif