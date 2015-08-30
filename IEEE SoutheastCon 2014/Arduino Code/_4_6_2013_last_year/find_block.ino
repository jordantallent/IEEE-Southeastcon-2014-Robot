void findBlock(int temp){  //temp = 0 for
  //Serial2.println("findBlock");
  int dir=1;  //1 for right, 0 for left
  lineSquare(0);
  if(temp == 0 && smallBlock1[0] != blockCount && smallBlock2[0] != blockCount && missedColor1 != blockCount && missedColor2 != blockCount && missedColor3 != blockCount && missedColor4 != blockCount && missedColor5 != blockCount && lastSize != 2){  //initial one check to the left
    backLeft(255,20);left(255,75);  //move left once just to be safe and double check for block
    lineSquare(0);
  }
  delay(15);
  
  if(temp == 0 && smallBlock1[0] != blockCount && smallBlock2[0] != blockCount && lastSize != 2){
    
    while(analogRead(lowLeft) > 250 || analogRead(lowRight) > 250){  //scan left until no blocks are seen
      if(analogRead(leftLine) > whiteValue){break;}
      backLeft(255,20);left(255,75);
      lineSquare(0);
    }
    
    if(analogRead(leftLine) < whiteValue){
      backLeft(255,20);left(255,75);
    }
    lineSquare(0);
    while(analogRead(lowLeft) > 250 || analogRead(lowRight) > 250){  //scan left until no blocks are seen
      if(analogRead(leftLine) > whiteValue){break;}
      backLeft(255,20);left(255,75);
      lineSquare(0);
    }
  }
  
  while(1){
    batteryCheck();
    //center up on found block
    if(analogRead(lowLeft) > 250 && analogRead(lowRight) < 250){  //if block seen on left but not right, center on it
      left(255, 20);
      lineSquare(0);
    }
    else if (analogRead(lowLeft) < 250 && analogRead(lowRight) > 250){  //if block seen on right but not left, look to the left a little
      right(255,20);
      lineSquare(0);
    }
    else if (analogRead(lowLeft) > 250 && analogRead(lowRight) > 250){  //both sensors see block
      //lineSquare(0);
      break;
    }
    else if(analogRead(rightLine) > whiteValue){  //if right line sensor is off line, change direction
      dir = 0;
      backLeft(255,20);left(255,100);
      lineSquare(0);
    }
    else if(analogRead(leftLine) > whiteValue){  //if left line sensor is off line, change direction
      dir = 1;
      backRight(200,10);right(255,100);
      lineSquare(0);
    }
    else if (analogRead(lowLeft) < 250 && analogRead(lowRight) < 250 && dir == 1){
      backRight(255,20);right(255,75);
      lineSquare(0);
    }
    else if (analogRead(lowLeft) < 250 && analogRead(lowRight) < 250 && dir == 0){
      backLeft(255,20);left(255,75);
      lineSquare(0);
    }
    
  }
}
