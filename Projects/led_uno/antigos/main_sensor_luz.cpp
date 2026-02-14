#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuração do LCD I2C (Endereço 0x27 é o mais comum)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Definição dos Pinos
const int pinoLDR = A0;    // Sensor de luz no pino analógico A0
const int pinoBuzzer = 8;  // Buzzer ativo no pino digital 8

// Ajuste este valor conforme a luz do seu escritório
// Se o valor lido for MAIOR que este, o alarme toca (Escuridão)
const int LIMITE_ESCURIDAO = 600; 

void setup() {
  // Inicia a comunicação com o terminal do Mac Mini M2
  Serial.begin(9600); 
  
  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  
  // Configura o pino do buzzer como saída
  pinMode(pinoBuzzer, OUTPUT);
  
  Serial.println("--- Sistema de Alarme de Escuridao Iniciado ---");
}

void loop() {
  // Lê o valor do LDR (0 a 1023)
  int valorLuz = analogRead(pinoLDR);

  // 1. SAÍDA NO LCD (Visível na bancada)
  lcd.setCursor(0, 0);
  lcd.print("Luz Atual: ");
  lcd.print(valorLuz);
  lcd.print("   "); // Limpa caracteres extras

  // 2. SAÍDA NO TERMINAL (Monitor serial no Mac)
  Serial.print("Leitura LDR: ");
  Serial.println(valorLuz);

  // 3. LÓGICA DO ALARME (Invertida para detectar escuridão)
  if (valorLuz > LIMITE_ESCURIDAO) {
    // Alerta no terminal do escritório
    Serial.println("!!! ALERTA: AMBIENTE ESCURO !!!");
    
    lcd.setCursor(0, 1);
    lcd.print("ESTA ESCURO!    ");

    // Som intermitente para o buzzer ativo
    digitalWrite(pinoBuzzer, HIGH);
    delay(100);
    digitalWrite(pinoBuzzer, LOW);
    delay(100);
  } else {
    // Status normal
    lcd.setCursor(0, 1);
    lcd.print("AMBIENTE CLARO  ");
    digitalWrite(pinoBuzzer, LOW);
  }

  // Pequena pausa antes da próxima leitura para não sobrecarregar o terminal
  delay(500); 
}