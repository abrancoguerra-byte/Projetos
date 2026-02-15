#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pinos do Joystick
const int pinX = A0;
const int pinY = A1;

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;);
  }
  display.clearDisplay();
}

void loop() {
  // Lê os valores analógicos (0 a 1023)
  int leituraX = analogRead(pinX);
  int leituraY = analogRead(pinY);

  // Mapeia os valores para o tamanho da tela
  // Invertemos o mapeamento se o movimento estiver trocado
  int x = map(leituraX, 0, 1023, 0, SCREEN_WIDTH);
  int y = map(leituraY, 0, 1023, 0, SCREEN_HEIGHT);

  display.clearDisplay(); // Limpa a tela para o próximo frame
  
  // Desenha a bola (Círculo preenchido)
  // Parâmetros: x, y, raio, cor
  display.fillCircle(x, y, 5, SSD1306_WHITE); 
  
  display.display(); // Atualiza a tela
  delay(10); // Ajusta a sensibilidade/velocidade
}