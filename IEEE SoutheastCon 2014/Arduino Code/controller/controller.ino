#include <HIDKeyboard.h>
#include <Keypad.h>

HIDkeyboard keyboard; // Initialize HIDkeyboard object

const byte ROWS = 4;
const byte COLS = 3;

char Keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {8, 3, 4, 6};
byte colPins[COLS] = {7, 9, 5};

Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 

void setup() {
  keyboard.begin(); // Start communication
  delay(2000); // Wait for device to be found as a keyboard
}

void loop() {
  char key = customKeypad.getKey();
  
  if (key != NO_KEY && key != 'x'){
    if     (key == '1'){keyboard.print("q");}
    else if(key == '2'){keyboard.print("w");}
    else if(key == '3'){keyboard.print("e");}
    else if(key == '4'){keyboard.print("a");}
    else if(key == '5'){keyboard.print("j");}
    else if(key == '6'){keyboard.print("d");}
    else if(key == '7'){keyboard.print("z");}
    else if(key == '8'){keyboard.print("s");}
    else if(key == '9'){keyboard.print("x");}
    else if(key == '0'){keyboard.print("0");}
    else if(key == '*'){keyboard.print("g");}
    else if(key == '#'){keyboard.print("h");}
  
  }
}
