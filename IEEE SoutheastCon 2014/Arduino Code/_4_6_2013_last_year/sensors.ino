void sensors(){
  Serial2.println("---------------------------------------");
  Serial2.print("Left Line = ");Serial2.println(analogRead(leftLine));
  Serial2.print("Middle Line = ");Serial2.println(analogRead(middleLine));
  Serial2.print("Right Line = ");Serial2.println(analogRead(rightLine));
  Serial2.print("Middle Left Line = ");Serial2.println(analogRead(middleLeftLine));
  Serial2.print("Middle Right Line = ");Serial2.println(analogRead(middleRightLine));
  Serial2.print("Top Left IR = ");Serial2.println(analogRead(topLeft));
  Serial2.print("Top Right IR = ");Serial2.println(analogRead(topRight));
  Serial2.print("Low Left IR = ");Serial2.println(analogRead(lowLeft));
  Serial2.print("Low Right IR = ");Serial2.println(analogRead(lowRight));
  Serial2.print("Pressure = ");Serial2.println(analogRead(pressure));
  Serial2.print("length1=");Serial2.print(digitalRead(length1));Serial2.print(", \t");
    Serial2.print("length2=");Serial2.print(digitalRead(length2));Serial2.print(", \t");
    Serial2.print("length3=");Serial2.println(digitalRead(length3));
  Serial2.print("Battery = ");Serial2.println(analogRead(battery));batteryCheck();
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial2.print("Gyro (x,y,z) = ");Serial2.print(gx);Serial2.print("\t");Serial2.print(gy);Serial2.print("\t");Serial2.println(gz);
  Serial2.print("Accel (x,y,z) = ");Serial2.print(ax);Serial2.print("\t");Serial2.print(ay);Serial2.print("\t");Serial2.println(az);
  
  analogWrite(LED,255);delay(250);
  Serial2.print("Color = ");Serial2.print("\t");
  Serial2.print(colors.getRed());Serial2.print("\t");Serial2.print(colors.getGreen());Serial2.print("\t");Serial2.println(colors.getBlue());
  delay(250);analogWrite(LED,0);
  
  Serial2.print("Spot color = \t");spotColor();
  if(analogRead(lowLeft) > 250 && analogRead(lowRight) > 250){
    Serial2.print("Block color = \t");blockColor();
  }
  Serial2.println("---------------------------------------");
  
}
void analogSensors(){
  Serial2.println("---------------------------------------");
  Serial2.print("Left Line = ");Serial2.println(analogRead(leftLine));
  Serial2.print("Middle Line = ");Serial2.println(analogRead(middleLine));
  Serial2.print("Right Line = ");Serial2.println(analogRead(rightLine));
  Serial2.print("Middle Left Line = ");Serial2.println(analogRead(middleLeftLine));
  Serial2.print("Middle Right Line = ");Serial2.println(analogRead(middleRightLine));
  Serial2.print("Top Left IR = ");Serial2.println(analogRead(topLeft));
  Serial2.print("Top Right IR = ");Serial2.println(analogRead(topRight));
  Serial2.print("Low Left IR = ");Serial2.println(analogRead(lowLeft));
  Serial2.print("Low Right IR = ");Serial2.println(analogRead(lowRight));
  Serial2.print("Pressure = ");Serial2.println(analogRead(pressure));
  Serial2.print("length1=");Serial2.print(digitalRead(length1));Serial2.print(", \t");
    Serial2.print("length2=");Serial2.print(digitalRead(length2));Serial2.print(", \t");
    Serial2.print("length3=");Serial2.println(digitalRead(length3));
  Serial2.print("Battery = ");Serial2.println(analogRead(battery));batteryCheck();
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial2.print("Gyro (x,y,z) = ");Serial2.print(gx);Serial2.print("\t");Serial2.print(gy);Serial2.print("\t");Serial2.println(gz);
  Serial2.print("Accel (x,y,z) = ");Serial2.print(ax);Serial2.print("\t");Serial2.print(ay);Serial2.print("\t");Serial2.println(az);
  Serial2.println("---------------------------------------");
}
