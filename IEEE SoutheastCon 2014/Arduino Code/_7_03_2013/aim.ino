void aim(int line){  //line is either a 1, 2, or 3 for each shooting line on the course
  int dist;  //dist will be set to the appropriate length from each shooting line
  if(line == 1){dist = 50;}      //distance to goal from line 1
  else if(line == 2){dist = 60;}  //distance to goal from line 2(three point)
  else if(line == 3){dist = 70;}  //distance to goal from line 3(half court)
  if(distance(leftPing) > distance(rightPing)){  //on the right side of course and needs to spin left to see goal
    while(distance(mastPing) > dist){
      spinLeft(100);  //turn left until the ping sensor 'sees' the goal
    }
    quickStop();
  }
  else if(distance(leftPing) < distance(rightPing)){  //on the right side of the course and needs to spin right to see goal
    while(distance(mastPing) > dist){
      spinRight(100);  //turn right until the ping sensor 'sees' the goal
    }
    quickStop();
  }
}
