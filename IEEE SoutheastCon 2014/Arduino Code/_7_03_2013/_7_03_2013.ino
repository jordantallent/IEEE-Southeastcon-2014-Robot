
#include "Arduino.h"
#include <avr/version.h>  //used for some math

// Motor H-Bridge pins
//A - front left
const int aForward = 4;  //digital 4
const int aBackward = 5;  //digital 5
//B - front right
const int bForward = 7;  //digital 7
const int bBackward = 6;  //digital 6
//C - back left
const int cForward = 8;  //digital 8
const int cBackward = 9;  //digital 9
//D - back right
const int dForward = 11;  //digital 11
const int dBackward = 10;  //digital 10

//line sensors-analog
const int leftCenterSensor = 3;
const int leftNearSensor = 4;
const int leftFarSensor = 5;
const int rightCenterSensor = 2;
const int rightNearSensor = 1;
const int rightFarSensor = 0;
      
      const int leftLine1 = 0;  //analog 0
      const int leftLine2 = 1;  //analog 1
      const int leftLine3 = 2;  //analog 2
      const int rightLine1 = 3;  //analog 3
      const int rightLine2 = 4;  //analog 4
      const int rightLine3 = 5;  //analog 5
      
const int whiteValue = 800;
int lastLeft = 0;
int lastRight = 0;
//Ultrasonic Sensors-digital
const int frontPing = 12;
const int leftPing = 13;
const int rightPing = 14;
const int backPing = 15;
//spot detection buttons
const int leftButton = 20;  //digital 20
const int rightButton = 21;  //digital 21
//Misc.
const int battery = 8;  ///analog 8
const int batteryWarn = 700;
//Mast ping sensors
const int mastPing = 22;  //digital 22

void setup(){
  Serial.begin(9600);
  //initilize motor control
  pinMode(aForward, OUTPUT);pinMode(aBackward, OUTPUT);
  pinMode(bForward, OUTPUT);pinMode(bBackward, OUTPUT);
  pinMode(cForward, OUTPUT);pinMode(cBackward, OUTPUT);
  pinMode(dForward, OUTPUT);pinMode(dBackward, OUTPUT);
  
  quickStop();
  Serial.println();Serial.println("ready");Serial.println();
  //batteryCheck();
}

void loop(){
  while (!Serial.available()){
    quickStop();
  }
  
  char motion = Serial.read();
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
