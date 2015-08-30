
#include "Arduino.h"
#include <avr/version.h>  //used for some math
#include "SoftwareSerial.h"

SoftwareSerial bluetooth(A0,A1);


// Motor H-Bridge pins
//A - front left
const int A = 3;
const int aForward = 2;
//const int aBackward = 4;
//B - front right
const int B = 5;
const int bForward = 4;
//const int bBackward = 8;
//C - back left
const int C = 6;
const int cForward = 5;
//const int cBackward = 11;
//D - back right
const int D = 9;
const int dForward = 7;
//const int dBackward = 13;

//Ultrasonic Sensors-digital
const int frontLeftPing = 8;
const int frontRightPing = 10;
const int leftPing = 11;
//Mast ping sensors
const int mastPing = 12;
//spot detection buttons
const int spotDetect = 13;
//Photocell
const int start = 5;
//Line distance constants
const int lineDist1 = 34;
const int lineDist2 = 48;
const int lineDist3 = 58;
int lineTrack;

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  //initilize motor control
  pinMode(aForward, OUTPUT);pinMode(aBackward, OUTPUT);
  pinMode(bForward, OUTPUT);pinMode(bBackward, OUTPUT);
  pinMode(cForward, OUTPUT);pinMode(cBackward, OUTPUT);
  pinMode(dForward, OUTPUT);pinMode(dBackward, OUTPUT);
  
  quickStop();
  Serial.println();Serial.println("ready");Serial.println();
  bluetooth.println();bluetooth.println("ready");bluetooth.println();
  //batteryCheck();
}

void loop(){
  char motion;
  while (!Serial.available() || !bluetooth.available()){
    quickStop();
  }
  if(Serial.available()){motion = Serial.read();}
  else if(bluetooth.available()){motion = bluetooth.read();}
  //driving
  if (motion == 'w'){forward(200);}
  else if (motion == 's'){backward(200);}
  else if (motion == 'a'){left(200);}
  else if (motion == 'd'){right(200);}
  else if (motion == 'q'){frontLeft(200);}
  else if (motion == 'e'){frontRight(200);}
  else if (motion == 'z'){backLeft(200);}
  else if (motion == 'x'){backRight(200);}
  else if (motion == 'g'){spinLeft(200);}
  else if (motion == 'h'){spinRight(200);}
  else if (motion == 'u'){squareSpinLeft(175);}
  else if (motion == 'i'){squareSpinRight(175);}
  
  
  //functions
  else if (motion == 'j'){sensors();}
  else if (motion == 'r'){aBegin();}
  else if (motion == 'f'){findSpot();}
  
}
