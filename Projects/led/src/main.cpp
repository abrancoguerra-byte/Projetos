#include <Arduino.h>
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

// Quadro 1: Coração Grande
const uint32_t heart_big[] = {
    0x3184a444,
    0x44042081,
    0x100a0040
};

// Quadro 2: Coração Pequeno (para dar o efeito de contração)
const uint32_t heart_small[] = {
    0x00000000,
    0x0a004000,
    0x00000000
};

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  // Mostra o coração grande
  matrix.loadFrame(heart_big);
  delay(500); // Fica cheio por meio segundo

  // Mostra o coração pequeno (contração)
  matrix.loadFrame(heart_small);
  delay(300); // Fica pequeno por 0.3 segundos
}