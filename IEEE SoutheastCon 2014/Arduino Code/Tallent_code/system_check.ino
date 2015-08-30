void system_check(){
  Serial3.println("Testing started...");
  Serial3.println("Forward...");
  forward(100);
  delay(1000);
  quickStop();
  Serial3.println("Backward...");
  backward(100);
  delay(1000);
  quickStop();
  Serial3.println("Pan/Tilt...");
  servo_test();
  Serial3.println("Fire Motor...");
  digitalWrite(fire_on, LOW);
  delay(1000);
  digitalWrite(fire_on, HIGH);
  Serial3.println("Sensor Data...");
  sensorOut();
  Serial3.println("Systems test finished");
  Serial3.println("To check sensors again, press 'n'");
  Serial3.println();
}
