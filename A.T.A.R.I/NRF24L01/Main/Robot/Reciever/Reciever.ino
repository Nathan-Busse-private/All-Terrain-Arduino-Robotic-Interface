#include <SPI.h>      //the communication interface with the modem
#include "RF24.h"     //the library which helps us to control the radio modem (nRF24L)

//Motor A
const int RightMotorForward = 2;    // IN1
const int RightMotorBackward = 4;   // IN2

//Motor B
const int LeftMotorForward = 7;     // IN3
const int LeftMotorBackward = 8;    // IN4


int data[2];

RF24 radio(10, 9); //10 and 9 are a digital pin numbers to which signals CE and CSN are connected

const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem,that will receive data from the Arduino


void setup() {
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);

  radio.begin();                    //it activates the modem
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data
  radio.startListening();           //enable receiving data via modem
}

void loop() {
  if (radio.available()) {
    radio.read(data, sizeof(data));

    //data X
    if (data[0] > 550) {
      digitalWrite(RightMotorForward, HIGH);
      digitalWrite(RightMotorBackward, LOW);
      digitalWrite(LeftMotorForward, HIGH);
      digitalWrite(LeftMotorBackward, LOW);
      Serial.println("FORWARD");
    }

    //data X
    if (data[0] < 400) {
      digitalWrite(RightMotorForward, LOW);
      digitalWrite(RightMotorBackward, HIGH);
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorBackward, HIGH);
            //delay(3000);

      Serial.println("BACKWARD");
    }

    //data Y
    if (data[1] > 550 ) {
      digitalWrite(RightMotorForward, LOW);
      digitalWrite(RightMotorBackward, HIGH);
      digitalWrite(LeftMotorForward, HIGH);
      digitalWrite(LeftMotorBackward, LOW);
        //    delay(3000);

      Serial.println("TURN RIGHT");
    }

    //data Y
    if (data[1] < 400 ) {
      digitalWrite(RightMotorForward, HIGH);
      digitalWrite(RightMotorBackward, LOW);
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorBackward, HIGH);
         //   delay(3000);

      Serial.println("TURN LEFT");
    }

    if (data[0] < 550 && data[0] > 400 && data[1] < 550 && data[1] > 400) {
      digitalWrite(RightMotorForward, LOW);
      digitalWrite(RightMotorBackward, LOW);
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorBackward, LOW);
         //   delay(3000);

      Serial.println("STOP");
    }

  }
}
