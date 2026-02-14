#include <Arduino.h> // Essencial para o PlatformIO no VS Code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int pinoNTC = A0;
const float OFFSET = 1.5; // <--- AJUSTE AQUI: Se marca 28 e está 22, subtraímos 6

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int leitura = analogRead(pinoNTC);
  
  // ... (cálculo da temperatura que você já tem) ...
  float temperaturaCalculada = (1.0 / (log((10000.0 / (1023.0 / (float)leitura - 1.0)) / 10000.0) / 3950.0 + 1.0 / 298.15)) - 273.15;

  // Aplica a correção
  float temperaturaFinal = temperaturaCalculada + OFFSET;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperaturaFinal, 1);
  lcd.write(223); 
  lcd.print("C  ");
  
  delay(1000);
}