#include "LedControl.h"
#include "binary.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 10 is connected to the CLK 
 pin 11 is connected to LOAD 
 We have only a single MAX72XX.
 */

LedControl lc = LedControl(12,10,11,1);

long delaytime;

// staying
byte st[8]= {B00011000,
             B00011000,
             B00111100,
             B01011010,
             B10011001,
             B00011000,
             B00111100,
             B00100100};

//arms up 1
byte armUp1[8]= {B00011000,
             B00011000,
             B00111100,
             B11011011,
             B00011000,
             B00011000,
             B00111100,
             B00100100};
//arms up 2
byte armUp2[8]= {B00011000,
             B00011000,
             B11111111,
             B00011000,
             B00011000,
             B00011000,
             B00111100,
             B00100100};

//arms up 3
byte armUp3[8]= {B10011001,
             B01011010,
             B00111100,
             B00011000,
             B00011000,
             B00011000,
             B00111100,
             B00100100};

//legs 2
byte legs2[8]= {B00011000,
             B00011000,
             B11111111,
             B00011000,
             B00011000,
             B00011000,
             B01111110,
             B10000001};
             
//legs 3
byte legs3[8]= {B10011001,
             B01011010,
             B00111100,
             B00011000,
             B00011000,
             B00011000,
             B00111100,
             B01000010};

void setup() {
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,8);
  // Clear the display
  lc.clearDisplay(0);  

}

void dancer(int delaytime){
  if (delaytime>1201)
  {
    lc.setRow(0,0,st[0]);
    lc.setRow(0,1,st[1]);
    lc.setRow(0,2,st[2]);
    lc.setRow(0,3,st[3]);
    lc.setRow(0,4,st[4]);
    lc.setRow(0,5,st[5]);
    lc.setRow(0,6,st[6]);
    lc.setRow(0,7,st[7]);
    delay(delaytime);
  }
   if (delaytime<1200 and delaytime>401)
  {
    lc.setRow(0,0,armUp1[0]);
    lc.setRow(0,1,armUp1[1]);
    lc.setRow(0,2,armUp1[2]);
    lc.setRow(0,3,armUp1[3]);
    lc.setRow(0,4,armUp1[4]);
    lc.setRow(0,5,armUp1[5]);
    lc.setRow(0,6,armUp1[6]);
    lc.setRow(0,7,armUp1[7]);
    delay(delaytime);
    lc.setRow(0,0,armUp2[0]);
    lc.setRow(0,1,armUp2[1]);
    lc.setRow(0,2,armUp2[2]);
    lc.setRow(0,3,armUp2[3]);
    lc.setRow(0,4,armUp2[4]);
    lc.setRow(0,5,armUp2[5]);
    lc.setRow(0,6,armUp2[6]);
    lc.setRow(0,7,armUp2[7]);
    delay(delaytime);
    lc.setRow(0,0,armUp3[0]);
    lc.setRow(0,1,armUp3[1]);
    lc.setRow(0,2,armUp3[2]);
    lc.setRow(0,3,armUp3[3]);
    lc.setRow(0,4,armUp3[4]);
    lc.setRow(0,5,armUp3[5]);
    lc.setRow(0,6,armUp3[6]);
    lc.setRow(0,7,armUp3[7]);
    delay(delaytime);
  }
  
  if (delaytime<400)
  {
    lc.setRow(0,0,armUp1[0]);
    lc.setRow(0,1,armUp1[1]);
    lc.setRow(0,2,armUp1[2]);
    lc.setRow(0,3,armUp1[3]);
    lc.setRow(0,4,armUp1[4]);
    lc.setRow(0,5,armUp1[5]);
    lc.setRow(0,6,armUp1[6]);
    lc.setRow(0,7,armUp1[7]);
    delay(delaytime);
    lc.setRow(0,0,armUp2[0]);
    lc.setRow(0,1,armUp2[1]);
    lc.setRow(0,2,armUp2[2]);
    lc.setRow(0,3,armUp2[3]);
    lc.setRow(0,4,armUp2[4]);
    lc.setRow(0,5,armUp2[5]);
    lc.setRow(0,6,legs2[6]);
    lc.setRow(0,7,legs2[7]);
    delay(delaytime);
    lc.setRow(0,0,armUp3[0]);
    lc.setRow(0,1,armUp3[1]);
    lc.setRow(0,2,armUp3[2]);
    lc.setRow(0,3,armUp3[3]);
    lc.setRow(0,4,armUp3[4]);
    lc.setRow(0,5,armUp3[5]);
    lc.setRow(0,6,legs3[6]);
    lc.setRow(0,7,legs3[7]);
    delay(delaytime);
  }
}

void loop(){
  dancer(1210);
  dancer(500);
  dancer(300);
  dancer(500);
  dancer(300);

}
