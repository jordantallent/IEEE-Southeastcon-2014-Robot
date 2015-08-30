void easy(){
  pinMode(startButton, OUTPUT);
  digitalWrite(startButton, HIGH);
  delay(10);
  digitalWrite(startButton, LOW); 
  pinMode(startButton, INPUT);
}
