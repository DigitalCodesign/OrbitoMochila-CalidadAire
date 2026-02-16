#ifndef I2CInstructions_h
#define I2CInstructions_h

class I2CInstructions{

    public:

        // BME688
        const static uint8_t BME688_i2c_addr = 0xBB;
        const static uint8_t BME688_read_temperature = 0x41;
        const static uint8_t BME688_read_humidity = 0x42;
        const static uint8_t BME688_read_pression = 0x43;
        const static uint8_t BME688_read_gas_resistance = 0x44;
        const static uint8_t BME688_read_altitude = 0x50;
        
        // SHT40
        const static uint8_t SHT40_i2c_addr = 0xB1;
        const static uint8_t SHT40_read_temperature = 0x41;
        const static uint8_t SHT40_read_humidity = 0x42;

        // SCD40
        const static uint8_t SCD40_i2c_addr = 0xB2;
        const static uint8_t SCD40_read_CO2 = 0x49;
        const static uint8_t SCD40_read_temperature = 0x41;
        const static uint8_t SCD40_read_humidity = 0x42;

        // SGP41
        const static uint8_t SGP41_i2c_addr = 0xB3;
        const static uint8_t SGP41_read_Voc = 0x45;
        const static uint8_t SGP41_read_Nox = 0x46;
        const static uint8_t SGP41_read_temperature = 0x41;
        const static uint8_t SGP41_read_humidity = 0x42;

        // SPS30
        const static uint8_t SPS30_i2c_addr = 0xB4;
        const static uint8_t SPS30_read_mc1p0 = 0x61;
        const static uint8_t SPS30_read_mc2p5 = 0x62;
        const static uint8_t SPS30_read_mc4p0 = 0x63;
        const static uint8_t SPS30_read_mc10p0 = 0x64;
        const static uint8_t SPS30_read_nc1p0 = 0x65;
        const static uint8_t SPS30_read_nc2p5 = 0x66;
        const static uint8_t SPS30_read_nc4p0 = 0x67;
        const static uint8_t SPS30_read_nc10p0 = 0x68;
        const static uint8_t SPS30_typical_size = 0x69;

        // Generic commands
        const static uint8_t BAG_ID = 0x51;
        const static uint8_t BAG_BEGIN = 0xA5;

    private:



};


#endif