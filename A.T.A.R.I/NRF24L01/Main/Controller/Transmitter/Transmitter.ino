#include <SPI.h>  //the communication interface with the modem
#include "RF24.h" //the library which helps us to control the radio modem

//define the data pins
int joyX = A0;
int joyY = A3;

//define variable values
int dataX;
int dataY;

int data[2];

RF24 radio(7,8); //10 and 9 are a digital pin numbers to which signals CE and CSN are connected
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem, that will receive data from Arduino


void setup(void){
  Serial.begin(9600);
  radio.begin();                      //it activates the modem
  radio.openWritingPipe(pipe);        //sets the address of the receiver to which the program will send data
}

void loop(){
  //Send signal data
  dataX = analogRead(joyX);
  dataY = analogRead(joyY);
  
  data[1] = dataX;
  data[0] = dataY;

  Serial.print("Data X:"); Serial.println(dataX);
  Serial.print("Data Y:"); Serial.println(dataY);
  radio.write(data, sizeof(data));
  
}
