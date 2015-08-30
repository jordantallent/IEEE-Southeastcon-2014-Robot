int distance(int pin){
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
  return inch;
}
