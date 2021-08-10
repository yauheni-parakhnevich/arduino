#include <FastLED.h>
#include <Button.h>

#define LED_PIN     4
#define NUM_LEDS    9 // Set to # of leds
#define GROUP_SIZE  NUM_LEDS / 3

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
    setColor(groupOneLeds, RED);
    setColor(groupTwoLeds, OFF);
    setColor(groupThreeLeds, YELLOW);
    FastLED.show();
    delay(1500);  
  
    setColor(groupOneLeds, OFF);
    setColor(groupTwoLeds, GREEN);
    setColor(groupThreeLeds, YELLOW);
    FastLED.show();
    delay(1500);  
  
    setColor(groupOneLeds, RED);
    setColor(groupTwoLeds, GREEN);
    setColor(groupThreeLeds, OFF);
    FastLED.show();
    delay(1500);  
 } else { // blue team
    setColor(groupOneLeds, GREEN);
    setColor(groupTwoLeds, OFF);
    setColor(groupThreeLeds, YELLOW);
    FastLED.show();
    delay(1500);  
  
    setColor(groupOneLeds, GREEN);
    setColor(groupTwoLeds, BLUE);
    setColor(groupThreeLeds, OFF);
    FastLED.show();
    delay(1500);  
  
    setColor(groupOneLeds, OFF);
    setColor(groupTwoLeds, BLUE);
    setColor(groupThreeLeds, YELLOW);
    FastLED.show();
    delay(1500);    
 }
  
}
