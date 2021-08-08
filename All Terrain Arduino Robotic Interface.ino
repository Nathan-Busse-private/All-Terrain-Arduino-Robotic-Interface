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

//If the motors turn the opposite direction swap the wires around in that output.

//Back Motor Pins  (OUTPUT 3 and 4) L298N 

int Enable1 = 6;
int Motor1_Pin1 = 10;  
int Motor1_Pin2 = 9;  

//Font Motor Pins  (OUTPUT 1 and 2)  L298N
int Motor2_Pin1 = 8; 
int Motor2_Pin2 = 7;
int Enable2 = 11; 

//Front Light pins   (RGB LED Module)
int front_light1 = A0;
int front_light2 = A1;
int front_light3 = A5;

//Back light pins (2 colour LED Module)
int back_light1 = A2;
int back_light2 = A3;
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

//Buzzer tone.
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
  if(bluetooth.available() > 0){ //Checking if there is some data available or not
    RGB () ;
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
      tone(12,660);
      
      
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
        velocity = 900;  //Full velocity
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
     // RGB();
  } 

  void RGB()

  /*
   * This is not just an RGB that is used for astetic purposes,
   * its main function is actually a diognostics indicator.
   * 
   * How it works...
   * 
   * The LED will remain solid if the robot is not connected to a device,
   * or their is a hardware issue with the connection of the module, 
   * check the connections but 9/10 your device is not connected.
   * 
   * Once powered on the LED will remain solid.
   * Once you have a connected the robot to your Android device the
   * RGB should start cycling through the colours.
   * 
   * If your device suddenly disconnects from the robot, 
   * The RGB will stop cycling and will remain solid,
   * letting the operator know the robot has lost connection.
   */
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
        byte intensity = random(0, 255);
         
         
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

      
// Nathan-Busse      
      
    
  
 
