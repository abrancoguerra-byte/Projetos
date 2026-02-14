#include <Arduino.h>

// Definição dos pinos conforme a ligação física
const int RED = 10;
const int YELLOW = 11;
const int GREEN = 12;

void setup() {
  // Configura todos como saída
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  // Inicia o Serial para monitorar no seu Mac
  Serial.begin(9600);
  Serial.println("--- Teste de Semaforo Iniciado ---");
}

void loop() {
  // VERDE: Siga por 5 segundos
  Serial.println("Sinal VERDE - SIGA");
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  delay(10000);

  // AMARELO: Atenção por 2 segundos
  Serial.println("Sinal AMARELO - ATENCAO");
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
  delay(2000);

  // VERMELHO: Pare por 5 segundos
  Serial.println("Sinal VERMELHO - PARE");
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
  delay(10000);
}