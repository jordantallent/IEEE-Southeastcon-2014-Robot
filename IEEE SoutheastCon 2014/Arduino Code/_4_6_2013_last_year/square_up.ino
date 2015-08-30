//----------------------------SQUARING----------------------------
void squareUp(){
  //Serial2.println("squareUp");
  while(1) {
    if (analogRead(topLeft) != analogRead(topRight)){
      if ((analogRead(topLeft)) > analogRead(topRight)){squareSpinLeft(150, 0);}
      else if ((analogRead(topLeft)) < analogRead(topRight)){squareSpinRight(150, 0);}
    }
     else{
       if (abs((analogRead(topLeft)) - analogRead(topRight))>2){
       }
       else{
         quickStop();
         break;}
     }
  }
}
