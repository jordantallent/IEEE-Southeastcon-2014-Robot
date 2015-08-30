void sensors(){
  Serial.println("---------------------------------------");
  
  Serial.print("Front Left = ");Serial.println(distance(frontLeftPing));
  Serial.print("Front Right = ");Serial.println(distance(frontRightPing));
  Serial.print("Left = ");Serial.println(distance(leftPing));
  
  Serial.println("---------------------------------------");
  
  //print over bluetooth
  Serial2.println("---------------------------------------");
  
  Serial2.print("Front Left = ");Serial.println(distance(frontLeftPing));
  Serial2.print("Front Right = ");Serial.println(distance(frontRightPing));
  Serial2.print("Left = ");Serial.println(distance(leftPing));
  
  Serial2.println("---------------------------------------");
  
}

