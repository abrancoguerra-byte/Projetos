
#include <Arduino.h> // Esta é a declaração da biblioteca base
// Mapeamento dos pinos para os segmentos (a, b, c, d, e, f, g)
const int segmentos[7] = {2, 3, 4, 5, 6, 7, 8};

// Matriz com os números de 0 a 9 para ANODO COMUM
// 0 = Aceso, 1 = Apagado
byte numeros[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
    digitalWrite(segmentos[i], HIGH); // Garante que comece tudo apagado
  }
}

void mostrarNumero(int n) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], numeros[n][i]);
  }
}

void loop() {
  // Contagem regressiva de 9 a 0
  for (int i = 9; i >= 0; i--) {
    mostrarNumero(i);
    delay(1000); // Espera 1 segundo
  }
  
  // Pisca o zero ao final
  delay(500);
  for(int j=0; j<3; j++){
    mostrarNumero(0);
    delay(200);
    for(int i=0; i<7; i++) digitalWrite(segmentos[i], HIGH);
    delay(200);
  }
}