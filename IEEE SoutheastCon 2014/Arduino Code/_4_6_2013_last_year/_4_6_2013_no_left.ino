//wheel reference - http://www.robotshop.com/content/images//dfrobotshop-rover-mecanum-wheel-motion.jpg
//gyro/accel - https://www.sparkfun.com/products/11028?
//wheel/encoder combo - http://www.robotshop.com/pololu-12v-29-1-gear-motor-encoder.html
//                      http://www.robotshop.com/content/PDF/datasheet-1443.pdf
//encoder reference - http://www.hessmer.org/blog/2011/01/30/quadrature-encoder-too-fast-for-arduino/
//line sensors - https://www.sparkfun.com/products/9453

#include "Arduino.h"
#include <digitalWriteFast.h>  // library for high performance reads and writes by jrraines
                               // see http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1267553811/0
                               // and http://code.google.com/p/digitalwritefast/
                               //used to read the encoder ticks
#include <MPU6050.h>  //accelerometer/gyro library
#include <I2Cdev.h>  //needed for above library
#include <Wire.h>    //needed for I2C
#include <avr/version.h>  //used for some math
#include <Servo.h>  //library needed for servos
#include <IEEEColorSensor.h>

IEEEColorSensor colors;
Servo upDown;                //claw servo
Servo claw;                  //claw servo
MPU6050 accelgyro;           //gyro

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
// Quadrature encoders
// A encoder
#define AEncoderInterrupt 0  // Mega's interrupt number
#define AEncoderPinA 2  //digital 2
#define AEncoderPinB 22  //digital 22
#define AEncoderIsReversed
volatile bool AEncoderBSet;
volatile long AEncoderTicks = 0;
/*
// B encoder
#define BEncoderInterrupt 1
#define BEncoderPinA 3
#define BEncoderPinB 23
volatile bool BEncoderBSet;
volatile long BEncoderTicks = 0;
// C encoder
#define CEncoderInterrupt 5
#define CEncoderPinA 18
#define CEncoderPinB 24
volatile bool CEncoderBSet;
volatile long CEncoderTicks = 0;
// D encoder
#define DEncoderInterrupt 4
#define DEncoderPinA 19
#define DEncoderPinB 25
volatile bool DEncoderBSet;
volatile long DEncoderTicks = 0;
*/
//Start Button Interrupt
//#define StartInterrupt 4
//#define startButton 19
//volatile bool DEncoderBSet;
//int hasStarted = 0;
//Wheel info, used for distance()
const double countsPerRevolution = 400;
const double wheelDiameter = 2.125;
const double distancePerCount = ((PI * wheelDiameter) / countsPerRevolution);    //.00359692
//Gyro stuff
int16_t ax, ay, az;
int16_t gx, gy, gz;
//gyro constants
const float a20= 15;
const float a30 = 29;
const float a45 = 51;
const float a60 = 74;
const float a90 = 105;
const float a135 = 187;
const float a180 = 248;
//claw constants for servo motors
const int upDownUp = 2000;
const int upDownDown = 500;
const int upDownBlocks = 1700;
const int upDownSpots = 1850;
const int clawOpen = 1925;
const int clawClose = 1100;
//line sensors-analog
const int leftLine = 0;  //analog 0
const int middleLine = 1;  //analog 1
const int rightLine = 2;  //analog 2
const int middleLeftLine = 10;
const int middleRightLine = 9;
const int whiteValue = 800;
//IR Sensors-analog
const int topLeft = 3;  //analog 3
const int topRight = 4;  //analog 4
const int lowLeft = 5;  //analog 5
const int lowRight = 6;  //analog 6
const int pressure = 7;  //analog 7
//servos-digital
const int upDownServo = 13;  //digital 13
const int clawServo = 14;  //digital 14
const int LED = 28;  //digital 28
const int solidState = 26;  //digital 26
const int battery = 8;  ///analog 8
const int startButton = 15;  //digital 15
//block length buttons
const int length1 = 53;
const int length2 = 49;
const int length3 = 51;
//various block/spot info
int block=0;
int blockCount=0;
int smallBlockCount = 0;
int firstSmallBlock = 0;
int smallBlock1[2], smallBlock2[2], smallBlock3[2], smallBlock4[2], smallBlock5[2];
int missedColor1, missedColor2, missedColor3, missedColor4, missedColor5;
int largeSpot[6], mediumSpot[6];
//wall distances
int wall4=395;
int wall5=350;
int wall6=310;
int wall = wall6;
int batteryWarn = 725;
int startTime;
int lastSize = 0;

void setup(){
  Serial2.begin(9600);
  Wire.begin();
  accelgyro.initialize();
  colors.initialize();
  //outputs
  pinMode(aForward, OUTPUT);pinMode(aBackward, OUTPUT);
  pinMode(bForward, OUTPUT);pinMode(bBackward, OUTPUT);
  pinMode(cForward, OUTPUT);pinMode(cBackward, OUTPUT);
  pinMode(dForward, OUTPUT);pinMode(dBackward, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(solidState, OUTPUT);
  pinMode(startButton, INPUT);
  pinMode(length1, INPUT);
  pinMode(length2, INPUT);
  pinMode(length3, INPUT);
  upDown.attach(upDownServo);
  claw.attach(clawServo);
  
  // Quadrature encoders
  // A encoder
  pinMode(AEncoderPinA, INPUT);      // sets pin A as input
  digitalWrite(AEncoderPinA, LOW);  // turn on pullup resistors
  pinMode(AEncoderPinB, INPUT);      // sets pin B as input
  digitalWrite(AEncoderPinB, LOW);  // turn on pullup resistors
  attachInterrupt(AEncoderInterrupt, HandleAMotorInterruptA, RISING);
//  // B encoder
//  pinMode(BEncoderPinA, INPUT);      // sets pin A as input
//  digitalWrite(BEncoderPinA, LOW);  // turn on pullup resistors
//  pinMode(BEncoderPinB, INPUT);      // sets pin B as input
//  digitalWrite(BEncoderPinB, LOW);  // turn on pullup resistors
//  attachInterrupt(BEncoderInterrupt, HandleBMotorInterruptA, RISING);
//Start Button Interrupt
/*
  pinMode(startButton, INPUT);      // sets pin A as input
  digitalWrite(startButton, LOW);  // turn on pullup resistors
  attachInterrupt(StartInterrupt, StartInterruptFunction, FALLING);
  */
  //
  upDown.writeMicroseconds(upDownDown);
  delay(500);
  claw.writeMicroseconds(clawOpen);
  quickStop();
  Serial2.println();Serial2.println("ready");Serial2.println();
  batteryCheck();
}

void loop(){
  digitalWrite(solidState, HIGH);
  while (!Serial2.available() && digitalRead(startButton) == LOW){
    ;
  }
  
  if(digitalRead(startButton) == HIGH){
    while(digitalRead(startButton) == HIGH){  //wait until the button is released
      ;
    }
    Serial2.println("beginning");
    delay(200);
    aBegin();  //start course run
  }
  
  char motion = Serial2.read();
  //rotations
  if (motion == '1'){rotate(a20);}
  else if (motion == '2'){rotate(a30);}
  else if (motion == '3'){rotate(a45);}
  else if (motion == '4'){rotate(a60);}
  else if (motion == '5'){rotate(a90);}
  else if (motion == '6'){rotate(a135);}
  else if (motion == '7'){rotate(a180);}
  
  else if (motion == '!'){rotate(-a20);}
  else if (motion == '@'){rotate(-a30);}
  else if (motion == '#'){rotate(-a45);}
  else if (motion == '$'){rotate(-a60);}
  else if (motion == '%'){rotate(-a90);}
  else if (motion == '^'){rotate(-a135);}
  else if (motion == '&'){rotate(-a180);}
  //driving
  else if (motion == 'w'){forward(200, 75);}
  else if (motion == 's'){backward(200, 75);}
  else if (motion == 'a'){left(200, 75);}
  else if (motion == 'd'){right(200, 75);}
  else if (motion == 'q'){frontLeft(200, 75);}
  else if (motion == 'e'){frontRight(200, 75);}
  else if (motion == 'z'){backLeft(200, 75);}
  else if (motion == 'x'){backRight(200, 75);}
  else if (motion == 'g'){spinLeft(200, 75);}
  else if (motion == 'h'){spinRight(200, 75);}
  else if (motion == 'u'){squareSpinLeft(175, 75);}
  else if (motion == 'i'){squareSpinRight(175, 75);}
  
  //claw movement
  else if (motion == 't'){pickUp();}
  else if (motion == 'y'){putDown();}
  else if (motion == 'n'){upDown.writeMicroseconds(upDownUp);}
  else if (motion == 'm'){upDown.writeMicroseconds(upDownDown);}
  else if (motion == 'o'){claw.writeMicroseconds(clawOpen);}
  else if (motion == 'p'){claw.writeMicroseconds(clawClose);}
  //functions
  else if (motion == 'j'){sensors();}
  else if (motion == ','){analogSensors();}
  //else if (motion == 'c'){creep();}
  else if (motion == 'v'){Serial2.println("input location size");
    while(!Serial2.available()){;}
    motion = Serial2.read();
    if (motion == '4'){wall = wall4;;}
    else if (motion == '5'){wall = wall5;}
    else if (motion == '6'){wall = wall6;}
    lineSquare(0);
    wall = wall6;}
  else if (motion == '-'){lineSquareRamp();}
  else if (motion == 'f'){blockCount = 20;findBlock(0);blockCount = 0;}
  else if (motion == 'k'){squareUp();}
  else if (motion == 'r'){aBegin();}
  else if (motion == '/'){findBlock(1);blockColor();pickUp();airBlocks();}
  else if (motion == 'b'){Serial2.print("input color number = ");
    while(!Serial2.available()){;}
    motion = Serial2.read();
    if (motion == '1'){block = 1;}
    else if (motion == '2'){block = 2;}
    else if (motion == '3'){block = 3;}
    else if (motion == '4'){block = 4;}
    else if (motion == '5'){block = 5;}
    else if (motion == '6'){block = 6;}
    Serial2.println(motion);
    Serial2.print("input location size = ");
    while(!Serial2.available()){;}
    motion = Serial2.read();
    if (motion == '4'){wall = wall4;;}
    else if (motion == '5'){wall = wall5;}
    else if (motion == '6'){wall = wall6;}
    Serial2.println(motion);
    findSpot();}
  else if (motion == '.'){	//color sensor calibration
    analogWrite(LED, 255);delay(250);
    colors.calibrateColor();  // This calibrates R, G, and B int registers
    colors.calibrateClear();  // This calibrates the C int registers
    colors.calibrateCapacitors();  // This calibrates the RGB, and C cap registers
    colors.getRGBC();  // After calibrating, we can get the first RGB and C data readings
    colors.printADJD_S311Values();  // Formats and prints all important ADJD-S311 registers
    delay(250);analogWrite(LED, 0);
  }
  else if (motion == '0'){straighten();}
  else if(motion == ';'){upDown.writeMicroseconds(1800);}
  delay(75);
  quickStop();
  
  /*
  while(digitalRead(startButton) == LOW){
    ;
  }
  while(digitalRead(startButton) == HIGH){  //wait until the button is released
    ;
  }
  Serial2.println("beginning");
  delay(200);
  //begin();  //start course run
  */
  
}
