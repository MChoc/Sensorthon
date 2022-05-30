#include <M5Core2.h>

void setup()
{
    M5.begin();

    // Fill the screen with white
    M5.Lcd.fillScreen(WHITE);

    // Set the text colour to be black
    // Set the background of the text to be white
    M5.Lcd.setTextColor(BLACK, WHITE);

    // Text size can be set at multiples of 10
    // E.g. text size of 2 means 20 pixels down in the y direction
    // The screen has a size of 320 across, 240 down
    M5.Lcd.setTextSize(2);

    // Set the cursor to start printing at the specified coordinates
    M5.Lcd.setCursor(100, 100);
    M5.Lcd.printf("Hello world!");
    M5.Lcd.setCursor(100, 120);
    M5.Lcd.printf("Hello world!");

    // Clear the screen to white
    delay(1000);
    M5.Lcd.clear(WHITE);

    // Draw rectangle outline at (100, 100) of size 50x50
    // Draw filled in rectangle
    M5.Lcd.drawRect(100, 100, 50, 50, RED);
    delay(1000);
    M5.Lcd.fillRect(100, 100, 50, 50, GREEN);
    delay(1000);

    // Draw circle at (100, 100) with radius 50
    // Draw filled in circle
    M5.Lcd.drawCircle(100, 100, 50, BLUE);
    delay(1000);
    M5.Lcd.fillCircle(100, 100, 50, ORANGE);
    delay(1000);

    // Draw triangle with vertices at (30, 30), (50, 50), (100, 100)
    // Draw filled in triangle
    M5.Lcd.drawTriangle(160, 10, 10, 230, 230, 230, YELLOW);
    delay(1000);
    M5.Lcd.fillTriangle(160, 10, 10, 230, 230, 230, PURPLE);
    delay(1000);
}

void loop()
{

}