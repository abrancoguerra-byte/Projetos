#include <Arduino.h>

const int pinX = A0;
const int pinY = A1;
const int pinSW = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pinSW, INPUT_PULLUP); // Ativa resistor interno para o botão
}

void loop() {
  int xValue = analogRead(pinX);
  int yValue = analogRead(pinY);
  int swValue = digitalRead(pinSW);

  Serial.print("X: "); Serial.print(xValue);
  Serial.print(" | Y: "); Serial.print(yValue);
  Serial.print(" | Botao: "); Serial.println(swValue == LOW ? "PRESSIONADO" : "-");

  delay(100); // Para não inundar o Monitor Serial no Arzopa
}