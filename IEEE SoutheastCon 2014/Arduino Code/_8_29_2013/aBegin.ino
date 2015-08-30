
void aBegin(){
  while(distance(frontLeftPing) < 9){
    backRight(200);
  }
  for(int i = 0; i < 3; i++){
    if(i = 0){lineTrack = lineDist1;}
    else if(i = 1){lineTrack = lineDist2;}
    else if(i = 2){lineTrack = lineDist3;}
    squareUp();
    while(distance(frontLeftPing) < lineTrack-4){
      backward(200);
    }
    while(distance(frontLeftPing) < lineTrack){
      backward(100);
    }
    onLine();
    findSpot();
    aim();
    shoot();
    squareUp();
  }
  endMove();
  
}
