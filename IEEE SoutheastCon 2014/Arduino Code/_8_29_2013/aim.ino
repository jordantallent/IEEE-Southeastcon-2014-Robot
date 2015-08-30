void aim(){
  if(distance(leftPing) > 24){  //on the right side of course and needs to spin left to see goal
    while(distance(mastPing) > lineTrack){
      spinLeft(100);  //turn left until the ping sensor 'sees' the goal
    }
    quickStop();
  }
  else{  //on the left side of the course and needs to spin right to see goal
    while(distance(mastPing) > lineTrack){
      spinRight(100);  //turn right until the ping sensor 'sees' the goal
    }
    quickStop();
  }
}
void shoot(){
  
}
