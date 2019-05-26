#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);   

void setup() {  
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (BTSerial.available()){
    char data = BTSerial.read();
    Serial.write(data);
    
    if(data == '0'){
      digitalWrite(13, HIGH);
    }else if(data == '1'){
      digitalWrite(13, LOW);
    }
  }
    
  if (Serial.available())
    BTSerial.write(Serial.read());
}
