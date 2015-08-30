void findSpot(){
  while(digitalRead(spotDetect) == LOW){
    int dir;  //0 = left, 1 = right
    if(distance(leftPing) > 24){
      dir = 0;
    }
    else{
      dir = 1;
    }
    if(dir == 0){
      while(digitalRead(spotDetect) == LOW && distance(leftPing) > 4){
        trackLeft(200);
      }
    }
    else if(dir == 1){
      while(digitalRead(spotDetect) == LOW && distance(leftPing) > 44){
        trackRight(200);
      }
    }
  }
}
void onLine(){
  int line = lineTrack;
  squareUp();
  while(distance(frontLeftPing) > line){  //if we are too far behind the line, move up
    forward(100);
  }
  while(distance(frontLeftPing) < line){  //if we are too far in front of the line, move back
    backward(100);
  }
  squareUp();
  
}
void squareUp(){
  while(distance(frontLeftPing) != distance(frontRightPing)){
    if(distance(frontLeftPing) > distance(frontRightPing)){
      spinRight(150);
    }
    else if(distance(frontLeftPing) < distance(frontRightPing)){
      spinLeft(150);
    }
  }
}
void trackLeft(int sp){
  left(sp);  //move left a little then re square up and check that robot is still on line.
  delay(250);
  onLine();
  
}

void trackRight(int sp){
  right(sp);  //move right a little then re square up and check that robot is still on line.
  delay(250);
  onLine();
}


