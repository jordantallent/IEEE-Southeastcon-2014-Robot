void blockColor(){
  //Serial2.print("blockColor \t");
  gainLow();
  block = 0;
  int count=0;
  while(1){
    digitalWrite(solidState, LOW);
    analogWrite(LED, 255);
    float red = colors.getRed();
    float green = colors.getGreen();
    float blue = colors.getBlue();
    analogWrite(LED, 0);
    digitalWrite(solidState, HIGH);
    Serial2.print(red);Serial2.print("\t");Serial2.print(green);Serial2.print("\t");Serial2.println(blue);
    //compare block to known
    if((abs(green-(2.0645*red)-16.861) <= 25) && (abs(blue-(1.1119*red)+0.8229) <= 25)){
      Serial2.println("green");  //green
  	block = 1;break;
    }
    
    else if((abs(green-(.5152*red)+4.0108) <= 15) && (abs(blue-(.2649*red)+9.7363) <= 15) && red > 125){
      Serial2.println("red");  //red
  	block = 2;break;
    }
   
    else if((abs(green-(0.6419*red)+2.4468) <= 20) && (abs(blue-(0.1826*red)+8.5201) <= 20) && red > (50*PI)){
      Serial2.println("orange");  //orange
  	block = 3;break;
    }
    
    else if(red > 200 && green > 200 && blue > 200){
    //else if((abs(green-(((1*pow(10,-6))*pow(red,3))-(.0013*pow(red,2)) - (0.8278*red)-29.119)) <= 20) && (abs(blue-(.1593 * pow(red, 1.1561))) <= 20)){
      Serial2.println("yellow");  //yellow
  	block = 4;break;
    }
    
    else if((abs(green-(1.881*red)-.5125) <= 25) && (abs(blue-(2.8407*red)+14.654) <= 25)){
      Serial2.println("blue");  //blue
  	block = 5;break;
    }
    
      else if((abs(green-(1.0801*red)+9.6584) <= 30) && (abs(blue-(((5*pow(10,-5))*pow(red,3))-(.0142*pow(red,2)) + (0.5291*red)-11.958)) <= 30)){
      Serial2.println("brown");  //brown
  	block = 6;break;
    }
    if(count<5){backward(255, 10);}
    else if(count == 5){left(255,20);findBlock(1);}
    else if(count < 10){backward(255, 10);}
    else{block = 0;break;}
    count++;
  }
  
  
}

int spotColor(){
  //Serial2.print("spotColor \t");
  gainHigh();
  digitalWrite(solidState, LOW);
  analogWrite(LED, 255);
  float red = colors.getRed();
  float green = colors.getGreen();
  float blue = colors.getBlue();
  analogWrite(LED, 0);
  digitalWrite(solidState, HIGH);
  Serial2.print(red);Serial2.print("\t");Serial2.print(green);Serial2.print("\t");Serial2.println(blue);
  //compare to picked up block
  if((abs(green-(2.0645*red)-16.861) <= 25) && (abs(blue-(1.1119*red)+0.8229) <= 25)){
      Serial2.println("green");  //green
  	return 1;
    }
    
    else if((abs(green-(.5152*red)+4.0108) <= 20) && (abs(blue-(.2649*red)+9.7363) <= 20) && red > 75){
      Serial2.println("red");  //red
  	return 2;
    }
    
    else if((abs(green-(0.6419*red)+2.4468) <= 20) && (abs(blue-(0.1826*red)+8.5201) <= 20) && red > (20*PI)){
      Serial2.println("orange");  //orange
  	return 3;
    }
   
    else if(red > 450 && green > 450){// && blue > 200){
    //else if((abs(green-(((1*pow(10,-6))*pow(red,3))-(.0013*pow(red,2)) - (0.8278*red)-29.119)) <= 20) && (abs(blue-(.1593 * pow(red, 1.1561))) <= 20)){
      Serial2.println("yellow");  //yellow
  	return 4;
    }
    
      else if((abs(green-(1.881*red)-.5125) <= 25) && (abs(blue-(2.8407*red)+14.654) <= 20) && blue > 25){
      Serial2.println("blue");  //blue
  	return 5;
    }
    
      else if((abs(green-(1.0801*red)+9.6584) <= 15) && (abs(blue-(((5*pow(10,-5))*pow(red,3))-(.0142*pow(red,2)) + (0.5291*red)-11.958)) <= 15)){
      Serial2.println("brown");  //brown
  	return 6;
    }

  else{
    gainLow();
    digitalWrite(solidState, LOW);
    analogWrite(LED, 255);
    float red = colors.getRed();
    float green = colors.getGreen();
    float blue = colors.getBlue();
    analogWrite(LED, 0);
    digitalWrite(solidState, HIGH);
    Serial2.print(red);Serial2.print("\t");Serial2.print(green);Serial2.print("\t");Serial2.println(blue);
    if((abs(green-(2.0645*red)-16.861) <= 15) && (abs(blue-(1.1119*red)+0.8229) <= 15)){
      Serial2.println("green");  //green
      return 1;
    }
    
    else if((abs(green-(.5152*red)+4.0108) <= 15) && (abs(blue-(.2649*red)+9.7363) <= 15) && red > 20 && red < 51){
      Serial2.println("red");  //red
      return 2;
    }
   
    else if((abs(green-(0.6419*red)+2.4468) <= 25) && (abs(blue-(0.1826*red)+8.5201) <= 25) && red > 50){
      Serial2.println("orange");  //orange
      return 3;
    }
    
    else if((abs(green-(((1*pow(10,-6))*pow(red,3))-(.0013*pow(red,2)) - (0.8278*red)-29.119)) <= 20) && (abs(blue-(.1593 * pow(red, 1.1561))) <= 20)){
      Serial2.println("yellow");  //yellow
      return 4;
    }
    
    else if((abs(green-(1.881*red)-.5125) <= 20) && (abs(blue-(2.8407*red)+14.654) <= 35) && blue > 20){
      Serial2.println("blue");  //blue
      return 5;
    }
    
    else if((abs(green-(1.0801*red)+9.6584) <= 15) && (abs(blue-(((5*pow(10,-5))*pow(red,3))-(.0142*pow(red,2)) + (0.5291*red)-11.958)) <= 15) && (green - red) < 10){
      Serial2.println("brown");  //brown
      return 6;
    }
    else{Serial2.println("none");return 0;}
  }
  
}
void gainHigh(){
    colors.writeInt(INT_CLEAR_LO, 1908);	//1908 353
  colors.writeInt(INT_RED_LO, 4095);	//4095 1035
  colors.writeInt(INT_GREEN_LO, 4095);	//4095 1035
  colors.writeInt(INT_BLUE_LO, 4095);	//4095 1035
}
void gainLow(){
    colors.writeInt(INT_CLEAR_LO, 353);
  colors.writeInt(INT_RED_LO, 1035);
  colors.writeInt(INT_GREEN_LO, 1035);
  colors.writeInt(INT_BLUE_LO, 1035);
}
