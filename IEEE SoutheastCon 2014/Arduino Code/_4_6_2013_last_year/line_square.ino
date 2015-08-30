void lineSquare(int flag1){
  ////Serial2.println("lineSquare");
  int seenWhite = 0;
  for(int i=0;i<5;i++){
    delay(50);
    int tempCount1=0;
    int tempCount2=0;
    int flag=0;
    int count = 0;
    while(1){
      if(count > 5){backRight(255,50);break;}
      int left_line = analogRead(leftLine);int middle_line = analogRead(middleLine);int right_line = analogRead(rightLine);
      int top_left = analogRead(topLeft)-20;int top_right = analogRead(topRight);int low_left = analogRead(lowLeft);int low_right = analogRead(lowRight);
      if(leftLine < whiteValue || rightLine < whiteValue){
        seenWhite = 1;
      }
      if(left_line < whiteValue && middle_line > whiteValue && right_line < whiteValue){  //left and right line detectors on
        break;
      }
      else if(left_line < whiteValue && middle_line < whiteValue && right_line > whiteValue){  //on the right corner, left and middle on
        break;
      }
      else if(left_line > whiteValue && middle_line < whiteValue && right_line < whiteValue){  //on the left corner, right and middle on
        break;
      }
      else if(top_left > wall && top_right > wall){  //no sensors on and too close to wall
        if(tempCount1 < 5){
          backRight(255,75);
          tempCount1++;
        }
        else{
         backLeft(255,75);
        }
      }
      
      else if(left_line > whiteValue && middle_line > whiteValue && right_line > whiteValue && top_left < wall && top_right < wall){  //no sensors on and wall far away
        forward(55,2);
      }
      
      else if(left_line > whiteValue && middle_line > whiteValue && right_line < whiteValue){flag = 1;  //only right sensor on
        if(top_left < wall && top_right < wall){
          if(seenWhite == 0){
            squareSpinRight(100,15);
          }
          else{
            squareSpinRight(150,15);
          }
        }
        else{backRight(200,50);}
      }
      
      else if(left_line < whiteValue && middle_line > whiteValue && right_line > whiteValue){flag = 2;  //only left sensor on
        if(top_left < wall && top_right < wall){
          if(seenWhite == 0 || flag1 == 0){
            squareSpinLeft(100,15);
          }
          else{
            squareSpinLeft(150,15);
          }
        }
        else{backLeft(200,50);}
      }
      
      else if (left_line < whiteValue && middle_line < whiteValue && right_line < whiteValue){flag = 3;  //all sensors are on
        backward(200,1);
      }
      
      else if(left_line > whiteValue && middle_line < whiteValue && right_line > whiteValue){flag = 4;  //only middle on
        if(top_left < top_right){
         if(seenWhite == 0 || flag1 == 0){
            squareSpinRight(100,15);
          }
          else{
            squareSpinRight(150,15);
          }
        }
        else if(top_left > top_right){
          if(seenWhite == 0){
            squareSpinLeft(100,15);
          }
          else{
            squareSpinLeft(150,15);
          }
        }
      }
      
      else if(top_left > (wall+10) || top_right > (wall+10)){Serial2.println("1");  //no sensors on and too close to wall
        if(tempCount2 < 5){
          backRight(255,75);
          tempCount2++;
        }
        else{
         backLeft(255,75);
        }
      }
      
      //all conditions that break the loop
      //else 
    }
  }
  //Serial2.println("exiting line square");
}



void lineSquareRamp(){
  int leftFlag = 0;
  int rightFlag = 0;
  int count = 0;
  for(int i=0;i<3;i++){
    int lastLine = 2;  //0 for left, 1 for right
    delay(20);
    int tempCount1=0;
    int tempCount2=0;
    int dir;  //0 is left, 1 is right
    int temp1 = 0;
    while(1){
      //if(count >=25){break;}
      if(leftFlag == 1 && rightFlag == 1){count++;}
      int left_line = analogRead(leftLine);int middle_line = analogRead(middleLine);int right_line = analogRead(rightLine);
      if(left_line < whiteValue){leftFlag = 1;}
      if(right_line < whiteValue){rightFlag = 1;}
      if(leftFlag == 1 && rightFlag == 1){
        int left_line = analogRead(middleLeftLine);int middle_line = analogRead(middleLine);int right_line = analogRead(middleRightLine);
      }
      if(left_line > whiteValue && middle_line > whiteValue && right_line > whiteValue){  //no sensors on and wall far away
        forward(55,2);
      }
      
      else if(left_line > whiteValue && middle_line > whiteValue && right_line < whiteValue){  //only right sensor on
      lastLine = 1;
      int count = 0;
        for(int i=0;i<5;i++){
          squareSpinRight(100,20);
          if(middleLine < whiteValue){
            backRight(50,40);
            temp1 = 1;
            count = i;
            break;
          }
        }
        if(temp1 == 0){
          for(int i = 0;i < 5;i++){
            squareSpinLeft(100,20);
          }
          backRight(50,40);
        }
        temp1 = 0;
        backRight(50, 40);
        right(50, 50);
        dir = 1;
      }
      
      else if(left_line < whiteValue && middle_line > whiteValue && right_line > whiteValue){  //only left sensor on
        lastLine = 0;
        int count = 0;
        for(int i=0;i<5;i++){
          squareSpinLeft(100,20);
          if(middleLine < whiteValue){
            backLeft(50,40);
            temp1 = 1;
            count = i;
            break;
          }
        }
        if(temp1 == 0){
          for(int i = 0;i < 5;i++){
            squareSpinRight(100,20);
          }
          backLeft(50,40);
        }
        temp1 = 0;
        backLeft(50, 20);
        left(50, 20);
        dir = 0;
      }
      
      else if (left_line < whiteValue && middle_line < whiteValue && right_line < whiteValue){  //all sensors are on
        break;
        //backward(200,1);
      }
      
      else if(left_line > whiteValue && middle_line < whiteValue && right_line > whiteValue){  //only middle on
        if(lastLine == 0){
          backLeft(50, 50);
          left(50, 50);
        }
        else if(lastLine ==1){
          backRight(50, 50);
          right(50, 50);
        }
        /*
        if(dir == 0){
          backLeft(75, 50);
          left(75, 50);
        }
        else if(dir ==1){
          backRight(75, 50);
          right(75, 50);
        }
        */
      }
      else if(left_line < whiteValue && middle_line > whiteValue && right_line < whiteValue){  //left and right line detectors on
        break;
      }
      else if(left_line < whiteValue && middle_line < whiteValue && right_line > whiteValue){  //on the right corner, left and middle on
        left(255,50);
        break;
        /*
        lastLine = 0;
        backLeft(50, 40);
        left(50, 50);
        dir = 0;
        */
      }
      else if(left_line > whiteValue && middle_line < whiteValue && right_line < whiteValue){  //on the left corner, right and middle on
        right(255,50);
        break;
        /*
        lastLine = 1;
        backRight(50, 40);
        right(50, 50);
        dir = 1;
        */
      }
    }
  }
}


