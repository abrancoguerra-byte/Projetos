#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configurações do Display OLED
#define LARGURA_TELA 128
#define ALTURA_TELA 64
Adafruit_SSD1306 display(LARGURA_TELA, ALTURA_TELA, &Wire, -1);

// Pinos do Joystick
const int PINO_JOY_Y = A1; 

// Variáveis do Jogo
int bolaX = 64, bolaY = 32;
int dirX = 3, dirY = 3;
const int raioBola = 2;

int raquetePos = 20;
const int raqueteLargura = 3;
const int raqueteAltura = 15;

int pontos = 0;
int vidas = 3;

void mostrarStatus() {
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(70, 0);
    display.print("P:"); display.print(pontos);
    display.setCursor(100, 0);
    display.print("V:"); display.print(vidas);
}

void setup() {
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        for(;;); // Trava se o display não for encontrado
    }
    display.clearDisplay();
    pinMode(PINO_JOY_Y, INPUT);
}

void loop() {
    if (vidas <= 0) {
        display.clearDisplay();
        display.setTextSize(2);
        display.setCursor(10, 20);
        display.print("GAME OVER");
        display.display();
        delay(3000);
        vidas = 3; pontos = 0; bolaX = 64; bolaY = 32;
        return;
    }

    // Leitura do Joystick (Eixo Y controla a raquete)
    int leitura = analogRead(PINO_JOY_Y);
    // Invertemos o mapeamento se o movimento estiver trocado
    raquetePos = map(leitura, 0, 1023, 0, ALTURA_TELA - raqueteAltura);

    // Movimentação da Bola
    bolaX += dirX;
    bolaY += dirY;

    // Colisão Teto e Chão
    if (bolaY <= 0 || bolaY >= ALTURA_TELA - raioBola) dirY *= -1;

    // Colisão Parede Direita
    if (bolaX >= LARGURA_TELA - raioBola) dirX *= -1;

    // Colisão com a Raquete (Lado Esquerdo)
    if (bolaX <= raqueteLargura) {
        if (bolaY >= raquetePos && bolaY <= raquetePos + raqueteAltura) {
            dirX *= -1;
            pontos += 5;
            // Aumenta a velocidade levemente a cada acerto
            if(dirX < 7) dirX++; 
        } else {
            vidas--;
            bolaX = 64; bolaY = 32; // Reseta posição
            dirX = 3; // Reseta velocidade
            delay(500);
        }
    }

    // Desenho
    display.clearDisplay();
    
    // Desenha Bola
    display.fillCircle(bolaX, bolaY, raioBola, SSD1306_WHITE);
    
    // Desenha Raquete
    display.fillRect(0, raquetePos, raqueteLargura, raqueteAltura, SSD1306_WHITE);
    
    mostrarStatus();
    display.display();
    delay(10); // Controla a fluidez do jogo
}