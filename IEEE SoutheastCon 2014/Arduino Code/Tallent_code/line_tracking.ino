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
    if(dir == 0){  //moving left
      while(distance(leftFrontPing) > 24.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        left(mSpeed);
      }
      getOnLine(dist);
      while(distance(leftFrontPing) > 10.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        left(mSpeed);
      }
      if(digitalRead(spotDetectR) || digitalRead(spotDetectL)){delay(100);break;}
      getOnLine(dist);
      dir = 1;
    }
    else if(dir == 1){  //moving right
      while(distance(leftFrontPing) < 38.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        right(mSpeed);
      }
      getOnLine(dist);
      while(distance(leftFrontPing) < 24.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        right(mSpeed);
      }
      if(digitalRead(spotDetectR) == HIGH || digitalRead(spotDetectL) == HIGH){delay(100);break;}
      getOnLine(dist);
      dir = 0;
    }
    getOnLine(dist);
  }
}

void squareUp(){
  float diff = distance(leftFrontPing) - distance(leftRearPing);
  diff = abs(diff);
  if(diff > 5){
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
  else{
    for(int i=0;i<10;i++){
      while(diff > 0.5){
        if(diff < 0.5){break;}
        if(distance(leftRearPing) > distance(leftFrontPing)){
          spinRight(255);
          delay(25);
          quickStop();
        }
        else if(distance(leftRearPing) < distance(leftFrontPing)){
          spinLeft(255);
          delay(25);
          quickStop();
        }
        diff = distance(leftRearPing) - distance(leftFrontPing);
        diff = abs(diff);
      }
    quickStop();
    }
  }
}

void getOnLine(int dist){
  squareUp();
  for(int i=0;i<5;i++){
    float minDist = dist - 0.5;
    float maxDist = dist + 0.5;
    float tempDist;
    if(distance(frontLeftPing) > distance(leftFrontPing)){tempDist = distance(frontLeftPing);}
    else{tempDist = distance(frontRightPing);}
    if(tempDist > maxDist){
      while(tempDist > maxDist){
        forward(.7*mSpeed);
        if(distance(frontLeftPing) > distance(leftFrontPing)){tempDist = distance(frontLeftPing);}
        else{tempDist = distance(frontRightPing);}
      }
    }
    else if(tempDist < minDist){
      while(tempDist < minDist){
        backward(.7*mSpeed);
        if(distance(frontLeftPing) > distance(leftFrontPing)){tempDist = distance(frontLeftPing);}
        else{tempDist = distance(frontRightPing);}
      }
    }
    quickStop();
  }
  squareUp();
}

void curvedLine(){
  //if dir=0, go left
  //if dir=1, go right
  int spinSpeed = 200;
  int spinDelay = 100;
  int dir;
  if(distance(leftFrontPing) > 24){dir = 1;}
  else{dir = 0;}
  int dist = dist = sqrt(pow(secondLine,2)-pow(distance(leftFrontPing)-24,2));
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
      if(distance(leftFrontPing) > 24){squareUp();spinLeft(spinSpeed);delay(spinDelay);quickStop();}
      else if(distance(leftFrontPing) > 10){squareUp();spinRight(spinSpeed);delay(spinDelay);quickStop();}
      while(distance(leftFrontPing) > 24.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        //modBackLeft(150);
        left(mSpeed);
      }
      if(digitalRead(spotDetectR) || digitalRead(spotDetectL)){delay(100);break;}
      dist = sqrt(pow(50,2)-pow(distance(leftFrontPing)-24,2));
      getOnLine(dist);
      //if(distance(leftFrontPing) > 24){squareUp();spinLeft(spinSpeed);delay(spinDelay);quickStop();}
      //else if(distance(leftFrontPing) > 10){squareUp();spinRight(spinSpeed);delay(spinDelay);quickStop();}
      while(distance(leftFrontPing) > 10.00 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        //modFrontLeft(150);
        left(mSpeed);
      }
      if(digitalRead(spotDetectR) || digitalRead(spotDetectL)){delay(100);break;}
      dist = sqrt(pow(50,2)-pow(distance(leftFrontPing)-24,2));
      getOnLine(dist);
      dir = 1;
    }
    else if(dir == 1){
      if(distance(leftFrontPing) < 24){squareUp();spinRight(spinSpeed);delay(spinDelay);quickStop();}
      else if(distance(leftFrontPing) <38){squareUp();spinLeft(spinSpeed);delay(spinDelay);quickStop();}
      while(distance(leftFrontPing) < 24 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        //modBackRight(150);
        right(mSpeed);
      }
      if(digitalRead(spotDetectR) || digitalRead(spotDetectL)){delay(100);break;}
      dist = sqrt(pow(50,2)-pow(distance(leftFrontPing)-24,2));
      getOnLine(dist);
      //if(distance(leftFrontPing) < 24){squareUp();spinRight(spinSpeed);delay(spinDelay);quickStop();}
      //else if(distance(leftFrontPing) <38){squareUp();spinLeft(spinSpeed);delay(spinDelay);quickStop();}
      while(distance(leftFrontPing) < 38 && !digitalRead(spotDetectR) && !digitalRead(spotDetectL)){
        //modFrontRight(150);
        right(mSpeed);
      }
      if(digitalRead(spotDetectR) == HIGH || digitalRead(spotDetectL) == HIGH){delay(100);break;}
      dist = sqrt(pow(50,2)-pow(distance(leftFrontPing)-24,2));
      getOnLine(dist);
      dir = 0;
    }
  }
  getOnLine(dist);
}
