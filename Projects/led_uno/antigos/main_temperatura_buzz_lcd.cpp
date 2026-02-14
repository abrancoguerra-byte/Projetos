#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int pinoNTC = A0;
const int pinoBuzzer = 8; 
const float LIMITE_TEMP = 23.0; 

void setup() {
  Serial.begin(9600); // Inicia a comunicação com o terminal do seu Mac
  lcd.init();
  lcd.backlight();
  pinMode(pinoBuzzer, OUTPUT);
  
  Serial.println("--- Sistema de Monitoramento Iniciado ---");
}

void loop() {
  int leitura = analogRead(pinoNTC);
  
  // Cálculo da resistência e temperatura com os ajustes que fizemos
  float resistencia = 10000.0 / (1023.0 / (float)leitura - 1.0);
  float temperatura = 1 / (log(resistencia / 10000.0) / 3950.0 + 1 / 298.15) - 273.15;
  float tempCalibrada = temperatura - 0; // Seu offset de calibração

  // 1. MOSTRAR NO LCD (Foco no valor da temperatura)
  lcd.setCursor(0, 0);
  lcd.print("TEMP. ATUAL:");
  lcd.setCursor(0, 1);
  lcd.print(tempCalibrada, 2); // Mostra com 2 casas decimais para precisão
  lcd.print(" Celsius    ");

  // 2. MOSTRAR NO TERMINAL (Foco no alerta de segurança)
  if (tempCalibrada > LIMITE_TEMP) {
    // Esta mensagem aparecerá no VS Code no seu Mac
    Serial.print("!!! ALERTA DE CALOR !!! -> ");
    Serial.print(tempCalibrada);
    Serial.println(" C");

    // Aciona o buzzer na bancada
    digitalWrite(pinoBuzzer, HIGH);
    delay(100);
    digitalWrite(pinoBuzzer, LOW);
  } else {
    // Mensagem de status normal no terminal
    Serial.print("Status: OK | Temp: ");
    Serial.println(tempCalibrada);
    digitalWrite(pinoBuzzer, LOW);
  }

  delay(1000); // Atualiza a cada 1 segundo
}