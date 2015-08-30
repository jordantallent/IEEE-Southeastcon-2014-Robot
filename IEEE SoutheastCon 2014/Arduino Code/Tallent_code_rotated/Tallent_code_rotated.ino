//Designed for use with an Arduino Mega 2560
// drill out hubs to 4mm or 0.16" for Rover 5 shafts

#include <Math.h>
#include <Servo.h>

Servo panServo;  //+90 goes left, -90 goes right
Servo tiltServo;  //+90 goes down, -90 goes up
Servo fireServo;  //-90 to move dart forward
const int panZero = 83;
const int tiltZero = 97;
const int panOff = panZero-90;
const int tiltOff = tiltZero-90;
const int panMax = 130;
const int panMin = 60;
const int tiltMax = 110;
const int tiltMin = 70;
//-----PIN ASSIGNMENTS-----
// Motor H-Bridge pins
//A - front left
const int aPWM = 2;
const int aDir = 3;
//C - back left
const int cPWM = 4;
const int cDir = 5;
//B - front right
const int bPWM = 6;
const int bDir = 7;
//D - back right
const int dPWM = 8;
const int dDir = 9;

const int leftFrontPing = 26;
const int leftRearPing = 24;
const int frontLeftPing = 28;
const int frontRightPing = 50;
 //bluetooth on 14 and 15-----Serial3
 //save pins 16-21 for extra serial port or I2C
const int tiltServoPin = 30;
const int panServoPin = 32;
const int fireServoPin = 34;
const int spotDetectR = 52;
const int spotDetectL = 22;
const int fire_on = 36;
const int fireCount = 38;
const int startDetect1 = 5;  //analog
const int startDetect2 = 6;
int startAmbient1;
int startAmbient2;

int mSpeed = 1 * 255;


void setup(){
  Serial3.begin(9600);
  //initilize motor control
  pinMode(aDir, OUTPUT);pinMode(aPWM, OUTPUT);
  pinMode(bDir, OUTPUT);pinMode(bPWM, OUTPUT);
  pinMode(cDir, OUTPUT);pinMode(cPWM, OUTPUT);
  pinMode(dDir, OUTPUT);pinMode(dPWM, OUTPUT);
  
  pinMode(spotDetectR, INPUT);
  pinMode(spotDetectL, INPUT);
  
  pinMode(fire_on, OUTPUT);
  digitalWrite(fire_on, HIGH);
  
  tiltServo.attach(tiltServoPin);
  tiltServo.write(tiltZero);
  panServo.attach(panServoPin);
  panServo.write(panZero);
  quickStop();
  Serial3.println("reset");
  commands();
  startAmbient1 = analogRead(startDetect1);
  startAmbient2 = analogRead(startDetect2);
}

int pan = panZero;
int tilt = tiltZero;

void loop(){
//  if(analogRead(startDetect1) > 100 || analogRead(startDetect2) > 100){
//    run_course();
//  }

  readSerial();
  
}

void readSerial(){
  char motion;
  while (!Serial3.available()){
    //quickStop();
  }
  if(Serial3.available()){motion = Serial3.read();}
  if(motion == 'w'){forward(mSpeed);}
  else if(motion == 's'){backward(mSpeed);}
  else if(motion == 'a'){left(mSpeed);}
  else if(motion == 'd'){right(mSpeed);}
  else if(motion == 'q'){frontLeft(mSpeed);}
  else if(motion == 'e'){frontRight(mSpeed);}
  else if(motion == 'z'){backLeft(mSpeed);}
  else if(motion == 'x'){backRight(mSpeed);}
  else if(motion == 'f'){spinLeft(mSpeed);}
  else if(motion == 'g'){spinRight(mSpeed);}

  else if(motion == ' '){quickStop();}
  
  else if(motion == '8' || motion =='5' || motion == '4' || motion == '6' || motion == '1' || motion == '3'){var_speed(motion);}
  
  else if(motion == 'v'){trackLine(24, 0);}  //track a 'line' 10 inches from wall and start by going left
  else if(motion == 'h'){curvedLine();}
  else if(motion == 'c'){getOnLine(36);}
  else if(motion == 'b'){squareUp();}
  else if(motion == 'n'){sensorOut();}
  else if(motion == 't'){end_move();}
  
  else if(motion == 'k'){pan++;panServo.write(pan);Serial3.println(pan);}
  else if(motion == ';'){pan--;panServo.write(pan);Serial3.println(pan);}
  else if(motion == 'l'){tilt++;tiltServo.write(tilt);Serial3.println(tilt);}
  else if(motion == 'o'){tilt--;tiltServo.write(tilt);Serial3.println(tilt);}
  else if(motion == 'm'){servo_test();}
  else if(motion == '2'){set_gun();}
  
  else if(motion == 'i'){targeting();}  //find target
  else if(motion == '['){digitalWrite(fire_on, !digitalRead(fire_on));}
  else if(motion == 'p'){fire();}
  
  else if(motion == '`'){run_course();}
  else{commands();}
}

void set_gun(){
  while(Serial3.available()<2){;}
  int pan_loc = Serial3.read();
  int tilt_loc = Serial3.read();
  pan_loc = map(pan_loc,0,180,180,0);
  pan_loc +=9;
  tilt_loc +=5;
  if(pan_loc > panMax){pan_loc=panMax;}
  else if(pan_loc < panMin){pan_loc=panMin;}
  if(tilt_loc > tiltMax){tilt_loc=tiltMax;}
  else if(tilt_loc < tiltMin){tilt_loc=tiltMin;}
  //Serial.println(pan_loc);
  //Serial.println(tilt_loc);
  panServo.write(pan_loc);
  tiltServo.write(tilt_loc);
}

void var_speed(char dir){
  Serial.println("variable speed");
  while(!Serial3.available()){;}
  int speed1 = Serial3.read();
  if(dir == '8'){forward(speed1);}
  else if(dir == '5'){backward(speed1);}
  else if(dir == '4'){spinLeft(speed1);}
  else if(dir == '6'){spinRight(speed1);}
  else if(dir == '1'){left(speed1);}
  else if(dir == '3'){right(speed1);}
}
void commands(){
  Serial3.println("Press A Command Key");
  Serial3.println("<----------MOVEMENT---------->");
  Serial3.print("\t");Serial3.println("w --> forward");
  Serial3.print("\t");Serial3.println("s --> backward");
  Serial3.print("\t");Serial3.println("a --> crab left");
  Serial3.print("\t");Serial3.println("d --> crab right");
  Serial3.print("\t");Serial3.println("q --> front left");
  Serial3.print("\t");Serial3.println("e --> fron right");
  Serial3.print("\t");Serial3.println("z --> back left");
  Serial3.print("\t");Serial3.println("x --> back right");
  Serial3.print("\t");Serial3.println("f --> spin left");
  Serial3.print("\t");Serial3.println("g --> spin right");
  Serial3.print("\t");Serial3.println("(space) --> quick stop");
  Serial3.println("<----------MOVEMENT FUNCTIONS---------->");
  Serial3.print("\t");Serial3.println("v --> track a line at x inches");
  Serial3.print("\t");Serial3.println("c --> get on line at x inches");
  Serial3.print("\t");Serial3.println("b --> square up function");
  Serial3.println("<----------DATA---------->");
  Serial3.print("\t");Serial3.println("n --> output sensor data to serial port");
  Serial3.println("<----------GUN CONTROL---------->");
  Serial3.print("\t");Serial3.println("k --> pan gun left");
  Serial3.print("\t");Serial3.println("; --> pan gun right");
  Serial3.print("\t");Serial3.println("l --> tilt gun down");
  Serial3.print("\t");Serial3.println("o --> tilt gun up");
  Serial3.print("\t");Serial3.println("m --> test gun servos");
  Serial3.print("\t");Serial3.println("i --> find target using Pings");
  Serial3.print("\t");Serial3.println("p --> fire gun");
  Serial3.println("<----------RUN ALL---------->");
  Serial3.print("\t");Serial3.println("` --> run course");
}
