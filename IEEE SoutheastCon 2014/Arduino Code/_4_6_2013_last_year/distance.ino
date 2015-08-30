void distance(float aDist){
  Serial2.println("distance");
  noInterrupts();
  delay(20);
  AEncoderTicks = 0;
  delay(20);
  interrupts();
  delay(20);
  float distance = 0.00;
  if (aDist > 0){forward(255, 0);}
  else{backward(255, 0);}
  aDist = abs(aDist);

  do{
    if (analogRead(topLeft) > wall-100 || analogRead(topRight) > wall-100){quickStop();Serial2.println("SAFETY");break;}
    //if(analogRead(leftLine) < whiteValue || analogRead(middleLine) < whiteValue || analogRead(rightLine) < whiteValue){quickStop();break;} 
    distance = abs(float(AEncoderTicks)) * float(distancePerCount);
    //if (analogRead(topLeft) > 190 || analogRead(topRight) > 190){//Serial2.print(analogRead(topLeft));//Serial2.print("-");//Serial2.println(analogRead(topRight));quickStop;break;}
  }while(abs(float(AEncoderTicks)) < ((aDist / (PI * float(wheelDiameter))) * float(countsPerRevolution)));
  quickStop();
}
