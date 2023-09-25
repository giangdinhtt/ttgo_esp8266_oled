#include "Wire.h"
#include "OLED.h"

//TTGO 0.91 OLED connection:
//SDA -- D4
//SCL -- D5
//RST -- D2

#define SDA D4
#define SCL D5

OLED display(SDA, SCL);
 
void setup() {
  pinMode(D2, OUTPUT);
  
  // low level signal on D2 restarts OLED
  digitalWrite(D2, LOW);
  delay(50);
  
  // high level signal on D2 cause OLED running
  digitalWrite(D2, HIGH);
  
  Serial.begin(115200);
  Serial.println("OLED test!");
 
  // Initialization
  display.begin();
 
  // Test message
  display.print("Hello TTGO");
  delay(3*1000);
  
  // Clear display
  display.clear();
  delay(3*1000);
  
  // Test long message
  display.print("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
  delay(3*1000);
  display.clear();
   
  // Test message's position
  display.print("TOP-LEFT");
  display.print("RIGHT-BOTTOM", 3, 4);
  delay(3*1000);
  display.clear();
  display.print("4th row", 3);
  delay(3*1000);
  
  // Test turn off of the display
  display.off();
  display.print("3rd row", 2, 8);
  delay(3*1000);
 
  // Test activate of the display
  display.on();
  delay(3*1000);
}
 
int r = 0, c = 0;
 
void loop() {
  
    r = r % 4;
    c = micros() % 6;
    if (r == 0) display.clear();
    display.print("Hello TTGO", r++, c++);
    delay(500);
}
