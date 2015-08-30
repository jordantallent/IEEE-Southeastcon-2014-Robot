void end_move(){
  
  while(distance(frontLeftPing) > 90){
    backward(200);
  }
  if(distance(leftPing) > 8){
    while(distance(leftPing) > 8){
      left(200);
    }
  }
  else if(distance(leftPing) < 8){
    while(distance(leftPing) < 8){
      right(200);
    }
  }
  quickStop();  //finished.
}
