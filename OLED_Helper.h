#ifndef OLED_Helper_h
#define OLED_Helper_h

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FishinoRTC.h>

class OLED_Helper
{
  public:
    OLED_Helper(Adafruit_SSD1306 *display);
    void firstLineText(String text);
    void secondLineText(String text, int size);
    String getTimeStamp(DateTime dateTime);
  private:
    Adafruit_SSD1306 *_display;
    String intToStr(int value);
};

#endif