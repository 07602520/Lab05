#include <Keypad.h> 

#define KEY_ROWS 4 
#define KEY_COLS 4 
 

char keymap[KEY_ROWS][KEY_COLS] = {
  {'0', '4', '8', 'C'},
  {'1', '5', '9', 'D'},
  {'2', '6', 'A', 'E'},
  {'3', '7', 'B', 'F'}};
  
byte colPins[KEY_COLS] = {9,8,7,6};	   。
byte rowPins[KEY_ROWS] = {5,4,3,2};  

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);
 
void setup(){
  Serial.begin(9600);
}
  
void loop(){
  
  char key = myKeypad.getKey();
  
  if (key){  
    Serial.println(key);  
  }
}
