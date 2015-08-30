/*-----STEP BY STEP-----
  sense leds are on
  
  move to first line
  scan line for the firing block
  find position to calculate the target location
  fire dart at target
  
  move to second line
  scan line for the firing block
  find position to calculate the target location
  fire dart at target
  
  move to third line
  scan line for the firing block
  find position to calculate the target location
  fire dart at target
  
  move to end position

*/

void run_course(){
  int startTime = millis();
  backward(mSpeed);
  delay(250);
  //first line
  while(distance(frontLeftPing) < firstLine){
    backward(mSpeed);
  }
  quickStop();
  trackLine(firstLine, 1);
  squareUp();
  targeting();
  
  //second line
  backward(100);
  delay(500);
  curvedLine();
  squareUp();
  targeting();
  
  //third line
  backward(100);
  delay(500);
  trackLine(thirdLine, 1);
  squareUp();
  targeting();
  
  //finish
  end_move();
  
 // while(1);
  
  //display run stats
  Serial3.println();
  Serial3.println("Run Finished...");
  int endTime = (millis() - startTime)/1000.00;
  Serial3.print("Course completed in ");
  Serial3.print(endTime);
  Serial3.println(" seconds");
  Serial3.print("Possible bonus points = ");
  Serial3.println(120 - endTime);
  
}
