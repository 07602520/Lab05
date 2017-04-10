#include <Keypad.h> 
#include <SevSeg.h>

SevSeg sevseg;

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

void setup()
{
  Serial.begin(9600);
  byte numDigits = 1;
  byte digitPins[] = {10};
  byte segmentPins[] = {A0,A1,A4,A3,A2,12,13,A5};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}
  
void loop()
{
  
  char key = myKeypad.getKey();
  char i,sum,sux=0;
  if (key != NO_KEY)
  {
    Serial.println(key);
    for(i=48;i<58;i++)
    {
      if(key == i)
      {
        sevseg.setNumber(i-48,2);
      }
    }
    for (i=65;i<71;i++)
    {
      if(key == i)
        sevseg.setNumber(i-55,2);
    }
  }
  sevseg.refreshDisplay();

}
