void sensors(){
  Serial.println("---------------------------------------");
  Serial.print("Left Line 1 = ");Serial.println(analogRead(leftLine1));
  Serial.print("Left Line 2 = ");Serial.println(analogRead(leftLine2));
  Serial.print("Left Line 3 = ");Serial.println(analogRead(leftLine3));
  Serial.print("Right Line 1 = ");Serial.println(analogRead(rightLine1));
  Serial.print("Right Line 2 = ");Serial.println(analogRead(rightLine2));
  Serial.print("Right Line 3 = ");Serial.println(analogRead(rightLine3));
  Serial.print("Front = ");Serial.println(distance(frontPing));
  Serial.print("Left = ");Serial.println(distance(leftPing));
  Serial.print("Right = ");Serial.println(distance(rightPing));
  Serial.print("Back = ");Serial.println(distance(backPing));
  
  Serial.print("Battery = ");Serial.println(analogRead(battery));batteryCheck();
  
  Serial.println("---------------------------------------");
  
}

void batteryCheck(){  //check battery voltage
  if(analogRead(battery) < batteryWarn){
    //battery low
  }
}

