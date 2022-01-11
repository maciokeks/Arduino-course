#include <Adafruit_NeoPixel.h> // dołączenie biblioteki do projektu
#define pin_strip = 5; // ustawienie pinu pod pasek led
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, pin_strip, NEO_GRB + NEO_KHZ800); // utworzenie objektu strip i podanie parametrów
void setup() {
  strip.begin(); // inicjalizacja
  strip.show();
}

void loop() {
  strip.setPixelColor(0,strip.Color(255,0,0)); // ustawienie koloru
  strip.show();
  delay(1000);
  
  strip.setPixelColor(0,strip.Color(0,0,0));
  strip.show();
  delay(1000);

}
