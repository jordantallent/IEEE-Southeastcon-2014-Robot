//-----PIN ASSIGNMENTS-----
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

const int spotDetect = 10;
const int frontLeftPing = 11;
const int frontRightPing = 12;
const int leftPing = 13;

void setup(){
  Serial.begin(9600);
  Serial2.begin(9600);
  //initilize motor control
  pinMode(aForward, OUTPUT);pinMode(aBackward, OUTPUT);
  pinMode(bForward, OUTPUT);pinMode(bBackward, OUTPUT);
  pinMode(cForward, OUTPUT);pinMode(cBackward, OUTPUT);
  pinMode(dForward, OUTPUT);pinMode(dBackward, OUTPUT);
  
  pinMode(spotDetect, INPUT);
  quickStop();
}

void loop(){
  trackLine(10, 0);  //track a 'line' 10 inches from wall and start by going left
}
