//this function is used to find the target and aim at the target
void targeting(){
  quickStop();
  float targetDist;
  float panAngle;
  float tiltAngle;
  float leftDist;
  float frontDist;
  for(int i=0;i<5;i++){
    //get left distance, must be the longest one
    if(distance(leftFrontPing) > distance(leftRearPing)){
      leftDist = distance(leftFrontPing);
    }
    else{
      leftDist = distance(leftRearPing);
    }
    //get front distance, must be the longest one
    if(distance(frontLeftPing) > distance(leftFrontPing)){
      frontDist = distance(frontLeftPing);
    }
    else{
      frontDist = distance(frontRightPing);
    }
  }
  
  targetDist = sqrt(pow(frontDist,2)+pow(leftDist-24,2));
  panAngle = ((atan((leftDist-24)/frontDist)*180)/PI)-2;
  tiltAngle = ((atan((27-15)/targetDist)*180)/PI);    //27 is the target height, 9 is the tilt axis height
  
//  //first line
//  if(distance(frontLeftPing) < 42){
//    if (leftDist > 26){Serial3.println("1");
//      panAngle = panOff + (180 - ((atan(frontDist/(leftDist-24)) * 180) / PI));
//      panServo.write(panAngle-9);  //add to go left
//      targetDist = sqrt(pow(frontDist,2)+pow(leftDist-24,2));
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-10);  //add more to go lower
//    }
//    else if(leftDist < 22){Serial3.println("2");
//      panAngle = panOff + ((atan(frontDist/(24-leftDist)) * 180) / PI);
//      panServo.write(panAngle-10);  //add to go left
//      targetDist = sqrt(pow(frontDist,2)+pow(24-leftDist,2));
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-10);  //add more to go lower
//    }
//    else{Serial3.println("3");
//      panServo.write(panZero-12);  //add to go left
//      targetDist = frontDist;
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-9);  //add more to go lower
//    }
//  }
//  //second line
//  else if(distance(frontLeftPing) < 54){
//    if (leftDist > 26){Serial3.println("4");
//      panAngle = panOff + (180 - ((atan(frontDist/(leftDist-24)) * 180) / PI));
//      panServo.write(panAngle-8);  //add to go left
//      targetDist = sqrt(pow(frontDist,2)+pow(leftDist-24,2));
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-7);  //add more to go lower
//    }
//    else if(leftDist < 22){Serial3.println("5");
//      panAngle = panOff + ((atan(frontDist/(24-leftDist)) * 180) / PI);
//      panServo.write(panAngle-9);  //add to go left
//      targetDist = sqrt(pow(frontDist,2)+pow(24-leftDist,2));
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-9);  //add more to go lower
//    }
//    else{Serial3.println("6");
//      panServo.write(panZero-6);  //add to go left
//      targetDist = frontDist;
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-9);  //add more to go lower
//    }
//  }
//  //third line
//  else{
//    if (leftDist > 26){Serial3.println("7");
//      panAngle = panOff + (180 - ((atan(frontDist/(leftDist-24)) * 180) / PI));
//      panServo.write(panAngle-7);  //add to go left
//      targetDist = sqrt(pow(frontDist,2)+pow(leftDist-24,2));
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-7);  //add more to go lower
//    }
//    else if(leftDist < 22){Serial3.println("8");
//      panAngle = panOff + ((atan(frontDist/(24-leftDist)) * 180) / PI);
//      panServo.write(panAngle-10);  //add to go left
//      targetDist = sqrt(pow(frontDist,2)+pow(24-leftDist,2));
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-7);  //add more to go lower
//    }
//    else{Serial3.println("9");
//      panAngle = panOff + ((atan(frontDist/(24-leftDist)) * 180) / PI);
//      panServo.write(panZero-7);
//      targetDist = frontDist;
//      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
//      tiltServo.write(tiltAngle-6);  //add more to go lower
//    }
//  }

  panServo.write(panZero + panAngle);
  tiltServo.write(tiltZero - tiltAngle);
  Serial3.print("pan angle = ");
  Serial3.println(panAngle);
  Serial3.print("target distance = ");
  Serial3.println(targetDist);
  Serial3.print("tilt angle = ");
  Serial3.println(tiltAngle);
  Serial3.print("left distance = ");
  Serial3.println(leftDist);
  Serial3.print("front distance = ");
  Serial3.println(frontDist);
  Serial3.println();
  /*
  |\\\\
  |  \\\
  |    \\
  |______\
  height = 27 - height of dart
  base length = front distance
  
  */
  
  digitalWrite(fire_on, LOW);
  delay(3100);
  fire();
  digitalWrite(fire_on, HIGH);
  delay(10);
  panServo.write(panZero);
  tiltServo.write(tiltZero);
}



void fire(){
  if(digitalRead(fire_on) == HIGH){return;}
  fireServo.attach(fireServoPin);
  fireServo.write(30);
  int lastRead = digitalRead(fireCount);
  int count = 0;
  while(count < 2){
    if(digitalRead(fireCount) && lastRead != digitalRead(fireCount)){
      count++;
    }
    lastRead = digitalRead(fireCount);
    delay(1);
  }
  fireServo.write(180);
  delay(20);
  fireServo.detach();
}
void servo_test(){
  fireServo.attach(fireServoPin);
  fireServo.write(30);
  //pan
  while(panLoc<170){//left
    panLoc++;
    panServo.write(panLoc);
    delay(15);
  }
  while(panLoc>20){//right
    panLoc--;
    panServo.write(panLoc);
    delay(15);
  }
  while(panLoc<panZero){//left until straight
    panLoc++;
    panServo.write(panLoc);
    delay(15);
  }
  //tilt
  while(tiltLoc<110){//down
    tiltLoc++;
    tiltServo.write(tiltLoc);
    delay(25);
  }
  while(tiltLoc>70){//up
    tiltLoc--;
    tiltServo.write(tiltLoc);
    delay(25);
  }
  while(tiltLoc<tiltZero){//down until straight
    tiltLoc++;
    tiltServo.write(tiltLoc);
    delay(25);
  }
}
