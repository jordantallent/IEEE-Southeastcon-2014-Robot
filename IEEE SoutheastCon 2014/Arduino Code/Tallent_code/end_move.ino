void end_move(){
  squareUp();
  while(distance(leftFrontPing) > 12){
    left(mSpeed);
  }
  quickStop();
  squareUp();
  int tempStart = millis();
  while(distance(frontLeftPing) < 87){
    backward(mSpeed);
  }
  quickStop();
  while(distance(leftFrontPing) < 11){
    right(mSpeed);
  }
  quickStop();
  squareUp();
  while(distance(leftFrontPing) > 11){
    left(mSpeed);
  }
  quickStop();
  squareUp();
  quickStop();
}                                                                                                                                                                                                                                                                                                                                                                                                                                        
