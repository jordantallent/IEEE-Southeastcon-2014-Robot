
#include "Arduino.h"
#include <avr/version.h>  //used for some math


// Motor H-Bridge pins
//A - front left
const int aForward = 2;
const int aBackward = 3;
//B - front right
const int bForward = 4;
const int bBackward = 5;
//C - back left
const int cForward = 6;
const int cBackward = 7;
//D - back right
const int dForward = 8;
const int dBackward = 9;

//Ultrasonic Sensors-digital
const int frontLeftPing = 10;
const int frontRightPing = 11;
const int leftPing = 12;
//Mast ping sensors
const int mastPing = 13;
//spot detection buttons
const int spotDetect = 16;
//Dart launcher
const int load = 17;
const int launch = 18;
//Photocell
const int start = 0;
//Line distance constants
const int lineDist1 = 34;
const int lineDist2 = 48;
const int lineDist3 = 58;
int lineTrack;

void setup(){
  Serial.begin(9600);
  Serial2.begin(9600);
  //initilize motor control
  pinMode(aForward, OUTPUT);pinMode(aBackward, OUTPUT);
  pinMode(bForward, OUTPUT);pinMode(bBackward, OUTPUT);
  pinMode(cForward, OUTPUT);pinMode(cBackward, OUTPUT);
  pinMode(dForward, OUTPUT);pinMode(dBackward, OUTPUT);
  
  quickStop();
  Serial.println();Serial.println("ready");Serial.println();
  Serial2.println();Serial2.println("ready");Serial2.println();
}

void loop(){
  char motion;
  while (!Serial.available() || !Serial2.available()){
    quickStop();
  }
  if(Serial.available()){motion = Serial.read();}
  else if(Serial2.available()){motion = Serial2.read();}
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
  
}
