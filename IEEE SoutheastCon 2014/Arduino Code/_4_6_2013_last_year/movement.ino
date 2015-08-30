//----------------------------MOVEMENT--------------------------

void forward(int sped, int del){//Serial2.println("forward");
  analogWrite(aForward, sped);
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
  analogWrite(dForward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void backward(int sped, int del){//Serial2.println("backward");
  analogWrite(aBackward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dBackward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void right(int sped, int del){//Serial2.println("right");
  analogWrite(aForward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void left(int sped, int del){//Serial2.println("left");
  analogWrite(aBackward, sped);
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void spinLeft(int sped, int del){//Serial2.println("spin left");
  analogWrite(aBackward, sped);
  analogWrite(bForward, sped);
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void spinRight(int sped, int del){//Serial2.println("spin right");
  analogWrite(aForward, sped);
  analogWrite(bBackward, sped);
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void squareSpinLeft(int sped, int del){//Serial2.println("square spin left");
  analogWrite(cBackward, sped);
  analogWrite(dForward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void squareSpinRight(int sped, int del){//Serial2.println("square spin right");
  analogWrite(cForward, sped);
  analogWrite(dBackward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void frontLeft(int sped, int del){//Serial2.println("front left");
  analogWrite(bForward, sped);
  analogWrite(cForward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void frontRight(int sped, int del){//Serial2.println("front right");
  analogWrite(aForward, sped);
  analogWrite(dForward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void backLeft(int sped, int del){//Serial2.println("back left");
  analogWrite(aBackward, sped);
  analogWrite(dBackward, sped);
  if (del != 0 ){delay(del);quickStop();}
}

void backRight(int sped, int del){//Serial2.println("back right");
  analogWrite(bBackward, sped);
  analogWrite(cBackward, sped);
  if (del != 0 ){delay(del);quickStop();}
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
