#include <Arduino.h>
#include <Stepper.h>

const int passosPorVolta = 2048;
Stepper meuMotor(passosPorVolta, 8, 10, 9, 11); // Ordem correta para o ULN2003

int velocidade = 12; // Velocidade inicial padrão

void setup() {
  meuMotor.setSpeed(velocidade);
  Serial.begin(9600);
  Serial.println("--- Controle do Motor via Mac ---");
  Serial.println("Comandos: [H] Horario, [A] Anti-horario, [+] Aumenta Vel, [-] Diminui Vel");
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Lê o que você digitou no Mac

    if (comando == 'H' || comando == 'h') {
      Serial.println("Girando Horario...");
      meuMotor.step(512); // Gira 90 graus
    } 
    else if (comando == 'A' || comando == 'a') {
      Serial.println("Girando Anti-horario...");
      meuMotor.step(-512);
    } 
    else if (comando == '+') {
      velocidade = min(velocidade + 1, 20); // Limite maximo seguro
      meuMotor.setSpeed(velocidade);
      Serial.print("Velocidade aumentada para: "); Serial.println(velocidade);
    } 
    else if (comando == '-') {
      velocidade = max(velocidade - 1, 1); // Limite minimo
      meuMotor.setSpeed(velocidade);
      Serial.print("Velocidade diminuida para: "); Serial.println(velocidade);
    }
  }
}