void aim(){
  if(distance(leftPing) > distance(rightPing)){
    while(distance(mastPing) > 50){
      spinLeft(150);
    }
    quickStop();
  }
}
