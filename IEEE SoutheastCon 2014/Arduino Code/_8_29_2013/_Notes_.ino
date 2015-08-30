/*
//wheel reference - http://www.robotshop.com/content/images//dfrobotshop-rover-mecanum-wheel-motion.jpg
//line sensors - https://www.sparkfun.com/products/9453

5/30/2013
copied over most of code from 2013 comp. (movement for meccanum wheels and manual control from serial)
distance function rewritten to read distance from ultrasonic range finders
Started on line tracking left and right

7/03/2013
removed start button code from previous year.  no start button is required on this
believe to be finished up on the simple aim function for finding the 'goal'

7/22/2013
used line tracking code from http://www.patrickmccabemakes.com/PatrickMccabeMakes/MazeV3Code.html
added a back only and front only function to movement.

8/01/2013
Remove line detectors for tracking along lines.  Use ultrasonics instead
revised tracking code to use ultrasonic instead of line detectors
added seperate software serial port for bluetoth use
ending move added to get robot to finish square
findSpot() function was added
a checker function, onLine(), was added to check that robot is on the line.

8/29/2013
modified movement function, reducing amount of code
reworked line tracking functions


*/
