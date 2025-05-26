#include <Arduino.h>
#include "rls_encoder.h"

// Create encoder object
RLS_Encoder encoder(10); // CS pin 10 for encoder SPI

float angle_value = 0.0f;
float angle_value_init = 0.0f;

void setup() 
{
  Serial.begin(9600);

  encoder.begin(ENCODER_RESOLUTION_17); // Initialize encoder SPI and pins

  // Read initial angle to use as reference
  angle_value_init = encoder.readAngle();
}

void loop() 
{
  angle_value = encoder.readAngle() - angle_value_init;
  Serial.println(angle_value, 1);
  delay(500);
}