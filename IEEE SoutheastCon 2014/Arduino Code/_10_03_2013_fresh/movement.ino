//----------------------------MOVEMENT--------------------------

void forward(int sped){
  quickStop();
  digitalWrite(aForward, HIGH);
  digitalWrite(bForward, HIGH);
  digitalWrite(cForward, HIGH);
  digitalWrite(dForward, HIGH);
}

void backward(int sped){
  quickStop();
  digitalWrite(aBackward, HIGH);
  digitalWrite(bBackward, HIGH);
  digitalWrite(cBackward, HIGH);
  digitalWrite(dBackward, HIGH);
}

void right(int sped){
  quickStop();
  digitalWrite(aForward, HIGH);
  digitalWrite(bBackward, HIGH);
  digitalWrite(cBackward, HIGH);
  digitalWrite(dForward, HIGH);
}

void left(int sped){
  quickStop();
  digitalWrite(aBackward, HIGH);
  digitalWrite(bForward, HIGH);
  digitalWrite(cForward, HIGH);
  digitalWrite(dBackward, HIGH);
}

void spinLeft(int sped){
  quickStop();
  digitalWrite(aBackward, HIGH);
  digitalWrite(bForward, HIGH);
  digitalWrite(cBackward, HIGH);
  digitalWrite(dForward, HIGH);
}

void spinRight(int sped){
  quickStop();
  digitalWrite(aForward, HIGH);
  digitalWrite(bBackward, HIGH);
  digitalWrite(cForward, HIGH);
  digitalWrite(dBackward, HIGH);
}

void squareSpinLeft(int sped){
  quickStop();
  digitalWrite(cBackward, HIGH);
  digitalWrite(dForward, HIGH);
}

void squareSpinRight(int sped){
  quickStop();
  digitalWrite(cForward, HIGH);
  digitalWrite(dBackward, HIGH);
}

void frontLeft(int sped){
  quickStop();
  digitalWrite(bForward, HIGH);
  digitalWrite(cForward, HIGH);
}

void frontRight(int sped){
  quickStop();
  digitalWrite(aForward, HIGH);
  digitalWrite(dForward, HIGH);
}

void backLeft(int sped){
  quickStop();
  digitalWrite(aBackward, HIGH);
  digitalWrite(dBackward, HIGH);
}

void backRight(int sped){
  quickStop();
  digitalWrite(bBackward, HIGH);
  digitalWrite(cBackward, HIGH);
}
void leftSide(int sped){
  quickStop();
  if (sped < 0){  //go backward
    sped = abs(sped);
    digitalWrite(aBackward, HIGH);
    digitalWrite(cBackward, HIGH);
  }
  else{  //go forward
    digitalWrite(aForward, HIGH);
    digitalWrite(cForward, HIGH);
  }
}
void rightSide(int sped){
  quickStop();
  if (sped < 0){  //go backward
    sped = abs(sped);
    digitalWrite(bBackward, HIGH);
    digitalWrite(dBackward, HIGH);
  }
  else{  //go forward
    digitalWrite(bForward, HIGH);
    digitalWrite(dForward, HIGH);
  }
}
void backOnly(int sped){
  quickStop();
  if (sped < 0){  //go right
    sped = abs(sped);
    digitalWrite(cBackward, HIGH);
    digitalWrite(dForward, HIGH);
  }
  else{  //go left
    digitalWrite(cForward, HIGH);
    digitalWrite(dBackward, HIGH);
  }
}
void frontOnly(int sped){
  quickStop();
  if (sped < 0){  //go right
    sped = abs(sped);
    digitalWrite(aBackward, HIGH);
    digitalWrite(bForward, HIGH);
  }
  else{  //go left
    digitalWrite(aForward, HIGH);
    digitalWrite(bBackward, HIGH);
  }
}
void quickStop(){
  digitalWrite(aForward, LOW);
  digitalWrite(aBackward, LOW);
  digitalWrite(bForward, LOW);
  digitalWrite(bBackward, LOW);
  digitalWrite(cForward, LOW);
  digitalWrite(cBackward, LOW);
  digitalWrite(dForward, LOW);
  digitalWrite(dBackward, LOW);
}
