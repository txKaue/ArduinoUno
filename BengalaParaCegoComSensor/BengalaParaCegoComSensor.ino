#include <NewPing.h>

// Definindo os pinos para o sensor ultrassônico e o buzzer
const int trig1 = 8; // Pino do trigger (pino de saída) do sensor ultrassônico
const int echo1 = 9; // Pino do echo (pino de entrada) do sensor ultrassônico

const int trig2 = 10;
const int echo2 = 11;


const int buzzerPin = 12; // Pino do buzzer

// Definindo a distância limite em centímetros
const int limiteDistancia = 100; // Distância limite em cm

// Definindo a instância do sensor ultrassônico
NewPing sonar(trig1, echo1);
NewPing sonar2(trig2, echo2);

void setup() {
  Serial.begin(9600); 
  pinMode(buzzerPin, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  int distancia = medirDistancia();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  int distancia2 = medirDistancia2();
  Serial.print("Distancia2: ");
  Serial.print(distancia2);
  Serial.println(" cm");

  if (distancia < limiteDistancia || distancia2 < limiteDistancia) {
    // Se a distância for menor que o limite, aciona o buzzer
    acionarBuzzer();
  } else {
    // Se a distância for maior ou igual ao limite, desliga o buzzer
    desligarBuzzer();
  }

  delay(1000); // Delay pequeno para evitar leituras muito rápidas
}

// Função para medir a distância com o sensor ultrassônico
int medirDistancia() {
  unsigned int distancia = sonar.ping_cm(); // Mede a distância em centímetros
  
  return distancia;
}

int medirDistancia2() {
  unsigned int distancia2 = sonar2.ping_cm(); // Mede a distância em centímetros
  
  return distancia2;
}

// Função para acionar o buzzer
void acionarBuzzer() {
  digitalWrite(buzzerPin, HIGH); // Liga o buzzer
  Serial.println("Perigo! Objeto muito próximo!");
}

// Função para desligar o buzzer
void desligarBuzzer() {
  digitalWrite(buzzerPin, LOW); // Desliga o buzzer
}