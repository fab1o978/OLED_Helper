#include <OLED_Helper.h>
#include <Arduino.h>
#include <FishinoRTC.h>
#include <stdio.h>

OLED_Helper::OLED_Helper(Adafruit_SSD1306 *display)
{
  //TODO
  _display = display;
}

void OLED_Helper::firstLineText(String text)
{
    _display->setTextSize(1);
    _display->setTextColor(WHITE);
    _display->setCursor(0, 3);
    _display->println(text);
    _display->drawLine(0, 15, 128, 15, WHITE);
    _display->display();
}

void OLED_Helper::secondLineText(String text, int size)
{
    _display->setTextSize(size);
    _display->setTextColor(WHITE);
    _display->setCursor(0,16);
    _display->println(text);
    _display->display();
}

String OLED_Helper::getTimeStamp(DateTime dateTime)
{
    String hour = intToStr(dateTime.hour());
    String minute = intToStr(dateTime.minute());
    String day = intToStr(dateTime.day());
    String month = intToStr(dateTime.month());
    String year = String(dateTime.year());
    
    return day + "/" + month + "/" + year + " " + hour + ":" + minute;
}

String OLED_Helper::intToStr(int value)
{
    if(value < 10)
        return "0" + String(value);
    else
        return String(value);
}