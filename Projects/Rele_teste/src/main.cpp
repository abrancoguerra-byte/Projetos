#include <Arduino.h>

// Definimos o pino 7 para o relé
const int pinoRele = 7;

void setup() {
  // Configura o pino como saída
  pinMode(pinoRele, OUTPUT);
  
  // Garante que ele comece desligado
  // (Lembrando: na maioria desses módulos, HIGH = Desligado / LOW = Ligado)
  digitalWrite(pinoRele, HIGH); 
}

void loop() {
  // LIGA o relé
  digitalWrite(pinoRele, LOW);
  delay(1000); // Espera 1 segundo
  
  // DESLIGA o relé
  digitalWrite(pinoRele, HIGH);
  delay(1000); // Espera 1 segundo
}