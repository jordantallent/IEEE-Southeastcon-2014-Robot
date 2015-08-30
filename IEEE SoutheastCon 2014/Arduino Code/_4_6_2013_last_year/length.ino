/*
int OLDlength(){
  //Serial2.print("length \t");
  int val = 0;
  
  for(int i=0;i<10; i++){
    val += analogRead(pressure);
    delay(5);
  }
  val = val/10;
  Serial2.print(val);Serial2.print(" = ");
  //return 3;
  if (val < 875){
    return 0;}  //no block
  else if (val < 905){
    return 1;}  //small block
  else if (val < 922){
    return 2;}  //medium block
  else {
    return 3;}  //large block
}
*/
int length(){
  //analogSensors();
  delay(100);
  if(digitalRead(length3) == HIGH){  //large block
    Serial2.println("large block");return 3;
  }
  else if(digitalRead(length2) == HIGH){  //medium block
    Serial2.println("medium block");return 2;
  }
  else if(digitalRead(length1) == HIGH){  //small block
    Serial2.println("small block");return 1;
  }
  else{  //no block
    Serial2.println("no block");return 0;
  }
}
