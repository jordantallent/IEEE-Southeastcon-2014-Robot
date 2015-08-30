//These functions are used to track a line at a specified distance and start the tracking in a specified direction,
//the direction automatically changes when a thresh hold distance is reached with the side distance sensor
void trackLine(int dist, int dir){  //tracks line until it detects a spot
  //if dir=0, go left
  //if dir=1, go right
  int minDist = dist - 1;
  int maxDist = dist + 1;
  squareUp();
  getOnLine(dist);
  squareUp();
  while(digitalRead(spotDetectR) == LOW && digitalRead(spotDetectL) == LOW){
    if(digitalRead(spotDetectR) == HIGH || digitalRead(spotDetectL) == HIGH){break;}
    if(dir == 0){
      while(distance(frontLeftPing) < 34.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        backward(mSpeed);
      }
      if(digitalRead(spotDetectR) || digitalRead(spotDetectL)){delay(100);break;}
      squareUp();
      getOnLine(dist);
      squareUp();
      dir = 1;
    }
    else if(dir == 1){
      while(distance(frontLeftPing) > 6 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        forward(mSpeed);
      }
      if(digitalRead(spotDetectR) == HIGH || digitalRead(spotDetectL) == HIGH){delay(100);break;}
      squareUp();
      getOnLine(dist);
      squareUp();
      dir = 0;
    }
  }
  squareUp();
}

void squareUp(){
  float diff = distance(frontLeftPing) - distance(frontRightPing);
  diff = abs(diff);
  if(diff > 5){
    for(int i=0;i<10;i++){
      while(diff > 0.5){
        if(diff < 0.5){break;}
        if(distance(leftFrontPing) > distance(leftRearPing)){
          spinRight(255);
          delay(25);
          quickStop();
        }
        else if(distance(leftFrontPing) < distance(leftRearPing)){
          spinLeft(255);
          delay(25);
          quickStop();
        }
        diff = distance(leftFrontPing) - distance(leftRearPing);
        diff = abs(diff);
      }
    quickStop();
    }
  }
  else{
    for(int i=0;i<10;i++){
      while(diff > 0.5){
        if(diff < 0.5){break;}
        if(distance(frontLeftPing) > distance(frontRightPing)){
          spinRight(255);
          delay(25);
          quickStop();
        }
        else if(distance(frontLeftPing) < distance(frontRightPing)){
          spinLeft(255);
          delay(25);
          quickStop();
        }
        diff = distance(frontLeftPing) - distance(frontRightPing);
        diff = abs(diff);
      }
    quickStop();
    }
  }
}

void getOnLine(int dist){
  for(int i=0;i<5;i++){
    float minDist = dist - 0.5;
    float maxDist = dist + 0.5;
    if(distance(leftRearPing) > maxDist){
      while(distance(leftRearPing) > maxDist){
        left(.75*mSpeed);
      }
    }
    else if(distance(leftRearPing) < minDist){
      while(distance(leftRearPing) < minDist){
        right(.75*mSpeed);
      }
    }
    quickStop();
  }
}

void curvedLine(){
  //if dir=0, go left
  //if dir=1, go right
  int spinSpeed = 200;
  int spinDelay = 100;
  int dir;
  if(distance(frontLeftPing) < 24){dir = 1;}
  else{dir = 0;}
  int dist = sqrt(pow(48,2)-pow(24 - distance(frontLeftPing),2));
  int minDist = dist - 1;
  int maxDist = dist + 1;
  if(digitalRead(spotDetectR) == LOW && digitalRead(spotDetectL) == LOW){
    squareUp();
    getOnLine(dist);
    squareUp();
  }
  while(digitalRead(spotDetectR) == LOW && digitalRead(spotDetectL) == LOW){
    if(digitalRead(spotDetectR) == HIGH || digitalRead(spotDetectL) == HIGH){break;}
    if(dir == 0){
      if(distance(frontLeftPing) < 24){squareUp();spinLeft(spinSpeed);delay(spinDelay);quickStop();}
      else if(distance(frontLeftPing) > 6){squareUp();spinRight(spinSpeed);delay(spinDelay);quickStop();}
      while(distance(frontLeftPing) < 24.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        //modBackLeft(150);
        backward(mSpeed);
      }
      if(digitalRead(spotDetectR) || digitalRead(spotDetectL)){delay(100);break;}
      dist = sqrt(pow(48,2)-pow(24 - distance(frontLeftPing),2));
      squareUp();
      getOnLine(dist);
      squareUp();
      //if(distance(leftFrontPing) > 24){squareUp();spinLeft(spinSpeed);delay(spinDelay);quickStop();}
      //else if(distance(leftFrontPing) > 10){squareUp();spinRight(spinSpeed);delay(spinDelay);quickStop();}
      while(distance(frontLeftPing) < 34.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        //modFrontLeft(150);
        backward(mSpeed);
      }
      if(digitalRead(spotDetectR) || digitalRead(spotDetectL)){delay(100);break;}
      dist = sqrt(pow(48,2)-pow(distance(leftFrontPing)-24,2));
      squareUp();
      getOnLine(dist);
      squareUp();
      dir = 1;
    }
    else if(dir == 1){
      if(distance(leftFrontPing) < 24){squareUp();spinRight(spinSpeed);delay(spinDelay);quickStop();}
      else if(distance(leftFrontPing) > 6){squareUp();spinLeft(spinSpeed);delay(spinDelay);quickStop();}
      while(distance(leftFrontPing) < 24 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        //modBackRight(150);
        forward(mSpeed);
      }
      if(digitalRead(spotDetectR) || digitalRead(spotDetectL)){delay(100);break;}
      dist = sqrt(pow(48,2)-pow(24 - distance(leftFrontPing),2));
      squareUp();
      getOnLine(dist);
      squareUp();
      //if(distance(leftFrontPing) < 24){squareUp();spinRight(spinSpeed);delay(spinDelay);quickStop();}
      //else if(distance(leftFrontPing) <38){squareUp();spinLeft(spinSpeed);delay(spinDelay);quickStop();}
      while(distance(leftFrontPing) > 10 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        //modFrontRight(150);
        forward(mSpeed);
      }
      if(digitalRead(spotDetectR) == HIGH || digitalRead(spotDetectL) == HIGH){delay(100);break;}
      dist = sqrt(pow(48,2)-pow(24 - distance(leftFrontPing),2));
      squareUp();
      getOnLine(dist);
      squareUp();
      dir = 0;
    }
  }
  squareUp();
}
