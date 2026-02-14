#include <Arduino.h>

// Definição dos pinos conforme sua montagem
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Motor de Passo - Teste Direto");
}

// Sequência de ativação das bobinas para o motor girar
void loop() {
  // Passo 1
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW); digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  delay(5); // Ajuste este delay para mudar a velocidade
  
  // Passo 2
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH); digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  delay(5);
  
  // Passo 3
  digitalWrite(in1, LOW); digitalWrite(in2, LOW); digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  delay(5);
  
  // Passo 4
  digitalWrite(in1, LOW); digitalWrite(in2, LOW); digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  delay(5);
}