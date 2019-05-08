#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>


RF24 antena(9,10);
const byte ENDRECO[6] = "111222";
int result = "";

void setup() {
Serial.begin(9600);
antena.begin();
antena.openReadingPipe(0,ENDRECO);
antena.setPALevel(RF24_PA_HIGH);
antena.startListening();
}

void loop() {
  if(antena.available()){
    antena.read(result,result);
    switch(result){
      case 1:
      //Acao1
      break;
      case 2:
      //Acao2
      break;
      case 3:
      //Acao3
      break;
      case 4:
      //Acao4
      break;
      default:
      //AcaoPadrao caso os casos aceima não sejam atendidos
      break;
    }   
   } else{Serial.print("Erro ao se comunicar");} 
  }

void Avancar(){
    
  }
void Recuar(){
    
  }
void Direita(){
    
  }
void Esquerda(){
    
  }

