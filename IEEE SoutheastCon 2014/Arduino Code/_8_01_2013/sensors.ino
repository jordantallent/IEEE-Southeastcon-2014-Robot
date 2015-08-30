void sensors(){
  Serial.println("---------------------------------------");
  
  Serial.print("Front Left = ");Serial.println(distance(frontLeftPing));
  Serial.print("Front Right = ");Serial.println(distance(frontRightPing));
  Serial.print("Left = ");Serial.println(distance(leftPing));
  
  Serial.print("Battery = ");Serial.println(analogRead(battery));batteryCheck();
  
  Serial.println("---------------------------------------");
  //print over bluetooth
  bluetooth.println("---------------------------------------");
  
  bluetooth.print("Front Left = ");Serial.println(distance(frontLeftPing));
  bluetooth.print("Front Right = ");Serial.println(distance(frontRightPing));
  bluetooth.print("Left = ");Serial.println(distance(leftPing));
  
  bluetooth.print("Battery = ");Serial.println(analogRead(battery));batteryCheck();
  
  bluetooth.println("---------------------------------------");
  
}

void batteryCheck(){  //check battery voltage
  if(analogRead(battery) < batteryWarn){
    //battery low
  }
}

