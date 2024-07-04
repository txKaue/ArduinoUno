#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;
const int botao = 2;
int estadoBotao = 0;

void setup() {
  
  pinMode(botao, INPUT);

  Serial.begin(9600);
  if (!driver.init()){
    Serial.println("Iniciação falhou");
  }

}

void loop() {
  estadoBotao = digitalRead(botao);
  Serial.println(estadoBotao);
  if (estadoBotao == HIGH){
    Serial.println("Botão apertado");
    const char *msg = "muda_led";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
  }

  delay(100);
}

