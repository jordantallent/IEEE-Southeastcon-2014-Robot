void airBlocks(){
  
  
  wall = 9999;
  while(1){
    while(analogRead(rightLine) < whiteValue){  //find the right edge of the block pick up
      right(255,100);
      lineSquare(0);
    }
    lineSquare(0);
    if(analogRead(rightLine) > whiteValue){
      break;
    }
  }
  while(analogRead(rightLine) > whiteValue){  //move back to be on the white line with two outside line sensors
    left(255,50);
    lineSquare(0);
  }
  backward(255,30);
  rotate(190);  //turn to go towards corner
  
  
  /*
  backward(255,25);
  rotate(109);delay(10);
  analogSensors();
  while(!Serial2.available()){;}
  while(analogRead(topLeft) < 150 && analogRead(topRight) < 150 && analogRead(lowLeft) < 90 && analogRead(lowRight) < 90){
    forward(255,50);
  }
  delay(10);analogSensors();
  rotate(80);
  */
  
  while(analogRead(topRight) < 195){  //go up to the wall but don't hit it
    forward(225,0);
  }
  forward(55,10);
  rotate(-70);  //turn towards the wall by ramp
  while(analogRead(topRight) < 225){  //go towards wall to get 'centered' up on ramp
    /*if(analogRead(lowLeft) > 100 || analogRead(lowRight) > 100){  //safety
      spinLeft(255,20);
    }*/
    forward(225,0);
  }
  forward(55,5);
  rotate(-110);delay(10);  //90 degree turn to face lower ramp
  //lower ramp
  distance(25);delay(15);  //get onto the ramp with all four wheels
  straighten();delay(10);
  distance(35);delay(15);  //continue up the ramp to the first platform
  //upper ramp
  rotate(-110);delay(15);  //rotate 90 degrees to face the upper part of the ramp
  distance(35);delay(15);  //get all four wheels onto upper ramp for measurement
  straighten();delay(10);
  distance(35);delay(15);  //continue on up the ramp some more
  straighten();delay(10);
  distance(14);delay(15);  //continue on up the ramp onto the top platform
  lineSquareRamp();
  if(firstSmallBlock ==1){
    right(255,100);  //jump left to check spot color
    forward(255,15);
    putDown();
  }
  else if(firstSmallBlock == 2){
    left(255,100);  //jump left to check spot color
    forward(255,15);
    putDown();
  }
  else{
    left(255,100);  //jump left to check spot color
    forward(255,15);
    delay(150);
    if(spotColor() == block){
      putDown();smallBlockCount++;
      firstSmallBlock = 1;
      backward(255,20);
      backRight(200,125);
    }
    else{
      backward(200,20);
      backRight(200,125);
      lineSquareRamp();
      right(200,100);
      delay(150);
      if(spotColor() == block){
        putDown();smallBlockCount++;
        firstSmallBlock = 2;
        backward(255,20);
        backLeft(255,125);
      }
      else{
        backward(255,20);
        backLeft(255,125);
        lineSquareRamp();
        left(200,100);
        putDown();smallBlockCount++;
        firstSmallBlock = 1;
        backward(255,20);
        backRight(255,125);
      }
    }
  }
  if(smallBlockCount != 2){
    lineSquareRamp();
    distance(-84);delay(10);
    rotate(110);delay(10);
    distance(-58);delay(10);
    rotate(-70);delay(10);
    distance(50);delay(10);
    lineSquare(1);
  }
  
  
  
}
void straighten(){
  int straight = 1000;  //1350;  //1517
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  //for(int i = 0;i < 2;i++){
    while(abs(ax - straight) > 50){  //sample and fix heading on ramp based on accelerometer readings
     delay(30);
     accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
     if(ax > (straight + 25)){  //if the accel reading is out of range and is too far to the left, spin right
       //squareSpinRight(255,25);
       /*
       analogWrite(cForward, 255);
       analogWrite(dBackward, 255);
       analogWrite(aForward, 130);
       analogWrite(bForward, 130);
       delay(10);quickStop();
       */
       spinRight(255,3);
       
     }
     else if(ax < (straight - 18)){  //if the accel reading is out of range and is too far to the right, spin left
       //squareSpinLeft(255,25);
       /*
       analogWrite(cBackward, 255);
       analogWrite(dForward, 255);
       analogWrite(aForward, 130);
       analogWrite(bForward, 130);
       delay(10);quickStop();
       */
       spinLeft(255,3);
     }
    } 
  //}
}
