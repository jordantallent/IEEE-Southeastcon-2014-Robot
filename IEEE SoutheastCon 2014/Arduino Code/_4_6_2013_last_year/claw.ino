void pickUp(){
  //Serial2.println("pickUp");
  claw.writeMicroseconds(clawOpen);
  delay(250);
  upDown.writeMicroseconds(upDownDown);
  delay(500);
  claw.writeMicroseconds(clawClose);
  delay(350);
  upDown.writeMicroseconds(upDownUp);
  delay(250);
}

void putDown(){
  //Serial2.println("putDown");
  upDown.writeMicroseconds(upDownDown);
  delay(500);
  int clawHalf = ((clawOpen - clawClose)/2) + clawClose+50;
  claw.writeMicroseconds(clawHalf);
  delay(300);
  upDown.writeMicroseconds(upDownUp);
  delay(350);
  claw.writeMicroseconds(clawOpen);
  Serial2.print("block count = ");Serial2.println(blockCount);
}

void pickUpMiss(){
  claw.writeMicroseconds(clawClose);
  delay(250);
  upDown.writeMicroseconds(upDownDown);
  delay(700);
  claw.writeMicroseconds(clawOpen);
  delay(250);
  for(int i = clawOpen;i < clawClose;i=i-25){
    claw.writeMicroseconds(i);
    delay(100);
  }
  delay(250);
  claw.writeMicroseconds(clawClose);
  delay(500);
  upDown.writeMicroseconds(upDownUp);
  delay(400);
}

