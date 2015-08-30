void trackLine(int dist, int dir){  //tracks line until it detects a spot
  //if dir=0, go left
  //if dir=1, go right
  int minDist = dist - 2;
  int maxDist = dist + 2;
  while(digitalRead(spotDetect) == LOW){
    while(distance(leftPing) > 10 && distance(leftPing) < 35){
      while(distance(frontLeftPing) > minDist && distance(frontLeftPing) < maxDist){
        if(dir = 0){
          left(200);
        }
        else if(dir = 1){
          right(200);
        }
      }
      squareUp();  //get square against the wall
      getOnLine(dist);  //then make sure you are still at the 'line' to be tracked
    }
    dir = (dir == 0) ? 1 : 0;  //if dir = 0 then set dir to 1, else set dir to 0
  }
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

void getOnLine(int dist){
  while(distance(frontLeftPing) > dist){
    forward(100);
  }
  quickStop();
  while(distance(frontLeftPing) < dist){
    backward(100);
  }
  quickStop();
}
