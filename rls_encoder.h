#ifndef RLS_ENCODER_H
#define RLS_ENCODER_H

#include <Arduino.h>
#include <SPI.h>

#define ENCODER_RESOLUTION_17 131072
#define ENCODER_RESOLUTION_18 262144
#define ENCODER_RESOLUTION_19 524288

class RLS_Encoder {
public:
    explicit RLS_Encoder(uint8_t cs_pin);       // Constructor: chip select pin
    void begin(uint32_t resolution);            // Initialize encoder (call in setup)
    float readAngle();                          // Read current angle in degrees
    uint16_t readMultiturn() const;             // Read multiturn counter (16-bit)
    bool crcValid() const;                      // Check if last CRC was valid

private:
    uint8_t _cs_pin;
    uint32_t _resolution = 0;
    bool _crc_valid = false;

    uint8_t crcSPI64(uint64_t input) const;     // CRC calculation helper
};

#endif // RLS_ENCODER_H
