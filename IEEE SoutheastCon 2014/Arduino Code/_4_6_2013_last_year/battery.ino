void batteryCheck(){  //check battery voltage
  if(analogRead(battery) < batteryWarn){
    for(int i=0;i<5;i++){
      digitalWrite(LED, HIGH);
      digitalWrite(solidState,LOW);
      delay(50);
      digitalWrite(LED,LOW);
      digitalWrite(solidState,HIGH);
      delay(50);
    }
    digitalWrite(LED,LOW);
    digitalWrite(solidState,LOW);
  }
}
