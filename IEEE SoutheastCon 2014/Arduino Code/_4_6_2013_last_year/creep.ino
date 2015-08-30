void creep(){
  //Serial2.println("creep");
  for(int i = 0;i<3;i++){
   delay(125);
   while (1){
     if (analogRead(lowLeft) > 300 || analogRead(lowRight) > 300){
      break; 
     }
     else if (analogRead(leftLine) > whiteValue && analogRead(middleLine) > whiteValue && analogRead(rightLine) > whiteValue && analogRead(topLeft) < 290 && analogRead(topRight) < 290){    //if no sensors are on line
       forward(60, 20);
     }
     
     else if (analogRead(leftLine) > whiteValue && analogRead(middleLine) > whiteValue && analogRead(rightLine) > whiteValue && analogRead(topLeft) > 290 && analogRead(topRight) > 290){  //no white line detected, don't get too close to the wall
       backRight(200, 100);
     }
       
     else if (analogRead(leftLine) < whiteValue && analogRead(middleLine) > whiteValue && analogRead(rightLine) > whiteValue){  //if only left sensor is on line
       squareSpinLeft(200, 50);delay(25);
     }
       
     else if (analogRead(leftLine) > whiteValue && analogRead(middleLine) > whiteValue && analogRead(rightLine) < whiteValue && analogRead(topLeft) < 300 ){  //if only right sensor is on line
       if (analogRead(topLeft) < 300){squareSpinRight(175, 50);quickStop;delay(25);}
       else{backRight(200, 75);}
     }
     
     else if(analogRead(leftLine) > whiteValue && analogRead(middleLine) < whiteValue && analogRead(rightLine) > whiteValue){  //only middle sensor is on a line
      if(analogRead(topLeft) > analogRead(topRight)){squareSpinLeft(175, 75);}
      else{squareSpinRight(200, 50);delay(25);}
     }
     
     else if (analogRead(leftLine) > whiteValue && analogRead(middleLine) < whiteValue && analogRead(rightLine) < whiteValue){  //only right and middle sensors are on line
       if (analogRead(lowLeft) > 250 || analogRead(lowRight) > 250){break;}  //if it sees a block
       else{right(200, 150);}
     }
     
     else if (analogRead(leftLine) < whiteValue && analogRead(middleLine) < whiteValue && analogRead(rightLine) > whiteValue){  //only left and middle sensors are on line
       if (analogRead(lowLeft) > 300 || analogRead(lowRight) > 300){break;}  //if it sees a block
       else{left(200, 150);}
     }
     
     else if (analogRead(leftLine) < whiteValue && analogRead(middleLine) < whiteValue && analogRead(rightLine) < whiteValue){  //all on line, back up
      backward(50, 35);
    }
      
     else if (analogRead(leftLine) < whiteValue && analogRead(middleLine) > whiteValue && analogRead(rightLine) < whiteValue){  //only the two outside sensors are on line
       if (analogRead(lowLeft) > 300 || analogRead(lowRight) > 300){break;}
       else{right(150, 150);}
     }
   }
  }
}
