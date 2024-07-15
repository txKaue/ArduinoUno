#include <Servo.h>

Servo eixo1;
Servo eixo2;
Servo eixo3;
Servo eixo4;

void setup() {
  
  	eixo1.attach(7);
  	eixo2.attach(8);
    eixo3.attach(9); 
    eixo4.attach(10); 
  	
  	eixo1.write(0); // PONTO 0
  	eixo2.write(0);
  	eixo3.write(0);
    eixo4.write(0);
  
  	pinMode(2, INPUT_PULLUP);
  	pinMode(13, OUTPUT);
  	pinMode(12, OUTPUT);
  
    Serial.begin(9600);
}

void loop(){

  if (digitalRead(2) == LOW) {

    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
                                                                                                                                                                                                                          
	  Movimento1();
    Movimento2();
    Movimento3();
    Movimento4();
    
    digitalWrite(13, HIGH);
  }
	
  else{
     digitalWrite(12, LOW);
     digitalWrite(13, HIGH);
     eixo1.write(90);
     eixo2.write(65); // 0 certo
     eixo3.write(35);
     eixo4.write(130); // 0 certo
  };

  delay(100);

}



