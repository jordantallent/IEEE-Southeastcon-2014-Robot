int LL1, LL2, LL3, RL1, RL2, RL3;
/*
void lineUp(){
  LL1 = analogRead(leftFarSensor1);LL2 = analogRead(leftLine2);LL3 = analogRead(leftLine3);
  RL1 = analogRead(leftLine1);RL2 = analogRead(leftLine2);RL3 = analogRead(leftLine3);
  while(1){  //run until both middle sensors are on
    if(LL2 < whiteValue && RL2 < whiteValue){break;}
    else if(LL1 > whiteValue && LL2 > whiteValue && LL3 > whiteValue && RL1 > whiteValue && RL2 > whiteValue && RL3 > whiteValue){
      backward(75);
    }
    else if(LL3 < whiteValue && RL1 > whiteValue && RL2 > whiteValue && RL3 > whiteValue){
      rightSide(-75);
    }
    else if(LL2 < whiteValue && RL1 > whiteValue && RL2 > whiteValue && RL3 > whiteValue){
      rightSide(-75);
    }
    else if(LL2 < whiteValue && RL1 > whiteValue && RL2 > whiteValue && RL3 < whiteValue){
      rightSide(-25);
    }
    else if(LL1 > whiteValue && LL2 > whiteValue && LL3 > whiteValue && RL3 < whiteValue){
      leftSide(-75);
    }
    else if(LL1 > whiteValue && LL2 > whiteValue && LL3 > whiteValue && RL2 < whiteValue){
      leftSide(-75);
    }
    else if(LL1 > whiteValue && LL2 > whiteValue && LL3 < whiteValue && RL2 < whiteValue){
      leftSide(-50);
    }
    
  }
}
*/
void trackLeft(){
  if( analogRead(leftCenterSensor2)<200){
    left(255);
    delay(1);
    frontOnly(255);
    delay(5);
    return;
  }
  if(analogRead(rightCenterSensor2)<200){
    left(255);
    delay(1);
    backOnly(255);
    delay(5);
    return;
  }
  left(255);
  
}

void trackRight(){
  
}

/*
void trackLeft(){
  LL1 = analogRead(leftLine1);LL2 = analogRead(leftLine2);LL3 = analogRead(leftLine3);
  RL1 = analogRead(leftLine1);RL2 = analogRead(leftLine2);RL3 = analogRead(leftLine3);
  if(LL1 < whiteValue){lastLeft = 1;}else if(LL2 < whiteValue){lastLeft = 2;}else if(LL3 < whiteValue){lastLeft = 3;}  //set last known sensor that saw line
  if(RL1 < whiteValue){lastRight = 1;}else if(RL2 < whiteValue){lastRight = 2;}else if(RL3 < whiteValue){lastRight = 3;}  //set last known sensor that saw line
  while(1){
    if(distance(leftPing) < 5){break;}
    else if(digitalRead(leftButton) == HIGH){left(100);delay(500);quickStop(); break;}  //if the button is pressed then keep going to fully cover the space
    else if(LL1 > whiteValue && LL2 > whiteValue && LL3 > whiteValue){
      if(lastLeft == 1){leftSide(75);}
      else if(lastLeft == 3){leftSide(-75);}
    }
    else if(RL1 > whiteValue && RL2 > whiteValue && RL3 > whiteValue){
      if(lastRight == 1){rightSide(75);}
      else if(lastRight == 3){rightSide(-75);}
    }
    else if(LL2 < whiteValue && RL2 < whiteValue){left(255);}
    
  }
  
}
void trackRight(){
  LL1 = analogRead(leftLine1);LL2 = analogRead(leftLine2);LL3 = analogRead(leftLine3);
  RL1 = analogRead(leftLine1);RL2 = analogRead(leftLine2);RL3 = analogRead(leftLine3);
  
}
*/
