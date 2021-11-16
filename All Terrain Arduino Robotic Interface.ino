/*     
  * This code was written for this project 
  * to work effectively with the
  * instructions provided and should
  * not be tampered with unless stated otherwise.
  
  * Follow the instructions in the README file included in the project's 
  * Github repository: https://github.com/Nathan-Busse/All-Terrain-Arduino-Robotic-Interface
  
  * Created by Nathan-Busse
  * 
  * Don't you love coding and Arduino?
  * Me too! ;)
  * 
  * All bugs will be repaired by me "Nathan-Busse" YOU can to.
  * Mention them in the Issues tab.
  * 
  */

//including the libraries
#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <LEDFader.h>

//Defining pins for RGB led
#define GREEN 13
#define BLUE 5
#define RED 4
#define delayTime 3
#define LED_NUM 3

LEDFader leds[LED_NUM] = {
LEDFader(4),
LEDFader(5),
LEDFader(13)
};


//Initializing pins for bluetooth Module
int bluetoothTx = 2; // bluetooth tx to 2 pin
int bluetoothRx = 3; // bluetooth rx to 3 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

//Steering Motor Pins  In my case.
int Enable1 = 6;

/* Swap pin values with your robot
 *  My steering for the robot is at the back and 
 *  the drive motors are at the front.
 */

int Motor1_Pin1 = 9;  
int Motor1_Pin2 = 10; 

// Drive Motor Pins  In my case  

/*Swap pin values with your robot
 *  My steering for the robot is at the back and 
 *  the drive motors are at the front.
 *  
 *  Excluding the enable pin
 */ 
int Motor2_Pin1 = 7; 
int Motor2_Pin2 = 8; 
int Enable2 = 11; 

//Front Light pins   
int front_light1 = A0;
int front_light2 = A1;
int front_light3 = A2;

//Back light pins
int back_light1 = A3;
int back_light2 = A4
;
int horn = 12;

char command ; //variable to store the data
int velocity = 0; //Variable to control the speed of motor

void setup() 
{       
  //Set the baud rate of serial communication and bluetooth module at same rate.
  Serial.begin(9600);  
  bluetooth.begin(9600);

  //Setting the L298N, LED and RGB LED pins as output pins.
  pinMode(Motor1_Pin1, OUTPUT);  
  pinMode(Motor1_Pin2, OUTPUT);
  pinMode(Enable1, OUTPUT);
  pinMode(Motor2_Pin1, OUTPUT);  
  pinMode(Motor2_Pin2, OUTPUT);
  pinMode(Enable2, OUTPUT); 
  pinMode(front_light1, OUTPUT);  
  pinMode(back_light1, OUTPUT);
  pinMode(front_light2, OUTPUT);  
  pinMode(back_light2, OUTPUT);
  pinMode(front_light3, OUTPUT);
  pinMode(horn, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);

/*
 * 


*/      

tone (12, 720, 100);
delay (100);
tone (12, 730, 100);
delay (100);
tone (12, 740, 100);
delay (100);
tone (12, 750, 100);
delay (100);
tone (12, 760, 100);
delay (100);
tone (12, 770, 100);
delay (100);
tone (12, 780, 100);
delay (100);
tone (12, 790, 100);
delay (100);
tone (12, 800, 100);
delay (100);
tone (12, 810, 100);
delay (100);
tone (12, 820, 100);
delay (100);
tone (12, 830, 100);
delay (100);
tone (12, 840, 100);
delay (100);
tone (12, 850, 100);
delay (100);
tone (12, 860, 100);
delay (100);
tone (12, 870, 100);
delay (100);
tone (12, 880, 100);
delay (100);
tone (12, 890, 100);
delay (100);
tone (12, 900, 100);
delay (100);
tone (12, 910, 100);
delay (100);
tone (12, 920, 100);
delay (100);
tone (12, 930, 100);
delay (100);
tone (12, 940, 100);
delay (100);
tone (12, 950, 100);
delay (100);
tone (12, 960, 100);
delay (100);
tone (12, 970, 100);
delay (100);
tone (12, 980, 100);
delay (100);
tone (12, 990, 100);
delay (100);
tone (12, 1000, 100);
delay (100);
tone (12, 1010, 100);
delay (100);
tone (12, 1020, 100);
delay (100);
tone (12, 1030, 100);
delay (100);
tone (12, 1040, 100);
delay (100);
tone (12, 1050, 100);
delay (100);
tone (12, 1060, 100);
delay (100);
tone (12, 1070, 100);
delay (100);
tone (12, 1080, 100);
delay (100);
tone (12, 1090, 100);
delay (100);
tone (12, 1100, 100);
delay (100);
tone (12, 1110, 100);
delay (100);
tone (12, 1120, 100);
delay (100);
tone (12, 1130, 100);
delay (100);
tone (12, 1140, 100);
delay (100);
tone (12, 1150, 100);
delay (100);
tone (12, 1160, 100);
delay (100);
tone (12, 1170, 100);
delay (100);
tone (12, 1180, 100);
delay (100);
tone (12, 1190, 100);
delay (100);
tone (12, 1200, 100);
delay (100);
tone(12,660,100);
      delay(150);
      tone(12,660,100);
      delay(300);
      tone(12,660,100);
      delay(300);
      tone(12,510,100);
      delay(100);
      tone(12,660,100);
      delay(300);
      tone(12,770,100);
      delay(550);
      tone(12,380,100);
      delay(575);
  
  //Setting the enable and RGB LED pins as HIGH.
  digitalWrite(Enable1, HIGH);
  digitalWrite(Enable2, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
}

void loop(){
  if(bluetooth.available() > 0){  //Checking if there is some data available or not
    command = bluetooth.read();   //Storing the data in the 'command' variable
    Serial.println(command);      //Printing it on the serial monitor
    
    //Change pin mode only if new command is different from previous.   
    switch(command){
    case 'F':  //Moving the Car Forward
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      break;
    case 'B':  //Moving the Car Backward
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      break;
    case 'L':  //Moving the Car Left
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, LOW);
      break;
    case 'R':   //Moving the Car Right
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);  
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, LOW);
      break;
    case 'S':   //Stop
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, LOW);
      break; 
    case 'I':  //Moving the Car Forward right
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);
      break; 
    case 'J':  //Moving the Car backward right
      digitalWrite(Motor1_Pin2, LOW);
      digitalWrite(Motor1_Pin1, HIGH);
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      break;        
    case 'G':  //Moving the Car Forward left
      digitalWrite(Motor2_Pin2, LOW);
      digitalWrite(Motor2_Pin1, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      break; 
    case 'H':  //Moving the Car backward left
      digitalWrite(Motor2_Pin1, LOW);
      digitalWrite(Motor2_Pin2, HIGH);
      digitalWrite(Motor1_Pin1, LOW);
      digitalWrite(Motor1_Pin2, HIGH);
      break;
    case 'W':  //Front light ON 
      analogWrite(front_light1, random(255, 255));
      
      analogWrite(front_light2, random(255, 255));
      
      analogWrite(front_light3, random(255,  255));
      
      break;
    case 'w':  //Front light OFF
      digitalWrite(front_light1, LOW);
      digitalWrite(front_light2, LOW);
      digitalWrite(front_light3, LOW);
      break;
    case 'U':  //Back light ON 
      digitalWrite(back_light1, HIGH);
      digitalWrite(back_light2, HIGH);
      break;
    case 'u':  //Back light OFF 
      digitalWrite(back_light1, LOW);
      digitalWrite(back_light2, LOW);
      break; 
    case 'V':  //Horn On
      tone(12,1000);
      
      
      break; 
    case 'v':  //Horn OFF 
       noTone(horn);
      break;   
    case 'x': //Turn ON Everything

    break;
    case 'X': //Turn OFF Everything
      
    break;

    //Controlling the Speed of Car  
    default:  //Get velocity
      if(command=='q'){
        velocity = 255;  //Full velocity
        analogWrite(Enable1, velocity);
      }
      else{ 
        //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
        if((command >= 48) && (command <= 57)){ 
          //Subtracting 48 changes the range from 48-57 to 0-9.
          //Multiplying by 25 changes the range from 0-9 to 0-225.
          velocity = (command - 48)*25;       
          analogWrite(Enable1, velocity);
        }
      }
    }
  }
     RGB();
  } 

  void RGB()
{
   // Update all LEDs and start new fades if any are done
  for (byte i = 0; i < LED_NUM; i++) 
  {
    LEDFader *led = &leds[i];
    led->update();
 
    // This LED is not fading, start a new fade
    if (led->is_fading() == false) 
    {
      int duration = random(1000, 3000); // between 1 - 3 seconds
 
      // Fade Up
      if (led->get_value() == 0) 

      
      {
        byte intensity = random(1, 255);
         
         
        led->fade(intensity, duration);
      }
      // Fade Down
      else 
      {
        led->fade(0, duration);

       }
     }
   }
 }
 
