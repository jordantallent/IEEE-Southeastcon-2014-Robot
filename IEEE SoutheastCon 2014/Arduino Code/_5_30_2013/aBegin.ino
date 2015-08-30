
void aBegin(){
  while(distance(frontPing) < 24){
    backward(255);
  }
  while(analogRead(leftLine3) > whiteValue && analogRead(rightLine3) > whiteValue){
    backward(125);
  }
  lineUp();
  trackRight();
  quickStop();
  
}
