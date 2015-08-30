//----------------------------MOVEMENT--------------------------

void forward(int sped){//Serial2.println("forward");
  analogWrite(aForward, sped);
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
  analogWrite(dForward, sped);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
  analogWrite(dBackward, 0);
}

void backward(int sped){//Serial2.println("backward");
  analogWrite(aBackward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dBackward, sped);
  analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(dForward, 0);
}

void right(int sped){//Serial2.println("right");
  analogWrite(aForward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(dBackward, 0);
}

void left(int sped){//Serial2.println("left");
  analogWrite(aBackward, sped);
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
  analogWrite(aForward, 0);
  analogWrite(dForward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
}

void spinLeft(int sped){//Serial2.println("spin left");
  analogWrite(aBackward, sped);
  analogWrite(bForward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
  analogWrite(aForward, 0);
  analogWrite(cForward, 0);
  analogWrite(bBackward, 0);
  analogWrite(dBackward, 0);
}

void spinRight(int sped){//Serial2.println("spin right");
  analogWrite(aForward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
  analogWrite(bForward, 0);
  analogWrite(dForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(cBackward, 0);
}

void squareSpinLeft(int sped){//Serial2.println("square spin left");
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
  analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(dBackward, 0);
}

void squareSpinRight(int sped){//Serial2.println("square spin right");
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
  analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(dForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
}

void frontLeft(int sped){//Serial2.println("front left");
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
  analogWrite(aForward, 0);
  analogWrite(dForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
  analogWrite(dBackward, 0);
}

void frontRight(int sped){//Serial2.println("front right");
  analogWrite(aForward, sped);
  analogWrite(dForward, sped);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
  analogWrite(dBackward, 0);
}

void backLeft(int sped){//Serial2.println("back left");
  analogWrite(aBackward, sped);
  analogWrite(dBackward, sped);
  analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(dForward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
}

void backRight(int sped){//Serial2.println("back right");
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
  analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(dForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(dBackward, 0);
}
void leftSide(int sped){
  analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(dForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
  analogWrite(dBackward, 0);
  if (sped < 0){  //go backward
    sped = abs(sped);
    analogWrite(aBackward, sped);
    analogWrite(cBackward, sped);
  }
  else{  //go forward
    analogWrite(aForward, sped);
    analogWrite(cForward, sped);
  }
}
void rightSide(int sped){
  analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(dForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
  analogWrite(dBackward, 0);
  if (sped < 0){  //go backward
    sped = abs(sped);
    analogWrite(bBackward, sped);
    analogWrite(dBackward, sped);
  }
  else{  //go forward
    analogWrite(bForward, sped);
    analogWrite(dForward, sped);
  }
}
void backOnly(int sped){
  analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(dForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
  analogWrite(dBackward, 0);
  if (sped < 0){  //go right
    sped = abs(sped);
    analogWrite(cBackward, sped);
    analogWrite(dForward, sped);
  }
  else{  //go left
    analogWrite(cForward, sped);
    analogWrite(dBackward, sped);
  }
}
void frontOnly(int sped){
    analogWrite(aForward, 0);
  analogWrite(bForward, 0);
  analogWrite(cForward, 0);
  analogWrite(dForward, 0);
  analogWrite(aBackward, 0);
  analogWrite(bBackward, 0);
  analogWrite(cBackward, 0);
  analogWrite(dBackward, 0);
  if (sped < 0){  //go right
    sped = abs(sped);
    analogWrite(aBackward, sped);
    analogWrite(bForward, sped);
  }
  else{  //go left
    analogWrite(aForward, sped);
    analogWrite(bBackward, sped);
  }
}
void quickStop(){////Serial2.println("quickStop");
  digitalWrite(aForward, LOW);
  digitalWrite(aBackward, LOW);
  digitalWrite(bForward, LOW);
  digitalWrite(bBackward, LOW);
  digitalWrite(cForward, LOW);
  digitalWrite(cBackward, LOW);
  digitalWrite(dForward, LOW);
  digitalWrite(dBackward, LOW);
}
