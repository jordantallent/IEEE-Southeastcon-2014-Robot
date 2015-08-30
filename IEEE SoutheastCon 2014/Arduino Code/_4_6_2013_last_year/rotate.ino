void rotate(float angle){
  //Serial2.println("rotate");
  unsigned long time;
  int sampleTime = 5;  // The sampling period of the gyro    10
  int turnRate;  
  float prev_turnRate = 0;
  long turnAngle = 0;
  int dir;
  int rotationThreshold = 2;   //Minimum deg/sec to keep track of, helps with gyro drifting
  if(angle > 0){spinRight(50, 0);}else{spinLeft(50, 0);}
  delay(5);
  if(angle > 0){spinRight(150, 0);}else{spinLeft(150, 0);}
  while(turnAngle < abs(angle)){
    // Every 10 ms take a sample from the gyro
    if(millis() - time > sampleTime){
      time = millis();  // update the time to get the next sample
  
      // get the gyro's angular velocity 
        accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
        turnRate = (abs(gz)/131);
    
      // Integrate the angular veloity to obtain angular position (or inclination)
      // Using the trapeziod method for numerical integration.
      // Angle = ---------------------------------------------- 
      //                        2 * 1000                            
      // because the sampleTime is expressed in milliseconds and rate in degree 
      // per seconds we also need to divide by 1000 ms/s to obtain the correct units. 
  
      // Ignore the gyro if our angular velocity does not meet our threshold
      
      if(turnRate >= rotationThreshold || turnRate <= -rotationThreshold){
        turnAngle  += ((long)(prev_turnRate + turnRate) * sampleTime) / 750;
      }
      
      
      //Serial2.println(turnRate);
      // remember the current speed for the next loop rate integration.
      prev_turnRate = turnRate;
  
      // Keep our angle between 0-359 degrees
      if (turnAngle < 0){
        turnAngle += 360;
      }
      else if (turnAngle > 359){
        turnAngle -= 360;
      }
    }
  }
  quickStop();
}

void TESTrotate(float angle){
  //Serial2.println("rotate");
  unsigned long time;
  int sampleTime = 5;  // The sampling period of the gyro    10
  int turnRate;  
  float prev_turnRate = 0;
  long turnAngle = 0;
  int dir;
  int rotationThreshold = 2;   //Minimum deg/sec to keep track of, helps with gyro drifting
  
  if(angle > 0){spinRight(150, 0);}else{spinLeft(150, 0);}
  
  while(turnAngle < abs(angle)){
    
    time = millis();
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    turnRate = (abs(gz)/75);
    delay(10);
    
    if (turnAngle < 0){
      turnAngle += 360;
    }
    else if (turnAngle > 359){
      turnAngle -= 360;
    }
    
    turnAngle += (turnRate * (millis()-time)/1000);
  }
  quickStop();
}

