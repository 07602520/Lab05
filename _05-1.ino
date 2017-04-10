#include <Keypad.h> 

#define KEY_ROWS 4 
#define KEY_COLS 4 
 

char keymap[KEY_ROWS][KEY_COLS] = {
  {'F', 'E', 'D', 'C'},
  {'B', '3', '6', '9'},
  {'A', '2', '5', '8'},
  {'0', '1', '4', '7'}};
  
byte colPins[KEY_COLS] = {9,8,7,6};
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
