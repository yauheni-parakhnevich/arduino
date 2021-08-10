#include <FastLED.h>
#include <Button.h>

#define LED_PIN     4
#define NUM_LEDS    9 // Set to # of leds
#define GROUP_SIZE  NUM_LEDS / 3
#define DELAY       1500

#define OFF         CRGB(0, 0, 0)
#define RED         CRGB(255, 0, 0)
#define GREEN       CRGB(0, 255, 0)
#define YELLOW      CRGB(255, 255, 0)
#define BLUE        CRGB(0, 0, 255)

CRGB leds[NUM_LEDS];
int groupOneLeds[] =   {0, 3, 6}; // Add led addresses here
int groupTwoLeds[] =   {1, 4, 7}; // Add led addresses here
int groupThreeLeds[] = {2, 5, 8}; // Add led addresses here

int buttonState = 1;

Button button1(2);

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  button1.begin();
}

void setColor(int group[], CRGB color) {
  for(int i = 0; i < GROUP_SIZE; i++) {
    leds[group[i]] = color;
  }
}

void showColorSet(CRGB color1, CRGB color2, CRGB color3) {
    setColor(groupOneLeds, color1);
    setColor(groupTwoLeds, color2);
    setColor(groupThreeLeds, color3);
    FastLED.show();
    delay(DELAY);  
}

void loop() {
 // read button state
    if (button1.pressed()) {
        if (buttonState == 1) {
          buttonState = 2;
        } else {
          buttonState = 1;
        }
    }
    
 if(buttonState == 1) { //red team
    showColorSet(RED, OFF, YELLOW);  
    showColorSet(OFF, GREEN, YELLOW);
    showColorSet(RED, GREEN, OFF);
 } else { // blue team
    showColorSet(GREEN, OFF, YELLOW);
    showColorSet(GREEN, BLUE, OFF);
    showColorSet(OFF, BLUE, YELLOW);
 }
  
}
