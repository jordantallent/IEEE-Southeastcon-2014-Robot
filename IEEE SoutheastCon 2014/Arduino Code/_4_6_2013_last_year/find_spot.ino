void findSpot(){
  //Serial2.println("findSpot");
  int count = 0;
  int dir=1;  //0 is left, 1 is right
  int color;
  while(1){
    batteryCheck();
    if(analogRead(lowLeft) < 250 && analogRead(lowRight) < 250){  //if there is no block, check color
      color = spotColor();
    }
    if(color == block && analogRead(lowLeft) < 250 && analogRead(lowRight) < 250){  //the spot color matches the color of the block and there is no block
//      if(block == 4){  //if it sees yellow move a little over, it is probably seeing white line bleeding
//       if(dir == 0){
//         left(200,50);
//       }
//       else if(dir == 1){
//         right(200,50);
//       }
//       break;
//      }
      if(block == 3 || block == 4 || block == 6){  //double check if it sees an orange or yellow spot to make sure it is actually orange or yellow
        if(dir == 0){
          backLeft(175,5);left(175,50);lineSquare(0);
          if(spotColor() == block){    //second check
            backLeft(175,5);left(175,50);lineSquare(0);
            if(spotColor() == block){    //third check
              backRight(175,5);right(175,50);lineSquare(0);
              if(spotColor() == block){    //double check return for block placement
                break;
              }
            }
            else{    //if third check is not the same color
              backRight(175,5);right(175,60);lineSquare(0);
              if(spotColor() == block){
                break; 
              }
            }
          }
          else{    //second check not the right color
            backRight(175,5);right(175,60);lineSquare(0);
            if(spotColor() == block){
             break; 
            }
          }
        }
        else if(dir == 1){
          backRight(175,5);right(175,50);lineSquare(0);
          if(spotColor() == block){    //second check
            backRight(175,5);right(175,50);lineSquare(0);
            if(spotColor() == block){    //third check
              backLeft(175,5);left(175,50);lineSquare(0);
              if(spotColor() == block){    //double check return for block placement
                break;
              }
            }
            else{    //if third check is not the same color
              backLeft(175,5);left(175,60);lineSquare(0);
              if(spotColor() == block){
                break; 
              }
            }
          }
          else{    //second check not the right color
            backLeft(175,5);left(175,60);lineSquare(0);
            if(spotColor() == block){
             break; 
            }
          }
        }
        
      }
      else{break;}
    }
    else if(analogRead(leftLine) < whiteValue && analogRead(rightLine) > whiteValue){    //left is on, right off
      if(count == 0 && analogRead(lowLeft) < 250 && analogRead(lowRight) < 250){  //search one more time to the right
        backRight(255,20);right(255,75);lineSquare(0);
        count = 1;
      }
      else{
        dir = 0;
        backLeft(255,25);left(255, 150);
        lineSquare(0);
        count = 0;
      }
    }
    else if (analogRead(leftLine) > whiteValue && analogRead(rightLine) < whiteValue){    //left is off, right on
      if(count == 0 && analogRead(lowLeft) < 250 && analogRead(lowRight) < 250){  //search one more time to the left
        backLeft(255,20);left(255,75);lineSquare(0);
        count = 1;
      }
      else{
        dir = 1;
        backRight(255,25);right(255,150);
        lineSquare(0);
        count = 0;
      }
    }
    else if (dir == 0){
      backLeft(255,25);left(255, 75);
      lineSquare(0);
    }
    else if (dir == 1){
      backRight(255,25);right(255, 75);
      lineSquare(0);
    }
  }
}
