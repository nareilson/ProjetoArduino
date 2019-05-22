#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"




RF24 radio(9,10);
const int pipe = 0xE8E8F0F0E1LL;
const int ButtonA = 2;//UP
const int ButtonB = 3;//RIGHT
const int ButtonC = 4;//DOWN
const int ButtonD = 5;//LEFT
const int ButtonE = 6;//E
const int ButtonF = 7;//F
const int ButtonSelect = 8;//Select
const byte Analog_X = 0;
const byte Analog_Y = 1;

int dados;

void setup() {
 Serial.begin(57600);
radio.begin();
radio.stopListening();
radio.setPALevel(RF24_PA_LOW);
radio.setDataRate( RF24_250KBPS );
radio.openWritingPipe(pipe);
radio.printDetails();

pinMode(ButtonA, INPUT_PULLUP);
pinMode(ButtonB, INPUT_PULLUP);
pinMode(ButtonC,INPUT_PULLUP);
pinMode(ButtonD, INPUT_PULLUP);

}

void loop() {
  if(digitalRead (ButtonA)==0){
    dados = 1;    
  } else if(digitalRead (ButtonB) == 0){
     dados = 2;
  } else if(digitalRead (ButtonC) ==0){
    dados = 3;
  } else if(digitalRead (ButtonD) == 0){
    dados = 4;
  } else{
   dados = 5;
  }
  bool ok = radio.write(&dados,dados);
  if(ok){
    Serial.println("Sucess");
  } else{Serial.println("FAIL");}
  Serial.println(dados);
  radio.printDetails();
  delay(100);
}
