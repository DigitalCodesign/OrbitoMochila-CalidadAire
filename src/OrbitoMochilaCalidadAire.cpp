#include "OrbitoMochilaCalidadAire.h"

/**
 * @brief Constructor de la clase OrbitoMochilaCalidadAire
 */
OrbitoMochilaCalidadAire::OrbitoMochilaCalidadAire(){

}

/**
 * @brief Esta funcion inicializa todos los sensores presentes en la mochila de calidad del aire
 */
void OrbitoMochilaCalidadAire::begin(){
    uint8_t payload[]{I2CInstructions::BAG_BEGIN};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 1);
}

/**
 * @brief Esta funcion obtiene el valor de la temperatura medido por el sensor BME688
 * @return Devuelve el valor de la temperatura en ºC en una variable tipo float
 */
float OrbitoMochilaCalidadAire::BME688::temperatura(){
    uint8_t payload[]{I2CInstructions::BME688_i2c_addr, I2CInstructions::BME688_read_temperature};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de la humedad relativa medido por el sensor BME688
 * @return Devuelve el valor de la humedad relativa en % en una variable tipo float
 */
float OrbitoMochilaCalidadAire::BME688::humedad(){
    uint8_t payload[]{I2CInstructions::BME688_i2c_addr, I2CInstructions::BME688_read_humidity};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de la presion medido por el sensor BME688
 * @return Devuelve el valor de la presion en pascales en una variable tipo float
 */
float OrbitoMochilaCalidadAire::BME688::presion(){
    uint8_t payload[]{I2CInstructions::BME688_i2c_addr, I2CInstructions::BME688_read_pression};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de la resistencia del gas medido por el sensor BME688
 * @return Devuelve el valor de la resistencia del gas en una variable tipo uint32_t
 */
uint32_t OrbitoMochilaCalidadAire::BME688::resistencia_gas(){
    uint8_t payload[]{I2CInstructions::BME688_i2c_addr, I2CInstructions::BME688_read_gas_resistance};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _uint32_tConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.uint8_t_bytes[0] = buffer[0];
        data.uint8_t_bytes[1] = buffer[1];
        data.uint8_t_bytes[2] = buffer[2];
        data.uint8_t_bytes[3] = buffer[3];
        return data.uint32_t_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de la altura aproximada calculado a traves del valor de presion medido por el sensor BME688
 * @return Devuelve el valor de la altura con respecto al mar en m en una variable tipo float
 */
float OrbitoMochilaCalidadAire::BME688::altitud(){
    uint8_t payload[]{I2CInstructions::BME688_i2c_addr, I2CInstructions::BME688_read_altitude};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de la temperatura medido por el sensor SHT40
 * @return Devuelve el valor de la temperatura en ºC en una variable tipo float
 */
float OrbitoMochilaCalidadAire::SHT40::temperatura(){
    uint8_t payload[]{I2CInstructions::SHT40_i2c_addr, I2CInstructions::SHT40_read_temperature};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de la humedad relativa medido por el sensor SHT40
 * @return Devuelve el valor de la humedad relativa en % en una variable tipo float
 */
float OrbitoMochilaCalidadAire::SHT40::humedad(){
    uint8_t payload[]{I2CInstructions::SHT40_i2c_addr, I2CInstructions::SHT40_read_humidity};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de particulas de CO2 en ppm medido por el sensor SCD40 
 * @return Devuelve el valor de particulas de CO2 en una variable tipo uint16_t
 */
uint16_t OrbitoMochilaCalidadAire::SCD40::CO2(){
    uint8_t payload[]{I2CInstructions::SCD40_i2c_addr, I2CInstructions::SCD40_read_CO2};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[2];
    delay(400);
    _uint16_tConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 2))
    {   
        data.bytes[0] = buffer[0];
        data.bytes[1] = buffer[1];
        return data.uint16_t_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de la temperatura medido por el sensor SCD40
 * @return Devuelve el valor de la temperatura en ºC en una variable tipo float
 */
float OrbitoMochilaCalidadAire::SCD40::temperatura(){
    uint8_t payload[]{I2CInstructions::SCD40_i2c_addr, I2CInstructions::SCD40_read_temperature};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion obtiene el valor de la humedad relativa medido por el sensor SCD40
 * @return Devuelve el valor de la humedad relativa en % en una variable tipo float
 */
float OrbitoMochilaCalidadAire::SCD40::humedad(){
    uint8_t payload[]{I2CInstructions::SCD40_i2c_addr, I2CInstructions::SCD40_read_humidity};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve el indice VOC medido por el sensor
 * @return Devuelve el valor de tipo uint16_t
 */
uint16_t OrbitoMochilaCalidadAire::SGP41::Voc(){
    uint8_t payload[]{I2CInstructions::SGP41_i2c_addr, I2CInstructions::SGP41_read_Voc};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _uint16_tConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 2))
    {   
        data.bytes[0] = buffer[0];
        data.bytes[1] = buffer[1];
        return data.uint16_t_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve el indice NOX medido por el sensor
 * @return Devuelve el valor de tipo uint16_t
 */
uint16_t OrbitoMochilaCalidadAire::SGP41::Nox(){
    uint8_t payload[]{I2CInstructions::SGP41_i2c_addr, I2CInstructions::SGP41_read_Nox};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 2);
    uint8_t buffer[4];
    delay(400);
    _uint16_tConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 2))
    {   
        data.bytes[0] = buffer[0];
        data.bytes[1] = buffer[1];
        return data.uint16_t_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve la concentracion de particulas de menos de 1 micrometro en ug/m3
 * @return Devuelve la concentracion de masa de particulas en un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::ConcentracionMasa::mc1p0(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_read_mc1p0};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve la concentracion de particulas de menos de 2.5 micrometros en ug/m3
 * @return Devuelve la concentracion de masa de particulas en un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::ConcentracionMasa::mc2p5(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_read_mc2p5};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve la concentracion de particulas de menos de 4 micrometros en ug/m3
 * @return Devuelve la concentracion de masa de particulas en un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::ConcentracionMasa::mc4p0(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_read_mc4p0};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve la concentracion de particulas de menos de 10 micrometros en ug/m3
 * @return Devuelve la concentracion de masa de particulas en un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::ConcentracionMasa::mc10p0(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_read_mc10p0};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve la concentracion numerica de particulas de menos de 1 micrometro en cantidad de particulas/cm3
 * @return Devuelve la concentracion numerica de particulas en un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::ConcentracionParticulas::nc1p0(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_read_nc1p0};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve la concentracion numerica de particulas de menos de 2.5 micrometros en en cantidad de particulas/cm3
 * @return Devuelve la concentracion numerica de particulas en un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::ConcentracionParticulas::nc2p5(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_read_nc2p5};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve la concentracion numerica de particulas de menos de 4 micrometros en cantidad de particulas/cm3
 * @return Devuelve la concentracion numerica de particulas en un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::ConcentracionParticulas::nc4p0(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_read_nc4p0};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve la concentracion numerica de particulas de menos de 10 micrometros en cantidad de particulas/cm3
 * @return Devuelve la concentracion numerica de particulas en un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::ConcentracionParticulas::nc10p0(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_read_nc10p0};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}

/**
 * @brief Esta funcion devuelve el tamaño tipico de particulas medido por el sensor
 * @return Devuelve un valor de tipo float
 */
float OrbitoMochilaCalidadAire::SPS30::tipicalSize(){
    uint8_t payload[]{I2CInstructions::SPS30_i2c_addr, I2CInstructions::SPS30_typical_size};
    Orbito._ioDriver._sendPacket(I2CInstructions::BAG_ID, payload, 4);
    uint8_t buffer[4];
    delay(400);
    _floatConversion data;
    if (Orbito._ioDriver._readResponse(buffer, 4))
    {   
        data.float_bytes[0] = buffer[0];
        data.float_bytes[1] = buffer[1];
        data.float_bytes[2] = buffer[2];
        data.float_bytes[3] = buffer[3];
        return data.float_value;
    }
    return -1;
}