void sensors(){
  Serial.println("---------------------------------------");
  
  Serial.print("Front Left = ");Serial.println(distance(frontLeftPing));
  Serial.print("Front Right = ");Serial.println(distance(frontRightPing));
  Serial.print("Left = ");Serial.println(distance(leftPing));
  Serial.print("Mast = ");Serial.println(distance(mastPing));
  Serial.print("Spot detect = ");Serial.println(digitalRead(spotDetect));
  Serial.print("Start photocell = ");Serial.println(analogRead(start));
  
  Serial.println("---------------------------------------");
  
  //print over bluetooth
  Serial2.println("---------------------------------------");
  
  Serial2.print("Front Left = ");Serial2.println(distance(frontLeftPing));
  Serial2.print("Front Right = ");Serial2.println(distance(frontRightPing));
  Serial2.print("Left = ");Serial2.println(distance(leftPing));
  Serial2.print("Mast = ");Serial2.println(distance(mastPing));
  
  Serial2.println("---------------------------------------");
  
}

