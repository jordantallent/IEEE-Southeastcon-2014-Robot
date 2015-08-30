//----------------------------MOVEMENT--------------------------
void setSped(int sped){
  if(sped > 255){sped = 255;}
  analogWrite(aPWM, sped);
  analogWrite(bPWM, sped);
  analogWrite(cPWM, sped);
  analogWrite(dPWM, sped);
}

void forward(int sped){
  quickStop();
  digitalWrite(aDir, HIGH);
  digitalWrite(bDir, HIGH);
  digitalWrite(cDir, HIGH);
  digitalWrite(dDir, HIGH);
  setSped(sped);
}

void backward(int sped){
  quickStop();
  digitalWrite(aDir, LOW);
  digitalWrite(bDir, LOW);
  digitalWrite(cDir, LOW);
  digitalWrite(dDir, LOW);
  setSped(sped);
}

void right(int sped){
  quickStop();
  digitalWrite(aDir, HIGH);
  digitalWrite(bDir, LOW);
  digitalWrite(cDir, LOW);
  digitalWrite(dDir, HIGH);
  setSped(sped);
}

void left(int sped){
  quickStop();
  digitalWrite(aDir, LOW);
  digitalWrite(bDir, HIGH);
  digitalWrite(cDir, HIGH);
  digitalWrite(dDir, LOW);
  setSped(sped);
}

void spinLeft(int sped){
  quickStop();
  digitalWrite(aDir, LOW);
  digitalWrite(bDir, HIGH);
  digitalWrite(cDir, LOW);
  digitalWrite(dDir, HIGH);
  setSped(sped);
}

void spinRight(int sped){
  quickStop();
  digitalWrite(aDir, HIGH);
  digitalWrite(bDir, LOW);
  digitalWrite(cDir, HIGH);
  digitalWrite(dDir, LOW);
  setSped(sped);
}

void squareSpinLeft(int sped){
  quickStop();
  digitalWrite(cDir, LOW);
  digitalWrite(dDir, HIGH);
  setSped(sped);
}

void squareSpinRight(int sped){
  quickStop();
  digitalWrite(cDir, HIGH);
  digitalWrite(dDir, LOW);
  setSped(sped);
}

void frontLeft(int sped){
  quickStop();
  digitalWrite(bDir, HIGH);
  digitalWrite(cDir, HIGH);
  setSped(sped);
  analogWrite(aPWM, 0);
  analogWrite(dPWM, 0);
}

void frontRight(int sped){
  quickStop();
  digitalWrite(aDir, HIGH);
  digitalWrite(dDir, HIGH);
  setSped(sped);
  analogWrite(bPWM, 0);
  analogWrite(cPWM, 0);
}

void backLeft(int sped){
  quickStop();
  digitalWrite(aDir, LOW);
  digitalWrite(dDir, LOW);
  setSped(sped);
  analogWrite(bPWM, 0);
  analogWrite(cPWM, 0);
}

void backRight(int sped){
  quickStop();
  digitalWrite(bDir, LOW);
  digitalWrite(cDir, LOW);
  setSped(sped);
  analogWrite(aPWM, 0);
  analogWrite(dPWM, 0);
}
void leftSide(int sped){
  quickStop();
  if (sped < 0){  //go backward
    sped = abs(sped);
    digitalWrite(aDir, LOW);
    digitalWrite(cDir, LOW);
  }
  else{  //go forward
    digitalWrite(aDir, HIGH);
    digitalWrite(cDir, HIGH);
  }
  setSped(sped);
  analogWrite(bPWM, 0);
  analogWrite(dPWM, 0);
}
void rightSide(int sped){
  quickStop();
  if (sped < 0){  //go backward
    sped = abs(sped);
    digitalWrite(bDir, LOW);
    digitalWrite(dDir, LOW);
  }
  else{  //go forward
    digitalWrite(bDir, HIGH);
    digitalWrite(dDir, HIGH);
  }
  setSped(sped);
  analogWrite(aPWM, 0);
  analogWrite(cPWM, 0);
}
void backOnly(int sped){
  quickStop();
  if (sped < 0){  //go right
    sped = abs(sped);
    digitalWrite(cDir, LOW);
    digitalWrite(dDir, HIGH);
  }
  else{  //go left
    digitalWrite(cDir, HIGH);
    digitalWrite(dDir, LOW);
  }
  setSped(sped);
  analogWrite(aPWM, 0);
  analogWrite(bPWM, 0);
}
void frontOnly(int sped){
  quickStop();
  if (sped < 0){  //go right
    sped = abs(sped);
    digitalWrite(aDir, LOW);
    digitalWrite(bDir, HIGH);
  }
  else{  //go left
    digitalWrite(aDir, HIGH);
    digitalWrite(bDir, LOW);
  }
  setSped(sped);
  analogWrite(cPWM, 0);
  analogWrite(dPWM, 0);
}
void modBackLeft(int sped){
  quickStop();
  digitalWrite(aDir, LOW);
  digitalWrite(bDir, HIGH);
  digitalWrite(cDir, HIGH);
  digitalWrite(dDir, LOW);
  analogWrite(aPWM, sped);
  analogWrite(bPWM, sped/2);
  analogWrite(cPWM, sped/2);
  analogWrite(dPWM, sped);
}
void modFrontRight(int sped){
  quickStop();
  digitalWrite(aDir, HIGH);
  digitalWrite(bDir, LOW);
  digitalWrite(cDir, LOW);
  digitalWrite(dDir, HIGH);
  analogWrite(aPWM, sped);
  analogWrite(bPWM, sped/2);
  analogWrite(cPWM, sped/2);
  analogWrite(dPWM, sped);
}
void modBackRight(int sped){
  quickStop();
  digitalWrite(aDir, HIGH);
  digitalWrite(bDir, LOW);
  digitalWrite(cDir, LOW);
  digitalWrite(dDir, HIGH);
  analogWrite(aPWM, sped/2);
  analogWrite(bPWM, sped);
  analogWrite(cPWM, sped);
  analogWrite(dPWM, sped/2);
}
void modFrontLeft(int sped){
  quickStop();
  digitalWrite(aDir, LOW);
  digitalWrite(bDir, HIGH);
  digitalWrite(cDir, HIGH);
  digitalWrite(dDir, LOW);
  analogWrite(aPWM, sped/2);
  analogWrite(bPWM, sped);
  analogWrite(cPWM, sped);
  analogWrite(dPWM, sped/2);
}
void quickStop(){
  //prevents the wheels from continuing when you want them to stop
  digitalWrite(aDir, !digitalRead(aDir));
  digitalWrite(bDir, !digitalRead(bDir));
  digitalWrite(cDir, !digitalRead(cDir));
  digitalWrite(dDir, !digitalRead(dDir));
  setSped(0);
}
