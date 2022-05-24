#include <Arduino.h>
#include <M5Core2.h>
#include "animation.h"

#define SCALE 3

void setup()
{
  Serial.begin(115200);
  M5.begin();
}

void loop()
{
  for (int z = 0; z < 12; z++)
  {
    for (int y = 0; y < 64; y++)
    {
      for (int x = 0; x < 64; x++)
      {
        char ch = frames[z][y][x];
        int colour = 0x0000;
        if (ch == ',')
        {
          colour = 0x000B;
        }
        else if (ch == '\'')
        {
          colour = 0x0000;
        }
        else if (ch == '*')
        {
          colour = 0x5ACB;
        }
        else if (ch == '.')
        {
          colour = 0xFFFF;
        }
        else if (ch == '%')
        {
          colour = 0xD435;
        }
        else if (ch == '@')
        {
          colour = 0xFFFA;
        }
        else if (ch == '$')
        {
          colour = 0xD435;
        }
        else if (ch == '-')
        {
          colour = 0xD010;
        }
        else if (ch == '>')
        {
          colour = 0xF800;
        }
        else if (ch == '&')
        {
          colour = 0xFD60;
        }
        else if (ch == '+')
        {
          colour = 0xFFE0;
        }
        else if (ch == '#')
        {
          colour = 0x87E0;
        }
        else if (ch == '=')
        {
          colour = 0x043F;
        }
        else if (ch == ';')
        {
          colour = 0x0015;
        }
        M5.Lcd.fillRect(x * SCALE, y * SCALE, SCALE, SCALE, colour);
      }
    }
  }
}