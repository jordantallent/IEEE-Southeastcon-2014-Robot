//Interrupt service routines for the A motor's quadrature encoder
void HandleAMotorInterruptA(){
  // Test transition; since the interrupt will only fire on 'rising' we don't need to read pin A
  AEncoderBSet = digitalReadFast(AEncoderPinB);   // read the input pin
  // and adjust counter + if A leads B
  #ifdef AEncoderIsReversed
    AEncoderTicks -= AEncoderBSet ? -1 : +1;
  #else
    AEncoderTicks += AEncoderBSet ? -1 : +1;
  #endif
}
/*
// Interrupt service routines for the B motor's quadrature encoder
void HandleBMotorInterruptA(){
  // Test transition; since the interrupt will only fire on 'rising' we don't need to read pin A
  BEncoderBSet = digitalReadFast(BEncoderPinB);   // read the input pin
  // and adjust counter + if A leads B
  #ifdef BEncoderIsReversed
    BEncoderTicks -= BEncoderBSet ? -1 : +1;
  #else
    BEncoderTicks += BEncoderBSet ? -1 : +1;
  #endif
}
// Interrupt service routines for the C motor's quadrature encoder
void HandleCMotorInterruptA(){
  // Test transition; since the interrupt will only fire on 'rising' we don't need to read pin A
  CEncoderBSet = digitalReadFast(CEncoderPinB);   // read the input pin
  // and adjust counter + if A leads B
  #ifdef CEncoderIsReversed
    CEncoderTicks -= CEncoderBSet ? -1 : +1;
  #else
    CEncoderTicks += CEncoderBSet ? -1 : +1;
  #endif
}
// Interrupt service routines for the D motor's quadrature encoder
void HandleDMotorInterruptA(){
  // Test transition; since the interrupt will only fire on 'rising' we don't need to read pin A
  DEncoderBSet = digitalReadFast(DEncoderPinB);   // read the input pin
  // and adjust counter + if A leads B
  #ifdef DEncoderIsReversed
    DEncoderTicks -= DEncoderBSet ? -1 : +1;
  #else
    DEncoderTicks += DEncoderBSet ? -1 : +1;
  #endif
}
*/
/*
//StartButton Interrupt
void StartInterruptFunction(){
  Serial2.println("interrupt");
  
  if(hasStarted == 1){
    quickStop();
    while(1){;}
  }
  else{
    hasStarted = 1;
    aBegin();
    
  }
  
}
*/
