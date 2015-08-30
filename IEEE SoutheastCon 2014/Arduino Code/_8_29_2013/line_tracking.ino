void findSpot(){
  while(digitalRead(spotDetect) == LOW){
    if(distance(leftPing) < 24){
      while(abs((distance(frontLeftPing) - distance(frontRightPing)) < 1)){
        while(distance(leftPing) < 40){
          right(150);
        }
      }
      onLine();
    }
    else{
      while(abs((distance(frontLeftPing) - distance(frontRightPing)) < 1)){
        while(distance(leftPing) > 10){
          left(150);
        }
      }
      onLine();
    }
  }
  onLine();
}
void onLine(){
  squareUp();
  while(distance(frontLeftPing) > lineTrack){  //if we are too far behind the line, move up
    forward(100);
  }
  while(distance(frontLeftPing) < lineTrack){  //if we are too far in front of the line, move back
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
  quickStop();
}


