#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"




RF24 radio(9,10);
const int pipe = 0xE8E8F0F0E1LL;
int dados;

void setup() {
Serial.begin(57600);
radio.begin();
radio.setDataRate( RF24_250KBPS );
radio.setPALevel(RF24_PA_LOW);
radio.openReadingPipe(1,pipe);
radio.startListening();
radio.setRetries(15,15);
radio.printDetails();
}

void loop() {
  if(radio.available()){
     bool ok = radio.read(&dados,dados);
     if(ok){
      switch(dados){
      case 5:
      Serial.println("F");
      break;
     }} else {
      Serial.println("Erro");  
     }
     
       
   }else{Serial.println(dados);} 
   delay(100);
  }

