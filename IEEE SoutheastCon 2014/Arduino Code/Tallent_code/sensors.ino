void sensorOut(){
  Serial3.print("Front left = ");Serial3.println(distance(frontLeftPing));
  Serial3.print("Front right = ");Serial3.println(distance(frontRightPing));
  Serial3.print("Left front = ");Serial3.println(distance(leftFrontPing));
  Serial3.print("Left rear = ");Serial3.println(distance(leftRearPing));
  Serial3.print("Light Sensor1 = ");Serial3.println(analogRead(startDetect1));
  Serial3.print("Light Sensor2 = ");Serial3.println(analogRead(startDetect2));
  Serial3.print("Spot Button Right = ");Serial3.println(digitalRead(spotDetectR));
  Serial3.print("Spot Button Left = ");Serial3.println(digitalRead(spotDetectL));
  Serial3.print("Fire Button = ");Serial3.println(digitalRead(fireCount));
  Serial3.print("Curved distance = ");Serial3.println(sqrt(pow(48,2)-pow(distance(leftFrontPing)-24,2)));
  Serial3.println();
}

float distance(int pin){
  delay(5);
  float duration, inch;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  duration = pulseIn(pin, HIGH);
  inch = duration / 73.746 / 2.0;
  
  if(pin == frontLeftPing || pin == frontRightPing){// || pin == backPing){
    inch += 5.5;
  }
  else if(pin == leftFrontPing || pin == leftRearPing){// || pin == rightPing){
    inch += 4.5;
  }
  return inch;
}
