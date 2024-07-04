#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;
const int led = 10;
bool statusLed = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  if (!driver.init()){
    Serial.println("Iniciação falhou");
  }
}

void loop() {
  uint8_t buf[10];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)){
    int i;
    String cleanInput = String((char*)buf).substring(0,10);
    
    if(cleanInput == "muda_led"){
      if (statusLed == 0){
        digitalWrite(led, HIGH);
        statusLed = 1;
        Serial.println("Led status:");
        Serial.print(statusLed);
      }
      else {
        digitalWrite(led, LOW);
        statusLed = 0;
        Serial.println("Led status:");
        Serial.print(statusLed);
      }
    }
  }
}









