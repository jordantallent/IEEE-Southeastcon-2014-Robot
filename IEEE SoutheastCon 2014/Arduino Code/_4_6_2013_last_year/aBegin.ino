int smallBlockFlag = 0;
void aBegin(){
  delay(500);
  int startTime = millis();
  smallBlockFlag = 0;
  wall = wall6;
  upDown.writeMicroseconds(upDownUp);
  claw.writeMicroseconds(clawOpen);
  
  distance(1);
  frontRight(255,600);
  distance(15);
  lineSquare(0);
  while(analogRead(leftLine) < whiteValue){
    left(255,75);
    lineSquare(0);
  }
  /*
  rotate(a30);
  distance(18);
  delay(100);
  rotate(-a30);
  delay(100);
  distance(13);
  */
  while(1){    //main loop to find blocks and put them where they go
    if(blockCount == 14){
       break;
    }
    batteryCheck();
    wall = wall6;
    lineSquare(0);
    upDown.writeMicroseconds(upDownBlocks);
    if(smallBlockFlag == 0){findBlock(0);}
    else{findBlock(1);smallBlockFlag = 0;}
    blockColor();
    if(block != 0){
      findBlock(1);
      pickUp();
      delay(50);
    }
    else{
      
      blockCount++;
      if(missedColor1 == 0){
        missedColor1 = blockCount;
          //Serial2.print("missed color at spot ");Serial2.println(missedColor1); 
      }
      else if(missedColor2 == 0){
        missedColor2 = blockCount;
          //Serial2.print("missed color at spot ");Serial2.println(missedColor2); 
      }
      else if(missedColor3 == 0){
        missedColor3 = blockCount;
          //Serial2.print("missed color at spot ");Serial2.println(missedColor3); 
      }
      else if(missedColor4 == 0){
        missedColor4 = blockCount;
          //Serial2.print("missed color at spot ");Serial2.println(missedColor4); 
      }
      else if(missedColor5 == 0){
        missedColor5 = blockCount;
          //Serial2.print("missed color at spot ");Serial2.println(missedColor5); 
      }
      right(255,75);
    }
    int count=0;
    
    //pick up and decide length
    while(1){
      batteryCheck();
      if(block == 0){break;}
      
      //NO BLOCK
      if (length() == 0){//Serial2.println("no block");  //no block
        if (count == 3){
          right(255,150);
          claw.writeMicroseconds(clawOpen);
          break;
          
        }
        findBlock(1);
        pickUpMiss();
        count++;
      }
      
      //SMALL BLOCKS
      else if (length()==1){//Serial2.println("small block");  //small block
        blockCount++;
        //airBlocks();
        //break;
        
        
        if(smallBlock1[0]==0){
          smallBlock1[0]=blockCount;
          smallBlock1[1]=block;
          Serial2.print("small block at spot ");Serial2.println(smallBlock1[0]);
        }
        else if(smallBlock2[0]==0 && smallBlock1[1] != block){
          smallBlock2[0]=blockCount;
          smallBlock2[1]=block;
          Serial2.print("small block at spot ");Serial2.println(smallBlock2[0]);
        }
        else{
          blockCount--;
          smallBlockFlag = 1;
        }
        putDown();
        backRight(255,50);right(255,150);
        break;
        
      }
      
      //MEDIUM BLOCKS
      else if (length()==2){//Serial2.println("medium block");  //medium block
        lastSize = 2;
        blockCount++;
        wall = wall4;
        backward(255,50);
        rotate(-a90);
        upDown.writeMicroseconds(upDownSpots);
        noInterrupts();
        AEncoderTicks = 0;
        interrupts();
        while((analogRead(topLeft) < (wall - 250)) || (analogRead(topRight) < (wall - 250))){
         forward(225,100); 
        }
        
        
        while(analogRead(leftLine) > whiteValue && analogRead(middleLine) > whiteValue && analogRead(rightLine) > whiteValue){
          forward(55,2);
        }
        int tempDist = abs(AEncoderTicks)-175;
        lineSquare(0);
        findSpot();
        //lineSquare(0);
        int temp=0;
        if(analogRead(rightLine) > whiteValue){
          temp = 1;
        }
        easy();
        backward(255,20);
        upDown.writeMicroseconds(upDownDown);
        delay(500);
        forward(255,30);
        putDown();  //place block into space
        backward(255,35);
        left(255,100);
        if(temp == 1){left(255,200);}  //go an extra jump left if at the right edge of sea blocks
        lineSquare(0);
        
        noInterrupts();
        AEncoderTicks = 0;
        interrupts();
        if(blockCount < 14){  //if not all blocks have been found, go to the next block in the row
          while(abs(AEncoderTicks) < tempDist){
           backward(225,100);
          }
        }
        else{  //if all 14 blocks have been found, go find the first small block
          while(abs(AEncoderTicks) < 200){
            backward(225,100);
          }
        }
        rotate(a90);
        while(analogRead(topLeft) < (wall6-150) && analogRead(topRight) < (wall6-150)){  //going back to blocks after already facing them
          forward(225, 100);
        }
        break;
        
      }
      
      //LARGE BLOCKS
      else if (length()==3){//Serial2.println("large block");  //large block
      lastSize = 3;
        blockCount++;
        wall = wall5;
        backward(255,50);
        if(blockCount < 4){  //135
          rotate(148);
          upDown.writeMicroseconds(upDownSpots);
          distance(37);
          lineSquare(1);
          findSpot();
          easy();
          backward(255,20);
          upDown.writeMicroseconds(upDownDown);
          delay(500);
          forward(255,30);
          putDown();  //place block into space
          backward(255,15);
          lineSquare(1);
          while(analogRead(rightLine) < whiteValue){
            right(255,100);
            lineSquare(0);
          }
          backward(255,65);
          rotate(173);distance(25);
          break;
        }
        else if(blockCount < 7){  //145
          rotate(165);
          upDown.writeMicroseconds(upDownSpots);
          distance(28);
          lineSquare(1);
          findSpot();
          easy();
          backward(255,20);
          upDown.writeMicroseconds(upDownDown);
          delay(500);
          forward(255,30);
          putDown();  //place block into space
          backward(255,30);
          lineSquare(1);
          while(analogRead(rightLine) < whiteValue){
            right(255,100);
            lineSquare(0);
          }
          backward(255,50);
          rotate(185);distance(25);
          break;
        }
        else if(blockCount < 10){  //153
          rotate(180);
          upDown.writeMicroseconds(upDownSpots);
          distance(22);
          lineSquare(1);
          findSpot();
          easy();
          backward(255,20);
          upDown.writeMicroseconds(upDownDown);
          delay(500);
          forward(255,30);
          putDown();  //place block into space
          backward(255,30);
          lineSquare(1);
          while(analogRead(rightLine) < whiteValue){
            right(255,100);
            lineSquare(0);
          }
          backward(255,50);
          rotate(200);distance(20);
          break;
        }
        else if(blockCount < 12){  //164
          rotate(205);
          upDown.writeMicroseconds(upDownSpots);
          distance(20);
          lineSquare(1);
          findSpot();
          easy();
          backward(255,20);
          upDown.writeMicroseconds(upDownDown);
          delay(500);
          forward(255,30);
          putDown();  //place block into space
          backward(255,30);
          lineSquare(1);
          while(analogRead(rightLine) < whiteValue){
            right(255,100);
            lineSquare(0);
          }
          backward(255,50);
          rotate(220);distance(18);
          break;
        }
        else if(blockCount < 15){  //180
          rotate(215);
          upDown.writeMicroseconds(upDownSpots);
          distance(18);
          lineSquare(1);
          findSpot();
          easy();
          backward(255,20);
          upDown.writeMicroseconds(upDownDown);
          delay(500);
          forward(255,30);
          putDown();  //place block into space
          lineSquare(1);
          while(analogRead(leftLine) > whiteValue){
            right(255,75);
            lineSquare(0);
          }
          lineSquare(1);
          backward(255,50);
          rotate(205);distance(18);
          break;
        }
        
        else{  //if all of the blocks have been placed after this one, go back to search for the small blocks
          rotate(215);
          upDown.writeMicroseconds(upDownSpots);
          distance(18);
          lineSquare(1);
          findSpot();
          easy();
          backward(255,20);
          upDown.writeMicroseconds(upDownDown);
          delay(500);
          forward(255,30);
          putDown();  //place block into space
          backward(255,30);
          lineSquare(1);
          while(analogRead(rightLine) < whiteValue){  //go to right corner to get ready to go back to block pick up location
            right(255,100);
            lineSquare(0);
          }
          if(smallBlock1[0] < 4){
            backward(255,50);
            rotate(173);distance(25);
          }
          else if(smallBlock1[0] < 7){
            backward(255,50);
            rotate(185);distance(25);
          }
          else if(smallBlock1[0] < 10){
            backward(255,50);
            rotate(200);distance(20);
          }
          else if(smallBlock1[0] < 12){
            backward(255,50);
            rotate(220);distance(18);
          }
          else if(smallBlock1[0] < 15){
            backward(255,50);
            rotate(210);distance(18);
          }
          
          break;    //exit loop and move to finding and placing the small blocks
        }
        
      }
    }
  }
  
  while(1){  //retrieve and place first small block
    findBlock(0);
    blockColor();
    findBlock(1);
    pickUp();
    airBlocks();
    if(smallBlockCount == 2){
      for(int i=0;i<10;i++){
        digitalWrite(LED, HIGH);
        digitalWrite(solidState,LOW);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(solidState,HIGH);
        delay(100);
      }
      digitalWrite(LED,HIGH);
      digitalWrite(solidState,HIGH);
      break;
    }
  }
  
}
