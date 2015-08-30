//----------------------------MOVEMENT--------------------------

void forward(int sped){//Serial2.println("forward");
  analogWrite(aForward, sped);
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
  analogWrite(dForward, sped);
}

void backward(int sped){//Serial2.println("backward");
  analogWrite(aBackward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dBackward, sped);
}

void right(int sped){//Serial2.println("right");
  analogWrite(aForward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
}

void left(int sped){//Serial2.println("left");
  analogWrite(aBackward, sped);
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
}

void spinLeft(int sped){//Serial2.println("spin left");
  analogWrite(aBackward, sped);
  analogWrite(bForward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
}

void spinRight(int sped){//Serial2.println("spin right");
  analogWrite(aForward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
}

void squareSpinLeft(int sped){//Serial2.println("square spin left");
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
}

void squareSpinRight(int sped){//Serial2.println("square spin right");
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
}

void frontLeft(int sped){//Serial2.println("front left");
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
}

void frontRight(int sped){//Serial2.println("front right");
  analogWrite(aForward, sped);
  analogWrite(dForward, sped);
}

void backLeft(int sped){//Serial2.println("back left");
  analogWrite(aBackward, sped);
  analogWrite(dBackward, sped);
}

void backRight(int sped){//Serial2.println("back right");
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
}
void leftSide(int sped){
  digitalWrite(bForward, LOW);
  digitalWrite(bBackward, LOW);
  digitalWrite(dForward, LOW);
  digitalWrite(dBackward, LOW);
  if (sped < 0){  //go backward
    sped = abs(sped);
    digitalWrite(aForward, LOW);
    digitalWrite(aBackward, HIGH);
    digitalWrite(cForward, LOW);
    digitalWrite(cBackward, HIGH);
  }
  else{  //go forward
    digitalWrite(aForward, HIGH);
    digitalWrite(aBackward, LOW);
    digitalWrite(cForward, HIGH);
    digitalWrite(cBackward, LOW);
  }
}
void rightSide(int sped){
  digitalWrite(aForward, LOW);
  digitalWrite(aBackward, LOW);
  digitalWrite(cForward, LOW);
  digitalWrite(cBackward, LOW);
  if (sped < 0){  //go backward
    sped = abs(sped);
    digitalWrite(bForward, LOW);
    digitalWrite(bBackward, HIGH);
    digitalWrite(dForward, LOW);
    digitalWrite(dBackward, HIGH);
  }
  else{  //go forward
    digitalWrite(bForward, HIGH);
    digitalWrite(bBackward, LOW);
    digitalWrite(dForward, HIGH);
    digitalWrite(dBackward, LOW);
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
