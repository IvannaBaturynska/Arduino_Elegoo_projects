#include <MD_MAX72xx.h>
#include <SPI.h>
#include <MD_Parola.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1
#define CS_PIN 11

#define DATA_PIN 12
#define CLK_PIN 10


// Create a new instance of the MD_MAX72XX class:
MD_Parola matrix = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  // put your setup code here, to run once:
  matrix.begin(); // MAX7219 initialization
  matrix.setIntensity(8);
  matrix.displayClear();
}

void loop() {
  // put your main code here, to run repeatedly:
  matrix.print("A");
  delay(1000);
  
  matrix.displayClear();
  
  matrix.print('B');
  delay(1000);
  matrix.displayClear();
}
