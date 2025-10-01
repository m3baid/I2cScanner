#include <Wire.h>
#include <GyverOLED.h>
//GyverOLED<SSD1306_128x32, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER, OLED_SPI, 8, 7, 6> oled;
GyverOLED<SSH1106_128x64> oled;

void I2cScanner();

void setup() {
  Wire.begin(); // Initialize I2C communication
  oled.init();
  oled.clear();
  oled.update();

  //oled.setCursorXY(28, 26);
  //oled.print("Hello World!");
  oled.rect(0,0,127,63,OLED_STROKE);
  oled.update();

  I2cScanner();
}

void loop() {

}


void I2cScanner() 
{
  byte error, address;
  int nDevices;
  oled.clear();
  oled.setCursorXY(28, 25);
  oled.print("Scanning...");
  oled.rect(0,0,127,63,OLED_STROKE);
  oled.update();

  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // 1- Ignore the address 0x3C
    if (address == 0x3C) {
      continue; // Skip the rest of the loop for this address
    }
    
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      oled.clear();
      oled.setCursorXY(5, 20);
      oled.print("Device found at 0x");
      
      if (address<16)
      { Serial.print("0"); }
      oled.print(address,HEX);
      oled.print("  !");
      nDevices++;
      oled.rect(0,0,127,63,OLED_STROKE);
      oled.update();
    }
    else if (error==4)
    {
      oled.clear();
      oled.setCursorXY(2, 20);
      oled.print("Unknown error at 0x");
      if (address<16)
      { oled.print("0"); }
      oled.print(address,HEX);
      oled.rect(0,0,127,63,OLED_STROKE);
      oled.update();
    }    
  }
  if (nDevices == 0)
  { 
    oled.clear();
    oled.setCursorXY(4, 20);
    oled.print("No I2C devices found");
    oled.rect(0,0,127,63,OLED_STROKE);
    oled.update();  
  }
}