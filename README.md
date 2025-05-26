
# RLS_Encoder Arduino Library

An Arduino library for interfacing with **RLS absolute magnetic encoders** via **SPI only**.  
This library allows reading absolute angular position and multiturn data, with built-in **CRC-8 validation** for data integrity.

---

## 📦 Features

- SPI communication (only)
- Reads 18-bit absolute position
- Reads 16-bit multiturn counter
- CRC-8 (polynomial 0x97) error checking
- Simple and efficient interface

---

## 🔧 Installation

1. Download or clone this repository into your Arduino `libraries` folder.
2. Include the library in your sketch:

```cpp
#include "rls_encoder.h"
```

---

## 🖥️ Dependencies

- Arduino SPI library (included by default)

---

## ⚙️ Usage

### Initialization

Create an encoder instance with the Chip Select (CS) pin number:

```cpp
RLS_Encoder encoder(10); // CS connected to pin 10

void setup() {
  encoder.begin(ENCODER_RESOLUTION_xx);
}
```

---

## 📘 Function Reference

### `void begin(uint32_t resolution)`

Initializes the SPI interface and sets up the chip select pin with resolution parameter.

### `float readAngle()`

Reads the xx-bit absolute angular position from the encoder.  
Returns the angle in **degrees** as a float from `0.0` to `360.0`.  
If the CRC or status check fails, it returns `-1.0f`.

### `uint16_t readMultiturn()`

Reads a 16-bit **multiturn counter** value from the encoder.  
This value is not validated by CRC, and represents the number of full revolutions detected by the encoder.

### `bool crcValid() const`

Returns the result of the **last CRC check** performed in `readAngle()`.  
Returns `true` if the data was valid, `false` otherwise.

---

## 🧮 Resolution

The angular data is xx-bit (2^xx steps per revolution):

```cpp
#define ENCODER_RESOLUTION_17 131072
#define ENCODER_RESOLUTION_18 262144
#define ENCODER_RESOLUTION_19 524288
```

---

## 💡 Example

```cpp
#include "rls_encoder.h"

RLS_Encoder encoder(10);

void setup() {
  Serial.begin(9600);
  encoder.begin();
}

void loop() {
  float angle = encoder.readAngle();
  if (angle >= 0.0f) {
    Serial.print("Angle: ");
    Serial.println(angle);
  } else {
    Serial.println("Read error (invalid CRC or status bit)");
  }

  uint16_t turns = encoder.readMultiturn();
  Serial.print("Multiturn: ");
  Serial.println(turns);

  delay(100);
}
```

---

## ⚠️ Notes

- **Only SPI communication is supported.**
- Make sure to connect **MOSI, MISO, SCK**, and **CS** to your RLS encoder.
- Timing and delays may need tuning depending on your hardware.

---

## 📄 License

MIT License

---

## 👨‍💻 Author

Developed by TESSON-MAKER

---