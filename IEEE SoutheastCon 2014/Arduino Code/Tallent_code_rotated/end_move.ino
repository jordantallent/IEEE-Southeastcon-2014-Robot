void end_move(){
  squareUp();
  while(distance(frontLeftPing) < 36){
    backward(mSpeed);
  }
  squareUp();
  spinLeft(mSpeed);
  delay(1500);
  squareUp();
  int start = millis();
  while(distance(frontLeftPing) < 88){
    if((millis() - start) > 1000){break;}
    backward(200);
  }
  while(distance(leftFrontPing) < 11){
    right(mSpeed);
  }
  quickStop();
  while(1);
}
