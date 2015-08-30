//this function is used to find the target and aim at the target
void targeting(){
    float targetDist;
    float panAngle;
    float tiltAngle;
    float rightDist;
    float frontDist;
  for(int i=0;i<5;i++){
    //get left distance, must be the longest one
    if(distance(frontLeftPing) > distance(frontRightPing)){
      rightDist = distance(frontLeftPing);
    }
    else{
      rightDist = distance(frontRightPing);
    }
    //get front distance, must be the longest one
    if(distance(leftFrontPing) > distance(leftRearPing)){
      frontDist = distance(leftFrontPing);
    }
    else{
      frontDist = distance(leftRearPing);
    }
  }
  //first line
  if(distance(leftFrontPing) < 42){
    if (rightDist < 22){Serial3.println("1");
      panAngle = panOff + (180 - ((atan(frontDist/(24 - rightDist)) * 180) / PI));
      panServo.write(panAngle+5);  //add to go left
      targetDist = sqrt(pow(frontDist,2)+pow(24 - rightDist,2));
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-5);  //add more to go lower
    }
    else if(rightDist > 26){Serial3.println("2");
      panAngle = panOff + ((atan(frontDist/(rightDist-24)) * 180) / PI);
      panServo.write(panAngle-2);  //add to go left
      targetDist = sqrt(pow(frontDist,2)+pow(24-rightDist,2));
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-3);  //add more to go lower
    }
    else{Serial3.println("3");
      panServo.write(panZero);  //add to go left
      targetDist = frontDist;
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-5);  //add more to go lower
    }
  }
  //second line
  else if(distance(leftFrontPing) < 54){
    if (rightDist < 22){Serial3.println("4");
      panAngle = panOff + (180 - ((atan(frontDist/(24 - rightDist)) * 180) / PI));
      panServo.write(panAngle+2);  //add to go left
      targetDist = sqrt(pow(frontDist,2)+pow(24 - rightDist,2));
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-5);  //add more to go lower
    }
    else if(rightDist > 26){Serial3.println("5");
      panAngle = panOff + ((atan(frontDist/(24-rightDist)) * 180) / PI);
      panServo.write(panAngle-5);  //add to go left
      targetDist = sqrt(pow(frontDist,2)+pow(rightDist-24,2));
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-5);  //add more to go lower
    }
    else{Serial3.println("6");
      panServo.write(panZero);  //add to go left
      targetDist = frontDist;
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-5);  //add more to go lower
    }
  }
  //third line
  else{
    if (rightDist < 22){Serial3.println("7");
      panAngle = panOff + (180 - ((atan(frontDist/(24 - rightDist)) * 180) / PI));
      panServo.write(panAngle);  //add to go left
      targetDist = sqrt(pow(frontDist,2)+pow(24 - rightDist,2));
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-4);  //add more to go lower
    }
    else if(rightDist > 26){Serial3.println("8");
      panAngle = panOff + ((atan(frontDist/(24-rightDist)) * 180) / PI);
      panServo.write(panAngle);  //add to go left
      targetDist = sqrt(pow(frontDist,2)+pow(rightDist-24,2));
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-2);  //add more to go lower
    }
    else{Serial3.println("9");
      panServo.write(panZero);  //add to go left
      targetDist = frontDist;
      tiltAngle = tiltZero - (atan(12/targetDist)*180)/PI;
      tiltServo.write(tiltAngle-3);  //add more to go lower
    }
  }
  
  Serial3.print("pan angle = ");
  Serial3.println(panAngle);
  Serial3.print("target distance = ");
  Serial3.println(targetDist);
  Serial3.print("tilt angle = ");
  Serial3.println(tiltAngle);
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
  delay(50);
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
  while(pan<170){//left
    pan++;
    panServo.write(pan);
    delay(15);
  }
  while(pan>20){//right
    pan--;
    panServo.write(pan);
    delay(15);
  }
  while(pan<panZero){//left until straight
    pan++;
    panServo.write(pan);
    delay(15);
  }
  //tilt
  while(tilt<110){//down
    tilt++;
    tiltServo.write(tilt);
    delay(25);
  }
  while(tilt>70){//up
    tilt--;
    tiltServo.write(tilt);
    delay(25);
  }
  while(tilt<tiltZero){//down until straight
    tilt++;
    tiltServo.write(tilt);
    delay(25);
  }
  fireServo.write(90);
  fireServo.detach();
}
