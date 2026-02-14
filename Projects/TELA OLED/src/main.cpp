#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;);
  }
  display.clearDisplay();
}

void desenhaOlho(bool aberto) {
  display.clearDisplay();
  
  if (aberto) {
    // Desenha o contorno do olho (Elipse)
    display.drawEllipse(64, 32, 40, 20, SSD1306_WHITE);
    // Desenha a pupila (Círculo preenchido)
    display.fillCircle(64, 32, 10, SSD1306_WHITE);
  } else {
    // Desenha apenas uma linha horizontal (Olho fechado)
    display.drawLine(24, 32, 104, 32, SSD1306_WHITE);
  }
  
  display.display();
}

void loop() {
  desenhaOlho(true);  // Olho aberto
  delay(2000);        // Espera 2 segundos
  
  desenhaOlho(false); // Olho fechado (pisca)
  delay(200);         // Pisca rápido
}