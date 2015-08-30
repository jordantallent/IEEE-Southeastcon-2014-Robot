
void aBegin(){
  while(distance(frontPing) < 24){
    backward(255);
  }
  while(analogRead(leftNearSensor1) > whiteValue || analogRead(rightNearSensor1) > whiteValue){
    backward(125);
  }
  //lineUp();
  trackRight();
  quickStop();
  
}
