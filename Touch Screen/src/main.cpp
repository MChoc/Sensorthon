#include <M5Core2.h>

// Draw a circle at the given point and colour
void printCircle(Point p, uint16_t c)
{
  M5.Lcd.drawCircle(p.x, p.y, 50, c);
  M5.Lcd.drawCircle(p.x, p.y, 52, c);
}

void setup()
{
  M5.begin();
  M5.Lcd.fillScreen(WHITE);
}

void loop()
{
  M5.update();
  Event &e = M5.Buttons.event;

  // Print a white circle when moving or releasing touch screen
  // The move condition gets overwritten by the next statement
  if (e & (E_MOVE | E_RELEASE)) printCircle(e & E_MOVE ? e.from : e.to, WHITE);

  // Print a red circle when moving or release touch screen
  if (e & (E_TOUCH | E_MOVE)) printCircle(e.to, e.finger ? BLUE : RED);
}