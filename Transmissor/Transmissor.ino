#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>



RF24 antena(9,10);
const byte ENDRECO[6] = "111222";
const int ButtonA = 2;//UP
const int ButtonB = 3;//RIGHT
const int ButtonC = 4;//DOWN
const int ButtonD = 5;//LEFT
const int ButtonE = 6;//E
const int ButtonF = 7;//F
const int ButtonSelect = 8;//Select
const byte Analog_X = 0;
const byte Analog_Y = 1;

int vrButtonArray[] = {0,0,0,0};

void setup() {
Serial.begin(9600);
antena.begin();
antena.openReadingPipe(0,ENDRECO);
antena.setPALevel(RF24_PA_HIGH);
antena.startListening();

pinMode(ButtonA, INPUT);
pinMode(ButtonB, INPUT);
pinMode(ButtonC, INPUT);
pinMode(ButtonD, INPUT);

}

void loop() {
  lerButtons();  
  antena.write(agenteButton(),agenteButton());
}

int agenteButton(){
  if((vrButtonArray[0]==1)&&(vrButtonArray[1]==0)&&(vrButtonArray[2]==0)&&(vrButtonArray[3]==0))return "1";
 else if((vrButtonArray[0]==0)&&(vrButtonArray[1]==1)&&(vrButtonArray[2]==0)&&(vrButtonArray[3]==0))return "2";
  else if((vrButtonArray[0]==0)&&(vrButtonArray[1]==0)&&(vrButtonArray[2]==2)&&(vrButtonArray[3]==0))return "3";
  else if((vrButtonArray[0]==0)&&(vrButtonArray[1]==0)&&(vrButtonArray[2]==0)&&(vrButtonArray[3]==3))return "4";
  else return "99";
}

 
void lerButtons(){
  vrButtonArray[0] = digitalRead (ButtonA);
  vrButtonArray[1] = digitalRead (ButtonB);
  vrButtonArray[2] = digitalRead (ButtonC);
  vrButtonArray[3] = digitalRead (ButtonD);
}
